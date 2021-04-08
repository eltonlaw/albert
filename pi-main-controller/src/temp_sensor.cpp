#include <QObject>
#include <QList>
#include <QDebug>
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
    temp = 0.0;
    emit temp_changed();
}

void TempSensor::stop() {
    qDebug() << "TempSensor::stop()";
    temp = -1.0;
    emit temp_changed();
}

double TempSensor::get_temp() {
    qDebug() << "TempSensor::get_temp()" << temp;
    return temp;
}

void TempSensor::set_temp(double d) {
    qDebug() << "TempSensor::set_temp() " << d;
    temp = d;
    emit temp_changed();
}

QList<float> TempSensor::get_temps() {
    return temps;
}
