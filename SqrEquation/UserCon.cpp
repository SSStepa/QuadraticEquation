#include "UserCon.h"


void ShowAns(Roots NumRoots, double x1, double x2, const char *OutColor)
{
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

void GetUserCoeffs(double *a, double *b, double *c, const char *InColor, const char *OutColor)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(InColor != NULL);
    assert(OutColor != NULL);

    printf("%sEnter a: " COLOR_RESET, OutColor);
    GetUserCoeff(a, InColor, OutColor);

    printf("%sEnter b: " COLOR_RESET, OutColor);
    GetUserCoeff(b, InColor, OutColor);

    printf("%sEnter c: " COLOR_RESET, OutColor);
    GetUserCoeff(c, InColor, OutColor);
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

void GetUserCoeff(double *a, const char *InColor, const char *OutColor)
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

int GetFileCoeffs(double *a, double *b, double *c, char *fileName, int fileLine)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(fileName != NULL);
    assert(isfinite(fileLine));

    FILE *file = fopen(fileName, "r");

    // на нужную строку
    char buf[100] = {};
    while (fileLine-- > 0) {
        fgets(buf, sizeof(buf), file);
    }
    int st = 0;
    if ((st = fscanf(file, "%lg %lg %lg", a, b, c)) == EOF || st != 3) {
        if (st == EOF)
            printf(GRN "END OF READING\n" COLOR_RESET);
        else
            printf(RED "WRONG SYMBOLS IN FILE\n" COLOR_RESET);
        return 1;
    }
    return 0;
}

int WorkWithFileInput(char *fileToRead, const char *OutColor)
{
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    static int fileLine = 0;

    int status = GetFileCoeffs(&a, &b, &c, fileToRead, fileLine++);
    if (status != 0) return 1;

    Roots NumRoots = SquareFind(a, b, c, &x1, &x2);
    ShowAns(NumRoots, x1, x2, OutColor);
    return 0;
}

int WorkWithUserInput(const char *InColor, const char *OutColor)
{
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;

    GetUserCoeffs(&a, &b, &c, InColor, OutColor);

    Roots NumRoots = SquareFind(a, b, c, &x1, &x2);
    ShowAns(NumRoots, x1, x2, OutColor);
    return 0;
}
