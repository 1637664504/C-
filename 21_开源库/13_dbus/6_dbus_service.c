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
    int ret;
    DBusConnection *conn;
    dbus_error_init(&dbus_error);

    // 1.与Dbus-daemon建立连接connection
    conn = dbus_bus_get(DBUS_BUS_SYSTEM, &dbus_error);
    if (conn == NULL || dbus_error_is_set(&dbus_error))
    {
        print_dbus_error("dbus connection error");
        exit(1);
    }

    // 2.connection注册bus_name
    ret = dbus_bus_request_name(conn, Bus_name, DBUS_NAME_FLAG_DO_NOT_QUEUE, &dbus_error);
    if (dbus_error_is_set(&dbus_error))
    {
        print_dbus_error("dbus_bus_request_name error");
    }
    if (ret != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER)
    {
        fprintf(stderr, "not primary owner,ret=%d\n", ret);
    }

    while (1)
    {
        // 3.读取connection 连接请求
        if (!dbus_connection_read_write_dispatch(conn, -1))
        {
            fprintf(stderr, "connection read write error\n");
            exit(2);
        }

        // 4.从connection 上读取消息
        DBusMessage *msg;
        if ((msg = dbus_connection_pop_message(conn)) == NULL)
        {
            fprintf(stderr, "don't get message\n");
            continue;
        }

        // 5.对比消息msg 中的, 方法接口Interface 与 方法名Method
        if (dbus_message_is_method_call(msg, Interface_name, Method_name))
        {
            char *s;
            // 6.获取参数
            if (dbus_message_get_args(msg, &dbus_error, DBUS_TYPE_STRING, &s, DBUS_TYPE_INVALID))
            {
                printf("message recv %s\n", s);

                // 8.回复
                char answer[256];
                DBusMessage *reply;
                assert((reply = dbus_message_new_method_return(msg)));
                DBusMessageIter iter;
                dbus_message_iter_init_append(reply, &iter);

                // 7.解析参数 object_path
                if (dbus_message_has_path(msg, Object_path_name_yes))
                {
                    sprintf(answer, "yes %s", s);
                }
                else if (dbus_message_has_path(msg, Object_path_name_no))
                {
                    sprintf(answer, "no %s", s);
                }

                char *ptr = answer;
                assert(dbus_message_iter_append_basic(&iter, DBUS_TYPE_STRING, &ptr));
                // 9.发送回复
                assert(dbus_connection_send(conn, reply, NULL));
                dbus_connection_flush(conn);
                dbus_message_unref(reply);
            }
            else
            {
                print_dbus_error("Error getting message");
            }
        }
    }

    return 0;
}