#ifndef COMMAND_H
#define COMMAND_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Command { // Simple key-value pair
    const char* name;
    bool (*cmd)(void* data);
} Command;

typedef struct CmdData {
    char** TokenizedInput; // e.g [ "ls" , "-l" , "/"]
    char* rawInput; // e.g "ls -l /"

    size_t TokenizedInputCount; // e.g 3
} CmdData;

extern Command Echo , Exit , Clear , List , Read , Write , Append , Changedir , Alias;

void InitBuiltInCommands();

#endif