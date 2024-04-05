#include <iostream>
#include <functional>

void fun_1(int x, int y, int z)
{
    std::cout << "print: x = " << x << ", y = " << y << ", z = " << z << std::endl;
}

int main(int argc, char* argv[])
{
    //f1的类型为 function<void(int, int, int)>
    //表示绑定函数 fun 的第一，二，三个参数值为： 1 2 3
    auto f1 = std::bind(fun_1, 1, 2, 3);
    f1(); 													//print: x=1,y=2,z=3

    return 0;
}
