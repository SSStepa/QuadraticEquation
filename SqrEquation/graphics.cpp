#include <TXLib.h>
#include "graphics.h"


void BuiltGraphic(double a, double b, double c)
{
    int mult = 1;

    double X_main = -b/(2*a);
    double Y_main = -(a*X_main*X_main + b*X_main + c);

    while (X_main > FIELD_X/4*mult || Y_main > FIELD_Y/4*mult) {
        mult *=2;
    }

    // Поле
    txCreateWindow(FIELD_X, FIELD_Y);
    txSetFillColor(TX_BLACK);
    txClearConsole();

    txSetColor(TX_WHITE);
    txSelectFont("Calibri", TEXTHIGN);
    txLine(0, FIELD_Y/2, FIELD_X, FIELD_Y/2);
    txLine(FIELD_X/2, 0, FIELD_X/2, FIELD_Y);

    txSetTextAlign(TA_RIGHT);
    for (unsigned int i = TEXTSTART; i <= FIELD_X - TEXTSTART; i += TEXTSTART) {
        char lable[MAXWORDLEN] = {};
        txLine(i, FIELD_Y/2 - DELTA/2, i, FIELD_Y/2 + DELTA/2);
        GetStrFromInt(lable, mult*(i-FIELD_X/2));
        txDrawText(i - TEXTMAXLEN/2, FIELD_Y/2 + DELTA, i + TEXTMAXLEN/2, FIELD_Y/2 + DELTA + TEXTHIGN, lable);
    }

    for (unsigned int i = TEXTSTART; i <= FIELD_Y - TEXTSTART; i += TEXTSTART) {
        char lable[MAXWORDLEN] = {};
        txLine(FIELD_X/2 - DELTA/2, i, FIELD_X/2 + DELTA/2, i);
        GetStrFromInt(lable, mult*(i-FIELD_Y/2));
        txDrawText(FIELD_X/2 - TEXTMAXLEN - DELTA, i - TEXTHIGN/2, FIELD_X/2 - DELTA, i + TEXTHIGN/2, lable);
    }
    txSetTextAlign();
    txBegin();
    for(double x = -FIELD_X/2; x <= FIELD_X; x+=STEP){
        double y = -(a*x*x + b*x + c);
        if (y > -400 || y < 400) {
            txSetPixel(FIELD_X/2 + x, FIELD_Y/2 + y, TX_LIGHTRED);
        }
    }
    txEnd();
    txBegin();
}
