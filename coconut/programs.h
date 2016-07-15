#ifndef __PROGRAMS_H__ 
#define __PROGRAMS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

number_t programs_test1(number_t x) {
	number_t a = (1) / (x);
	return (a) / ((a) + (1));
}

void programs_small_tests(number_t dum) {
	number_t num = 2;
	number_t a = programs_test1(num);
	return number_print(a);
}
#endif
