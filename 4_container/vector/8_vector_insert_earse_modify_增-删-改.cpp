#include <iostream>
#include <vector>
using namespace std;

void show_vector_int(vector<int> a)
{
	vector<int>::iterator it;
	for(it=a.begin(); it!=a.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main(void)
{
	vector<int> a;
	for(int i=0;i<5;i++)
	{
		a.push_back(i);
	}
	show_vector_int(a);
	
	//1、增
	vector<int>::iterator it;
	it = a.begin() +2;
	//it.insert(a,8);
	a.insert(it,8);
	show_vector_int(a);


	//2、删
	it = a.begin() +1;
	a.erase(it);
	show_vector_int(a);

	//3、改
	it = a.begin();
	*it = 9;
	show_vector_int(a);

	//4、尾删 头删
	a.pop_back();
	a.erase(a.begin());
	show_vector_int(a);


    return 0;
}
/*
测试结果:

0 1 2 3 4
0 1 8 2 3 4
0 8 2 3 4
9 8 2 3 4
8 2 3

*/