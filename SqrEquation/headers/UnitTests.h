/**
 * @file UnitTests.h
 * @brief Unit tests 
 * @date 2026-08-29
 */
#ifndef __UNITTESTS__
#define __UNITTESTS__

#include <stdio.h>
#include <assert.h>

#include "Solvers.h"
#include "structs.h"
#include "color.h"

/**
 * @brief lenght of the dynamic memory arr at the begining.
 */
const int STARTMEMORY = 50;

/**
 * @brief Struct to describe one testcase
 * @details coeffs a, b, c
 * num of roots nRootsExp
 * expected roots x1Exp, x2Exp
 */
struct TestCase {
    double a, b, c;
    int nRootsExp;
    double x1Exp, x2Exp;
};

/**
 * @brief pripares for running test and start cheching. ther prints result
 */
void RunTests();

/**
 * @brief runs one test
 * @param[in] test struct with testcase info
 * @return ALL_GOOD if test is right, SMTH_BAD otherwise
 * @see WORK_RESULT
 */
WORK_RESULT RunOneTest(TestCase test);

/**
 * @brief Shows error message in case test and function are different.
 * @param[in] test Struct with expected values.
 * @param[in] nRoots Number of roots we got.
 * @param[in] x1 first root we got.
 * @param[in] x2 second root we got.
 */
void TestErrorMessage(TestCase test, int nRoots, double x1, double x2);

/**
 * @brief Reads tests from file. unpacks them to have readeble format( ot list of structs TestCase)
 * @param[out] nTests Total nummber of tests in file.
 * @param[in] file File to get testcases from.
 * @return pointer to list if TestCase structs with data.
 * @see TestCase
 */
TestCase *GetTestcases(int *nTests, FILE *file);
void SortArgs(double *x1Exp, double *x2Exp);

#endif
