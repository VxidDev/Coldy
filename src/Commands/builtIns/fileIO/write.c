#include "../../../../include/Commands/builtIns/fileIO/write.h"
#include "../../../../include/Commands/command.h"
#include <stdio.h>
#include <string.h>

bool CMD_write(void *data) {
    const CmdData* Data = (const CmdData*)data;

    if (!Data->TokenizedInput[1] || !Data->TokenizedInput[2]) {
        printf("Usage: write <file> <text>\n");
        return true;
    }

    FILE *file = fopen(Data->TokenizedInput[1] , "w");

    if (!file) {
        printf("Failed to open file.\n");
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

Command Write = {
    "write",
    CMD_write
};