#include <ncurses.h>

#include "sprites.h"
#include "score.h"

WINDOW *get_score_window() {
    WINDOW *score_window = newwin(SCORE_WINDOW_H,SCORE_WINDOW_W,0,0);
    wclear(score_window);
    wprintw(score_window,score_window_banner);

    return score_window;
}