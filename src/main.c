#include<ncurses.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

#include "sprites.h"
#include "ground.h"
#include "input.h"
#include "score.h"
#include "vessels.h"

void sleep(int msecs) {
    struct timespec ts;
    ts.tv_sec = msecs/1000;
    ts.tv_nsec = msecs%1000*1000*1000;
    nanosleep(&ts, NULL);
}

int main() {
    srand(time(0));

    initscr();
    cbreak();
    noecho();
    clear();
    curs_set(0);

    // minimum window size - 24 ROWS x 32 COLS
    refresh();

    WINDOW *ground_window = get_ground_window();
    WINDOW *score_window = get_score_window();
    WINDOW *input_window = get_input_window();

    mvwin(ground_window,LINES-GROUND_WINDOW_H-SCORE_WINDOW_H,0);
    mvwin(score_window,LINES-SCORE_WINDOW_H,COLS-SCORE_WINDOW_W);
    mvwin(input_window,LINES-SCORE_WINDOW_H,0);
    wrefresh(ground_window);
    wrefresh(input_window);
    wrefresh(score_window);

    int avx = COLS-VESSEL_SPRITE_W;
    int avy = LINES-SCORE_WINDOW_H-GROUND_WINDOW_H-VESSEL_SPRITE_H-SPAWN_OFFSET;

    init_score();
    init_vessel_manager();
    for(int i=0; i<10; i++) {
        add_vessel(rand()%avy,rand()%avx);
    }
    render_all_vessels();

    /*
    for(int i=0; i<10; i++) {
        sleep(500);
        step_all_vessels();
    }

    for(int i=0; i<20; i++) {
        sleep(500);
        destroy_vessel(0);
        step_all_vessels();
    }
    */

   while(num_vessels>0) {
       sleep(500);
       step_all_vessels();
   }

    getch();
    endwin();
    
    return 0;
}