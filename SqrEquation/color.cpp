#include "color.h"


void AskColorSettings(const char **InColor, const char **OutColor)
{
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
    char ans[] = "\n";

    printf("Write a colour you want for input(more for list): ");
    GetLine(ans);
    *InColor = ChangeColor(ans);

    printf("Write a colour you want for output(more for list): ");
    GetLine(ans);
    *OutColor = ChangeColor(ans);
}

const char *ChangeColor(char *ans)
{
    for (int i = 0; i < COLORNUM; i++) {
        if (strcmp(color[i].name, ans) == 0) {
            return color[i].code;
        }
    }
    if (strcmp("more", ans) == 0) {
        ShowColors();
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
    fgets(ans, MAXWORD, stdin);
    int i = 0;
    while(ans[i] != '\n') {
        i++;
    }
    ans[i] = '\0';
}
