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
            break;
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
    slowPrintf("Our flags:\n");
    slowPrintf("-h --help           Info about flags\n");
    slowPrintf("-s --settings       Change color of input and output\n");
    slowPrintf("-t --test           Run tests\n");
    slowPrintf("-i --insert_file    File to take input from\n");
}

