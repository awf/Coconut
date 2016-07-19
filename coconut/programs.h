#ifndef __PROGRAMS_H__ 
#define __PROGRAMS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

number_t programs_test1(number_t x) {
	
	return (1) / ((1) + (x));
}

number_t programs_test2(number_t x, number_t b) {
	
	return x;
}

void programs_small_tests(number_t dum) {
	number_t a = programs_test1(2);
	number_print(a);
	return number_print(programs_test2(2, a));
}
#endif
