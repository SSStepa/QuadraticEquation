#include "UserCon.h"


void ShowAns(Roots NumRoots, double x1, double x2, const char *OutColor)
{
    assert(OutColor != NULL);
    
    switch (NumRoots) {
        case NO_ROOTS:
            slowPrintf("%sNo Roots!" COLOR_RESET, OutColor);
            break;

        case ONE_ROOT:
            slowPrintf("%sOne root: %lg" COLOR_RESET, OutColor, x1);
            break;

        case TWO_ROOTS:
            slowPrintf("%sTwo Roots: %lg %lg" COLOR_RESET, OutColor, x1, x2);
            break;

        case INF_ROOTS:
            slowPrintf("%sThere are infinity Roots" COLOR_RESET, OutColor);
            break;

        default:
            slowPrintf("%sSorry, input is incorrect!" COLOR_RESET, OutColor);
    };

    slowPrintf("\n");
}

void GetUserCoeffs(double *a, double *b, double *c, const char *InColor, const char *OutColor)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(InColor != NULL);
    assert(OutColor != NULL);

    slowPrintf("%sEnter a: " COLOR_RESET, OutColor);
    GetUserCoeff(a, InColor, OutColor);

    slowPrintf("%sEnter b: " COLOR_RESET, OutColor);
    GetUserCoeff(b, InColor, OutColor);

    slowPrintf("%sEnter c: " COLOR_RESET, OutColor);
    GetUserCoeff(c, InColor, OutColor);
}

bool SolveEquaAgain(const char *InColor, const char *OutColor)
{
    assert(InColor != NULL);
    assert(OutColor != NULL);

    char ans = 0;

    slowPrintf("%sIf you want to finish write 0, otherwise anything else: " COLOR_RESET, OutColor);

    slowPrintf("%s", InColor);
    scanf("%c" , &ans);
    slowPrintf(COLOR_RESET);

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

    slowPrintf("%s", InColor);
    bool rightInput = false;
    while (!rightInput){
        char buf[MAXWORDLEN] = {};
        if (scanf("%lg", a) == 1) {
            fgets(buf, MAXWORDLEN, stdin);
            int i = 0;
            for (i = 0; buf[i] != '\0'; i++) 
                if(!isspace(buf[i])) break;
            if (buf[i] == '\0') break;

        }
        else
            fgets(buf, MAXWORDLEN, stdin);
        slowPrintf("%sSorry, your input is wrong!!!!\n" COLOR_RESET, OutColor);
        slowPrintf("%sTry again: " COLOR_RESET, OutColor);

        slowPrintf("%s", InColor); // подготовились к следующему вводу
    }

    slowPrintf(COLOR_RESET);
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
            slowPrintf(GRN "END OF READING\n" COLOR_RESET);
        else
            slowPrintf(RED "WRONG SYMBOLS IN FILE\n" COLOR_RESET);
        return 1;
    }
    return 0;
}

int WorkWithFileInput(char *fileToRead, const char *OutColor, bool Graphic)
{
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    static int fileLine = 0;

    int status = GetFileCoeffs(&a, &b, &c, fileToRead, fileLine++);
    if (status != 0) return 1;

    if (Graphic) {
        BuiltGraphic(a, b, c);
    }
    else {
        Roots NumRoots = SquareFind(a, b, c, &x1, &x2);
        ShowAns(NumRoots, x1, x2, OutColor);
    }
    return 0;
}

int WorkWithUserInput(const char *InColor, const char *OutColor, bool Graphic)
{
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;

    GetUserCoeffs(&a, &b, &c, InColor, OutColor);

    if (Graphic) {
        BuiltGraphic(a, b, c);
    }
    else {
        Roots NumRoots = SquareFind(a, b, c, &x1, &x2);
        ShowAns(NumRoots, x1, x2, OutColor);
    }
    return 0;
}
