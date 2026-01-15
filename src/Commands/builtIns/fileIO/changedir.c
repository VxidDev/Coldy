#define _GNU_SOURCE
#include "../../../../include/Commands/command.h"
#include "../../../../include/Commands/builtIns/fileIO/changedir.h"
#include "../../../../include/coldy.h"
#include "../../../../include/utils/getuserdata.h"

#include <unistd.h>
#include <stdio.h>

bool CMD_changedir(void *data) {
    const CmdData* Data = (const CmdData*)data;
    if (!Data->TokenizedInput[1]) return true;

    char *Path;
    asprintf(&Path, "%s%s",
        Data->TokenizedInput[1][0] == '~' ? USERPATH : "",
        Data->TokenizedInput[1][0] == '~' ? Data->TokenizedInput[1] + 1 : Data->TokenizedInput[1]
    );


    if (chdir(Path) != 0) {
        printf("Unknown directory.\n");
        free(Path);
        return false;
    }

    CURRDIR = GetCurrDir();
    free(Path);

    return true;
}

Command Changedir = {
    "changedir",
    CMD_changedir
};