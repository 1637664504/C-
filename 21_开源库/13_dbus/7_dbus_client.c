#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <ctype.h>
#include <dbus/dbus.h>
#include "6_bus_service_common.h"

DBusError dbus_error;
void print_dbus_error(char *str)
{
    fprintf(stderr, "%s: %s\n", str, dbus_error.message);
    dbus_error_free(&dbus_error);
}

int main(int argc, char **argv)
{
    DBusConnection *conn;
    char input[64];

    dbus_error_init(&dbus_error);
    // 1.连接dbus服务,获取connection
    assert((conn = dbus_bus_get(DBUS_BUS_SYSTEM, &dbus_error)));
    if (dbus_error_is_set(&dbus_error))
    {
        print_dbus_error("dbus_bus_get");
    }

    // 2.请求服务 bus_name,object,interface,method
    DBusMessage *req;
    const char *objects = Object_path_name_yes;
    // const char *objects = Object_path_name_no;
    assert((req = dbus_message_new_method_call(Bus_name, objects, Interface_name, Method_name)));

    // 3.填充请求服务参数
    DBusMessageIter iter;
    dbus_message_iter_init_append(req, &iter);
    snprintf(input, sizeof(input), "test");

    char *ptr = input;
    assert(dbus_message_iter_append_basic(&iter, DBUS_TYPE_STRING, &ptr));

    // 4.发送请求
    DBusPendingCall *pending;
    assert(dbus_connection_send_with_reply(conn, req, &pending, -1));
    assert(pending);
    dbus_connection_flush(conn);
    dbus_message_unref(req);
    dbus_pending_call_block(pending);

    // 5.获取响应
    DBusMessage *resp;
    assert((resp = dbus_pending_call_steal_reply(pending)));
    dbus_pending_call_unref(pending);
    char *s;
    // 6.获取响应参数
    if (dbus_message_get_args(resp, &dbus_error, DBUS_TYPE_STRING, &s, DBUS_TYPE_INVALID))
    {
        printf("Response: %s\n", s);
    }
    else
    {
        fprintf(stderr, "can't get arguments. Error: %s\n", dbus_error.message);
        exit(1);
    }
    dbus_message_unref(resp);
    // dbus_connection_close(conn);

    return 0;
}