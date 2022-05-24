#include <iostream>
#include <string>
using namespace std;

enum color{
    color_black=0,
    color_white,
    color_gry,
    color_brown
};

class dog{
    public:
    enum color skin;
    void bark();
};

void dog::bark()
{
    cout <<"汪汪汪"<<endl;
}

int main(void)
{
    //class dog wangCai = new dog();
    dog wangCai;
    wangCai.bark();

    return 0;
}