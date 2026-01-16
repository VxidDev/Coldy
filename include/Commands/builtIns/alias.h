#ifndef ALIAS_H
#define ALIAS_H

#include <stdbool.h>
#include <stddef.h>

typedef struct CmdAlias {
    char* name;
    char* cmd;
} CmdAlias;

extern size_t CURRALIAS;
extern size_t ALIASCOUNT;
extern CmdAlias *Aliases;

bool CMD_alias(void* data);
void InitAliases();
void FreeAliases();

#endif