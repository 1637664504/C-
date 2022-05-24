#include <iostream>
#include <string>
using namespace std;

class people{
public:
    people(string Name,int Height,int Weight,int Age);
    int get_name(string &dst);
    string get_name();
    int get_height();
    int get_wright();
    int get_age();

private:
    string name;
    int height;
    int weight;
    int age;
};

people::people(string Name,int Height,int Weight,int Age)
{
    name = Name;
    height = Height;
    weight = Weight;
    age = Age;
}

int people::get_name(string &dst)
{
    dst = name;
    return 0;
}

string people::get_name()
{
    return name;
}

int main(void)
{
    class people mm = people("ailisi",165,45,18);

    string name = "";
    //mm.get_name(name);
    //cout << "name " << name <<endl;
    cout << "name " << mm.get_name() <<endl;

    return 0;
}