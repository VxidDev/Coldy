#include "../../../include/Commands/builtIns/exit.h"
#include "../../../include/Commands/command.h"

#include <stdlib.h>

bool CMD_exit(void* data) {
    (void)data;
    exit(0); // this would exit app anyways...
}

Command Exit = {
    "exit",
    CMD_exit
};