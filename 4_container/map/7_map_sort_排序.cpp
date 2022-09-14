/*
map 排序
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

void map_show(map<int,string> &student)
{
	map<int,string>::iterator it;
    for(it=student.begin(); it!=student.end(); it++)
    {
        cout << (*it).first << ": " <<(*it).second <<endl;
    }
}

int main(void)
{
    map<int,string> a;

	a.insert(pair <int,string>(2,"lilisi"));
	a.insert(std::map < int, std::string > ::value_type (1, "Tom"));
	a[7] = "Akali";
	a[3] = "Marke";
	map_show(a);
	//a.sort();		-->编译错误,无此成员

    return 0;
}
/*
测试:
1: Tom
2: lilisi
3: Marke
7: Akali

结论:
Map中的元素是自动按 key升序排序

*/