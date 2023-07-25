#include <iostream>
#include <stdint.h>
using namespace std;
 
class A {
private:
    int a;
public:
    A(int num) :a(num)
    {
        
    }

    int get_num()
    {
        return a;
    }
};

class B {
private:
    A &a1;
    int b;
public:
    B(int num,A &a):a1(a),b(num)
    {
    }

    /* 类-引用成员变量 初始化 必须在成员建造*/
    // B(int num,A &a):b(num)
    // {
    //     int c = num;
    //     a1 = a;
    // }
    
    void show_num()
    {
        cout << b << a1.get_num() << endl;
    }
};


int main()
{
    A a(10);
    B b(5, a);

    return 0;
}
 
/*

*/
