#include <ncurses.h>
#include <string.h>
#include "sprites.h"
#include "vessels.h"
#include "namegen.h"
#include "score.h"

enum vessel_state {FLYING, ON_FIRE, DESTROYED};

static WINDOW *vessels[MAX_VESSELS];
static char vessel_names[MAX_VESSELS][VESSEL_NAME_SIZE+1];
static enum vessel_state vessel_states[MAX_VESSELS];

int num_vessels;

void init_vessel_manager() {
    num_vessels = 0;
}

void add_vessel(int y, int x) {
    if (num_vessels == MAX_VESSELS)
        return;

    generate_random_name(vessel_names[num_vessels]);
    vessels[num_vessels] = newwin(VESSEL_SPRITE_H,VESSEL_SPRITE_W,y,x);
    vessel_states[num_vessels] = FLYING;
    num_vessels++;
}

void destroy_vessel(int v) {
    if (vessel_states[v] == FLYING) {
        vessel_states[v] = ON_FIRE;
        update_score(SCORE_ON_KILL);
    }
}

static void delete_vessel(int v) {
    wclear(vessels[v]);
    wrefresh(vessels[v]);
    delwin(vessels[v]);

    vessels[v] = vessels[num_vessels-1];
    strcpy(vessel_names[v],vessel_names[num_vessels-1]);
    vessel_states[v] = vessel_states[num_vessels-1];
    num_vessels--;
}

void move_vessel(WINDOW *v, int y, int x) {
    wclear(v);
    wrefresh(v);
    mvwin(v,y,x);
}

void render_all_vessels() {
    for(int i=0; i<num_vessels; i++) {
        wclear(vessels[i]);
        switch (vessel_states[i]) {
            case FLYING:
                wprintw(vessels[i],vessel_sprite);
                mvwprintw(vessels[i],VESSEL_NAME_Y,VESSEL_NAME_X,vessel_names[i]);
                break;
            case ON_FIRE:
            case DESTROYED:
                wprintw(vessels[i],vessel_destroyed_sprite);
                break;
        }
        wrefresh(vessels[i]);
    }
}

void step_all_vessels() {
    for(int i=0; i<num_vessels; i++) {
        switch(vessel_states[i]) {
            case FLYING:
                // check whether vessel is colliding
                if (getbegy(vessels[i]) == LINES-SCORE_WINDOW_H-GROUND_WINDOW_H-VESSEL_SPRITE_H) {
                    vessel_states[i] = ON_FIRE;

                    update_score(SCORE_ON_ATTACK);

                    // reprocess this
                    i--;
                    break;
                }
                move_vessel(vessels[i],getbegy(vessels[i])+1,getbegx(vessels[i]));
                break;
            case ON_FIRE:
                vessel_states[i] = DESTROYED;
                break;
            case DESTROYED:
                delete_vessel(i);
                i--;
        }
    }
    render_all_vessels();
}