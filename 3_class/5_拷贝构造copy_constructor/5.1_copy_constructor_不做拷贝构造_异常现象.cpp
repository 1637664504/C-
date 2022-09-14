#include <iostream>
#include <stdio.h>
using namespace std;

class demo{
	private:
	int a;

	public:
	demo(int num)
	{
		a = num;
	}

	void show()
	{
		cout << a << endl;
	}

};

class example{
private:
	char *p;

public:
	example(int len)
	{
		p = (char *)malloc(len);
		if(p == NULL)
		{
			cerr<<"class example failed"<<endl;
		}
	}
	~example()
	{
		if(p)
			free(p);
	}
	void show_pointer()
	{
		printf("p address=%p\n",p);
	}
};

int main(void)
{
	demo A(100);
	demo B = A;
	B.show();

	//A,B 指向相同的内存地址
	example C(16);
	example D = C;
	D.show_pointer();

	return 0;
}

/*
运行结果:
100
p address=0x565306c1f2c0
free(): double free detected in tcache 2
zsh: IOT instruction  ./a.out

问题原因:
C,D执行析构函数时，
	1. C free(p)
	2. D free(p), 释放第二次，提示错误

*/