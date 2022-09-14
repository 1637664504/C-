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
    map<int,string> student;

	//1. insert 函数插入 pair 数据
	student.insert(pair <int,string>(1,"lilisi"));
	//2. insert 函数插入 value_type 数据
	student.insert(std::map < int, std::string > ::value_type (2, "Tom"));
	//3. 用数组方式插入数据
	student[3] = "kenliya";

	map_show(student);

    return 0;
}
/*
1: lilisi
2: Tom
3: kenliya

*/