#include <ncurses.h>
#include "sprites.h"
#include "input.h"

WINDOW *get_input_window() {
    char banner[COLS-SCORE_WINDOW_W+1];
    for(int i=0; i<COLS-SCORE_WINDOW_W; i++)
        banner[i] = '=';
    banner[COLS-SCORE_WINDOW_W]='\0';

    WINDOW *input_window = newwin(SCORE_WINDOW_H,COLS-SCORE_WINDOW_W,0,0);
    wclear(input_window);
    mvwprintw(input_window,0,0,banner);
    mvwprintw(input_window,SCORE_WINDOW_H-1,0,banner);

    for(int i=1; i<SCORE_WINDOW_H-1; i++)
        mvwaddch(input_window,i,0,'|');

    return input_window;
}
