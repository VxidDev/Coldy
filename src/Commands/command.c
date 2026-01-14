#include "../../include/Commands/command.h"

#include <stdlib.h>

size_t AmountOfBuiltIns = 3;
Command *BuiltInCommands[3];

void InitBuiltInCommands() {
    BuiltInCommands[0] = &Echo;
    BuiltInCommands[1] = &Exit;
    BuiltInCommands[2] = &Clear;
}