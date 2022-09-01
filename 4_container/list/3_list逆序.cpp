#include <iostream>
#include <list>
#include <vector>
using namespace std;

//测试1:逆序遍历
void test1(list<int> a)
{
	//list<int>::reverse_iterator rit = rbegin(); rit != rend() 倒序遍历
	//list<int>::iterator rit;		#iterator编译错误
	list<int>::reverse_iterator rit;
	cout << "逆序遍历:" <<endl;
	for(rit=a.rbegin(); rit!=a.rend(); rit++)
	{
		cout << " "<< *rit;
	}
	cout<<endl;
}
/*
逆序遍历:
5 4 3 2 1 0
*/

//测试2:list反序
void test2(list<int> a)
{
	a.reverse();
	list<int>::iterator it;
	cout << "倒序的结果:" <<endl;
	for(it=a.begin(); it!=a.end(); it++)
	{
		cout << " "<< *it;
	}
	cout<<endl;
}
/*
倒序的结果:
5 4 3 2 1 0
*/

int main(void)
{
    list<int> a;
    int i;
    for(i=0;i<=5;i++)
    {
        a.push_back(i);
    }

	test1(a);
	test2(a);



    return 0;
}
