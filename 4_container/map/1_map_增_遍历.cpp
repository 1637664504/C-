#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    map<int,string> student;
    student[1]="lilisi";
    student[2]="John";
    student[101]="Alisi";
    student[222]="Makr";
    //student.insert(333,"Aka");    //insert 必须添加pair<int, string>
    student.insert(pair<int,string> (333,"Aka"));

    cout << "student[2]="<<student[2] <<endl;
    cout << "student[3]="<<student[3] <<endl;   //输出空,且添加了一个为空的 student[3] {3,""}
    cout << "student.size=" << student.size() << endl;

    // c++98
    map<int, string>::iterator it;
    for(it=student.begin(); it!=student.end(); it++)
    {
        cout << (*it).first << ": " <<(*it).second <<endl;
    }

    // c++11
    for(auto it:student)
    {
        cout << it.first << ": " <<it.second <<endl;
    }
    return 0;
}