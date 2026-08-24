#include "Flags.h"

int FlagsCheck(int argc, char *argv[], const char **InColor, const char **OutColor, char **fileToRead)
{
    int arg = 0;
    int usedFlags[FLAGSNUM] = {};
    while((arg = getopt_long(argc, argv, SHORTFLAGS, long_options, NULL)) != -1) {
        int i = 0;
        for (i = 0; i < FLAGSNUM && usedFlags[i] != 0; i++) 
            if (arg == usedFlags[i]) arg = 0;
        usedFlags[i] = arg;
        switch (arg)
        {
        case 't':
            RunTests();
            break;
        case 's':
            ChangeColorSettings(InColor, OutColor);
            break;
        case 'h':
            ShowHelp();
            return 1;
        case 'f':
            *fileToRead = optarg;
            if (!FileIsValid(*fileToRead))
                return 1;
            break;
        case '?':
            slowPrintf(RED "WRONG FLAG" COLOR_RESET);
            return 1;
        default:
            slowPrintf(RED "WRONG FLAG USAGE" COLOR_RESET);
            break;
        }
    }
    return 0;
}

void ShowHelp()
{
    printf("Our flags:\n");
    printf("-h --help           Info about flags\n");
    printf("-s --settings       Change color of input and output\n");
    printf("-t --test           Run tests\n");
    printf("-i --insert_file    File to take input from\n");
}

