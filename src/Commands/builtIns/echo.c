#include "../../../include/Commands/builtIns/echo.h"
#include "../../../include/Commands/command.h"

#include <stdio.h>

bool CMD_echo(void* data) {
    const CmdData* Data = (const CmdData*)data;

    for (size_t i = 1; i < Data->TokenizedInputCount; i++) {
        printf("%s " , Data->TokenizedInput[i]);
    }

    printf("\n");

    return true;
}

Command Echo = {
    "echo",
    CMD_echo
};