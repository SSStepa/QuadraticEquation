#include "UnitTests.h"

void RunTests()
{
    int nTests = 0;
    int nGoodTests = 0;

    TestCase test = {};

    while (GetTestcase(nTests, &test) != NULL) {
        nTests++;
        nGoodTests += RunOneTest(test);
    }
    const char *resultColor = (nGoodTests == nTests) ? GRN : RED;
    slowPrintf("%sGood tests are %d of %d\n" COLOR_RESET, resultColor, nGoodTests, nTests);
}

int RunOneTest(TestCase test)
{
    assert(isfinite(test.a));
    assert(isfinite(test.b));
    assert(isfinite(test.c));
    assert(isfinite(test.nRootsExp));

    double x1 = NAN, x2 = NAN;
    int nRoots = (int) SquareFind(test.a, test.b, test.c, &x1, &x2);
    if (nRoots == test.nRootsExp){
        switch (nRoots) {
            case NO_ROOTS: case INF_ROOTS:
                if (!isnan(x1) && !isnan(x2)) {
                    TestErrorMessage(test, nRoots, x1, x2);  
                    return 0; 
                }
                return 1;
            
            case ONE_ROOT:
                if (!isnan(x2)) {
                    TestErrorMessage(test, nRoots, x1, x2);  
                    return 0; 
                }
                if (IsZero(x1 - test.x1Exp) || IsZero(x1 - test.x2Exp))
                    return 1;
                TestErrorMessage(test, nRoots, x1, x2);
                return 0;
            
            case TWO_ROOTS:
                if ((IsZero(x1 - test.x1Exp) && IsZero(x2 - test.x2Exp)))
                    return 1;
                TestErrorMessage(test, nRoots, x1, x2);
                return 0;
            
            default:
                slowPrintf("WRONG TYPE OF OUTPUT");
                return 0;
        }
    }
    TestErrorMessage(test, nRoots, x1, x2);
    return 0;

}

void TestErrorMessage(TestCase test, int nRoots, double x1, double x2)
{
    assert(isfinite(test.a));
    assert(isfinite(test.b));
    assert(isfinite(test.c));
    assert(isfinite(test.nRootsExp));
    assert(isfinite(nRoots));

    slowPrintf(RED "Testing FAILED:\n" COLOR_RESET);
    slowPrintf("Input params: a = %lg b = %lg c = %lg\n\n",test.a, test.b, test.c);

    // не совпало количество корней
    if (test.nRootsExp == NO_ROOTS || test.nRootsExp == INF_ROOTS || nRoots != test.nRootsExp){
        if (test.nRootsExp == NO_ROOTS)
            slowPrintf("Expected: No roots\n");
        else if(test.nRootsExp == INF_ROOTS)
            slowPrintf("Expected: Inf roots\n");
        else 
            slowPrintf("Expected: %d roots\n", test.nRootsExp);
        slowPrintf("Got:      %d  roots\n", nRoots);
    
    // неверный 1 корень
    } else if (nRoots == ONE_ROOT){
        slowPrintf("One root\n");
        slowPrintf("Expected: x1 = %lg\n", test.x1Exp);
        slowPrintf("Got:      x1 = %lg\n", x1);

    // неверные 2 корня
    } else {
        slowPrintf("Two roots\n");
        slowPrintf("Expected: x1 = %lg, x2 = %lg\n", test.x1Exp, test.x2Exp);
        slowPrintf("Got:      x1 = %lg, x2 = %lg\n", x1, x2);
    }
}

int GetTestcase(int testNum, TestCase *test)
{
    assert(isfinite(testNum));
    assert(test != 0);

    FILE *file = fopen("Testcases.txt", "r");

    if (file == NULL) {
        slowPrintf(RED "NO FILE WITH TESTS\n" COLOR_RESET);
        return NULL;
    }

    // на нужную строку
    char buf[100] = {};
    while (testNum-- > 0) {
        fgets(buf, sizeof(buf), file);
    } 

    if (fscanf( file, "%lg %lg %lg %d %lg %lg", 
                &(test -> a), &(test -> b), &(test -> c),
                &(test -> nRootsExp), &(test -> x1Exp), &(test -> x2Exp)) != EOF) { 
        SortArgs(&(test -> x1Exp), &(test -> x2Exp));
        fclose(file);
        return 1;
    } 
    fclose(file);
    return NULL;
}

void SortArgs(double *x1Exp, double *x2Exp)
{
    if (isnan(*x1Exp) || isnan(*x2Exp)) 
        return;

    if (*x1Exp > *x2Exp) {
        double i = *x1Exp;
        *x1Exp = *x2Exp;
        *x2Exp = i;
    }
}
