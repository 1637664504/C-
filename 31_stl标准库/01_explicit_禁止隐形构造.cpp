#include <iostream>
using namespace std;
class Point{
public:
    int point_x,point_y;
    explicit Point(int x=0,int y=0);
};

Point::Point(int x,int y)
{
    point_x = x;
    point_y = y;
}

int main()
{
    Point a(2,3);
    Point b(2.0,3.0);

    return 0;
}