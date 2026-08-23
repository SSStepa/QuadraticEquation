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
