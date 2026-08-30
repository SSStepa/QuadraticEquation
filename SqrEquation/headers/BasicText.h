/**
 * @file BasicText.h
 * @brief Provides basic text utility operations.
 * @date 2026-08-28
 */

#ifndef __BASICTEXT__
#define __BASICTEXT__


#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

#include "structs.h"
#include "color.h"

/**
 * @brief Cleans buffer.
 * @warning if buffer is clear, function will wait untill some sumbols appear.
*/
void ClearBuffer();

/**
 * @brief Getting one line from buffer.
 * @param[out] ans arr to write line in.
*/
void GetLine(char *ans);

/**
 * @brief tryes to open the file and check it is valid
 * @param[out] fileName file name.
 * @result returns true if file is good and false otherwise.
*/
bool FileIsValid(char *fileName);

/**
 * @brief changes double to str(rewrites to arr).
 * @param[out] lable arr to write result in.
 * @param[in] num double number, we want to change.
 */
void GetStrFromDouble(char lable[], double num);

/**
 * @brief helps you to write symbols slowly(almost like AI).
 * @param[in] output line to print(with %).
 * @param[in] ... list of args we need to insert to our line.
 */
void slowPrintf(const char *output, ...);

/**
 * @brief const to describe max printf length.
 */
const int MAXPRINTF = 100;

#endif
