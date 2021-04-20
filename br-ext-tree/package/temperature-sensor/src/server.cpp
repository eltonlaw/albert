#include <algorithm>
#include <map>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/sdbuspp_support/server.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>

#include "org/joomby/TemperatureSensor/server.hpp"




#include "org/joomby/TemperatureSensor/error.hpp"


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

TemperatureSensor::TemperatureSensor(bus::bus& bus, const char* path,
                           const std::map<std::string, PropertiesVariant>& vals,
                           bool skipSignal)
        : TemperatureSensor(bus, path)
{
    for (const auto& v : vals)
    {
        setPropertyByName(v.first, v.second, skipSignal);
    }
}


int TemperatureSensor::_callback_Read(
        sd_bus_message* msg, void* context, sd_bus_error* error)
{
    auto o = static_cast<TemperatureSensor*>(context);

    {
        return sdbusplus::sdbuspp::method_callback(
                msg, o->_intf, error,
                std::function(
                    [=](int64_t&& x, int64_t&& y)
                    {
                        return o->read(
                                x, y);
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
        utility::tuple_to_array(message::types::type_id<
                int64_t, int64_t>());
static const auto _return_Read =
        utility::tuple_to_array(message::types::type_id<
                int64_t>());
}
}


void TemperatureSensor::cleared(
            int64_t unnamed)
{
    auto& i = _org_joomby_TemperatureSensor_interface;
    auto m = i.new_signal("Cleared");

    m.append(unnamed);
    m.signal_send();
}

namespace details
{
namespace TemperatureSensor
{
static const auto _signal_Cleared =
        utility::tuple_to_array(message::types::type_id<
                int64_t>());
}
}


auto TemperatureSensor::lastResult() const ->
        int64_t
{
    return _lastResult;
}

int TemperatureSensor::_callback_get_LastResult(
        sd_bus* /*bus*/, const char* /*path*/, const char* /*interface*/,
        const char* /*property*/, sd_bus_message* reply, void* context,
        sd_bus_error* error)
{
    auto o = static_cast<TemperatureSensor*>(context);

    {
        return sdbusplus::sdbuspp::property_callback(
                reply, o->_intf, error,
                std::function(
                    [=]()
                    {
                        return o->lastResult();
                    }
                ));
    }
}

auto TemperatureSensor::lastResult(int64_t value,
                                         bool skipSignal) ->
        int64_t
{
    if (_lastResult != value)
    {
        _lastResult = value;
        if (!skipSignal)
        {
            _org_joomby_TemperatureSensor_interface.property_changed("LastResult");
        }
    }

    return _lastResult;
}

auto TemperatureSensor::lastResult(int64_t val) ->
        int64_t
{
    return lastResult(val, false);
}

int TemperatureSensor::_callback_set_LastResult(
        sd_bus* /*bus*/, const char* /*path*/, const char* /*interface*/,
        const char* /*property*/, sd_bus_message* value, void* context,
        sd_bus_error* error)
{
    auto o = static_cast<TemperatureSensor*>(context);

    {
        return sdbusplus::sdbuspp::property_callback(
                value, o->_intf, error,
                std::function(
                    [=](int64_t&& arg)
                    {
                        o->lastResult(std::move(arg));
                    }
                ));
    }

    return true;
}

namespace details
{
namespace TemperatureSensor
{
static const auto _property_LastResult =
    utility::tuple_to_array(message::types::type_id<
            int64_t>());
}
}

auto TemperatureSensor::status() const ->
        State
{
    return _status;
}

int TemperatureSensor::_callback_get_Status(
        sd_bus* /*bus*/, const char* /*path*/, const char* /*interface*/,
        const char* /*property*/, sd_bus_message* reply, void* context,
        sd_bus_error* error)
{
    auto o = static_cast<TemperatureSensor*>(context);

    {
        return sdbusplus::sdbuspp::property_callback(
                reply, o->_intf, error,
                std::function(
                    [=]()
                    {
                        return o->status();
                    }
                ));
    }
}

auto TemperatureSensor::status(State value,
                                         bool skipSignal) ->
        State
{
    if (_status != value)
    {
        _status = value;
        if (!skipSignal)
        {
            _org_joomby_TemperatureSensor_interface.property_changed("Status");
        }
    }

    return _status;
}

auto TemperatureSensor::status(State val) ->
        State
{
    return status(val, false);
}


namespace details
{
namespace TemperatureSensor
{
static const auto _property_Status =
    utility::tuple_to_array(message::types::type_id<
            org::joomby::server::TemperatureSensor::State>());
}
}

auto TemperatureSensor::owner() const ->
        std::string
{
    return _owner;
}

int TemperatureSensor::_callback_get_Owner(
        sd_bus* /*bus*/, const char* /*path*/, const char* /*interface*/,
        const char* /*property*/, sd_bus_message* reply, void* context,
        sd_bus_error* error)
{
    auto o = static_cast<TemperatureSensor*>(context);

    try
    {
        return sdbusplus::sdbuspp::property_callback(
                reply, o->_intf, error,
                std::function(
                    [=]()
                    {
                        return o->owner();
                    }
                ));
    }
    catch(sdbusplus::org::joomby::TemperatureSensor::Error::PermissionDenied& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }
}

auto TemperatureSensor::owner(std::string value,
                                         bool skipSignal) ->
        std::string
{
    if (_owner != value)
    {
        _owner = value;
        if (!skipSignal)
        {
            _org_joomby_TemperatureSensor_interface.property_changed("Owner");
        }
    }

    return _owner;
}

auto TemperatureSensor::owner(std::string val) ->
        std::string
{
    return owner(val, false);
}

int TemperatureSensor::_callback_set_Owner(
        sd_bus* /*bus*/, const char* /*path*/, const char* /*interface*/,
        const char* /*property*/, sd_bus_message* value, void* context,
        sd_bus_error* error)
{
    auto o = static_cast<TemperatureSensor*>(context);

    try
    {
        return sdbusplus::sdbuspp::property_callback(
                value, o->_intf, error,
                std::function(
                    [=](std::string&& arg)
                    {
                        o->owner(std::move(arg));
                    }
                ));
    }
    catch(sdbusplus::org::joomby::TemperatureSensor::Error::PermissionDenied& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace TemperatureSensor
{
static const auto _property_Owner =
    utility::tuple_to_array(message::types::type_id<
            std::string>());
}
}

void TemperatureSensor::setPropertyByName(const std::string& _name,
                                     const PropertiesVariant& val,
                                     bool skipSignal)
{
    if (_name == "LastResult")
    {
        auto& v = std::get<int64_t>(val);
        lastResult(v, skipSignal);
        return;
    }
    if (_name == "Status")
    {
        auto& v = std::get<State>(val);
        status(v, skipSignal);
        return;
    }
    if (_name == "Owner")
    {
        auto& v = std::get<std::string>(val);
        owner(v, skipSignal);
        return;
    }
}

auto TemperatureSensor::getPropertyByName(const std::string& _name) ->
        PropertiesVariant
{
    if (_name == "LastResult")
    {
        return lastResult();
    }
    if (_name == "Status")
    {
        return status();
    }
    if (_name == "Owner")
    {
        return owner();
    }

    return PropertiesVariant();
}


namespace
{
/** String to enum mapping for TemperatureSensor::State */
static const std::tuple<const char*, TemperatureSensor::State> mappingTemperatureSensorState[] =
        {
            std::make_tuple( "org.joomby.TemperatureSensor.State.Success",                 TemperatureSensor::State::Success ),
            std::make_tuple( "org.joomby.TemperatureSensor.State.Error",                 TemperatureSensor::State::Error ),
        };

} // anonymous namespace

auto TemperatureSensor::convertStateFromString(const std::string& s) ->
        State
{
    auto i = std::find_if(
            std::begin(mappingTemperatureSensorState),
            std::end(mappingTemperatureSensorState),
            [&s](auto& e){ return 0 == strcmp(s.c_str(), std::get<0>(e)); } );
    if (std::end(mappingTemperatureSensorState) == i)
    {
        throw sdbusplus::exception::InvalidEnumString();
    }
    else
    {
        return std::get<1>(*i);
    }
}

std::string TemperatureSensor::convertStateToString(TemperatureSensor::State v)
{
    auto i = std::find_if(
            std::begin(mappingTemperatureSensorState),
            std::end(mappingTemperatureSensorState),
            [v](auto& e){ return v == std::get<1>(e); });
    if (i == std::end(mappingTemperatureSensorState))
    {
        throw std::invalid_argument(std::to_string(static_cast<int>(v)));
    }
    return std::get<0>(*i);
}

const vtable::vtable_t TemperatureSensor::_vtable[] = {
    vtable::start(),

    vtable::method("Read",
                   details::TemperatureSensor::_param_Read
                        .data(),
                   details::TemperatureSensor::_return_Read
                        .data(),
                   _callback_Read),

    vtable::signal("Cleared",
                   details::TemperatureSensor::_signal_Cleared
                        .data()),
    vtable::property("LastResult",
                     details::TemperatureSensor::_property_LastResult
                        .data(),
                     _callback_get_LastResult,
                     _callback_set_LastResult,
                     vtable::property_::emits_change),
    vtable::property("Status",
                     details::TemperatureSensor::_property_Status
                        .data(),
                     _callback_get_Status,
                     vtable::property_::const_),
    vtable::property("Owner",
                     details::TemperatureSensor::_property_Owner
                        .data(),
                     _callback_get_Owner,
                     _callback_set_Owner,
                     vtable::property_::emits_change),
    vtable::end()
};

} // namespace server
} // namespace joomby
} // namespace org
} // namespace sdbusplus

