#include "../../include/Commands/command.h"

#include <stdlib.h>

size_t AmountOfBuiltIns = 5;
Command *BuiltInCommands[5];

void InitBuiltInCommands() {
    BuiltInCommands[0] = &Echo;
    BuiltInCommands[1] = &Exit;
    BuiltInCommands[2] = &Clear;
    BuiltInCommands[3] = &List;
    BuiltInCommands[4] = &Read;
}