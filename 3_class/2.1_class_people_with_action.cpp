#include <iostream>
#include <string>
using namespace std;

class people{
public:
    people(string Name,int Height,int Weight,int Age);
    int get_name(string &dst);
    string get_name();
    int get_height();
    int get_weight();
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

int people::get_age()
{
    return age;
}

int people::get_height()
{
    return height;
}

int people::get_weight()
{
    return weight;
}


int main(void)
{
    class people mm = people("ailisi",165,45,18);

    string name = "";
    //mm.get_name(name);
    //cout << "name " << name <<endl;
    cout << "name " << mm.get_name() <<endl;
    cout << "age " << mm.get_age() << endl;
    cout << "heigh " << mm.get_height() << endl;
    cout << "weigh " << mm.get_weight() << endl;

    return 0;
}