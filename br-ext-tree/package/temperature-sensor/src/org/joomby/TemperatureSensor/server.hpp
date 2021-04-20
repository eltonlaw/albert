#pragma once
#include <limits>
#include <map>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <sdbusplus/utility/dedup_variant.hpp>
#include <string>
#include <systemd/sd-bus.h>
#include <tuple>






namespace sdbusplus
{
namespace org
{
namespace joomby
{
namespace server
{

class TemperatureSensor
{
    public:
        /* Define all of the basic class operations:
         *     Not allowed:
         *         - Default constructor to avoid nullptrs.
         *         - Copy operations due to internal unique_ptr.
         *         - Move operations due to 'this' being registered as the
         *           'context' with sdbus.
         *     Allowed:
         *         - Destructor.
         */
        TemperatureSensor() = delete;
        TemperatureSensor(const TemperatureSensor&) = delete;
        TemperatureSensor& operator=(const TemperatureSensor&) = delete;
        TemperatureSensor(TemperatureSensor&&) = delete;
        TemperatureSensor& operator=(TemperatureSensor&&) = delete;
        virtual ~TemperatureSensor() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        TemperatureSensor(bus::bus& bus, const char* path);

        enum class State
        {
            Success,
            Error,
        };

        using PropertiesVariant = sdbusplus::utility::dedup_variant<
                State,
                int64_t,
                std::string>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        TemperatureSensor(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);


        /** @brief Implementation for Read
         *  Reads current data off sensor
         *
         *  @param[in] x - The first integer to multiply.
         *  @param[in] y - The second integer to multiply.
         *
         *  @return z[int64_t] - The result of (x*y).
         */
        virtual int64_t read(
            int64_t x,
            int64_t y) = 0;


        /** @brief Send signal 'Cleared'
         *
         *  Signal indicating the LastReset property has been set to zero by the 'Clear' method.
         *
         *  @param[in] unnamed - Value of LastReset prior to Clear.
         */
        void cleared(
            int64_t unnamed);

        /** Get value of LastResult */
        virtual int64_t lastResult() const;
        /** Set value of LastResult with option to skip sending signal */
        virtual int64_t lastResult(int64_t value,
               bool skipSignal);
        /** Set value of LastResult */
        virtual int64_t lastResult(int64_t value);
        /** Get value of Status */
        virtual State status() const;
        /** Set value of Status with option to skip sending signal */
        virtual State status(State value,
               bool skipSignal);
        /** Set value of Status */
        virtual State status(State value);
        /** Get value of Owner */
        virtual std::string owner() const;
        /** Set value of Owner with option to skip sending signal */
        virtual std::string owner(std::string value,
               bool skipSignal);
        /** Set value of Owner */
        virtual std::string owner(std::string value);

        /** @brief Sets a property by name.
         *  @param[in] _name - A string representation of the property name.
         *  @param[in] val - A variant containing the value to set.
         */
        void setPropertyByName(const std::string& _name,
                               const PropertiesVariant& val,
                               bool skipSignal = false);

        /** @brief Gets a property by name.
         *  @param[in] _name - A string representation of the property name.
         *  @return - A variant containing the value of the property.
         */
        PropertiesVariant getPropertyByName(const std::string& _name);

        /** @brief Convert a string to an appropriate enum value.
         *  @param[in] s - The string to convert in the form of
         *                 "org.joomby.TemperatureSensor.<value name>"
         *  @return - The enum value.
         */
        static State convertStateFromString(const std::string& s);

        /** @brief Convert an enum value to a string.
         *  @param[in] e - The enum to convert to a string.
         *  @return - The string conversion in the form of
         *            "org.joomby.TemperatureSensor.<value name>"
         */
        static std::string convertStateToString(State e);

        /** @brief Emit interface added */
        void emit_added()
        {
            _org_joomby_TemperatureSensor_interface.emit_added();
        }

        /** @brief Emit interface removed */
        void emit_removed()
        {
            _org_joomby_TemperatureSensor_interface.emit_removed();
        }

        static constexpr auto interface = "org.joomby.TemperatureSensor";

    private:

        /** @brief sd-bus callback for Read
         */
        static int _callback_Read(
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'LastResult' */
        static int _callback_get_LastResult(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'LastResult' */
        static int _callback_set_LastResult(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Status' */
        static int _callback_get_Status(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Owner' */
        static int _callback_get_Owner(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Owner' */
        static int _callback_set_Owner(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _org_joomby_TemperatureSensor_interface;
        sdbusplus::SdBusInterface *_intf;

        int64_t _lastResult = 0;
        State _status = State::Success;
        std::string _owner{};

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type TemperatureSensor::State.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
inline std::string convertForMessage(TemperatureSensor::State e)
{
    return TemperatureSensor::convertStateToString(e);
}

} // namespace server
} // namespace joomby
} // namespace org

namespace message
{
namespace details
{
template <>
inline auto convert_from_string<org::joomby::server::TemperatureSensor::State>(
        const std::string& value)
{
    return org::joomby::server::TemperatureSensor::convertStateFromString(value);
}

template <>
inline std::string convert_to_string<org::joomby::server::TemperatureSensor::State>(
        org::joomby::server::TemperatureSensor::State value)
{
    return org::joomby::server::TemperatureSensor::convertStateToString(value);
}
} // namespace details
} // namespace message
} // namespace sdbusplus

