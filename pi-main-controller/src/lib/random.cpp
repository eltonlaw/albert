#include <iostream>
#include <fstream>
#include "random.h"

namespace lib {

urandom::urandom() {
    f.open("/dev/urandom", std::ios::in|std::ios::binary);
}

urandom::~urandom() {
    if (f.is_open())
        f.close();
}

unsigned long long int urandom::random() {
    if (f.is_open()) {
        f.read(reinterpret_cast<char*>(&val), size);
        return val;
    }
    else {
        return val;
    }
}

} // namespace lib
