#include<ncurses.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

// cross platform sleep
#ifdef _WIN32
//  For Windows (32- and 64-bit)
#   include <windows.h>
#   define SLEEP(msecs) Sleep(msecs)
#elif __unix
//  For linux, OSX, and other unixes
// #   define _POSIX_C_SOURCE 199309L // or greater
#   include <time.h>
#   define SLEEP(msecs) do {            \
        struct timespec ts;             \
        ts.tv_sec = msecs/1000;         \
        ts.tv_nsec = msecs%1000*1000*1000;   \
        nanosleep(&ts, NULL);           \
        } while (0)
#else
#   error "Unknown system. This code will compile on Windows or Linux."
#endif

#include "sprites.h"
#include "ground.h"
#include "input.h"
#include "score.h"
#include "vessels.h"

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

    init_vessel_manager();
    for(int i=0; i<10; i++) {
        add_vessel(rand()%20,rand()%50);
    }
    render_all_vessels();

    for(int i=0; i<10; i++) {
        SLEEP(500);
        step_all_vessels();
    }

    getch();
    endwin();
    
    return 0;
}