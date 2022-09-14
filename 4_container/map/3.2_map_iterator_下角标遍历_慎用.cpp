#include <iostream>
#include <string>
#include <map>
using namespace std;

void map_show_by_array(map<int,string> &student)
{
	unsigned int size = student.size();
	unsigned int i;
    for(i=1; i<= size; i++)
    {
        cout << i << ": "<< student[i] <<endl;
    }
}

int main(void)
{
    map<int,string> student;

	student.insert(pair <int,string>(1,"lilisi"));
	student.insert(std::map < int, std::string > ::value_type (2, "Tom"));
	student[3] = "kenliya";
	student[7] = "Marke";

	map_show_by_array(student);

    return 0;
}
/*
结果:
1: lilisi
2: Tom
3: kenliya
4:				--> NG

识别原因:
map student.size() 为 4，但第四个元素 key = 7
所以要慎用下角标

*/