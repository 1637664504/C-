/*
map搜索key
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

	map<int,string>::iterator it;
	it = student.find(3);
	if(it == student.end())
		cout << "map not find" << endl;
	else
		cout << "key value " << (*it).second << endl;

    return 0;
}
/*
结果:
key value kenliya

*/