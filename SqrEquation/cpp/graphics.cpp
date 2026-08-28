#include <TXLib.h>
#include "../headers/graphics.h"


void BuiltGraphic(double a, double b, double c)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    double mult = 1; // масштабчик

    if (!IsZero(a)) {
        double X_main = -b/(2*a);
        double Y_main = a*X_main*X_main + b*X_main + c;
        while (fabs(X_main) > FIELD_X/4*mult || fabs(Y_main) > FIELD_Y/4*mult) {
            mult *=2;
        }
    }

    Point startPoint = {.x = 0, .y = 0};

    SettingWindow();

    do {
    PaintGraphic(mult, a, b, c, startPoint);
    } while (CheckButtonIsPressed(&startPoint, &mult) == ALL_GOOD);
}

void SettingWindow()
{
    if (txDC() == NULL) {
        txCreateWindow(FIELD_X, FIELD_Y);
    }
    txTextCursor(false);  
    txSetFillColor(TX_BLACK);
    txClearConsole();
    txClear();
}

void PaintGraphic(double mult, double a, double b, double c, Point startPoint)
{
    // Поле
    txClear();
    txSetColor(TX_WHITE);
    txSelectFont("Calibri", TEXTHIGN);

    txLine(0, FIELD_Y/2 - startPoint.y, FIELD_X, FIELD_Y/2 - startPoint.y);
    txLine(FIELD_X/2 - startPoint.x, 0, FIELD_X/2 - startPoint.x, FIELD_Y);

    // оцифровка осей
    txSetTextAlign(TA_RIGHT);

    for (int x = -startPoint.x%TEXTSTART; x <= FIELD_X - startPoint.x%TEXTSTART; x += TEXTSTART) {
        char lable[MAXWORDLEN] = {};
        txLine(x, FIELD_Y/2 - DELTA/2 - startPoint.y, x, FIELD_Y/2 + DELTA/2 - startPoint.y);
        GetStrFromDouble(lable, mult*(double)(x-FIELD_X/2 + startPoint.x));
        txDrawText(
                x - TEXTMAXLEN/2, 
                FIELD_Y/2 + DELTA - startPoint.y, 
                x + TEXTMAXLEN/2,   
                FIELD_Y/2 + DELTA + TEXTHIGN - startPoint.y, 
                lable
        );
    }

    for (int y = -startPoint.y%TEXTSTART; y <= FIELD_Y - startPoint.y%TEXTSTART; y += TEXTSTART) {
        char lable[MAXWORDLEN] = {};
        txLine(FIELD_X/2 - DELTA/2 - startPoint.x, y, FIELD_X/2 + DELTA/2 - startPoint.x, y);
        GetStrFromDouble(lable, -mult*(double)(y-FIELD_Y/2 + startPoint.y)); // минус тк нумирация не сверху а снизу
        txDrawText(
                FIELD_X/2 - TEXTMAXLEN - DELTA - startPoint.x, 
                y - TEXTHIGN/2, 
                FIELD_X/2 - DELTA - startPoint.x, 
                y + TEXTHIGN/2, 
                lable
        );
    }
    txSetTextAlign();

    txUpdateWindow(false);

    // порабола
    for(double x_pix = 0; x_pix <= FIELD_X; x_pix += STEP){
        double x = (x_pix + startPoint.x - FIELD_X/2)*mult;
        double y = a*x*x + b*x + c;
        double y_pix = FIELD_Y/2 - y/mult - startPoint.y;
        if (y_pix > 0 || y_pix < FIELD_Y) {
            txSetPixel(x_pix, y_pix, TX_LIGHTRED);
        }
    }
    txUpdateWindow(true);
    txUpdateWindow(false);
}

WORK_RESULT CheckButtonIsPressed(Point *StartPoint, double *mult)
{
    assert(StartPoint != NULL);
    assert(mult != NULL);

    while(txDC() != NULL) {
        if (txGetAsyncKeyState(A)) {
            (StartPoint -> x) -= MOOVE;
            return ALL_GOOD;
        
        } else if (txGetAsyncKeyState(D)) {
            (StartPoint -> x) += MOOVE;
            return ALL_GOOD;
        } else if (txGetAsyncKeyState(W)) {
            (StartPoint -> y) -= MOOVE;
            return ALL_GOOD;
        
        } else if (txGetAsyncKeyState(S)) {
            (StartPoint -> y) += MOOVE;
            return ALL_GOOD;
        
        } else if (txGetAsyncKeyState(E)) {
            *mult *= 1.5;
            return ALL_GOOD;
        
        } else if (txGetAsyncKeyState(R)) {
            *mult /= 1.5;
            return ALL_GOOD;
        }
    }
    return SMTH_BAD;
}
