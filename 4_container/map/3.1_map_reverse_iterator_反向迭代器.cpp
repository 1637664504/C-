#include <iostream>
#include <string>
#include <map>
using namespace std;

void map_iterator_reverse(map<int,string> &student)
{
	map<int,string>::reverse_iterator it;
	for(it=student.rbegin(); it!=student.rend(); it++)
    {
        cout << (*it).first << ": " <<(*it).second <<endl;
    }
}

int main(void)
{
    map<int,string> student;

	student.insert(pair <int,string>(1,"lilisi"));
	student.insert(std::map < int, std::string > ::value_type (2, "Tom"));
	student[3] = "kenliya";

	map_iterator_reverse(student);

    return 0;
}
/*
3: kenliya
2: Tom
1: lilisi


*/