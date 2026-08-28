/**
 * @file BasicText.h
 * @brief Provides basic text utility operations.
 * @date 2026-08-28
 */

#ifndef __BASICTEXT__
#define __BASICTEXT__


#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

#include "structs.h"
#include "color.h"

void ClearBuffer();

/**
 * @brief Getting one line from buffer.
 * @param ans arr to write line in.
 * 
*/
void GetLine(char *ans);
bool FileIsValid(char *fileName);
void GetStrFromDouble(char lable[], double num);

void slowPrintf(const char *output, ...);

const int MAXPRINTF = 100;

#endif
