#include <ncurses.h>
#include "sprites.h"
#include "vessels.h"

static WINDOW *vessels[MAX_VESSELS];
static int num_vessels;

void init_vessel_manager() {
    num_vessels = 0;
}

void add_vessel(int y, int x) {
    if (num_vessels == MAX_VESSELS)
        return;

    vessels[num_vessels++] = newwin(VESSEL_SPRITE_H,VESSEL_SPRITE_W,y,x);
}

void move_vessel(WINDOW *v, int y, int x) {
    wclear(v);
    wrefresh(v);
    mvwin(v,y,x);
}

void render_all_vessels() {
    for(int i=0; i<num_vessels; i++) {
        wclear(vessels[i]);
        wprintw(vessels[i],vessel_sprite);
        wrefresh(vessels[i]);
    }
}

void step_all_vessels() {
    for(int i=0; i<num_vessels; i++) {
        move_vessel(vessels[i],getbegy(vessels[i])+1,getbegx(vessels[i]));
    }
    render_all_vessels();
}