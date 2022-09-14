/*
iterator erase（iterator it)	;//通过一个条目对象删除
iterator erase（iterator first，iterator last）；	//删除一个范围
size_type erase(const Key&key);	//通过关键字删除
clear()；//就相当于enumMap.erase(enumMap.begin(),enumMap.end());
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    map<int,string> student;

	student.insert(pair <int,string>(1,"lilisi"));
	student.insert(std::map < int, std::string > ::value_type (2, "Tom"));
	student[3] = "Akali";
	student[7] = "Marke";

	//方法1: 通过迭代器it 删除
	map<int,string>::iterator it;
	it = student.find(3);
	student.erase(it);

	//方法2: 下角标删除
	student.erase(2);

    return 0;
}