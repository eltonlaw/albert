#include <sdbusplus/server.hpp>
#include "org/joomby/TemperatureSensor/server.hpp"
#include "org/joomby/TemperatureSensor/error.hpp"

int main() {
    constexpr auto path = "/org/joomby/TemperatureSensor";

    auto b = sdbusplus::bus::new_default();
    sdbusplus::server::manager_t m{b, path};

    return 0;
}
