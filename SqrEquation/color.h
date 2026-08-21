#ifndef __COLOR__
#define __COLOR__

#include <string.h>

#include "ColorsList.h"
#include "UserCon.h"

struct Colors {
    const char *name;
    const char *code;
};

#define COLORNUM 9
static Colors color[] = {
    {"default", COLOR_RESET},
    {"black", BLK},
    {"red", RED},
    {"green", GRN},
    {"yellow", YEL},
    {"blue", BLU},
    {"purple", MAG},
    {"turquoise", CYN},
    {"white", WHT},
};

void AskColorSettings(const char **InColor, const char **OutColor);
void ChangeColorSettings(const char **InColor, const char **OutColor);
const char *ChangeColor(char *);
void ShowColors();

#endif
