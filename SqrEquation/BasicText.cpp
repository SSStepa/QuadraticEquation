#include "BasicText.h"


void ClearBuffer()
{
    while (getchar() != '\n');
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

bool FileIsValid(char *fileName)
{
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf(RED "NO FILE TO READ FROM\n" COLOR_RESET);
        return false;
    }

    fclose(file);
    return true;
}
