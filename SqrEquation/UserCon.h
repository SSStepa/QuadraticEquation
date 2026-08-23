#ifndef __USERCON__
#define __USERCON__

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "structs.h"
#include "color.h"
#include "BasicText.h"
#include "Solvers.h"

void ShowAns(Roots NumRoots, double x1, double x2, const char *OutColor);

void GetUserCoeffs(double *a, double *b, double *c, const char *, const char *);
void GetUserCoeff(double *a, const char *, const char *);
int GetFileCoeffs(double *a, double *b, double *c, char *fileName, int fileLine);

bool SolveEquaAgain(const char *InColor, const char *OutColor);

int WorkWithFileInput(char *fileToRead, const char *OutColor);
int WorkWithUserInput(const char *InColor, const char *OutColor);

#endif
