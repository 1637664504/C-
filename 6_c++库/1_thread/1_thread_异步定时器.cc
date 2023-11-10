#include <iostream>
#include <mutex>
#include <thread>
#include <functional>
#include <condition_variable>
#include <atomic>
#include <unistd.h>

using namespace std;
class AsyncTimer {

public:
    AsyncTimer() {
        expired = true;
        tryToExpire = false;
    }

    void start(int interval, std::function<void()> task)
    {

        if (expired == false)
            return;

        expired = false;
        //将lambda函数传递给线程，做线程函数
        std::thread([this, interval, task]() {
            //小缺点：在task执行的过程中设置tryToExpire为true的话，需要等到本次task执行完毕后才能被while条件判断检测到。
            while (!tryToExpire)
            {
                // sleep every interval and do the task again and again until times up
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                task(); //call this function every interval milliseconds.
            }

            std::lock_guard<std::mutex> locker(mut);
            expired = true;
            cv.notify_one();

            }).detach();
    }

    void stop()//该接口负责修改tryToExipired的值。
    {
        // do not stop again
        if (expired)
            return;

        if (tryToExpire)
            return;

        tryToExpire = true;
        std::unique_lock<std::mutex> locker(mut);
        cv.wait(locker, [this] {return expired == true; });//不给lambda函数串this，不能使用成员变量expired!
        if (expired == true)
            tryToExpire = false;

    }

private:
    condition_variable cv;
    mutex mut;//与cv配合

    atomic<bool> expired; //timer stop status
    atomic<bool> tryToExpire;//timer is in stop process.

};

double get_now_time(void)
{
    // 获取当前时间点
    auto now = std::chrono::system_clock::now();
    // 将时间点转换为时间戳
    auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    return timestamp / 1000;
}

void printNum()
{
    static int a = 0;
    a++;
    double time = get_now_time();
    printf("time: %f a=%d\n", time,a);
}

int main()
{
    AsyncTimer obj;
    obj.start(1000, printNum);

    //定时线程执行了detatch，这里需要等待才能看到起输出数字到屏幕上
    int idx = 0;
    while (1) {
        cout << "idx=" << idx++ << endl;
        sleep(1);
    }
    obj.stop();

    return 0;
}
