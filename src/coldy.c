#include "../include/coldy.h"
#include "../include/utils/getuserdata.h"

char* USERNAME = NULL;
char* HOSTNAME = NULL;
char* USERPATH = NULL;
char* PROMPT = NULL;
char* CURRDIR = NULL;

void InitUserData() {
    USERNAME = GetUser();
    HOSTNAME = GetHost(); // Needs to be freed!
    USERPATH = GetUserPath();
    PROMPT = GetPrompt(); // Needs to be freed!
    CURRDIR = GetCurrDir(); // Needs to be freed!
}