#include "../../../../include/Commands/command.h"
#include "../../../../include/Commands/builtIns/fileIO/changedir.h"

#include <unistd.h>
#include <stdio.h>

bool CMD_changedir(void *data) {
    const CmdData* Data = (const CmdData*)data;
    if (!Data->TokenizedInput[1]) return true;

    const char* Path = Data->TokenizedInput[1];

    if (chdir(Path) != 0) {
        printf("Unknown directory.\n");
        return false;
    }

    return true;
}

Command Changedir = {
    "changedir",
    CMD_changedir
};