#include <cmath>
#include <QAbstractItemModel>
#include <QDebug>
#include <QList>
#include <QModelIndex>
#include <QObject>
#include <QPointF>
#include <Qt>
#include <QtGlobal>
#include <QVariant>
#include <thread>

#include "temp_sensor.h"

TempSensor::TempSensor()
{
    QObject::connect(this, &TempSensor::new_temp_measurement,
                     this, &TempSensor::append,
                     Qt::QueuedConnection);
}

void TempSensor::append(const QPointF& point)
{
    if (queue.capacity == queue.size) {
        queue.enqueue(point);
        QModelIndex top_left = createIndex(0, 0);
        QModelIndex bottom_right = createIndex(rowCount(), 2);
        emit dataChanged(top_left, bottom_right);
    } else {
        beginInsertRows(QModelIndex(), rowCount() -1 , rowCount() -1);
        queue.enqueue(point);
        endInsertRows();
    }
}

/* Returns number of time/temperature datapoints available
 *
 * Number of rows should usually be the max size of the fixed_queue
 * except in the beginning (when its still filling up)
 *
 * Required when subclassing QAbstractTableModel
 */
int TempSensor::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return queue.size;
}

/* Returns number of columns in data
 *
 * Fixed to 2 because each datapoint is [time, temperature]
 *
 * Required when subclassing QAbstractTableModel
 */
int TempSensor::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant TempSensor::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(orientation)
    Q_UNUSED(role)

    if(section == 0)
        return "x";
    else
        return "y";
}

/* Returns most recent n temperatures
 *
 * ...where n is the size of the fixed_queue, currently hardcoded at 50
+*/
QVariant TempSensor::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)
    auto r = index.row();
    auto e = queue.get(r);
    if (index.column() == 0)
        // FIXME: Hacky, this is circumventing the QModelIndex using
        // the row index and a fixed queue.
        return r;
    else
        return e.y();
}

/* Read temperature from device
 *
 * Assumes that there's a char device driver at `/dev/bme280`
 */
double TempSensor::read_temperature_sensor() {
    return (double) (rng.random() % 25);
}

/* Continuously poll temperature sensor
 *
 * while true fn to continuously read latest temp from device and emit
 * new_temp_measurement. This is run in a separate thread
 *
 * FIXME: argument should be a std::chrono::duration<Rep, Period> instead of ms
 */
void TempSensor::poll(std::chrono::milliseconds ms)
{
    std::thread t([this, ms] {
        for(double t=0 ; ; t+=1)
        {
            double y = read_temperature_sensor();
            // double y = (1 + sin(t/10.0)) / 2.0 * 20;

            emit new_temp_measurement(QPointF((int)t % queue.capacity, y));

            std::this_thread::sleep_for(ms);
        }
    });
    t.detach();
}
