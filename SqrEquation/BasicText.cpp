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

    char buf[MAXPRINTF] = {};
    vsprintf(buf, output, args);

    for (int i = 0; buf[i] != '\0'; i++) {
        int port = rand() % 4 + 3;
        for (int j = 0; j < port; j++) {
            putchar(buf[i]);
            txSleep(50);
            
            i++;
        }
        i--;
        txSleep(rand() % 120 + 70);
    }

    va_end(args);
}

void GetStrFromInt(char lable[], int num)
{
    int i   = 0;
    int ind = 0;

    if (num < 0) {
        lable[0] = '-';
        i++;
        ind++;
    }
    num = (int) fabs(num);
    while (num > 0) {
        lable[ind++] = (char)( num % 10 + int('0'));
        num /= 10;
    }
    ind--;
    for (; i < ind; i++, ind--) {
        char el  = lable[i];
        lable[i] = lable[ind];
        lable[ind] = el;

    }
}
