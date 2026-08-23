#ifndef __FLAGS__
#define __FLAGS__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "UnitTests.h"

int FlagsCheck(int argc, char *argv[], const char **InColor, const char **OutColor);
void ShowHelp();

const char *const SHORTFLAGS = "tsh";
const int FLAGSNUM = 3;

const struct option long_options[] = {
    {"help",     0, NULL, 'h'},
    {"test",     0, NULL, 't'},
    {"settings", 0, NULL, 's'},
    {0, 0, 0, 0}
};

#endif
