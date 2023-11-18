#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<pair<int,string>> number = {{1,"lili"},
    {2,"ailisi"},{3,"Marke"}};

    for(auto it=number.cbegin();it!=number.cend();++it){
        cout << it->first << ": " << it->second <<endl;
    }

    return 0;
}
