#define _GNU_SOURCE

#include "../../include/parser/parser.h"
#include "../../include/coldy.h"
#include "../../include/Commands/command.h"
#include "../../include/Commands/builtIns/alias.h"

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

    for (size_t i = 0; i < AmountOfBuiltIns; i++) { // Check if in Built-Ins
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

    for (size_t i = 0; i < ALIASCOUNT; i++) { // Check if in Aliases
        if (strcmp(Aliases[i].name , tokens[0]) == 0) {
            char **cmd = calloc(8 , sizeof(char*));
            size_t MAXITEMS = 8;
            size_t USEDSPACE = 0;

            char **AliasTokens = SplitString(Aliases[i].cmd);

            for (size_t i = 0; AliasTokens[i]; i++) { // Add alias tokens.
                if (USEDSPACE >= MAXITEMS) {
                    MAXITEMS *= 2;
                    void* ptr = realloc(cmd , MAXITEMS * sizeof(char));

                    if (!ptr) {
                        free(cmd);
                        free(AliasTokens);
                        free(tokens);
                        printf("Failed to execute alias command.\n");
                        
                        return false;
                    }

                    cmd = ptr;
                }

                cmd[USEDSPACE++] = AliasTokens[i];
            }

            for (size_t i = 1; i < tokenCount; i++) { // add main command tokens.
                if (USEDSPACE >= MAXITEMS) {
                    MAXITEMS *= 2;
                    void* ptr = realloc(cmd , MAXITEMS * sizeof(char*));

                    if (!ptr) {
                        free(cmd);
                        free(AliasTokens);
                        free(tokens);
                        printf("Failed to execute alias command.\n");
                        
                        return false;
                    }

                    cmd = ptr;
                }

                cmd[USEDSPACE++] = tokens[i];
            }

            char* command = calloc(16 , sizeof(char));

            size_t MAXCHARS = 16;
            size_t USEDCHARS = 0;

            for (size_t i = 0; i < USEDSPACE; i++) { // build a char* from char **.
                size_t len = strlen(cmd[i]);
                for (size_t j = 0; j < len; j++) {
                    if (USEDCHARS >= MAXCHARS) {
                        MAXCHARS *= 2;
                        void* ptr = realloc(command , MAXCHARS * sizeof(char));

                        if (!ptr) {
                            free(cmd);
                            free(AliasTokens);
                            free(tokens);
                            free(command);

                            printf("Failed to execute alias command.\n");
                            
                            return false;
                        }

                        command = ptr;
                    }

                    command[USEDCHARS++] = cmd[i][j];
                }

                if (i != USEDSPACE - 1) command[USEDCHARS++] = ' ';
            }

            command[USEDCHARS] = '\0';

            ParseInput(command);

            free(cmd);
            free(command);
            free(AliasTokens);

            ExecutedCommand = true;

            }
        }

    if (!ExecutedCommand) printf("\"%s\" not recognized as internal command or alias.\n" , tokens[0]);

    free(tokens);

    return true;
}