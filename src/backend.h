#pragma once
#include <QObject>

struct State {
    bool initialized = false;
};

class Backend : public QObject
{
	Q_OBJECT
	Q_PROPERTY(State state READ get_state WRITE set_state NOTIFY state_changed)
public:
    Backend();
    State get_state();
    void set_state(State s);
signals:
    void state_changed();
private:
    State state;
};
