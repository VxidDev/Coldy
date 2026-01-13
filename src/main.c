#include "../include/input/input.h"
#include "../include/parser/parser.h"
#include "../include/Commands/command.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool _RUNNING = true;

int main() {
    InitBuiltInCommands();

    while (_RUNNING) {
        char *userInput = UserInput();

        if (!userInput) {
            perror("err @ userInput() -> GOT NULL");
            return 1;
        }

        ParseInput(userInput);

        free(userInput);
    } 

    return 0;
}