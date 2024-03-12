#include <iostream>
using namespace std;

class base
{
	int a,b;
	public:
	void test()
	{
		cout <<"base test" << endl;
	}
};

class inheriter:public base
{
	public:
	void test()
	{
		cout << "inheriter test" << endl;
	}
};

int main(void)
{
	base *p1=new base;
	base *p2=new inheriter;

	p1->test();
	p2->test();

	return 0;
}
/*
测试内容: 虚函数
原理: 在c++中，一个基类的指针或者引用可以指向或者引用派生类的对象。同时，派生类可以重写基类中的成员函数。

结果:
base test
base test 

结论
1.从c语言内存角度看，*p2 = (class base *)inheriter
2.从gdb 调试结果看, *p2的内存模型class base {a,b}

*/