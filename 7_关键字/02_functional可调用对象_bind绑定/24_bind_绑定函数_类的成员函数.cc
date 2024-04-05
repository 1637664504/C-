#include <iostream>
#include <functional>

class A {
public:
    void fun_3(int k, int m) {
        std::cout << "print: k = " << k << ", m = " << m << std::endl;
    }
};

int main(int argc, char* argv[]) {
    A a;
    //f5的类型为 function<void(int, int)>
    auto f5 = std::bind(&A::fun_3, &a, std::placeholders::_1, std::placeholders::_2); //使用auto关键字
    f5(10, 20);												//调用a.fun_3(10,20),print: k=10,m=20

    std::function<void(int, int)> fc = std::bind(&A::fun_3, a, std::placeholders::_1, std::placeholders::_2);
    fc(11, 22);   											//调用a.fun_3(11,22) print: k=11,m=22

    return 0;
}
/*
print: k = 10, m = 20
print: k = 11, m = 22

 */