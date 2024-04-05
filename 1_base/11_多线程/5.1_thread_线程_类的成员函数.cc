#include <iostream>
#include <thread>
#include <chrono>

class MyClass
{
public:
    void print_numbers() {
        for (int i = 1; i <= 10; ++i) {
            std::cout << "线程 " << std::this_thread::get_id() << " 打印数字: " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

int main()
{
    std::cout << "主线程 ID: " << std::this_thread::get_id() << std::endl;

    MyClass obj;

    // 创建一个新线程，将成员函数作为执行函数
    std::thread t(&MyClass::print_numbers, &obj);

    // 等待新线程执行完成
    t.join();

    std::cout << "主线程结束" << std::endl;
    return 0;
}
