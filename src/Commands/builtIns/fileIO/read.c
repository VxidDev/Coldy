#define _POSIX_C_SOURCE 200809L

#include "../../../../include/Commands/builtIns/fileIO/read.h"
#include "../../../../include/Commands/command.h"
#include <stdio.h>

bool CMD_read(void *data) {
    const CmdData* Data = (const CmdData*)data;

    if (!Data->TokenizedInput[1]) {
        printf("Usage: read <file>\n");
        return true;
    }

    FILE *file = fopen(Data->TokenizedInput[1] , "r");

    if (!file) {
        printf("Unknown file.\n");
        return false;
    }

    int c;
    
    while ((c = getc(file)) && c != EOF) {
        putc(c , stdout);
    }

    putc('\n' , stdout);

    fclose(file);

    return true;
}

Command Read = {
    "read",
    CMD_read
};
