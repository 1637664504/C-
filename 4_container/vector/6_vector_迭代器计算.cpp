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
	
	vector<int>::iterator it,it1,it2;
	it = a.begin();
	it1=it+2;
	it2=it+4;
	long t = it2 - it1;

	if(it2>it1)
	{
		t=1;
	}
	else
	{
		t=2;
	}



    return 0;
}
/*
it即地址

*/