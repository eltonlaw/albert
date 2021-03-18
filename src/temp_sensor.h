#pragma once
#include <QObject>

class TempSensor: public QObject {
    Q_OBJECT
    Q_PROPERTY(double temp READ get_temp WRITE set_temp NOTIFY temp_changed)
public:
    explicit TempSensor(QObject *parent = nullptr);

signals:
    void temp_changed(void);

public slots:
    void start();
    void stop();

private:
    double _temp = -1.0;
    double get_temp();
    void set_temp(double);
};
