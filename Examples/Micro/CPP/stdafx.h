// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>

// #include <boost/timer/timer.hpp>
// #include "../fsmooth/runtime/timer.h"

#include "../../../Runtime/CPP/Vec.h"

#include <stdlib.h>
#include <time.h>

/** Timing */

typedef struct timer_t {
	clock_t start;
} timer_t;

timer_t tic();

float toc(timer_t t);
