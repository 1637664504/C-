#ifndef _player_h_
#define _player_h_
#include "map.h"

enum palyer_cmd{
    Move_up='i',
    Move_down='k',
    Move_left='j',
    Move_right='l'
};

class player: public map
{
public:
    int posx;
    int posy;
    int move(int cmd);
    void move_mapObj_pos(int next_x, int next_y);
};
#endif