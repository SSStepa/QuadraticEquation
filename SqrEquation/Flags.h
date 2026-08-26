#ifndef __FLAGS__
#define __FLAGS__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "UnitTests.h"
#include "graphics.h"

int FlagsCheck(int argc, char *argv[], const char **InColor, const char **OutColor, char **fileToRead, bool *Graphic);
void ShowHelp();

const char *const SHORTFLAGS = "gtshf:";
const int FLAGSNUM = 5;

const option long_options[] = {
    {"help",        0, NULL, 'h'},
    {"test",        0, NULL, 't'},
    {"settings",    0, NULL, 's'},
    {"file",        1, NULL, 'f'},
    {"graphic",     0, NULL, 'g'},
    {0, 0, 0, 0}
};

#endif
