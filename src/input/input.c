#include "../../include/input/input.h"

#include <stdlib.h>
#include <stdio.h>

char* UserInput() {
    char* buff = calloc(64 , sizeof(char));

    if (!buff) {
        return NULL;
    }

    size_t cPos = 0;
    size_t buffSize = 64;

    int c;

    while ((c = getc(stdin)) != EOF && c != '\n') {
        if (cPos + 1 >= buffSize) {
            buffSize *= 2;

            void* ptr = realloc(buff , buffSize * sizeof(char));

            if (!ptr) { 
                free(buff);
                return NULL;
            }

            buff = ptr;
        }

        buff[cPos++] = (char)c;
    }

    buff[cPos] = '\0';

    return buff;
}

