
安装dbus库: `sudo apt install libdbus-1-dev`

编译: `scons`

## 实例1:

https://blog.csdn.net/ZengYinning/article/details/128188252

- 1_dbus_server.c

    - 运行错误: dbus_bus_request_name: Connection ":1.113" is not allowed to own the service "com.flork.dbus" due to security policies in the configuration file
    - 解决方法1: sudo 运行
    - 解决方法2: 将com.flork.dbus.conf 中的 `<policy user="root">` **root** 改为自己的用户名


- 2_dbus_client.c


## 实例2

https://www.matthew.ath.cx/articles/dbus

- 在线代码: https://www.matthew.ath.cx/projects.git/dbus-example.c
- [5_dbus-example.c](21_开源库/13_dbus/5_dbus-example.c)

命令:
- To receive signals: `5_dbus-example receive`
- To send a signal: `5_dbus-example send param`
- To listen for method calls: `5_dbus-example listen`
- To call the method: `5_dbus-example query param`


## 实例3

- https://www.cnblogs.com/cxt-janson/p/11428362.html
- [6_dbus_service.c](21_开源库/13_dbus/6_dbus_service.c)
- [7_dbus_client.c](21_开源库/13_dbus/7_dbus_client.c)

运行方法:
