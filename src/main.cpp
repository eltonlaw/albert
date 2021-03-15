#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDirIterator>
#include <QDebug>
#include "backend.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Backend backend;
    engine.rootContext()->setContextProperty("backend", &backend);
    engine.load(QStringLiteral("qrc:/main.qml"));

    // QDirIterator it(":/", QDirIterator::Subdirectories);
    // while (it.hasNext())
    //     qDebug() << it.next();

    return app.exec();
}
