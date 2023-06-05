#include <iostream>
#include <queue>

using namespace std;
int main(void)
{
    queue<int> a;
    a.push(1);
    a.push(3);
    a.push(5);

    //遍历
   int size = a.size();
   for(int i = 0; i < size; i++) {
      cout << a.front() << endl;
      a.push(a.front());
      a.pop();
   } 
}