#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;

void thread_value_args(int value)
{
    value += 1;
    printf("value %d\n", value);
}

void thread_ref_function(int& value)
{
    value += 2;
    printf("p ref thread %d\n", value);
}

void thread_point_function(int* value)
{
    *value += 3;
    printf("p point thread %d\n", *value);
}

int main(void)
{
    int value = 42;
    std::thread thread0(thread_value_args, value);
    std::thread thread1(thread_ref_function, ref(value));
    std::thread thread2(thread_point_function, &value);

    // 等待线程完成
    thread0.join();
    thread1.join();
    thread2.join();

    // 输出修改后的变量值
    std::cout << "Modified variable value: " << value << std::endl;

    return 0;
}

/*测试结果:

p point thread 45
p ref thread 47
Modified variable value: 47

 */