#define _POSIX_C_SOURCE 200809L

#include "../../../../include/Commands/builtIns/fileIO/remove.h"
#include "../../../../include/Commands/command.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>

bool CMD_remove(void* data) {
    const CmdData* Data = (const CmdData*)data;

    if (!Data->TokenizedInput[1]) {
        printf("Usage: remove <file/dir>\n");
        return true;
    }

    struct stat st;
    stat(Data->TokenizedInput[1] , &st);

    if (S_ISDIR(st.st_mode)) {
        size_t stackSize = 16;
        size_t stackUsed = 0;
        char **stack = calloc(stackSize, sizeof(char*));

        stack[stackUsed++] = strdup(Data->TokenizedInput[1]);

        while (stackUsed > 0) {
            char *path = stack[stackUsed - 1];
            DIR *dir = opendir(path);

            if (!dir) {
                unlink(path);
                free(path);
                stackUsed--;
                continue;
            }

            struct dirent *ent;
            int isEmpty = 1;

            while ((ent = readdir(dir))) {
                if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
                    continue;

                isEmpty = 0;

                char *child = calloc(PATH_MAX, 1);
                snprintf(child, PATH_MAX, "%s/%s", path, ent->d_name);

                struct stat st2;
                stat(child, &st2);

                if (stackUsed >= stackSize) {
                    stackSize *= 2;
                    stack = realloc(stack, stackSize * sizeof(char*));
                }

                stack[stackUsed++] = child;
                break; 
            }

            closedir(dir);

            if (isEmpty) {
                rmdir(path);
                free(path);
                stackUsed--;
            }
        }

        free(stack);
    }
    else if (remove(Data->TokenizedInput[1]) != 0) {
        printf("Failed to remove file.\n");
    }

    return true;
}

Command Remove = {
    "remove",
    CMD_remove
};