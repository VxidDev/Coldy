#include "../../include/Commands/command.h"

#include <stdlib.h>

size_t AmountOfBuiltIns = 4;
Command *BuiltInCommands[4];

void InitBuiltInCommands() {
    BuiltInCommands[0] = &Echo;
    BuiltInCommands[1] = &Exit;
    BuiltInCommands[2] = &Clear;
    BuiltInCommands[3] = &List;
}