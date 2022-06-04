#include <iostream>
#include <stdio.h>
#include "map.h"
using namespace std;

/*
Map
y axis
|
|
|________ x Axis
*/

void map::session_init(char *res,int h,int w)
{
    map_res = res;
    height = h;
    width = w;

    map_x = width-1;
    map_y = height;
}

void map::draw_map()
{
    int x;
    int y;
    char *p;
    cout << endl;
    for(y=0;y<map_y;y++)
    {
        for(x=0;x<map_x;x++)
        {
            //cout << *(map_res+y*x+x);
            p = map_res+(y*width)+x;
            printf("%c",*p);
        }
        cout << endl;
    }
}

char map::get_pos_element(int x, int y)
{
    if(x > map_x || y > map_y
        || x < 0 || y < 0)
        return Map_Invaild;

    char *p_elem= map_res+(y*width)+x;

    return *p_elem;
}

int map::get_player_pos(int &player_x, int &player_y)
{
    int x;
    int y;
    char *p;
    for(y=1;y<map_y-1;y++)
    {
        for(x=1;x<map_x-1;x++)
        {
            p = map_res+(y*width)+x;
            if(*p == Map_Player)
            {
                player_x = x;
                player_y = y;
                return 1;
            }
        }
    }

    return 0;
}

#if 0
int main(void)
{
    map map_session_1;
    map_session_1.session_init((char *)session_1,4,17);
    map_session_1.draw_map();

    return 0;
}
#endif