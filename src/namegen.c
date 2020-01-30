#include <string.h>
#include <stdlib.h>
#include "namegen.h"
#include "sprites.h"

#define VALID_CHARS_SIZE 63

static const char validchars[VALID_CHARS_SIZE] =  \
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789";

void generate_random_name(char name_arr[VESSEL_NAME_SIZE+1]) {
    for(int i=0; i<VESSEL_NAME_SIZE; i++) {
        name_arr[i] = validchars[rand()%(VALID_CHARS_SIZE-1)];
    }
    name_arr[VESSEL_NAME_SIZE] = '\0';
}