#ifndef SCORE_H
#define SCORE_H

#define SCORE_ON_KILL 10
#define SCORE_ON_ATTACK -10

void init_score();
WINDOW *get_score_window();
void update_score(int delta);

#endif