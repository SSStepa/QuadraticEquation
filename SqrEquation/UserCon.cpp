#include "UserCon.h"


void ClearBuffer()
{
    while (getchar() != '\n');
}

void ShowAns(Roots NumRoots, double x1, double x2)
{
    switch (NumRoots) {
        case NO_ROOTS:
            printf("No Roots!");
            break;

        case ONE_ROOT:
            printf("One root: %lg", x1);
            break;

        case TWO_ROOTS:
            printf("Two Roots: %lg %lg", x1, x2);
            break;

        case INF_ROOTS:
            printf("There are infinity Roots");
            break;

        default:
            printf("Sorry, input is incorrect!");
    };

    printf("\n");
}

void GetCoeffs(double *a, double *b, double *c)
{
    printf("Enter a: ");
    GetCoeff(a);

    printf("Enter b: ");
    GetCoeff(b);

    printf("Enter c: ");
    GetCoeff(c);
}

bool SolveEquaAgain()
{
    char ans = 0;

    printf("If you want to finish write 0, otherwise anything else: ");

    ClearBuffer(); // ничего не осталось с прошлого
    scanf("%c", &ans);
    if (ans != '\n')
        ClearBuffer(); // для нового случая буфер пуст

    if (ans == '0') {
        return false;
    }
    else {
        return true;
    }
}

void GetCoeff(double *a)
{
    while (scanf("%lg", a) != 1){
        printf("Sorry, your input is wrong!!!!\n");
        printf("Try again: ");

        ClearBuffer();
    }
}
