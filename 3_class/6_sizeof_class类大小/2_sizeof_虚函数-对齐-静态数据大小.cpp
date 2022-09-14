/**

 */
#include<iostream>
using namespace std;
class A
{
    public:
		
		//char b;					// 8字节，对齐
        //virtual void fun() {};	// 虚函数指针64位 8字节
		//int a;					// 4字节
		static int b;				// 0字节 静态数据成员被编译器放在程序的一个global data members中，它是类的一个数据成员，但不影响类的大小
};

int main()
{
    cout<<sizeof(A)<<endl;
    return 0;
}
/*
char b;					// 8字节，对齐
virtual void fun() {};	// 虚函数指针64位 8字节
int a;					// 4字节
static int b;			// 0字节 静态数据成员被编译器放在程序的一个global data members中，它是类的一个数据成员，但不影响类的大小

*/