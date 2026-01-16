#include "../../../include/Commands/builtIns/currdir.h"
#include "../../../include/Commands/command.h"
#include "../../../include/coldy.h"

#include <stdio.h>
#include <string.h>

bool CMD_currdir(void *data) {
    (void)data;

    printf("%s\n" , strcmp(CURRDIR , "~") == 0 ? USERPATH : CURRDIR);

    return true;
}

Command Currdir = {
    "currdir",
    CMD_currdir
};