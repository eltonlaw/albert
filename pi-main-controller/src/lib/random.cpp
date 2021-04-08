#include <iostream>
#include <fstream>
#include "random.h"

namespace lib {

urandom::urandom() {
    f.open("/dev/urandom", std::ios::in|std::ios::binary);
}

urandom::~urandom() {
    f.close();
}

unsigned long long int urandom::random() {
    f.read(reinterpret_cast<char*>(&val), size);
    return val;
}

} // namespace lib
