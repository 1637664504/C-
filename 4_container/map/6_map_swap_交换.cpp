/*

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
	a.insert(pair <int,string>(1,"lilisi"));
	a.insert(std::map < int, std::string > ::value_type (2, "Tom"));
	a[3] = "Akali";
	a[7] = "Marke";

	map<int,string> b;
	b[1] = "aaa";
	b[2] = "bbb";
	b[3] = "ccc";

	a.swap(b);
	map_show(a);
	map_show(b);

    return 0;
}
/*
1: aaa
2: bbb
3: ccc

1: lilisi
2: Tom
3: Akali
7: Marke

*/