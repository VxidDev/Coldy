#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include "../../../include/Commands/builtIns/alias.h"
#include "../../../include/Commands/command.h"
#include "../../../include/utils/getuserdata.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t ALIASCOUNT = 0;
size_t MAXALIASES = 8;
CmdAlias *Aliases = NULL;

void FreeAliases(void) {
    for (size_t i = 0; (i < ALIASCOUNT && Aliases[i].inUse); i++) {
        free(Aliases[i].cmd);
        free(Aliases[i].name);
    }

    free(Aliases);
}

bool CMD_alias(void* data) {
    CmdData* Data = (CmdData*)data;

    if (!Data->TokenizedInput[1]) {
        printf("Usage: alias [-rm <cmdName>] <cmdName>=<cmd>\n");
        return true;
    }

    if (strcmp("-rm" , Data->TokenizedInput[1]) == 0) {
        if (!Data->TokenizedInput[2]) {
            printf("Please enter a removal target.\n");
            return false;
        }

        bool AliasFound = false;

        for (size_t i = 0; i < ALIASCOUNT; i++) {
            if (strcmp(Aliases[i].name , Data->TokenizedInput[2]) == 0) {
                free(Aliases[i].name);
                free(Aliases[i].cmd);
                Aliases[i].inUse = false;
                AliasFound = true;
            }
        }

        if (!AliasFound) {
            printf("Target not found.\n");
        }

        return true;
    }

    size_t AliasLen = strlen(Data->TokenizedInput[1]);

    for (size_t i = 0; i < AliasLen; i++) {
        if (Data->TokenizedInput[1][i] == '+') {
            Data->TokenizedInput[1][i] = ' ';
        }
    }

    // printf("Replaced whitespace...\n");

    char *aliasName = strtok(Data->TokenizedInput[1] , "=");

    if (!aliasName) {
        printf("Syntax Error @ aliasName.\n");
        return false;
    }

    // printf("Got aliasName...\n");

    char *aliasContent = strtok(NULL , "");

    if (!aliasContent) {
        printf("Syntax Error @ aliasContent.\n");
        return false;
    }

    // printf("Got aliasContent...\n");

    for (size_t i = 0; i < ALIASCOUNT; i++) {
        if (strcmp(Aliases[i].name , aliasName) == 0) {
            free(Aliases[i].cmd);
            Aliases[i].cmd = strdup(aliasContent);

            return true;
        }
    }

    // printf("Checked if there are duplicate names...\n");

    CmdAlias alias = {
        strdup(aliasName),
        strdup(aliasContent),
        true
    };

    // printf("Created alias var...\n");

    if (ALIASCOUNT >= MAXALIASES) {
        MAXALIASES *= 2;
        void* ptr = realloc(Aliases , sizeof(CmdAlias) * MAXALIASES);

        if (!ptr) {
            MAXALIASES /= 2;
            printf("Failed to resize aliases.\n");
            return false;
        }

        Aliases = ptr;
    }

    Aliases[ALIASCOUNT++] = alias;

    return true;
}

Command Alias = {
    "alias",
    CMD_alias
};

void InitAliases() {
    Aliases = calloc(MAXALIASES , sizeof(CmdAlias));

    if (!Aliases) {
        printf("Failed to initialize aliases.\n");
        return;
    }

    char* Path;

    if (asprintf(&Path , "%s/.coldyAliases.cfg" , GetUserPath()) == -1) {
        free(Aliases);
        return;
    }

    FILE* file = fopen(Path , "r");

    if (!file) {
        free(Path);
        return;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line , &len , file)) != -1) {
        for (ssize_t i = 0; i < nread; i++) {
            if (line[i] == '+') line[i] = ' ';
        }
        line[strcspn(line, "\n")] = 0;

        char* name = strtok(line , "=");

        if (!name) {
            printf("[ ALIAS-INIT ] Syntax Error @ aliasName\n");
            free(Path);
            fclose(file);

            FreeAliases();

            return;
        }

        char* content = strtok(NULL , "");
        
        if (!content) {
            printf("[ ALIAS-INIT ] Syntax Error @ aliasContent\n");
            free(Path);
            fclose(file);

            FreeAliases();

            return;
        }

        bool AliasExists = false;

        for (size_t i = 0; i < ALIASCOUNT; i++) {
            if (strcmp(Aliases[i].name , name) == 0) {
                free(Aliases[i].cmd);
                Aliases[i].cmd = strdup(content);
                AliasExists = true;
                break;
            }
        }

        if (!AliasExists) {
                CmdAlias alias = {
                strdup(name),
                strdup(content),
                true
            };

            if (ALIASCOUNT >= MAXALIASES) {
                MAXALIASES *= 2;
                void* ptr = realloc(Aliases , sizeof(CmdAlias) * MAXALIASES);

                if (!ptr) {
                    MAXALIASES /= 2;
                    printf("Failed to resize aliases.\n");

                    fclose(file);
                    free(Path);
                    free(line);

                    FreeAliases();

                    return;
                }

                Aliases = ptr;
            }

            Aliases[ALIASCOUNT++] = alias;
        }
    }

    free(Path);
    fclose(file);
    free(line);
}