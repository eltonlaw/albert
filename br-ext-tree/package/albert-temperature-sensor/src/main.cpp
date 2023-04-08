#include <dbus/dbus.h>
#include <iostream>

DBusHandlerResult handle_method_call(DBusConnection *conn, DBusMessage *msg, void *user_data) {
    DBusMessage *reply = dbus_message_new_method_return(msg);
    if (reply == NULL) {
        printf("Error creating reply message object.\n");
        exit(1);
    }
    dbus_message_set_destination(reply, dbus_message_get_sender(msg));

    // FIXME: read from sensor
    const double return_value = 21.8;
    dbus_message_append_args(reply, DBUS_TYPE_DOUBLE, &return_value, DBUS_TYPE_INVALID);

    dbus_connection_send(conn, reply, NULL);
    dbus_connection_flush(conn);

    // cleanup the allocated reply obj
    dbus_message_unref(reply);

    return DBUS_HANDLER_RESULT_HANDLED;
}

int main (int argc, char * argv[]) {
    DBusError err;
    dbus_error_init(&err);
    DBusConnection *connection = dbus_bus_get(DBUS_BUS_SYSTEM, &err);

    const char *object_path = "/io/github/eltonlaw/albert/TemperatureSensor";
    const char *interface_name = "io.github.eltonlaw.albert.TemperatureSensor";
    const char *service_name = "io.github.eltonlaw.albert.TemperatureSensor";

    dbus_bool_t ret = dbus_bus_request_name(connection, service_name, 0, &err);
    if (ret != TRUE) {
        printf("Error requesting service name: %s \n", err.message);
        exit(1);
    }

    DBusObjectPathVTable vtable = {
        .unregister_function = NULL,
        .message_function = handle_method_call,
    };
    dbus_connection_register_object_path(connection, object_path, &vtable, NULL);

    printf("Service listening at object path %s...\n", object_path);
    while (true) {
        dbus_connection_read_write_dispatch(connection, -1);
    }
}
