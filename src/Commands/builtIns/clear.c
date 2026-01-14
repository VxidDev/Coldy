#include "../../../include/Commands/builtIns/clear.h"
#include "../../../include/Commands/command.h"

#include <stdio.h>

bool CMD_clear(void* data) {
    (void)data;

    printf("\033[2J");
    printf("\033[2;1H");
    fflush(stdout);

    return true;
}

Command Clear = {
    "clear",
    CMD_clear
};