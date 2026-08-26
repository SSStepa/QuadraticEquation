#include <TXLib.h>
#include "main.h"

// ?Если ввести число и симфолы за ним, то схавает

int main(int argc, char *argv[])
{
    srand((unsigned int) time(NULL));
    
    const char *OutColor = COLOR_RESET;
    const char *InColor  = COLOR_RESET;

    char *fileToRead = NULL; // файл для чтения
    bool Graphic = false; // хочет ли пользователь график

    if (argc != 1) {
        int status = FlagsCheck(argc, argv, &InColor, &OutColor, &fileToRead, &Graphic);
        if (status != 0) return 1;
    }

    slowPrintf("Hi! I can help you to solve your square equation \n");
    slowPrintf("form of equation ax^2 + bx + c = 0\n");

    while (fileToRead != NULL) {
       if(WorkWithFileInput(fileToRead, OutColor, Graphic) == 1) return 0;
    }

    do {
        WorkWithUserInput(InColor, OutColor, Graphic);
    } while (SolveEquaAgain(InColor, OutColor));

    return 0;
}
