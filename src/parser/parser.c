#include "../../include/parser/parser.h"
#include "../../include/coldy.h"
#include "../../include/Commands/command.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool ParseInput(char *input) {
    char** tokens = SplitString(input);

    if (!tokens || !tokens[0]) {
        if (tokens) {
            free(tokens);
        }
        return false;
    }

    size_t tokenCount = 0;
    while (tokens[tokenCount]) tokenCount++;

    bool ExecutedCommand = false;

    for (size_t i = 0; i < AmountOfBuiltIns; i++) {
        if (strcmp(BuiltInCommands[i]->name , tokens[0]) == 0) {
            CmdData Data = {
                tokens,
                input,

                tokenCount
            };

            BuiltInCommands[i]->cmd(&Data);
            ExecutedCommand = true;
        }
    }
    
    if (!ExecutedCommand) printf("\"%s\" not recognized as internal command.\n" , tokens[0]);

    free(tokens);

    return true;
}