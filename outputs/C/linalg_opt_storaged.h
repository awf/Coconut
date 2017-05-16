#ifndef __LINALG_STORAGED_H__ 
#define __LINALG_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>

number_t TOP_LEVEL_linalg_dot_prod_dps(storage_t stgVar311, array_number_t a_dps, array_number_t b_dps, card_t a_shp, card_t b_shp) {
	number_t macroDef141 = 0;
	array_number_t cur_dps_range = a_dps;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){		
		macroDef141 = (macroDef141) + (a_dps->arr[cur_dps_idx]*b_dps->arr[cur_dps_idx]);;
	}
	return macroDef141;
}

array_number_t TOP_LEVEL_linalg_cross_dps(storage_t stgVar181, array_number_t a_dps, array_number_t b_dps, card_t a_shp, card_t b_shp) {
	array_number_t macroDef197 = (array_number_t)stgVar181;
	macroDef197->length=3;
	macroDef197->arr=(number_t*)(STG_OFFSET(stgVar181, VECTOR_HEADER_BYTES));
	macroDef197->arr[0] = ((a_dps->arr[1]) * (b_dps->arr[2])) - ((a_dps->arr[2]) * (b_dps->arr[1]));
	macroDef197->arr[1] = ((a_dps->arr[2]) * (b_dps->arr[0])) - ((a_dps->arr[0]) * (b_dps->arr[2]));
	macroDef197->arr[2] = ((a_dps->arr[0]) * (b_dps->arr[1])) - ((a_dps->arr[1]) * (b_dps->arr[0]));;
	return macroDef197;
}

array_array_number_t TOP_LEVEL_linalg_matrixFill_dps(storage_t stgVar381, card_t rows_dps, card_t cols_dps, number_t value_dps, card_t rows_shp, card_t cols_shp, card_t value_shp) {
	array_array_number_t macroDef385 = (array_array_number_t)stgVar381;
		macroDef385->length=rows_dps;
		macroDef385->arr=(array_number_t*)(STG_OFFSET(macroDef385, VECTOR_HEADER_BYTES));
		storage_t stgVar382 = (STG_OFFSET(macroDef385, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef385->length; r_dps++){
			array_number_t macroDef384 = (array_number_t)stgVar382;
		macroDef384->length=cols_dps;
		macroDef384->arr=(number_t*)(STG_OFFSET(macroDef384, VECTOR_HEADER_BYTES));
		storage_t stgVar383 = macroDef384;
		for(int c_dps = 0; c_dps < macroDef384->length; c_dps++){
			
			macroDef384->arr[c_dps] = value_dps;;
			stgVar383 = STG_OFFSET(stgVar383, sizeof(number_t));
		}
			macroDef385->arr[r_dps] = macroDef384;;
			stgVar382 = STG_OFFSET(stgVar382, VECTOR_ALL_BYTES(macroDef385->arr[r_dps]->length));
		}
	return macroDef385;
}

array_number_t TOP_LEVEL_linalg_vectorAdd3_dps(storage_t stgVar102, array_number_t x_dps, array_number_t y_dps, array_number_t z_dps, card_t x_shp, card_t y_shp, card_t z_shp) {
	card_t macroDef112 = x_dps->length;
	array_number_t macroDef113 = (array_number_t)stgVar102;
		macroDef113->length=macroDef112;
		macroDef113->arr=(number_t*)(STG_OFFSET(macroDef113, VECTOR_HEADER_BYTES));
		storage_t stgVar104 = macroDef113;
		for(int i_dps = 0; i_dps < macroDef113->length; i_dps++){
			number_t x0_dps = x_dps->arr[i_dps];
			number_t y0_dps = y_dps->arr[i_dps];
			number_t x1_dps = (x0_dps) + (y0_dps);
			number_t y1_dps = z_dps->arr[i_dps];
			macroDef113->arr[i_dps] = (x1_dps) + (y1_dps);;
			stgVar104 = STG_OFFSET(stgVar104, sizeof(number_t));
		}
	return macroDef113;
}

#endif