#include "../../../include/utils/getuserdata.h"

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include <stdio.h>

char* GetUserPath() {
    struct passwd *pw = getpwuid(getuid());
    
    if (!pw) {
        perror("err @ GetUserPath -> FAILED TO EXTRACT USERPATH");
        return NULL;
    }

    return pw->pw_dir;
}
