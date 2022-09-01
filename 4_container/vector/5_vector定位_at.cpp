#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> a;
	for(int i=0;i<5;i++)
	{
		a.push_back(i);
	}
	int value = a.at(2);


    return 0;
}