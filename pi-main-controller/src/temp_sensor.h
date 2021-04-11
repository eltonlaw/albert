#pragma once

#include <QAbstractTableModel>
#include <QObject>
#include <QList>
#include <QPointF>
#include <vector>

#include "lib/lib.h"

class TempSensor : public QAbstractTableModel
{
    Q_OBJECT
signals:
    // signal emitted during every tick of poll(), passing along the new measurement
    void new_temp_measurement(const QPointF& point);
public:
    TempSensor();

    // QT specific methods (rowCount, columnCount and data are required to subclass QAbstractTableModel)
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    /* */
    void poll();
    double read_temperature_sensor();

private:
    void append(const QPointF& point);
    // lib::fixed_queue<QPointF, 10> queue;
    lib::urandom rng {};
    std::vector<QPointF> m_data;
};
