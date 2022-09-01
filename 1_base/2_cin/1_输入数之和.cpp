#include <iostream>

using namespace std;

int main(void)
{
	int val;
	int sum=0;
	while(cin>>val)	//ctrl + d 结束
		sum+=val;

	cout << sum <<endl;
    return 0;
}