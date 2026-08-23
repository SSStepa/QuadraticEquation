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
    printf("%sGood tests are %d of %d\n" COLOR_RESET, resultColor, nGoodTests, nTests);
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
                if ((IsZero(x1 - test.x1Exp) && IsZero(x2 - test.x2Exp)) || (IsZero(x1 - test.x2Exp) && IsZero(x2 - test.x1Exp)))
                    return 1;
                TestErrorMessage(test, nRoots, x1, x2);
                return 0;
            
            default:
                printf("WRONG TYPE OF OUTPUT");
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

    printf(RED "Testing FAILED:\n" COLOR_RESET);
    printf("Input params: a = %lg b = %lg c = %lg\n\n",test.a, test.b, test.c);

    // не совпало количество корней
    if (test.nRootsExp == NO_ROOTS || test.nRootsExp == INF_ROOTS || nRoots != test.nRootsExp){
        if (test.nRootsExp == NO_ROOTS)
            printf("Expected: No roots\n");
        else if(test.nRootsExp == INF_ROOTS)
            printf("Expected: Inf roots\n");
        else 
            printf("Expected: %d roots\n", test.nRootsExp);
        printf("Got:      %d  roots\n", nRoots);
    
    // неверный 1 корень
    } else if (nRoots == ONE_ROOT){
        printf("One root\n");
        printf("Expected: x1 = %lg\n", test.x1Exp);
        printf("Got:      x1 = %lg\n", x1);

    // неверные 2 корня
    } else {
        printf("Two roots\n");
        printf("Expected: x1 = %lg, x2 = %lg\n", test.x1Exp, test.x2Exp);
        printf("Got:      x1 = %lg, x2 = %lg\n", x1, x2);
    }
}

int GetTestcase(int testNum, TestCase *test)
{
    assert(isfinite(testNum));
    assert(test != 0);

    FILE *file = fopen("Testcases.txt", "r");

    if (file == NULL) {
        printf(RED "NO FILE WITH TESTS\n" COLOR_RESET);
        return NULL;
    }

    // на нужную строку
    char buf[100] = {};
    while (testNum-- > 0) {
        fgets(buf, sizeof(buf), file);
    } 

    if (fscanf( file, "%lg %lg %lg %d %lg %lg", 
                &(test -> a), &(test -> b), &(test -> c),
                &(test -> nRootsExp), &(test -> x1Exp), &(test -> x2Exp)) != EOF)

        return 1;
    else 
        return NULL;
}

