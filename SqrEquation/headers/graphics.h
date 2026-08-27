#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <assert.h>

#include "BasicText.h"
#include "Solvers.h"
#include "structs.h"

const int A = 0x41;
const int S = 0x53;
const int D = 0x44;
const int W = 0x57;
const int E = 0x45;
const int R = 0x52;

const int FIELD_X = 1000;
const int FIELD_Y = 800;
const int DELTA = 5;
const double STEP = 0.001;
const int MOOVE = 5;

const int TEXTHIGN = 15;
const int TEXTMAXLEN = 50;
const int TEXTSTART = 50;

struct Point {
    int x;
    int y;
};

void BuiltGraphic(double a, double b, double c);
void PaintGraphic(double mult, double a, double b, double c, Point startPoint);
void SettingWindow();
WORK_RESULT CheckButtonIsPressed(Point *StartPoint, double *mult);

#endif