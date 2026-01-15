#define _POSIX_C_SOURCE 200809L
#include "../../../include/utils/getuserdata.h"
#include "../../../include/coldy.h"

#include <unistd.h>
#include <string.h>

char* GetCurrDir() {
    char *path = getcwd(NULL , 0); // Needs to be freed!

    if (strcmp(path , USERPATH) == 0) {
        free(path);
        path = calloc(2 , sizeof(char));
        path[0] = '~';
        path[1] = '\0';
    }

    return path;
}