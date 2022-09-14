#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> a;
	int i;
	for(i=0;i<10;i++)
	{
		a.push_back(i);
		cout << "size=" << a.size() << " capacity=" << a.capacity() << endl;
	}

	a.resize(4);
	cout << "resize : size=" << a.size() << " capacity=" << a.capacity() << endl;

	return 0;
}

/*
gdb 无法获取a.capacity()，提示内联函数 initline

测试结果:
size=1 capacity=1
size=2 capacity=2
size=3 capacity=4
size=4 capacity=4
size=5 capacity=8
size=6 capacity=8
size=7 capacity=8
size=8 capacity=8
size=9 capacity=16
size=10 capacity=1
resize : size=4 capacity=16

*/