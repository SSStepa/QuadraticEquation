#ifndef __UNITTESTS__
#define __UNITTESTS__

#include <stdio.h>
#include <assert.h>

#include "Solvers.h"
#include "structs.h"
#include "color.h"

struct TestCase {
    double a, b, c;
    int nRootsExp;
    double x1Exp, x2Exp;
};

void RunTests();
int RunOneTest(TestCase test);
void TestErrorMessage(TestCase test, int nRoots, double x1, double x2);
int GetTestcase(int testNum, TestCase *test);

#endif
