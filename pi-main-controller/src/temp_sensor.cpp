#include <cmath>
#include <QObject>
#include <QList>
#include <QDebug>
#include <QPointF>
#include <thread>
#include "temp_sensor.h"

TempSensor::TempSensor(QObject *parent) {
    temps.append(1.0);
    temps.append(3.0);
    temps.append(4.0);
    temps.append(7.0);
    temps.append(5.0);
    temps.append(6.0);
    temps.append(6.0);
    temps.append(9.0);
    temps.append(9.0);
    temps.append(9.0);
    temps.append(9.0);
}

void TempSensor::start() {
    qDebug() << "TempSensor::start()";
    temps[0] = 0.0;
    emit temps_changed();
}

void TempSensor::stop() {
    qDebug() << "TempSensor::stop()";
    temps[0] += 1.0;
    emit temps_changed();
}

double TempSensor::get_temp() {
    qDebug() << "TempSensor::get_temp()" << temp;
    return temp;
}

void TempSensor::set_temp(double d) {
    qDebug() << "TempSensor::set_temp() " << d;
    emit temps_changed();
}

QList<float> TempSensor::get_temps() {
    return temps;
}

MyDataModel::MyDataModel()
{
    QObject::connect(this, &MyDataModel::newPointAdded, this, &MyDataModel::addNewPoint,
                     Qt::QueuedConnection);
}


void MyDataModel::handle_new_point(const QPointF &point)
{
    emit newPointAdded(point);
}

void MyDataModel::addNewPoint(const QPointF& point)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.push_back(point);
    endInsertRows();
}


int MyDataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.size();
}

int MyDataModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant MyDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(orientation)
    Q_UNUSED(role)

    if(section == 0)
        return "x";
    else
        return "y";
}

QVariant MyDataModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)

    if (index.column() == 0)
        return m_data[index.row()].x();
    else
        return m_data[index.row()].y();
}

void MyDataModel::point_generator_proc()
{
    for(double t=0 ; ; t+=1)
    {
        double y = (1 + sin(t/10.0)) / 2.0;

        handle_new_point(QPointF(t, y));

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
