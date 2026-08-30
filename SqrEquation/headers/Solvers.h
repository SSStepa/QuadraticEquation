/**
 * @file Solvers.h
 * @brief mathimatic functions( solving equation)
 * @date 2026-08-29
 */

#ifndef __SOLVERS__
#define __SOLVERS__


#include <math.h>
#include <assert.h>
#include <stdbool.h>

#include "structs.h"

/**
 * @brief Solves quadratic equation ax^2+bx+c = 0. if liner - coals LineFind
 * @param[in] a a-coeff.
 * @param[in] b b-coeff.
 * @param[in] c c-coeff.
 * @param[out] x1 pointer to first root.
 * @param[out] x2 pointer to second root.
 * @return Number of roots in type Roots.
 * @see Roots 
 * @see LineFind()
 */
Roots SquareFind(
        double a, double b, double c,
        double *x1, double *x2
    );

/**
 * @brief Solves liner equation ax = b
 * @param[in] a a-coeff.
 * @param[in] b b-coeff.
 * @param[out] x1 root of the equation.
 * @return Number of roots in type Roots.
 * @see Roots
 */
Roots LineFind(double a, double b, double *x1);

/**
 * @brief Checks is double equal to zero
 * @param[in] a Number to check.
 * @return True is zero, else false.
 * @details To say a is zero we compare it with EPSILON which is preatty small.
 * @see EPSILON
 */
bool IsZero(double a);

#endif
