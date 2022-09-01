#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(void)
{
	list<int> a;
	//list<int> iter1=a.begin(),iter2=a.end();	//编译错误

	//测试2: list 初始化
	//list<int> b=(1,2,3); 编译错误
	//list<int> b=[1,2,3]; 编译错误
	//list<int> b={1,2,3}; 内存值诡异

    return 0;
}
