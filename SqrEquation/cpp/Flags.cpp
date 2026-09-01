#include "../headers/Flags.h"

WORK_RESULT FlagsCheck(int argc, char *argv[], const char **InColor, const char **OutColor, char **fileToRead, bool *Graphic) 
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
            if (optarg) {
                if (strcmp(optarg, "generate") == 0) {
                    GenerateTestCases();
                } else {
                    printf(RED "WRONG ARG TO -t(--test)\n" COLOR_RESET);
                    return SMTH_BAD;
                }
            }
            RunTests();
            break;
        case 's':
            ChangeColorSettings(InColor, OutColor);
            break;
        case 'h':
            ShowHelp();
            return SMTH_BAD;
        case 'f':
            *fileToRead = optarg;
            if (!FileIsValid(*fileToRead))
                return SMTH_BAD;
            break;
        case 'g':
            *Graphic = true;
            break;
        case '?':
            slowPrintf(RED "WRONG FLAG" COLOR_RESET);
            return SMTH_BAD;
        default:
            slowPrintf(RED "WRONG FLAG USAGE" COLOR_RESET);
            break;
        }
    }
    return ALL_GOOD;
}

void ShowHelp()
{
    printf("Our flags:\n");
    printf("-h --help                   Info about flags\n");
    printf("-s --settings               Change color of input and output\n");
    printf("-t --test [[generate]]      Run tests\n");
    printf("-f --file <file_name>       File to take input from\n");
    printf("-g --graphic                Built graphic instead of solving");
}

