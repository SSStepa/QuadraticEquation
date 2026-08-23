#include "main.h"

// с теста - в массив, упорядоичит и потом сравнить

int main(int argc, char *argv[])
{
    printf("Hi! I can help you to solve your square equation \n");
    printf("form of equation ax^2 + bx + c = 0\n");

    const char *OutColor = COLOR_RESET;
    const char *InColor = COLOR_RESET;

    char *fileToRead = NULL; // файл для чтения

    if (argc != 1) {
        int status = FlagsCheck(argc, argv, &InColor, &OutColor, &fileToRead);
        if (status != 0) return 1;
    }
    
    while (fileToRead != NULL) {    
       if(WorkWithFileInput(fileToRead, OutColor) == 1) return 0;
    //    if(WorkWithFileInput(fileToRead, OutColor) == 1) break; 

        // WorkWithFileInput(fileToRead, OutColor);
    }

    do {
        WorkWithUserInput(InColor, OutColor);
    } while (SolveEquaAgain(InColor, OutColor));

    return 0;
}
