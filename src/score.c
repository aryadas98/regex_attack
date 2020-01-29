#include <ncurses.h>

#include "sprites.h"
#include "score.h"

static WINDOW *score_window;
static int score;

void init_score() {
    score = 0;
    update_score(0);
}

WINDOW *get_score_window() {
    score_window = newwin(SCORE_WINDOW_H,SCORE_WINDOW_W,0,0);
    wclear(score_window);
    wprintw(score_window,score_window_banner);

    return score_window;
}

void update_score(int delta) {
    score += delta;
    wclear(score_window);
    wprintw(score_window,score_window_banner);
    mvwprintw(score_window,SCORE_Y,SCORE_X,"%d",score);
    wrefresh(score_window);
}