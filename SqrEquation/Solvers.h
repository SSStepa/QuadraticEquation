#ifndef __SOLVERS__
#define __SOLVERS__


#include <math.h>
#include <assert.h>

#include "structs.h"

Roots SquareFind(
        double a, double b, double c,
        double *x1, double *x2
    );
Roots LineFind(double a, double b, double *x1);

#endif
