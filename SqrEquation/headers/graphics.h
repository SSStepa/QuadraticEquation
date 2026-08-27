#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <assert.h>

#include "BasicText.h"
#include "Solvers.h"

const int FIELD_X = 1000;
const int FIELD_Y = 800;
const int DELTA = 5;
const double STEP = 0.001;

const int TEXTHIGN = 15;
const int TEXTMAXLEN = 50;
const int TEXTSTART = 50;

void BuiltGraphic(double a, double b, double c);

#endif