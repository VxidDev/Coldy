#define _POSIX_C_SOURCE 200809L

#include "../../../include/utils/getuserdata.h"
#include "../../../include/coldy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* GetPrompt() {
    char *confPath = calloc(strlen(USERPATH) + 16 , sizeof(char));
    if (!confPath) {
        char *prompt = malloc(sizeof(char) * strlen("%U@%H+%P+>+") + 1);
        if(!prompt) return NULL;
        strcpy(prompt, "%U@%H+%P+>+");
        return prompt;
    }

    sprintf(confPath , "%s/.coldy.cfg" , USERPATH);

    FILE *config = fopen(confPath , "r");

    if (!config) {
        free(confPath);
        char *prompt = malloc(sizeof(char) * strlen("%U@%H+%P+>+") + 1);
        if(!prompt) return NULL;
        strcpy(prompt, "%U@%H+%P+>+");
        return prompt;
    }

    char *line = NULL;
    size_t cap = 0;
    ssize_t len;

    char *prompt = NULL;

    while ((len = getline(&line , &cap , config)) != -1) {
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        char *token = strtok(line , "=");
        if (token && strcmp(token , "PROMPT") == 0) {
            token = strtok(NULL , "=");

            if (!token) {
                break;
            }

            prompt = calloc(strlen(token) + 1, sizeof(char));
    
            if (!prompt) {
                break;
            }

            strcpy(prompt , token);
            break;
        }
    }

    if (!prompt) {
        prompt = calloc(strlen("%U@%H+%P+>+") + 1, sizeof(char));
        if (prompt) strcpy(prompt, "%U@%H+%P+>+");
    }

    free(confPath);
    fclose(config);
    free(line);

    return prompt;
}