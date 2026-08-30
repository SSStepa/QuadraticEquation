#include "../headers/UnitTests.h"

void RunTests()
{
    int nTests = 0;
    int nGoodTests = 0;


    FILE *file = fopen("./texts/Testcases.txt", "r");
    if (file == NULL) {
        slowPrintf(RED "NO FILE WITH TESTS\n" COLOR_RESET);
    } else {
        TestCase *tests = GetTestcases(&nTests, file);
        for (int test = 0; test < nTests; test++) {
            if (RunOneTest(tests[test]) == ALL_GOOD) 
                nGoodTests++;
        }

        free(tests);
    }

    fclose(file);

    const char *resultColor = (nGoodTests == nTests && nTests != 0) ? GRN : RED;
    slowPrintf("%sGood tests are %d of %d\n" COLOR_RESET, resultColor, nGoodTests, nTests);
}

WORK_RESULT RunOneTest(TestCase test)
{
    assert(isfinite(test.a));
    assert(isfinite(test.b));
    assert(isfinite(test.c));

    double x1 = NAN, x2 = NAN;
    int nRoots = (int) SquareFind(test.a, test.b, test.c, &x1, &x2);

    if (nRoots == test.nRootsExp) {
        switch (nRoots) {
            case NO_ROOTS: case INF_ROOTS:
                if (!isnan(x1) && !isnan(x2)) {
                    TestErrorMessage(test, nRoots, x1, x2);  
                    return SMTH_BAD; 
                }
                return ALL_GOOD;
            
            case ONE_ROOT:
                if (!isnan(x2)) {
                    TestErrorMessage(test, nRoots, x1, x2);  
                    return SMTH_BAD; 
                }
                if (IsZero(x1 - test.x1Exp) || IsZero(x1 - test.x2Exp))
                    return ALL_GOOD;
                TestErrorMessage(test, nRoots, x1, x2);
                return SMTH_BAD;
            
            case TWO_ROOTS:
                if ((IsZero(x1 - test.x1Exp) && IsZero(x2 - test.x2Exp)))
                    return ALL_GOOD;
                TestErrorMessage(test, nRoots, x1, x2);
                return SMTH_BAD;
            
            default:
                slowPrintf("WRONG TYPE OF OUTPUT");
                return SMTH_BAD;
        }
    }
    TestErrorMessage(test, nRoots, x1, x2);
    return SMTH_BAD;
}

void TestErrorMessage(TestCase test, int nRoots, double x1, double x2)
{
    assert(isfinite(test.a));
    assert(isfinite(test.b));
    assert(isfinite(test.c));

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

TestCase *GetTestcases(int *nTests, FILE *file)
{
    assert(nTests != NULL);
    assert(file != NULL);

    fseek(file, 0L, SEEK_END);
    int length = ftell(file);
    fseek(file, 0L, SEEK_SET);

    TestCase *tests = (TestCase *) calloc(STARTMEMORY, sizeof(TestCase));

    char *file_text = (char *) calloc(length, sizeof(char));
    char *first_file = file_text;
    if (file_text == NULL) {
        printf(RED "NOT ENOUGHT MAMORY" COLOR_RESET);
        return tests;
    }

    fread(file_text, sizeof(char), length, file);

    *nTests = STARTMEMORY;
    if (tests == NULL)
        printf(RED "NOT ENOUGHT MAMORY" COLOR_RESET);
    
    int ind = 0;
    int lineInd = 0;
    while (sscanf(file_text, 
        "%lg %lg %lg %d %lg %lg%n", 
        &tests[ind].a, &tests[ind].b, &tests[ind].c, 
        &tests[ind].nRootsExp, &tests[ind].x1Exp, &tests[ind].x2Exp, &lineInd) == 6) {  

            SortArgs(&tests[ind].x1Exp, &tests[ind].x2Exp);

            file_text = &file_text[lineInd];
            (ind)++;
            if (ind == *nTests) {
                *nTests *= 2;
                TestCase *temp = (TestCase *) realloc(tests, sizeof(TestCase)*(*nTests));
                if (temp == NULL) {
                    printf(RED "NOT ENOUGHT MAMORY" COLOR_RESET); // AHAHAHAHA ЭНОХТ МАМОРИ
                    return tests;
                } else 
                    tests = temp;
                
            }
        }
    free(first_file);
    *nTests = ind;
    tests = (TestCase *) realloc(tests, sizeof(TestCase)*ind);
    return tests;
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
