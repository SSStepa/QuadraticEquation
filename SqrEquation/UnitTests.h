#ifndef __UNITTESTS__
#define __UNITTESTS__

#include <stdio.h>
#include <assert.h>

#include "Solvers.h"
#include "structs.h"
#include "color.h"

void RunTests();
int RunTest(double a, double b, double c, int nRootsExp, double x1Exp, double x2Exp);
void TestErrorMessage(
    double a, double b, double c,
    int nRootsExp, double x1Exp, double x2Exp, 
    int nRoots, double x1, double x2
);
int GetTestcase(int testNum, double *a, double *b, double *c, int *nRoots, double *x1, double *x2);

#endif
