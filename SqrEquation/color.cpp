#include "color.h"


void AskColorSettings(const char **InColor, const char **OutColor)
{
    assert(InColor != NULL);
    assert(OutColor != NULL);

    char ans = 0;
    printf("If you want to change color settings press s: ");
    scanf("%c" , &ans);

    if (ans != '\n')
        ClearBuffer();

    if (ans == 's') {
        ChangeColorSettings(InColor, OutColor);
    }
}

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

void GetLine(char *ans)
{
    assert(ans);

    fgets(ans, MAXWORD, stdin);
    int i = 0;
    while(ans[i] != '\n' && i < MAXWORD) {
        i++;
    }
    if (ans[i] != '\n')
        ClearBuffer();
    ans[i] = '\0';

}
