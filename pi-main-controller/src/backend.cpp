#include "backend.h"
#include <QObject>
#include <QDebug>

Backend::Backend(QObject *parent): QObject(parent) {

}

State Backend::get_state() {
    qDebug() << "get_state called";
    return state;
}

void Backend::set_state(State s) {
    qDebug() << "set_state called";
    state = s;
}

void Backend::handle() {
    qDebug() << "handle called";
}
