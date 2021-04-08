#include <iostream>
#include <fstream>
namespace lib {

class urandom {
public:
    urandom();
    ~urandom();
    unsigned long long int random();

private:
    unsigned long long int val;
    size_t size = sizeof(val);
    std::ifstream f;
};

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
