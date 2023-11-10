#include <iostream>
#include <chrono>
#include <unistd.h>

double get_now_time(void)
{
    // 获取当前时间点
    auto now = std::chrono::system_clock::now();
    // 将时间点转换为时间戳
    auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    return timestamp / 1000;
}

int main() {
    while (1) {
        double now_time = get_now_time();
        printf("%f seconds\n", now_time);

        sleep(1);
    }

    return 0;
}
