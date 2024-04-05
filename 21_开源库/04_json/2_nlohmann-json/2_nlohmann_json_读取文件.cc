#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

int main()
{
    ifstream f("modified.json");
    if (f.is_open())
    {
        json data = json::parse(f);
        string buf = data.dump();
        cout << buf << endl;
    }
    f.close();

    return 0;
}
