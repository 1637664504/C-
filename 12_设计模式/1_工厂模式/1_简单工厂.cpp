#include <iostream>
using namespace std;

enum CTYPE {COREA,COREB};
class singlecore
{
	public:
		virtual void show()=0;
};

class singlecoreA:public singlecore
{
	public:
	void show()
	{
		cout << "singlecore A" <<endl;
	}
};

int main(void)
{
	singlecoreA coreA;
	coreA.show();

	return 0;
}