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
    TempSensor temp_sensor;
    auto my_data_model = new MyDataModel();

    auto mapper = new QtCharts::QVXYModelMapper();
    mapper->setModel(my_data_model);
    mapper->setXColumn(0);
    mapper->setYColumn(1);

    std::thread point_generator_thread(&MyDataModel::point_generator_proc, my_data_model);
    point_generator_thread.detach();

    engine.rootContext()->setContextProperty("tempSensor", &temp_sensor);
    engine.rootContext()->setContextProperty("mapper", mapper);
    engine.load(QStringLiteral("qrc:/qml/main.qml"));

    return app.exec();
}
