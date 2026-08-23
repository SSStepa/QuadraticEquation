#include "Solvers.h"

//solve ax^2 + bx + c = 0
Roots SquareFind(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (IsZero(a)) {
        return LineFind(b, -c, x1);;
    }
    else { // a != 0
        if (IsZero(c)) { // x(ax+b) = 0 
            *x1 = 0;
            if (IsZero(b)) return ONE_ROOT;
            LineFind(a, -b, x2);
            if (*x2 < *x1) {
                double i = *x1;
                *x1 = *x2;
                *x2 = i;
            }
            return TWO_ROOTS;
        }

        double d = b*b - 4*a*c;

        if (IsZero(d)) {
            *x1 = (-b)/(2*a);
            return ONE_ROOT;
        }
        else if (d > 0) {
            double sqrt_d = sqrt(d);
            *x1 = (-b - sqrt_d) / (2*a);
            *x2 = (-b + sqrt_d) / (2*a);
            if (*x2 < *x1) {
                double i = *x1;
                *x1 = *x2;
                *x2 = i;
            } 
            return TWO_ROOTS;
        }
        else {
            return NO_ROOTS;
        }
    }
}

// solve ax = b
Roots LineFind(double a, double b, double *x1)
{
    assert(isfinite(a));
    assert(isfinite(b));

    assert(x1 != NULL);

    if (IsZero(a))
            return (IsZero(b))? INF_ROOTS : NO_ROOTS;
    else {
        *x1 = b/a;
        return ONE_ROOT;
    }
}

bool IsZero(double a)
{
    // assert(isfinite(a));

     return fabs(a) < EPSILON;
}
