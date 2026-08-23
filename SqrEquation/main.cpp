#include "main.h"

// с теста - в массив, упорядоичит и потом сравнить

int main(int argc, char *argv[])
{
    printf("Hi! I can help you to solve your square equation \n");
    printf("form of equation ax^2 + bx + c = 0\n");

    const char *OutColor = COLOR_RESET;
    const char *InColor = COLOR_RESET;

    if (argc != 1) {
        int status = FlagsCheck(argc, argv, &InColor, &OutColor);
        if (status != 0) return 1;
    }
    
    double a = NAN, b = NAN, c = NAN; // Коэфиценты
    double x1 = NAN, x2 = NAN; // Корни

    do {
        GetCoeffs(&a, &b, &c, InColor, OutColor);

        Roots NumRoots = SquareFind(a, b, c, &x1, &x2);
        ShowAns(NumRoots, x1, x2, OutColor);

    } while (SolveEquaAgain(InColor, OutColor));

    return 0;
}
