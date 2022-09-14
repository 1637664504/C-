#include <iostream>
using namespace std;

class base
{
public:
	virtual void test() = 0;
};

class derived: public base{
public:
	void test()
	{
		cout << "In derived" << endl;
	}
};

int main(void)
{
	//base a;		//编译错误，class base 有虚函数
	//base *b = new base();	//编译错误，class base 有虚函数

	base *c = new derived();	// ok
	c->test();

	derived *d = new derived();
	d->test();

	return 0;
}