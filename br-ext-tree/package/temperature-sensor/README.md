# Temperature Sensor

```
cd src
sdbus++ interface server-cpp org.joomby.TemperatureSensor    > server.cpp
sdbus++ interface server-header org.joomby.TemperatureSensor > org/joomby/TemperatureSensor/server.hpp
sdbus++ error exception-cpp org.joomby.TemperatureSensor     > error.cpp
sdbus++ error exception-header org.joomby.TemperatureSensor  > org/joomby/TemperatureSensor/error.hpp
```

## Dev

### Starting the service

cd build && cmake .. && make && ./src/temperature-sensor

### Working with DBus

Check whether the service is in the list of peers connected to the bus

    busctl --user | grep joomby

Inspect service

    busctl --user introspect org.joomby.TemperatureSensor /org/joomby/TemperatureSensor

To call READ method

    busctl --user call org.joomby.TemperatureSensor /org/joomby/TemperatureSensor org.joomby.TemperatureSensor Read

Check that the dbus daemon is running

    ps aux | grep dbus

Assuming you have a /etc/dbus-1/system.d/system-local.conf to set the policy to allow eavesdropping

    <!DOCTYPE busconfig PUBLIC
    "-//freedesktop//DTD D-Bus Bus Configuration 1.0//EN"
    "http://www.freedesktop.org/standards/dbus/1.0/busconfig.dtd">
    <busconfig>
        <policy user="root">
            <allow eavesdrop="true"/>
            <allow eavesdrop="true" send_destination="*"/>
        </policy>
    </busconfig>

Monitoring the messages that go through the user/session bus

    dbus-monitor --session
    # For filtering by type and sender
    dbus-monitor "type=error,sender='org.freedesktop.DBus'" --session
