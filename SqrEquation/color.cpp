#include "color.h"

void ChangeColorSettings(const char **InColor, const char **OutColor)
{
    assert(InColor != NULL);
    assert(OutColor != NULL);

    printf("Write a colour you want for input(more for list): ");
    *InColor = ChangeColor();

    printf("Write a colour you want for output(more for list): ");
    *OutColor = ChangeColor();
}

const char *ChangeColor()
{
    char ans[MAXWORD] = {};

    while (true) {
        GetLine(ans);
        for (int i = 0; i < COLORNUM; i++) {
            if (strcmp(color[i].name, ans) == 0) {
                return color[i].code;
            }
        }
        if (strcmp("more", ans) == 0) {
            ShowColors();
            printf("So, your choise: ");
        }
        else {
            printf("Sorry, try again: ");
        }
    }
    return COLOR_RESET;
}

void ShowColors()
{
    for (int i = 0; i < COLORNUM; i++) {
        printf("%s", color[i].code);
        printf("%s", color[i].name);
        printf("\n");
    }
}
