#include <iostream>
#include <fstream>

namespace lib {

class urandom {
public:
    urandom();
    ~urandom();
    unsigned long long int random();

private:
    unsigned long long int val = 0;
    size_t size = sizeof(val);
    std::ifstream f;
};

} // namespace lib
