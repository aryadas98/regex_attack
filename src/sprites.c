#include "sprites.h"

/* -------- GROUND SPRITES --------------- */
#define GROUND_BASE_W 12
#define GROUND_BASE_H 6

const char ground_base[GROUND_BASE_W*GROUND_BASE_H+1] = \
                "     /\\     "
                "    /  \\    "
                "   /    \\   "
                "  /      \\  "
                " /        \\ "
                "/          \\";

/* -------- END GROUND SPRITES ----------- */

/* --------- SCORE WINDOW --------------- */
#define SCORE_WINDOW_W 25
#define SCORE_WINDOW_H 3
#define SCORE_X 2
#define SCORE_Y 1

const char score_window_banner[SCORE_WINDOW_W*SCORE_WINDOW_H+1] = \
                "========================\n"
                "|                      |\n"
                "========================\0";

/* --------- END SCORE WINDOW ----------- */

/* -------------- VESSELS --------------- */
#define VESSEL_SPRITE_W 9
#define VESSEL_SPRITE_H 2
#define VESSEL_NAME_SIZE 6
#define VESSEL_NAME_X 1
#define VESSEL_NAME_Y 0

const char vessel_sprite[VESSEL_SPRITE_W*VESSEL_SPRITE_H+1] = \
                "[      ]\n"
                "   ::   \0";

const char vessel_destroyed_sprite[VESSEL_SPRITE_W*VESSEL_SPRITE_H+1] = \
                "[******]\n"
                "   **   \0";

/* ---------- END VESSELS --------------- */