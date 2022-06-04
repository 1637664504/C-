#include <iostream>
#include "player.h"
using namespace std;

int player::move(int cmd)
{
    int next_posx;
    int next_posy;
    char next_elem;
    if(cmd == Move_up)
    {
        next_posx = posx;
        next_posy = posy -1;
    }
    else if(cmd == Move_down){
        next_posx = posx;
        next_posy = posy +1;
    }
    else if(cmd == Move_left){
        next_posx = posx -1;
        next_posy = posy;
    }
    else if(cmd == Move_right){
        next_posx = posx +1;
        next_posy = posy;
    }

    next_elem = get_pos_element(next_posx,next_posy);
    if(next_elem == Map_Invaild){
        cout << "can't move "<<next_posx << ":" << next_posy << endl;
    }
    else if(next_elem == Map_Wall)
    {
        cout << "next pos is Wall" << endl;
        return 0;
    }
    else if(next_elem == Map_Box){
        //to do
        return 0;
    }
    else if(next_elem == Map_Space){
        //move
        move_mapObj_pos(next_posx,next_posy);
        posx = next_posx;
        posy = next_posy;
    }
    else if(next_elem == Map_Exit){
        move_mapObj_pos(next_posx,next_posy);
        posx = next_posx;
        posy = next_posy;
    }

    return next_elem;
}

void player::move_mapObj_pos(int next_x, int next_y)
{
    char tmp;
    //clean last pos
    char *p = map_res+(posy*width)+posx;
    tmp = *p;
    *p = Map_Space;

    //set now pos
    p= map_res+(next_y*width)+next_x;
    *p = tmp;
}