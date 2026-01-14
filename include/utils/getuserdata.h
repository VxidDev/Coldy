#ifndef GETUSERDATA_H
#define GETUSERDATA_H

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

char* GetUser();
char* GetUserPath();
char* GetHost();
char* GetPrompt();

#endif