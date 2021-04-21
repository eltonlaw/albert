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



        /** @brief Implementation for Read
         *  Reads current data off sensor
         *
         *  @return t[int64_t] - The result of (x*y).
         */
        virtual int64_t read(
            ) = 0;




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


        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _org_joomby_TemperatureSensor_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace joomby
} // namespace org

namespace message
{
namespace details
{
} // namespace details
} // namespace message
} // namespace sdbusplus

