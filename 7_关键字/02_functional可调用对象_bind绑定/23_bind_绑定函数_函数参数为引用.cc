#include <iostream>
#include <functional>


void fun_2(int& a, int& b) {
    ++a;
    ++b;
    std::cout << "print: a = " << a << ", b = " << b << std::endl;
}

int main(int argc, char* argv[]) {

    int m = 2;
    int n = 3;

    //表示绑定fun_2的第一个参数调用f4的第一个参数（_1）指定, fun_2的第二个参数为n的值
    auto f4 = std::bind(fun_2, std::placeholders::_1, n);
    f4(m); 													//print: a=3,b=4
    std::cout << "m = " << m << std::endl;					//m=3  说明：bind对于不事先绑定的参数，通过std::placeholders传递的参数是通过引用传递的,如m
    std::cout << "n = " << n << std::endl;					//n=3  说明：bind对于预先绑定的函数参数是通过值传递的，如n

    return 0;
}
