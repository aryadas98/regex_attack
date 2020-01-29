#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "namegen.h"
#include "sprites.h"
#include <stdio.h>

#define VALID_CHARS_SIZE 63

static const char validchars[VALID_CHARS_SIZE] =  \
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789";

void generate_name_series(char names[][VESSEL_NAME_SIZE+1], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<VESSEL_NAME_SIZE; j++) {
            names[i][j] = validchars[rand()%(VALID_CHARS_SIZE-1)];
        }
        names[i][VESSEL_NAME_SIZE] = '\0';
    }
}

// int main() {
//     srand(time(0));
//     char names[5][VESSEL_NAME_SIZE+1];

//     for(int i=0; i<5; i++) {
//         generate_name_series(names+i,1);
//     }

//     for(int i=0; i<5; i++) {
//         printf("%s\n",names[i]);
//     }
// }