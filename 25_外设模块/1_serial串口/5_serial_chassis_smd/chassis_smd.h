#include <stdint.h>
// 命令模式
enum Cmd{
    CMD_RTK_INS        = 0x80,  // RTK+INS输出数据
    CMD_SLAM_LOCAL     = 0xC0,  // SLAM输出位置和状态数据
    CMD_SLAM_OBSTACLE  = 0xC1,  // SLAM输出障碍物信息数据
    CMD_ASSIC          = 0x3F,  // ASSIC
};

// 设备地址
enum Address_id{
    Host_ID = 0x00,
    NAV_ID = 0x05,
    Laser_Slam_ID = 0x18,
    Vision_Slam_ID = 0x19,
};

// slam状态
enum Slam_state{
    Slam_Local_Lost     = 0,
    Slam_Reserve        = 1,
    Slam_Local_Available= 2,
    Slam_Map_State      = 3,
};

enum Map_state{
    Start_Map       = 0,
    Building_Map    = 1,
    Finish_Map      = 2,
    Map_Available   = 3,
    Map_Unavailable = 4,
    No_Map          = 5,
};

struct serial_frame{
    // 数据帧协议格式
    char head0 = 'R';
    char head1 = 'E';
    uint16_t length = 0;
    uint8_t cmd = CMD_SLAM_LOCAL;
    uint8_t dst_id = Vision_Slam_ID;
    uint8_t src_id = NAV_ID;
    uint8_t *data;
    // uint16_t crc;
};

struct Slam_packet{
    float x;
    float y;
    float z;
    float pitch;
    float roll;
    float yaw;
    float used_w;
    uint8_t slam_state;
    uint8_t map_state;
    float v;
    float w;
    float used_x;
};