#ifndef __USERCON__
#define __USERCON__

#include <stdio.h>
#include <stdbool.h>

#include  "structs.h"

void ClearBuffer();

void ShowAns(Roots NumRoots, double x1, double x2);

void GetCoeffs(double *a, double *b, double *c);
void GetCoeff(double *a);

bool SolveEquaAgain();

#endif
