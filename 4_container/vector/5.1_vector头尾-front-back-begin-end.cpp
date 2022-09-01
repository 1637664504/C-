#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> a;
	for(int i=1;i<=5;i++)
	{
		a.push_back(i);
	}
	int val = a.at(2);
	val = a.front();
	val = a.back();

	vector<int>::iterator it;
	it = a.begin();
	cout << *it <<endl;
	it = a.end();
	cout << *it <<endl;


    return 0;
}
/*
val = 3
a.front() = 1
a.back() = 5

a.begin() = 1
a.end() = 0
*/