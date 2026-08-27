#ifndef __USERCON__
#define __USERCON__

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#include "structs.h"
#include "color.h"
#include "BasicText.h"
#include "Solvers.h"
#include "graphics.h"

void ShowAns(Roots NumRoots, double x1, double x2, const char *OutColor);

void GetUserCoeffs(double *a, double *b, double *c, const char *, const char *);
void GetUserCoeff(double *a, const char *, const char *);
WORK_RESULT GetFileCoeffs(double *a, double *b, double *c, FILE *file);

bool SolveEquaAgain(const char *InColor, const char *OutColor);

WORK_RESULT WorkWithFileInput(char *fileToRead, const char *OutColor, bool Graphic);
WORK_RESULT WorkWithUserInput(const char *InColor, const char *OutColor, bool Graphic);

#endif
