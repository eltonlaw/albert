#pragma once
#include <QObject>
#include <QList>
#include "lib/lib.h"

class TempSensor: public QObject {
    Q_OBJECT
    Q_PROPERTY(double temp READ get_temp WRITE set_temp NOTIFY temp_changed)
    Q_PROPERTY(QList<float> temps READ get_temps NOTIFY temps_changed)
public:
    explicit TempSensor(QObject *parent = nullptr);

signals:
    void temp_changed(void);
    void temps_changed(void);

public slots:
    void start();
    void stop();

private:
    double temp = -1.0;
    double get_temp();
    void set_temp(double);
    lib::fixed_queue<double, 10> queue;
    QList<float> temps;
    QList<float> get_temps();
};
