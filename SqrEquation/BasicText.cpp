#include <TXLib.h>
#include "BasicText.h"

void ClearBuffer()
{
    while (getchar() != '\n');
}

void GetLine(char *ans)
{
    assert(ans);

    fgets(ans, MAXWORDLEN, stdin);
    int i = 0;
    while(ans[i] != '\n' && i < MAXWORDLEN) {
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
        slowPrintf(RED "NO FILE TO READ FROM\n" COLOR_RESET);
        return false;
    }

    fclose(file);
    return true;
}

void slowPrintf(const char *output, ...)
{
    va_list args;
    va_start(args, output);

    char buf[100] = {};
    vsprintf(buf, output, args);

    for (int i = 0; buf[i] != '\0'; i++) {
        putchar(buf[i]);
        txSleep(5);
    }
}
