#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include "temp_sensor.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    TempSensor temp_sensor;
    engine.rootContext()->setContextProperty("tempSensor", &temp_sensor);
    engine.load(QStringLiteral("qrc:/qml/main.qml"));

    return app.exec();
}
