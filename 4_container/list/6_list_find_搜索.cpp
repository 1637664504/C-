#include <iostream>
#include <list>
#include <vector>
using namespace std;

list<string>::iterator list_find_string(list<string> &src,string &key)
{
	list<string>::iterator it;
	for(it=src.begin(); it!=src.end(); it++)
	{
		if(*it == key)
		{
			break;
		}
	}

	return it;
}


int  list_find_string(list<string> &src, string &key, list<string>::iterator &result)
{
	int ret = -1;
	list<string>::iterator it;
	for(it=src.begin(); it!=src.end(); it++)
	{
		if(*it == key)
		{
			result = it;
			ret = 0;
			break;
		}
	}

	return ret;
}

int main(void)
{
	list<string> a={"123","345","aaa","bbb"};
	string b="345",c="ccc";
	list<string>::iterator result;
	int ret=0;

	result=list_find_string(a,b);
	if(*result != b)
		ret = -1;

	result=list_find_string(a,c);
	//if(*result == "") -->异常，运行无法进入
	//if(result == "") //-->编译错误
	if(*result != c)
		ret = -1;

	//更合理的搜索 实现方法
	ret = list_find_string(a,b,result);


    return 0;
}
