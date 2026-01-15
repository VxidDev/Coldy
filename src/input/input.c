#include "../../include/input/input.h"
#include "../../include/coldy.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* UserInput() {
    char* buff = calloc(64 , sizeof(char));

    if (!buff) {
        return NULL;
    }

    size_t cPos = 0;
    size_t buffSize = 64;

    int c;

    size_t promptLen = strlen(PROMPT);
    for (size_t i = 0; i < promptLen; i++) {
        if (PROMPT[i] == '%' && i + 1 < promptLen) {
            switch (PROMPT[++i]) {
                case 'U': printf("%s" , USERNAME); break;
                case 'H': printf("%s" , HOSTNAME); break;
                case 'P': printf("%s" , CURRDIR); break;
                default: printf("UNKNOWN"); 
            }

            continue;
        }
        if (PROMPT[i] == '+') PROMPT[i] = ' ';
        putc(PROMPT[i] , stdout);
    }

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

