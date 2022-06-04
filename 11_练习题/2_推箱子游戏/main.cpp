#include <iostream>
#include <stdlib.h>
#include "map.h"
#include "player.h"
using namespace std;

char session_1[][17]={
{"****************"},
{"*  N           *"},
{"*           O  *"},
{"****************"},
};

int main_loop(void)
{
    char cmd;
    char ret;
    player master;
    master.session_init((char *)session_1,4,17);
    master.get_player_pos(master.posx,master.posy);
    master.draw_map();
    while(1){
        cmd=getchar();
        ret = master.move(cmd);
        master.draw_map();
        if(ret == Map_Exit)
        {
            cout << "You did it" << endl;
            break;
        }
    }

    return 0;
}

int main(void)
{
    system("stty -icanon");
    main_loop();
    return 0;
}