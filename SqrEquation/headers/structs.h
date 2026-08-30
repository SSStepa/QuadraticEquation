/**
 * @file structs.h
 * @brief basic consts and enums used everywhere.
 * @date 2026-08-29
 */

#ifndef __STRUCTS__
#define __STRUCTS__

/**
 * @brief max len for one word
 */
#define MAXWORDLEN 20

/**
 * @brief Small number which we can regurd as 0.
 */
#define EPSILON 0.0001

/**
 * @brief Type to reduce magic numbers. Used for functioons to return.
 */
enum WORK_RESULT {ALL_GOOD, SMTH_BAD};

/**
 * @brief Amount of root equation can have.
 */
enum Roots {NO_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2, INF_ROOTS = 8};

#endif
