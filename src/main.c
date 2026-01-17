#include "../include/input/input.h"
#include "../include/parser/parser.h"
#include "../include/Commands/command.h"
#include "../include/coldy.h"
#include "../include/Commands/builtIns/alias.h"

#include <stdbool.h>
#include <stdio.h>

bool _RUNNING = true;

int main() {
    InitBuiltInCommands();
    InitUserData();
    InitAliases();

    while (_RUNNING) {
        char *userInput = UserInput();

        if (!userInput) {
            perror("err @ userInput() -> GOT NULL");
            return 1;
        }

        ParseInput(userInput);

        free(userInput);
    } 

    free(HOSTNAME);
    free(PROMPT);
    FreeAliases();

    return 0;
}