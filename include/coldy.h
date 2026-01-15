#ifndef COLDY_H
#define COLDY_H

#include "Commands/command.h"
#include <stdlib.h>

extern Command Echo;

extern size_t AmountOfBuiltIns;
extern Command *BuiltInCommands[];
void InitUserData();

extern char* HOSTNAME;
extern char* USERNAME;
extern char* PROMPT;
extern char* USERPATH;
extern char* CURRDIR;

#endif
