#include "../../../include/utils/getuserdata.h"

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include <stdio.h>

char* GetUser() {
    struct passwd *pw = getpwuid(getuid());
    
    if (!pw) {
        perror("err @ GetUser -> FAILED TO EXTRACT USERNAME");
        return NULL;
    }

    return pw->pw_name;
}