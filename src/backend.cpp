#include "backend.h"

Backend::Backend() {

}

State Backend::get_state() {
    return state;
}

void Backend::set_state(State s) {
    state = s;
}
