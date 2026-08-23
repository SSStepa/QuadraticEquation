#ifndef __USERCON__
#define __USERCON__

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "structs.h"
#include "color.h"
#include "BasicText.h"

void ShowAns(Roots NumRoots, double x1, double x2, const char *OutColor);

void GetCoeffs(double *a, double *b, double *c, const char *, const char *);
void GetCoeff(double *a, const char *, const char *);

bool SolveEquaAgain(const char *InColor, const char *OutColor);

#endif
