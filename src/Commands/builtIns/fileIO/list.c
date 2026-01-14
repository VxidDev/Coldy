#define _POSIX_C_SOURCE 200809L

#include "../../../../include/Commands/builtIns/fileIO/list.h"
#include "../../../../include/Commands/command.h"
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

#ifndef DT_DIR
#define DT_DIR 4
#endif

bool CMD_list(void *data) {
    const CmdData *Data = (const CmdData*)data;
    char *path = NULL;
    bool FreeNeeded = false;

    if (!Data->TokenizedInput[1]) {
        path = getcwd(NULL , 0);
        FreeNeeded = true;

        if (!path) {
            printf("Failed to get current directory.\n");
            return false;
        } 
    } else {
        path = Data->TokenizedInput[1];
    }

    DIR *dir = opendir(path);

    if (!dir) {
        printf("Failed to open directory for iteration.\n");
        if (FreeNeeded) free(path);
        return false;
    }

    struct dirent *entry;
    unsigned char lineEntries = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            printf("%s%s%s " , entry->d_type == DT_DIR ? "\033[34m" : "", entry->d_name , entry->d_type == DT_DIR ? "\033[0m" : "");
        }

        if (lineEntries++ >= 9) {
            putc('\n' , stdout);
            lineEntries = 0;
        }
    }

    closedir(dir);
    if (FreeNeeded) free(path);

    return true;
}

Command List = {
    "list",
    CMD_list
};