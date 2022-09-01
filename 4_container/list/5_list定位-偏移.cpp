//list<int>::iterator it = ilist.begin()+2; #编译错误

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int get_list_pos(list<int>a, unsigned int pos)
{
	
	list<int>::iterator it = a.begin();
	//it+=pos;		#编译错误

	while(--pos)
		it++;

	cout << *it <<endl;

	return *it;
}

int main(void)
{
	//初始化为10个大小
	list<int> a(10);
	list<int>::iterator it;
	int i=0;
	for(it=a.begin(); it!=a.end(); it++){
		*it = i++;
	}
	get_list_pos(a,5);

	cout << endl;
    return 0;
}
