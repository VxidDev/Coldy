#include "../../../include/Commands/builtIns/exit.h"
#include "../../../include/Commands/command.h"
#include "../../../include/coldy.h"
#include "../../../include/Commands/builtIns/alias.h"

#include <stdlib.h>

bool CMD_exit(void* data) {
    (void)data;

    free(HOSTNAME);
    free(PROMPT);
    free(CURRDIR);

    FreeAliases();

    exit(0); // this would exit app anyways...
}

Command Exit = {
    "exit",
    CMD_exit
};