#include "../../include/Commands/command.h"

#include <stdlib.h>

size_t AmountOfBuiltIns = 10;
Command *BuiltInCommands[10];

void InitBuiltInCommands() {
    BuiltInCommands[0] = &Echo;
    BuiltInCommands[1] = &Exit;
    BuiltInCommands[2] = &Clear;
    BuiltInCommands[3] = &List;
    BuiltInCommands[4] = &Read;
    BuiltInCommands[5] = &Write;
    BuiltInCommands[6] = &Append;
    BuiltInCommands[7] = &Changedir;
    BuiltInCommands[8] = &Alias;
    BuiltInCommands[9] = &Currdir;
}