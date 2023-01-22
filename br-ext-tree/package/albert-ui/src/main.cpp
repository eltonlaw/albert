#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QVXYModelMapper>
#include "temp_sensor.h"

/* Start QT5 UI */
int main(int argc, char *argv[])
{
    // Class that contains the event loop
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    auto temp_sensor = new TempSensor();
    temp_sensor->poll(std::chrono::milliseconds(200));

    // Create a model mapper that takes temp sensor as the data source
    auto temp_sensor_mapper = new QtCharts::QVXYModelMapper();
    temp_sensor_mapper->setModel(temp_sensor);
    temp_sensor_mapper->setXColumn(0);
    temp_sensor_mapper->setYColumn(1);

    engine.rootContext()->setContextProperty("temp_sensor_mapper", temp_sensor_mapper);
    engine.load(QStringLiteral("qrc:/qml/main.qml"));

    // Start the event loop. Only returns when `quit()` is called
    return app.exec();
}
