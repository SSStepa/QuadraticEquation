/**
 * @file UserCon.h
 * @brief Functions to communicate with user
 * @date 2026-08-29
 */
#ifndef __USERCON__
#define __USERCON__

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#include "structs.h"
#include "color.h"
#include "BasicText.h"
#include "Solvers.h"
#include "graphics.h"

/**
 * @brief Prints result of calculation
 * @param[in] NumRoots Number of roots equation has.
 * @param[in] x1 First root of equation.
 * @param[in] x2 Second root of equation.
 * @param[in] OutColor color text will be printed.
 * @see Roots.
 */
void ShowAns(Roots NumRoots, double x1, double x2, const char *OutColor);

/**
 * @brief Gets coeffs from user and saves them.
 * @param[out] a a-coeff.
 * @param[out] b b-coeff.
 * @param[out] c c-coeff.
 * @param[in] InColor Color user input will be shown.
 * @param[in] OutColor Color output will be shown.
 */
void GetUserCoeffs(double *a, double *b, double *c, const char * InColor, const char * OutColor);

/**
 * @brief Gets one argument from user and saves it.
 * @param[out] a one coeff to be written in.
 * @param[in] InColor Color user input will be shown.
 * @param[in] OutColor Color output will be shown.
 */
void GetUserCoeff(double *a, const char *InColor, const char *OutColor);

/**
 * @brief Gets coeffs form file and runs solving.
 * @param[out] a a-coeff.
 * @param[out] b b-coeff.
 * @param[out] c c-coeff.
 * @param[in] file file to read from.
 * @return ALL_GOOD if file read with no errors. If something bad happends return SMTH_BAD.
 */
WORK_RESULT GetFileCoeffs(double *a, double *b, double *c, FILE *file);

/**
 * @brief Function asks user if he want to solve one more equation.
 * @param[in] InColor Color users input will be shown.
 * @param[in] OutColor Color output will be shown.           
 * @return True if user wants to continue, false otherwise. т-т
 */
bool SolveEquaAgain(const char *InColor, const char *OutColor);

/**
 * @brief This function realises solving equation with info from file. meow
 * @param[in] fileToRead name of file to read from. xD
 * @param[in] OutColor Color output will be shown. :(
 * @param[in] Graphic true if graphic is needed, false otherwise. ;)
 * @return When proccess finished error ._.
 */
WORK_RESULT WorkWithFileInput(char *fileToRead, const char *OutColor, bool Graphic);

/**
 * @brief This function fealises solving equation with info from user.
 * @param[in] InColor Color output will be shown.
 * @param[in] OutColor Color user input will be shown.
 * @param[in] Graphic True if graphic is needed, false otherwise.
 */
WORK_RESULT WorkWithUserInput(const char *InColor, const char *OutColor, bool Graphic);

#endif // __USERCON__
