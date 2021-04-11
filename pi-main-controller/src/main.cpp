#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QVXYModelMapper>
#include "temp_sensor.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    auto temp_sensor = new TempSensor();
    temp_sensor->poll(std::chrono::milliseconds(100));

    auto temp_sensor_mapper = new QtCharts::QVXYModelMapper();
    temp_sensor_mapper->setModel(temp_sensor);
    temp_sensor_mapper->setXColumn(0);
    temp_sensor_mapper->setYColumn(1);

    engine.rootContext()->setContextProperty("temp_sensor_mapper", temp_sensor_mapper);
    engine.load(QStringLiteral("qrc:/qml/main.qml"));

    return app.exec();
}
