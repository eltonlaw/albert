#pragma once

#include <sdbusplus/exception.hpp>

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

struct DivisionByZero final : public sdbusplus::exception_t
{
    static constexpr auto errName = "org.joomby.TemperatureSensor.Error.DivisionByZero";
    static constexpr auto errDesc =
            "An attempt to divide by zero was attempted.";
    static constexpr auto errWhat =
            "org.joomby.TemperatureSensor.Error.DivisionByZero: An attempt to divide by zero was attempted.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PermissionDenied final : public sdbusplus::exception_t
{
    static constexpr auto errName = "org.joomby.TemperatureSensor.Error.PermissionDenied";
    static constexpr auto errDesc =
            "The user does not have enough privileges to perform the operation.";
    static constexpr auto errWhat =
            "org.joomby.TemperatureSensor.Error.PermissionDenied: The user does not have enough privileges to perform the operation.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace TemperatureSensor
} // namespace joomby
} // namespace org
} // namespace sdbusplus

