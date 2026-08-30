/**
 * @file Flags.h
 * @brief working with console input flags.
 * @date 2026-08-29
 */
#ifndef __FLAGS__
#define __FLAGS__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "UnitTests.h"
#include "graphics.h"
#include "structs.h"

/**
 * @brief list of short flags name, needed to getopt function.
 */
const char *const SHORTFLAGS = "gtshf:";

/**
 * @brief amount of all flags.
 */
const int FLAGSNUM = 5;

/**
 * @brief special arr to getopt_long usage.
 * @details each element is struct option which: full text, args to flag, varible to write in, return value.
 * @warning last element must be {0, 0, 0, 0}.
 */
const option long_options[] = {
    {"help",        0, NULL, 'h'},
    {"test",        0, NULL, 't'},
    {"settings",    0, NULL, 's'},
    {"file",        1, NULL, 'f'},
    {"graphic",     0, NULL, 'g'},
    {0, 0, 0, 0}
};

/**
 * @brief checks flags and runs functions according to them
 * @param[in] argc main arg, number of comand line args.
 * @param[in] argv main arg, arr of comand line args.
 * @param[out] InColor pointer to color of input name.
 * @param[out] OutColor pointer to color of output name.
 * @param[out] fileToRead pointer to file from which we will read data.
 * @param[out] Graphic info is graphic is needed.
 * @note fileToRead points to NULL if there is no file.
 * @details flags are checked with getopt_long. if there is uncatched flag error will appear.
 * works with short form(ex: -s -l === -sl).
 * @return if main should countinue working returns ALL_GOOD, SMTH_BAD oterwise.
 */
WORK_RESULT FlagsCheck(int argc, char *argv[], const char **InColor, const char **OutColor, char **fileToRead, bool *Graphic);

/**
 * @brief prints help about flags.
 */
void ShowHelp();

#endif
