#ifndef VESSELS_H
#define VESSELS_H

#define MAX_VESSELS 30
#define SPAWN_OFFSET 10

extern int num_vessels;

void init_vessel_manager();
void add_vessel(int, int);
void destroy_vessel(int);
//void delete_vessel(int);
void move_vessel(WINDOW *v, int y, int x);
void render_all_vessels();
void step_all_vessels();

#endif