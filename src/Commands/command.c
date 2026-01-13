#include "../../include/Commands/command.h"

#include <stdlib.h>

size_t AmountOfBuiltIns = 2;
Command *BuiltInCommands[2];

void InitBuiltInCommands() {
    BuiltInCommands[0] = &Echo;
    BuiltInCommands[1] = &Exit;
}