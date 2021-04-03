#include <QObject>
#include <QDebug>
#include "temp_sensor.h"

TempSensor::TempSensor(QObject *parent) {

}

void TempSensor::start() {
    qDebug() << "TempSensor::start()";
    _temp = 0.0; 
    emit temp_changed();
}

void TempSensor::stop() {
    qDebug() << "TempSensor::stop()";
    _temp = -1.0; 
    emit temp_changed();
}

double TempSensor::get_temp() {
    qDebug() << "TempSensor::get_temp()" << _temp;
    return _temp;
}

void TempSensor::set_temp(double d) {
    qDebug() << "TempSensor::set_temp() " << d;
    _temp = d;
    emit temp_changed();
}
