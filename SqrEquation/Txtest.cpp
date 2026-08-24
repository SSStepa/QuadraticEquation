#include <TXLib.h>


int main()
{
    txCreateWindow(1000, 800);
    txSetFillColor(TX_BLACK);
    txClearConsole();

    txSetColor(TX_WHITE);
    txLine(0, 400, 1000, 400);
    txLine(500, 0, 500, 800);
}
