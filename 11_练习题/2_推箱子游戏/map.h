#ifndef _map_h_
#define _map_h_

enum map_obj_type{
    Map_Invaild=-'\0',
    Map_Wall='*',
    Map_Space=' ',
    Map_Box='#',
    Map_Player='O',
    Map_Exit='N'
};

class map
{
public:
    int height;
    int width;
    int map_x;
    int map_y;
    char *map_res;
    void session_init(char *res,int h, int w);
    void draw_map();
    char get_pos_element(int x, int y);
    int get_player_pos(int &player_x, int &player_y);
};
#endif