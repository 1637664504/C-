#include <iostream>
#include <functional>

void fun_1(int x, int y, int z) {
    std::cout << "print: x = " << x << ", y = " << y << ", z = " << z << std::endl;
}

void fun_2(int& a, int& b) {
    ++a;
    ++b;
    std::cout << "print: a = " << a << ", b = " << b << std::endl;
}

int main(int argc, char* argv[]) {
    //f1的类型为 function<void(int, int, int)>
    //表示绑定函数 fun 的第一，二，三个参数值为： 1 2 3
    auto f1 = std::bind(fun_1, 1, 2, 3);
    f1(); 													//print: x=1,y=2,z=3

    //表示绑定函数 fun_1的第一，二个参数分别由调用 f2 的第一，二个参数指定, 而 fun_1 的第三个参数为 3
    auto f2 = std::bind(fun_1, std::placeholders::_1, std::placeholders::_2, 3);
    f2(1, 2);												//print: x=1,y=2,z=3

    //表示绑定函数 fun_1 的第一，二个参数分别由调用 f3 的第二，一个参数指定, 而 fun_1 的第三个参数为 3
    auto f3 = std::bind(fun_1, std::placeholders::_2, std::placeholders::_1, 3);
    f3(1, 2);												//print: x=2,y=1,z=3

    return 0;
}

/*
print: x = 1, y = 2, z = 3
print: x = 1, y = 2, z = 3
print: x = 2, y = 1, z = 3

 */