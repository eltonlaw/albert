#include <QObject>
#include <QDebug>
#include "temp_sensor.h"

TempSensor::TempSensor(QObject *parent) {

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
