#include "main.h"


int main()
{
    printf("Hi! I can help you to solve your square equation \n");
    printf("form of equation ax^2 + bx + c = 0\n");

    double a = 0, b = 0, c = 0; // coefficients
    double x1 = 0, x2 = 0; // Roots

    do {
        GetCoeffs(&a, &b, &c);

        Roots NumRoots = SquareFind(a, b, c, &x1, &x2);
        ShowAns(NumRoots, x1, x2);

    } while (SolveEquaAgain());

    return 0;
}
