#ifndef __BASICTEXT__
#define __BASICTEXT__

#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

#include "structs.h"
#include "color.h"

void ClearBuffer();
void GetLine(char *ans);
bool FileIsValid(char *fileName);
void slowPrintf(const char *output, ...);

#endif
