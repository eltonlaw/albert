#include <cmath>
#include <QDebug>
#include <QList>
#include <QObject>
#include <QPointF>
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
    if (m_data.size() > 0) {
        beginRemoveRows(QModelIndex(), rowCount(), rowCount());
        m_data.pop_back();
        endRemoveRows();
    }

    beginInsertRows(QModelIndex(), rowCount() -1 , rowCount() -1);
    m_data.push_back(point);
    for (auto e: m_data)
        std::cout << e.x() << ", "<< e.y() << std::endl;
    endInsertRows();
}


int TempSensor::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.size();
}

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

QVariant TempSensor::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)
    // FIXME: make queue store tuples
    // if (index.column() == 0)
    //     return queue.get(index.row());
    // else
    //     return queue.get(index.row());
    if (index.column() == 0)
        return m_data[index.row()].x();
    else
        return m_data[index.row()].y();
}

void TempSensor::poll()
{
    for(double t=0 ; ; t+=1)
    {
        double y = (1 + sin(t/10.0)) / 2.0;

        emit new_temp_measurement(QPointF(0, y));

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
