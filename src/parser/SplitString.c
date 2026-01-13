#include "../../include/parser/parser.h"

#include <stdlib.h>
#include <string.h>

char **SplitString(char *string) {
    char** buff = calloc(4, sizeof(char*));

    size_t currS = 0;
    size_t currC = 4;

    char* token = strtok(string , " ");

    while (token != NULL) {
        if (currS == currC) {
            currC *= 2;
            void* ptr = realloc(buff , currC * sizeof(char*));

            if (!ptr) {
                free(buff);
                return NULL;
            }

            buff = ptr;
        }

        buff[currS++] = token;
        token = strtok(NULL , " ");
    }

    buff[currS] = NULL;

    return buff;
}