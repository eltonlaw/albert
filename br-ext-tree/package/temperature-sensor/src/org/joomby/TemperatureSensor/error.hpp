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

struct FileNotFound final : public sdbusplus::exception_t
{
    static constexpr auto errName = "org.joomby.TemperatureSensor.Error.FileNotFound";
    static constexpr auto errDesc =
            "No such file";
    static constexpr auto errWhat =
            "org.joomby.TemperatureSensor.Error.FileNotFound: No such file";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace TemperatureSensor
} // namespace joomby
} // namespace org
} // namespace sdbusplus

