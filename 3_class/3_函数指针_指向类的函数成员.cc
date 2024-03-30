#include <iostream>
#include <string>
using namespace std;

// 假设有如下类及其成员函数声明
class MyClass {
public:
    void myMethod(int value)
    {
        cout << "myMethod "<< value << endl;
    }
};

// 声明一个指向 MyClass 类中接受一个 int 参数并返回 void 类型的成员函数的指针
// typedef void (MyClass::* MemberFuncPtr)(int);

// C++11之后可以使用更简洁的auto或者using声明
using MemberFuncPtr = void (MyClass::*)(int);

int main()
{
    // 获取成员函数的地址
    MemberFuncPtr mfptr = &MyClass::myMethod;

    // 调用成员函数
    MyClass obj;
    (obj.*mfptr)(10); // 通过对象实例调用

    // 或者通过类对象指针调用
    MyClass* pObj = new MyClass();
    (pObj->*mfptr)(11); // 通过对象指针调用

    return 0;
}

/*Running:
myMethod 10
myMethod 11

 */