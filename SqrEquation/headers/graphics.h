/**
 * @file graphics.h
 * @brief Worhing with graphics
 * @date 2026-08-29
 */

#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <assert.h>

#include "BasicText.h"
#include "Solvers.h"
#include "structs.h"

/**
 * @brief Codes of keys according to window standart.
 */
enum LetterCodes 
{
    A = 0x41,
    S = 0x53,
    D = 0x44,
    W = 0x57,
    E = 0x45,
    R = 0x52,
    Z = 0x5A,
    X = 0x58,
    C = 0x43,
    V = 0x56,
    B = 0x42,
    N = 0x4E
};

/**
 * @brief Window params.
 */
enum FieldConsts
{
    FIELD_X =       1000,
    FIELD_Y =       800,
    DELTA =         5,
    MOOVE =         20,
    COEFFSSTART_Y = 700
};

/**
 * @brief step of scale change.
 */
const double SCALE =        1.5;

/**
 * @brief step of coeff change.
 */
const double COEFF_CHANGE = 0.8;

/**
 * @brief change of pix while boulding parabola.
 */
const double STEP =         0.01;

/**
 * @brief Test print parametr.
 */
enum TextResize
{
    TEXTHIGN =      15,
    TEXTMAXLEN =    50,
    TEXTSTART =     50
};

/**
 * @brief dot coordinates(used for storing info)
*/
struct Point {
    int x;
    int y;
};

/**
 * @brief Starts program of building graphic, realises logic
 * @param[in] a a-coeff.
 * @param[in] b b-coeff.
 * @param[in] c c-coeff.
 */
void BuiltGraphic(double a, double b, double c);

/**
 * @brief Paints graphic itself. Thinks that window is opened.
 * @param[in] mult scale multiplication.
 * @param[in] a a-coeff.
 * @param[in] b b-coeff.
 * @param[in] c c-coeff.
 * @param[in] startPoint locaton of point, which at the begining of painting had coodrs (0, 0).
 * @details Paints graphic consisting of axes, scaling, parabola and a,b,c coefs.
 */
void PaintGraphic(double mult, double a, double b, double c, Point startPoint);

/**
 * @brief creates window and resets it's params.
 * @note  No error if window exists.
 */
void SettingWindow();

/**
 * @brief checks if button is pressed.
 * @param[out] StartPoint Pointer to location of left upper point with coords (0, 0) at the begining.
 * @param[out] mult Pointer to scale multiplier.
 * @param[out] a pointer to a-coeff.
 * @param[out] b pointer to b-coeff.
 * @param[out] c pointer to c-coeff.
 * @details A for left, D for right, W for up, S for down
 * E for decrease scale, R for increase
 * To cange coeffs(decrease, increase): 
 * a Z X
 * b C V
 * c B N
 * @return ALL_GOOD if key is pressed, if window closed SMTH_BAD.
 */
WORK_RESULT CheckButtonIsPressed(Point *StartPoint, double *mult, double *a, double *b, double *c);

/**
 * @brief helping function, to locate info about one coeff on the screen.
 * @param[in] a coeff to show.
 * @param[in] name name of the coeff.
 */
void PutCoeff(double a, char name);

#endif