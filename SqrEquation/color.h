#ifndef __COLOR__
#define __COLOR__

#include <string.h>

#include "ColorsList.h"
#include "UserCon.h"
#include "BasicText.h"
#include "structs.h"

struct Colors {
    const char *name;
    const char *code;
};

#define COLORNUM 9

const Colors color[] = {
    {"default",   COLOR_RESET},
    {"black",     BLK},
    {"red",       RED},
    {"green",     GRN},
    {"yellow",    YEL},
    {"blue",      BLU},
    {"purple",    MAG},
    {"turquoise", CYN},
    {"white",     WHT},
};

void ChangeColorSettings(const char **InColor, const char **OutColor);
const char *ChangeColor();
void ShowColors();

#endif
