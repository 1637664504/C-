#include <iostream>
#include <string>
using namespace std;

class people{
    public:
    string name;
    int height;
    int weight;
    int age;
    
    people(string Name,int Height,int Weight,int Age);
};

people::people(string Name,int Height,int Weight,int Age)
{
    name = Name;
    height = Height;
    weight = Weight;
    age = Age;
}

int main(void)
{
    class people mm = people("ailisi",165,45,18);
    cout << "Name " << mm.name << endl;
    cout << "height " << mm.height << endl;
    cout << "weight " << mm.weight << endl;
    cout << "age " << mm.age << endl;

    return 0;
}