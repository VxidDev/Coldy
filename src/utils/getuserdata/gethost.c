#define _POSIX_C_SOURCE 200809L
#include "../../../include/utils/getuserdata.h"

#include <unistd.h>
#include <stdlib.h>

char* GetHost() {
    char *hostname = calloc(256 , sizeof(char));
    gethostname(hostname, sizeof(hostname));

    return hostname;
}