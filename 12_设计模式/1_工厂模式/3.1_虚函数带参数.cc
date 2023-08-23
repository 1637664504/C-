
#include <iostream>
using namespace std;

enum CTYPE { COREA, COREB };
class SingleCore
{
public:
    virtual void Show() = 0;
};

//单核A    
class SingleCoreA : public SingleCore
{
private:
    int a;
public:
    SingleCoreA(int x):a(x)
    {}
    void Show() { cout << "SingleCore A" << endl; }
};

//单核B    
class SingleCoreB : public SingleCore
{
public:
    void Show() { cout << "SingleCore B" << endl; }
};

void test()
{
    SingleCore* pCore = NULL;
    pCore = new SingleCoreA(5);
    pCore->Show();
    delete pCore;
}

int main(void)
{
    test();
    return 0;
}
/*
SingleCore A

 */
