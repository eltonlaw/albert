#include "org/joomby/TemperatureSensor/error.hpp"

namespace sdbusplus
{
namespace org
{
namespace joomby
{
namespace TemperatureSensor
{
namespace Error
{
const char* FileNotFound::name() const noexcept
{
    return errName;
}
const char* FileNotFound::description() const noexcept
{
    return errDesc;
}
const char* FileNotFound::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace TemperatureSensor
} // namespace joomby
} // namespace org
} // namespace sdbusplus

