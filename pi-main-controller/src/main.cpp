#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QVXYModelMapper>
#include <thread>
#include "temp_sensor.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    auto temp_sensor = new TempSensor();

    auto temp_sensor_mapper = new QtCharts::QVXYModelMapper();
    temp_sensor_mapper->setModel(temp_sensor);
    temp_sensor_mapper->setXColumn(0);
    temp_sensor_mapper->setYColumn(1);

    std::thread point_generator_thread(&TempSensor::poll, temp_sensor);
    point_generator_thread.detach();

    engine.rootContext()->setContextProperty("temp_sensor_mapper", temp_sensor_mapper);
    engine.load(QStringLiteral("qrc:/qml/main.qml"));

    return app.exec();
}
