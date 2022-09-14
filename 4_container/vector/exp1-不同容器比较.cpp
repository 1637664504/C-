/*
Exercise 9.20:
编写程序判断一个 vector<int> 容器所包含的元素是否
与一个 list<int> 容器的完全相同。
*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int compare_container(vector<int> &a, list<int> &b)
{
	int ret = 0;
	vector<int>::iterator ia;
	list<int>::iterator ib;
	for(ia=a.begin(),ib=b.begin(); ia!=a.end() || ib!=b.end(); ia++,ib++)
	{
		if(*ia != *ib)
		{
			ret = -1;
			break;
		}
	}

	return ret;
}

int main(void)
{
	vector<int> a={1,2,3,4,5};
	list<int> b={1,2,3,4,5};
	list<int> c={1,2,3,4};
	list<int> d={1,2,3,4,7};

	compare_container(a,b);
	compare_container(a,c);
	compare_container(a,d);

	return 0;
}

/*
注意:
list.end() 是 5
vector.end() 是 0，指向空
*/