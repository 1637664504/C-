#include <dbus/dbus.h>
// #include <dbus/dbus-glib.h>
// #include <glib/gmain.h>
#include <stdio.h>

#define DBUS_SERVICE_NAME "com.example.HelloWorld"
#define DBUS_OBJECT_PATH "/com/example/HelloWorld"

static DBusMethodInfo HelloWorld_methods[] = {
    {"HelloWorld", DBUS_METHOD_NO_ARGS, DBUS_METHOD_IN_ORDER},
    {"EchoString", "<s", DBUS_METHOD_IN_ORDER},
    {NULL}};

static DBusObjectInfo HelloWorld_object_info = {
    DBUS_METHOD_INFO_C(HelloWorld_methods)};

int main(int argc, char *argv[])
{
    DBusConnection *connection;
    DBusError *error;
    int r;

    // 连接到DBus
    r = dbus_open(DBUS_BUS_SYSTEM, &connection, &error);
    if (r != DBUS_SUCCESS)
    {
        fprintf(stderr, "dbus_open: %s\n", error->message);
        return 1;
    }
    dbus_error_free(error);

    // 注册DBus服务
    r = dbus_register_service(connection, DBUS_SERVICE_NAME, &HelloWorld_object_info);
    if (r != DBUS_SUCCESS)
    {
        fprintf(stderr, "dbus_register_service: %s\n", error->message);
        return 1;
    }

    // 开始监听并处理DBus消息
    g_main_loop_new(NULL, TRUE);
    g_main_loop_run();

    // 销毁DBus连接
    dbus_connection_unref(connection);

    return 0;
}
