#include "main.h"

int main(int argc,char *argv[])
{
    printf("Hi! I can help you to solve your square equation \n");
    printf("form of equation ax^2 + bx + c = 0\n");

    const char *OutColor = COLOR_RESET;
    const char *InColor = COLOR_RESET;

    if (argc != 1) {
        int status = FlagsCheck(argc, argv, &InColor, &OutColor);
        if (status != 0) return 1;
    }
    
    double a = 0, b = 0, c = 0; // Коэфиценты
    double x1 = 0, x2 = 0; // Корни

    do {
        GetCoeffs(&a, &b, &c, InColor, OutColor);

        Roots NumRoots = SquareFind(a, b, c, &x1, &x2);
        ShowAns(NumRoots, x1, x2, OutColor);

    } while (SolveEquaAgain(InColor, OutColor));

    return 0;
}
