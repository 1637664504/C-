#include <stdio.h>
#include <stdlib.h>
#include <dbus/dbus.h>

static DBusConnection *connection = NULL;

int main()
{
    DBusError error;
    dbus_error_init(&error);

    // 连接到会话总线
    connection = dbus_bus_get(DBUS_BUS_SESSION, &error);
    if (dbus_error_is_set(&error))
    {
        fprintf(stderr, "连接到dbus失败: %s\n", error.message);
        dbus_error_free(&error);
        return 1;
    }

    // 准备要发送的消息
    DBusMessage *msg = dbus_message_new_method_call(
        "org.example.TestService",   // service name
        "/org/example/TestObject",   // object path
        "org.example.TestInterface", // interface name
        "TestMethod"                 // method name
    );

    if (NULL == msg)
    {
        fprintf(stderr, "创建dbus消息失败.\n");
        return 1;
    }

    // 发送消息并获取回复
    DBusMessage *reply = dbus_connection_send_with_reply_and_block(
        connection,
        msg,
        -1, // 等待无限长时间直到收到回复
        &error);

    dbus_message_unref(msg);

    if (dbus_error_is_set(&error))
    {
        fprintf(stderr, "发送dbus消息失败: %s\n", error.message);
        dbus_error_free(&error);
        return 1;
    }

    // 处理回复消息
    if (NULL != reply)
    {
        // 在实际应用中，这里应该解析并处理回复中的数据
        dbus_message_unref(reply);
    }

    // 断开dbus连接
    dbus_connection_close(connection);
    dbus_connection_unref(connection);

    return 0;
}