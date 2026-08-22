#include "UnitTests.h"

void RunTests()
{
    int goodTests = 0;

    double a = 0;
    double b = 0;
    double c = 0;
    Roots nRootsExp = INF_ROOTS;
    double x1Exp = 0;
    double x2Exp = 0;

    goodTests += RunTest(a, b, c, nRootsExp, x1Exp, x2Exp);

    printf("Good tests are: %d\n", goodTests);
}

int RunTest(double a, double b, double c, Roots nRootsExp, double x1Exp, double x2Exp)
{
    double x1 = 0, x2 = 0;

    Roots nRoots = SquareFind(a, b, c, &x1, &x2);
    if (nRoots == nRootsExp){
        switch (nRoots) {
            case NO_ROOTS: case INF_ROOTS:
                return 1;
            case ONE_ROOT:
                if (IsZero(x1 - x1Exp) || IsZero(x1 - x2Exp))
                    return 1;
                TestErrorMessage(a, b, c, nRootsExp, x1Exp, x2Exp, nRoots, x1, x2);
                return 0;
            case TWO_ROOTS:
                if ((IsZero(x1 - x1Exp) && IsZero(x2 - x2Exp)) || (IsZero(x1 - x2Exp) && IsZero(x2 - x1Exp)))
                    return 1;
                TestErrorMessage(a, b, c, nRootsExp, x1Exp, x2Exp, nRoots, x1, x2);
                return 0;
            default:
                printf("WRONG TYPE OF OUTPUT");
                return 0;
        }
    }
    TestErrorMessage(a, b, c, nRootsExp, x1Exp, x2Exp, nRoots, x1, x2);
    return 0;

}

void TestErrorMessage(double a, double b, double c, 
                    Roots nRootsExp, double x1Exp, double x2Exp, 
                    Roots nRoots, double x1, double x2)
{
    printf(RED "Testing FAILED:\n" COLOR_RESET);
    printf("Input params: a = %lg b = %lg c = %lg\n\n", a, b, c);

    // не совпало количество корней
    if (nRootsExp == NO_ROOTS || nRootsExp == INF_ROOTS || nRoots != nRootsExp){
        if (nRootsExp == NO_ROOTS)
            printf("Expected: No roots\n");
        else if(nRootsExp == INF_ROOTS)
            printf("Expected: Inf roots\n");
        else 
            printf("Expected: %d roots\n", nRootsExp);
        printf("Got:      %d  roots\n", nRoots);
    
    // неверный 1 корень
    } else if (nRoots == ONE_ROOT){
        printf("One root\n");
        printf("Expected: x1 = %lg\n", x1Exp);
        printf("Got:      x1 = %lg\n", x1);

    // неверные 2 корня
    } else {
        printf("Two roots\n");
        printf("Expected: x1 = %lg, x2 = %lg\n", x1Exp, x2Exp);
        printf("Got:      x1 = %lg, x2 = %lg\n", x1, x2);
    }
}
 