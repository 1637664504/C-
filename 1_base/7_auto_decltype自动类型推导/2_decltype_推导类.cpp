#include<string> 
#include<iostream>
using namespace std;

class A{
private:

public:
    int val;
    A(int val_){
        val = val_;
    }
};

int main(void)
{
    // 推导 class A 类型
    A a1 = A(2);
    decltype(a1) a2 = 5;
    cout << a2.val << endl;

    return 0;
}