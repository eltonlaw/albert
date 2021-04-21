#include <fstream>
#include <filesystem>
#include <sdbusplus/server.hpp>
#include "org/joomby/TemperatureSensor/server.hpp"
#include "org/joomby/TemperatureSensor/error.hpp"

using server = sdbusplus::server::object_t<sdbusplus::org::joomby::server::TemperatureSensor>;

constexpr auto device_path = "/dev/bme2800";
std::ifstream f;

struct TemperatureSensor : server {
    TemperatureSensor(sdbusplus::bus::bus& bus, const char* path) :
        server(bus, path)
    {
       if (!std::filesystem::exists(device_path))
           throw sdbusplus::org::joomby::TemperatureSensor::Error::FileNotFound();
       f.open(device_path, std::ios::in|std::ios::binary);
    }

    int64_t read() override
    {
        return 21;
    }
};

int main() {
    constexpr auto path = "/org/joomby/TemperatureSensor";

    auto b = sdbusplus::bus::new_default();
    sdbusplus::server::manager_t m{b, path};

    b.request_name("org.joomby.TemperatureSensor");

    TemperatureSensor sensor{b, path};

    while (1) {
        b.process_discard(); // discard any unhandled messages
        b.wait();
    }

    return 0;
}
