#include "sprites.h"

#define GROUND_BASE_W 12
#define GROUND_BASE_H 6

const char ground_base[GROUND_BASE_W*GROUND_BASE_H+1] = \
                "     /\\     "
                "    /  \\    "
                "   /    \\   "
                "  /      \\  "
                " /        \\ "
                "/          \\";

#define SCORE_WINDOW_W 14
#define SCORE_WINDOW_H 3

const char score_window_banner[SCORE_WINDOW_W*SCORE_WINDOW_H+1] = \
                "=============\n"
                "|    xxx    |\n"
                "=============\0";

#define VESSEL_SPRITE_W 9
#define VESSEL_SPRITE_H 2

const char vessel_sprite[VESSEL_SPRITE_W*VESSEL_SPRITE_H+1] = \
"[xxxxxx]\n"
"   ::   \0";