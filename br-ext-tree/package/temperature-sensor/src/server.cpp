#include <algorithm>
#include <map>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/sdbuspp_support/server.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>

#include "org/joomby/TemperatureSensor/server.hpp"


namespace sdbusplus
{
namespace org
{
namespace joomby
{
namespace server
{

TemperatureSensor::TemperatureSensor(bus::bus& bus, const char* path)
        : _org_joomby_TemperatureSensor_interface(
                bus, path, interface, _vtable, this), _intf(bus.getInterface())
{
}


int TemperatureSensor::_callback_Read(
        sd_bus_message* msg, void* context, sd_bus_error* error)
{
    auto o = static_cast<TemperatureSensor*>(context);

    {
        return sdbusplus::sdbuspp::method_callback(
                msg, o->_intf, error,
                std::function(
                    [=]()
                    {
                        return o->read(
                                );
                    }
                ));
    }

    return 0;
}

namespace details
{
namespace TemperatureSensor
{
static const auto _param_Read =
        utility::tuple_to_array(std::make_tuple('\0'));
static const auto _return_Read =
        utility::tuple_to_array(message::types::type_id<
                int64_t>());
}
}




const vtable::vtable_t TemperatureSensor::_vtable[] = {
    vtable::start(),

    vtable::method("Read",
                   details::TemperatureSensor::_param_Read
                        .data(),
                   details::TemperatureSensor::_return_Read
                        .data(),
                   _callback_Read),
    vtable::end()
};

} // namespace server
} // namespace joomby
} // namespace org
} // namespace sdbusplus

