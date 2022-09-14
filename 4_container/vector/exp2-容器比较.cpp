/*
Exercise 9.21:
假设 c1 和 c2 都是容器，下列用法给 c1 和 c2 的元素
类型带来什么约束？
if (c1 < c2)
*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;



int main(void)
{
	list<int> a={1,2,3,4,5};
	list<int> b={1,2,3,4};
	list<int> c={3,1};
	vector<int> d={1,2,3,4,5};

	int ret = 0;

	if(a>b)
		ret = 0;
	else
		ret =1;
	
	if(c>a)
		ret = 2;
	
	//if(d>a)
	//	ret = 3;


	return 0;
}

/*
测试结论:
容器比较条件
	1.容器类型要相同
	2.容器比较是按顺序比较 成员的大小
*/