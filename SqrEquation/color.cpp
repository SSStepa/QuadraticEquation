#include "color.h"

void ChangeColorSettings(const char **InColor, const char **OutColor)
{
    assert(InColor  != NULL);
    assert(OutColor != NULL);

    slowPrintf("Write a colour you want for input (more for list): ");
    *InColor = ChangeColor();

    slowPrintf("Write a colour you want for output (more for list): ");
    *OutColor = ChangeColor();
}

const char *ChangeColor()
{
    char ans[MAXWORDLEN] = {};

    while (true) {
        GetLine(ans);
        for (int i = 0; i < COLORNUM; i++) {
            if (strcmp(color[i].name, ans) == 0) {
                return color[i].code;
            }
        }
        if (strcmp("more", ans) == 0) {
            ShowColors();
            slowPrintf("So, your choise: ");
        }
        else {
            slowPrintf("Sorry, try again: ");
        }
    }
    return COLOR_RESET;
}

void ShowColors()
{
    for (int i = 0; i < COLORNUM; i++) {
        slowPrintf("%s", color[i].code);
        slowPrintf("%s", color[i].name);
        slowPrintf("\n");
    }
}
