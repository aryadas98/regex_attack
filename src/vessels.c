#include <ncurses.h>
#include <string.h>
#include "sprites.h"
#include "vessels.h"
#include "namegen.h"
#include "score.h"

static WINDOW *vessels[MAX_VESSELS];
static char vessel_names[MAX_VESSELS][VESSEL_NAME_SIZE+1];
static int num_vessels;

void init_vessel_manager() {
    num_vessels = 0;
    generate_name_series(vessel_names,MAX_VESSELS);
}

void add_vessel(int y, int x) {
    if (num_vessels == MAX_VESSELS)
        return;

    vessels[num_vessels] = newwin(VESSEL_SPRITE_H,VESSEL_SPRITE_W,y,x);
    num_vessels++;
}

void delete_vessel(int v) {
    wclear(vessels[v]);
    wrefresh(vessels[v]);
    delwin(vessels[v]);

    for(int i=v; i<num_vessels; i++) {
        vessels[i] = vessels[i+1];
        strcpy(vessel_names[i],vessel_names[i+1]);
    }
    num_vessels--;

    render_all_vessels();
    update_score(10);
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
        mvwprintw(vessels[i],VESSEL_NAME_Y,VESSEL_NAME_X,vessel_names[i]);
        wrefresh(vessels[i]);
    }
}

void step_all_vessels() {
    for(int i=0; i<num_vessels; i++) {
        move_vessel(vessels[i],getbegy(vessels[i])+1,getbegx(vessels[i]));
    }
    render_all_vessels();
}