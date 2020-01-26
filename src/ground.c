#include <ncurses.h>
#include <stdlib.h>

#include "sprites.h"
#include "ground.h"

#define GROUND_TERRAIN_H 3
#define GROUND_TERRAIN_SKIP 5
#define GROUND_SHIELD_SKIP 2

static char *ground;

static void ground_copy_shield() {
    for(int i=0; i<COLS; i++)
        ground[i] = '=';
}

static void ground_copy_base() {
    for(int i=0; i<GROUND_BASE_H; i++) {
        for(int j=0; j<GROUND_BASE_W; j++)
            ground[(i+GROUND_SHIELD_SKIP)*COLS+(COLS-GROUND_BASE_W)/2+j] = ground_base[i*GROUND_BASE_W+j];
    }
}

static void ground_write_value(int x, int y, char c) {
    ground[(y+GROUND_TERRAIN_SKIP)*COLS+x] = c;
    for(int i=y+1; i<GROUND_TERRAIN_H; i++)
        ground[(i+GROUND_TERRAIN_SKIP)*COLS+x] = ':';
}

static void ground_generate_random() {

    int x,y,oy,ooy;
    x = 0, y = rand()%GROUND_TERRAIN_H, oy=y, ooy=y;

    ground_write_value(x,y,'_');

    for(x=1; x<COLS-1; x++) {
        if (ooy == oy) {
            if (y == 0) {
                y -= rand()%2-1;
            } else if (y == GROUND_TERRAIN_H-1) {
                y -= rand()%2;
            } else {
                y += rand()%3-1;
            }
        }

        if (y == oy) {
            ground_write_value(x,y,'_');
        } else if (y < oy) {
            ground_write_value(x,oy,'/');
        } else {
            ground_write_value(x,y,'\\');
        }

        ooy = oy;
        oy = y;
    }
}

static void ground_get_ground() {
    int h = GROUND_WINDOW_H;

    for(int i=0; i<COLS*GROUND_WINDOW_H; i++)
        ground[i] = ' ';

    ground_copy_shield(ground);
    ground_copy_base(ground);
    ground_generate_random(ground+COLS*GROUND_TERRAIN_SKIP);

    for(int i=1; i<=GROUND_WINDOW_H; i++)
        ground[i*COLS-1] = '\n';
    ground[COLS*h-1] = '\0';
}

WINDOW *get_ground_window() {
    WINDOW *ground_window;
    ground_window = newwin(GROUND_WINDOW_H,COLS,0,0);
    wclear(ground_window);

    char tmp[COLS*GROUND_WINDOW_H];
    ground=tmp;

    ground_get_ground();
    wprintw(ground_window,ground);

    return ground_window;
}