#include <iostream>
#include <stdio.h>
using namespace std;

class example{
private:
	int *p;

public:
	example(int num)
	{
		p = new int;
		*p = num;
	}
	example(const example &obj)
	{
		p = new int;
		*p = *obj.p + 1;
	}
	~example()
	{
		delete(p);
	}
	void show()
	{
		printf("p address=%p,val=%d\n",p,*p);
	}
};

int main(void)
{
	example C(16);
	example D = C;
	C.show();
	D.show();

	return 0;
}

/*
p address=0x55f0c6304eb0,val=16
p address=0x55f0c6304ed0,val=17

结论:
	1.指向两个不同的地址
	2.不像示例6 运行错误:free double error

*/