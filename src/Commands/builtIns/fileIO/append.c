#include "../../../../include/Commands/builtIns/fileIO/append.h"
#include "../../../../include/Commands/command.h"
#include <stdio.h>
#include <string.h>

bool CMD_append(void *data) {
    const CmdData* Data = (const CmdData*)data;

    if (!Data->TokenizedInput[1] || !Data->TokenizedInput[2]) {
        printf("Usage: append <file> <text>\n");
        return true;
    }

    FILE *file = fopen(Data->TokenizedInput[1] , "a");

    if (!file) {
        printf("Failed to open file. (maybe file does not exist?)\n");
        return false;
    }

    for (size_t i = 2; Data->TokenizedInput[i]; i++) {
        size_t inputLen = strlen(Data->TokenizedInput[i]);
        for (size_t j = 0; j < inputLen; j++) {
            if (Data->TokenizedInput[i][j] == '\\' && j + 1 < inputLen && Data->TokenizedInput[i][j + 1] == 'n') {
                putc('\n' , file);
                j++;
                continue;
            }
            putc(Data->TokenizedInput[i][j] , file);
        }
        putc(' ' , file);
    }

    fclose(file);
    return true;
}

Command Append = {
    "append",
    CMD_append
};