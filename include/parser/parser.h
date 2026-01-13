#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include <stddef.h>

bool ParseInput(char *input);
char** SplitString(char* string);

#endif