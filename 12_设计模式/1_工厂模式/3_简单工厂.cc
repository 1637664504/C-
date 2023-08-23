
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
    void Show() { cout << "SingleCore A" << endl; }
};

//单核B    
class SingleCoreB : public SingleCore
{
public:
    void Show() { cout << "SingleCore B" << endl; }
};

// 唯一的工厂，可以生产两种型号的处理器核，在内部判断    
class Factory
{
public:
    SingleCore* CreateSingleCore(enum CTYPE ctype)
    {
        if (ctype == COREA) //工厂内部判断    
            return new SingleCoreA(); //生产核A    
        else if (ctype == COREB)
            return new SingleCoreB(); //生产核B    
        else
            return NULL;
    }
};

void test()
{
    SingleCore* pCore = NULL;
    pCore = new SingleCoreA();
    pCore->Show();
    delete pCore;
}

int main(void)
{
    Factory f;
    SingleCore* pCore = f.CreateSingleCore(COREA);
    pCore->Show();
    delete pCore;

    pCore = f.CreateSingleCore(COREB);
    pCore->Show();
    delete pCore;


    test();
    return 0;
}

/*
SingleCore A
SingleCore B
SingleCore A
 */