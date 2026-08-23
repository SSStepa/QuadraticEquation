#include "UserCon.h"


void ShowAns(Roots NumRoots, double x1, double x2, const char *OutColor)
{
    assert(isfinite(x1));
    assert(isfinite(x2));
    assert(OutColor != NULL);
    
    switch (NumRoots) {
        case NO_ROOTS:
            printf("%sNo Roots!" COLOR_RESET, OutColor);
            break;

        case ONE_ROOT:
            printf("%sOne root: %lg" COLOR_RESET, OutColor, x1);
            break;

        case TWO_ROOTS:
            printf("%sTwo Roots: %lg %lg" COLOR_RESET, OutColor, x1, x2);
            break;

        case INF_ROOTS:
            printf("%sThere are infinity Roots" COLOR_RESET, OutColor);
            break;

        default:
            printf("%sSorry, input is incorrect!" COLOR_RESET, OutColor);
    };

    printf("\n");
}

void GetCoeffs(double *a, double *b, double *c, const char *InColor, const char *OutColor)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(InColor != NULL);
    assert(OutColor != NULL);

    printf("%sEnter a: " COLOR_RESET, OutColor);
    GetCoeff(a, InColor, OutColor);

    printf("%sEnter b: " COLOR_RESET, OutColor);
    GetCoeff(b, InColor, OutColor);

    printf("%sEnter c: " COLOR_RESET, OutColor);
    GetCoeff(c, InColor, OutColor);
}

bool SolveEquaAgain(const char *InColor, const char *OutColor)
{
    assert(InColor != NULL);
    assert(OutColor != NULL);

    char ans = 0;

    printf("%sIf you want to finish write 0, otherwise anything else: " COLOR_RESET, OutColor);

    printf("%s", InColor);
    scanf("%c" , &ans);
    printf(COLOR_RESET);

    if (ans != '\n')
        ClearBuffer(); // для нового случая буфер пуст

    if (ans == '0') {
        return false;
    }
    else {
        return true;
    }
}

void GetCoeff(double *a, const char *InColor, const char *OutColor)
{
    assert(a != NULL);
    assert(InColor != NULL);
    assert(OutColor != NULL);

    printf("%s", InColor);
    while (scanf("%lg", a) != 1){
        printf("%sSorry, your input is wrong!!!!\n" COLOR_RESET, OutColor);
        printf("%sTry again: " COLOR_RESET, OutColor);

        printf("%s", InColor); // подготовились к следующему вводу

        ClearBuffer();
    }

    ClearBuffer();
    printf(COLOR_RESET);
}
