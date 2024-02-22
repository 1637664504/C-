/*
蓝牙扫描实例
依赖第三方库bluez: apt-get install libbluetooth-dev
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

int main(int argc, char **argv)
{
    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    char addr[19] = {0};
    char name[248] = {0};

    dev_id = hci_get_route(NULL);
    sock = hci_open_dev(dev_id);
    if (dev_id < 0 || sock < 0)
    {
        perror("opening socket");
        exit(1);
    }

    len = 8;
    max_rsp = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info *)malloc(max_rsp * sizeof(inquiry_info));

    num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    if (num_rsp < 0)
        perror("hci_inquiry");

    for (i = 0; i < num_rsp; i++)
    {
        ba2str(&(ii + i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii + i)->bdaddr, sizeof(name),
                                 name, 0) < 0)
            strcpy(name, "[unknown]");

        // 9C:2E:A1:48:47:8A 小米手机
        printf("%s %s\n", addr, name);
    }

    free(ii);
    close(sock);
    return 0;
}

/* 运行结果
70:D8:23:EA:ED:DA carter
70:D8:23:E5:53:11 wp
68:13:24:58:68:21 安的Mate 40 Pro
C4:E1:A1:A0:A8:62 OPPO K3
AC:C4:BD:2E:2D:A0 APP
9C:2E:A1:48:47:8A 小米手机
DA:84:46:64:2C:6B [unknown]
48:F3:F3:5A:AA:DD 添添旋转智能屏
4C:EB:BD:19:DE:82 [unknown]
A8:98:92:EF:88:D4 OPPO Reno7 5G
 */