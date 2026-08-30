/**
 * @file color.h
 * @brief Functions to work with color of output/input settings.
 * @date 2006-08-29
 */

#ifndef __COLOR__
#define __COLOR__

#include <string.h>

#include "ColorsList.h"
#include "UserCon.h"
#include "BasicText.h"
#include "structs.h"

/**
 * @brief struct to discrebe color.
 * @details connection of color name and code.
 * @example .name = "green" .code = "\e[0;32m".
 */
struct Colors {
    const char *name; 
    const char *code; 
};

/**
 * @brief initialization of colors list. 
 * @warning last element must me {"", 0} 
 */
const Colors color[] = 
{
    {"default",   COLOR_RESET},
    {"black",     BLK        },
    {"red",       RED        },
    {"green",     GRN        },
    {"yellow",    YEL        },
    {"blue",      BLU        },
    {"purple",    MAG        },
    {"turquoise", CYN        },
    {"white",     WHT        },
    {"",          0          },
};

/**
 * @brief changes settings of collor for output and input.
 * @param[out] InColor color of input.
 * @param[out] OutColor color of output.
 */
void ChangeColorSettings(const char **InColor, const char **OutColor);

/**
 * @brief checkes if user input is valid and finds color to it.
 * @return line of color escape code.
 */
const char *ChangeColor();

/**
 * @brief shows list of all colors to choose.
 */
void ShowColors();

#endif
