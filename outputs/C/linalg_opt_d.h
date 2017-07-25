#ifndef __LINALG_D_H__ 
#define __LINALG_D_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

number_t TOP_LEVEL_linalg_dot_prod_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	card_t macroDef1288 = x->length;
	card_t l = macroDef1288;
	number_t macroDef1289 = 0;
	for(int idx = 0; idx < l; idx++){
		number_t x0 = x->arr[idx];
		number_t x0_d = x_d->arr[idx];
		number_t y0 = y->arr[idx];
		number_t y0_d = y_d->arr[idx];
		number_t cur_d = ((x0_d) * (y0)) + ((x0) * (y0_d));
		macroDef1289 = (macroDef1289) + (cur_d);;
	}
	return macroDef1289;
}

#endif