#include "../../../../include/Commands/command.h"
#include "../../../../include/Commands/builtIns/fileIO/create.h"

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

bool CMD_create(void* data) {
    const CmdData* Data = (const CmdData*)data;

    if (!Data->TokenizedInput[1] || !Data->TokenizedInput[2]) {
        printf("Usage: create <-F/-D> <name>\n");
        return true;
    }

    bool IsDirectory = false;
    if (strcmp(Data->TokenizedInput[1] , "-D") == 0) IsDirectory = true;

    if (!IsDirectory && strcmp(Data->TokenizedInput[1] , "-F") != 0) {
        printf("Unknown parameter.\n");
        return false;
    }

    if (!IsDirectory) {
        FILE* file = fopen(Data->TokenizedInput[2] , "w");
        
        if (!file) {
            printf("Failed to create file.\n");
            return false;
        }

        fclose(file);
    } else if (mkdir(Data->TokenizedInput[2] , 0755) != 0) {
        printf("Failed to create directory.\n");
    }

    return true;
}

Command Create = {
    "create",
    CMD_create
};