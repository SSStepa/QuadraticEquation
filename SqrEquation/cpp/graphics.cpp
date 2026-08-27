#include <TXLib.h>
#include "../headers/graphics.h"


void BuiltGraphic(double a, double b, double c)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    int mult = 1;

    if (!IsZero(a)) {
        double X_main = -b/(2*a);
        double Y_main = a*X_main*X_main + b*X_main + c;
        while (fabs(X_main) > FIELD_X/4*mult || fabs(Y_main) > FIELD_Y/4*mult) {
            mult *=2;
        }
    }

    // Поле
    if (txWindow() == NULL)
        txCreateWindow(FIELD_X, FIELD_Y);
    txTextCursor(false);  
    txSetFillColor(TX_BLACK);
    txClearConsole();

    txSetColor(TX_WHITE);
    txSelectFont("Calibri", TEXTHIGN);
    txLine(0, FIELD_Y/2, FIELD_X, FIELD_Y/2);
    txLine(FIELD_X/2, 0, FIELD_X/2, FIELD_Y);

    // оцифровка осей
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
        GetStrFromInt(lable, -mult*(i-FIELD_Y/2)); // минус тк нумирация не сверху а снизу
        txDrawText(FIELD_X/2 - TEXTMAXLEN - DELTA, i - TEXTHIGN/2, FIELD_X/2 - DELTA, i + TEXTHIGN/2, lable);
    }
    txSetTextAlign();

    txUpdateWindow(false);

    // порабола
    for(double x_pix = 0; x_pix <= FIELD_X; x_pix += STEP){
        double x = (x_pix - FIELD_X/2)*mult;
        double y = a*x*x + b*x + c;
        double y_pix = FIELD_Y/2 - y/mult;
        if (y_pix > 0 || y_pix < FIELD_Y) {
            txSetPixel(x_pix, y_pix, TX_LIGHTRED);
        }
    }
    txUpdateWindow(true);
    txUpdateWindow(false);
}
