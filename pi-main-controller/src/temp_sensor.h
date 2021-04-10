#pragma once

#include <QObject>
#include <QAbstractTableModel>
#include <QList>
#include <QPointF>
#include "lib/lib.h"
#include <vector>

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
    lib::urandom rng {};
    QList<float> temps;
    QList<float> get_temps();
};

class MyDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    void handle_new_point(const QPointF& point);
signals:
    void newPointAdded(const QPointF& point);
public:
    MyDataModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void point_generator_proc();

private:
    void addNewPoint(const QPointF& point);
    std::vector<QPointF> m_data;
};
