#pragma once
#include <QObject>

struct State {
    bool initialized = false;
};

class Backend : public QObject
{
	Q_OBJECT
	// Q_PROPERTY(State state READ get_state WRITE set_state NOTIFY state_changed)
public:
    explicit Backend(QObject *parent = 0);
    State get_state();
    void set_state(State s);

public slots:
    void handle();
// signals:
//     void state_changed();
private:
    State state;
};
