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

void map_iterator_show(map<int,string> &student)
{
	map<int,string>::iterator it,itEnd;
	it=student.begin();
	itEnd=student.end();
    while(it != itEnd)
    {
        cout << (*it).first << ": " <<(*it).second <<endl;
		it++;
    }
}

int main(void)
{
    map<int,string> student;

	student.insert(pair <int,string>(1,"lilisi"));
	student.insert(std::map < int, std::string > ::value_type (2, "Tom"));
	student[3] = "kenliya";

	//map_show(student);
	map_iterator_show(student);

    return 0;
}
/*
1: lilisi
2: Tom
3: kenliya

*/