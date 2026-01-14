#ifndef COMMAND_H
#define COMMAND_H

#include "builtIns/echo.h"
#include "builtIns/exit.h"
#include <stdlib.h>

typedef struct Command { // Simple key-value pair
    const char* name;
    bool (*cmd)(void* data);
} Command;

typedef struct CmdData {
    char** TokenizedInput; // e.g [ "ls" , "-l" , "/"]
    char* rawInput; // e.g "ls -l /"

    size_t TokenizedInputCount; // e.g 3
} CmdData;

extern Command Echo;
extern Command Exit;
extern Command Clear;

void InitBuiltInCommands();

#endif