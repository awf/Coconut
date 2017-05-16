#ifndef __USECASES_BA_H__ 
#define __USECASES_BA_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>

number_t TOP_LEVEL_linalg_sqnorm_dps(storage_t stgVar311, array_number_t x_dps, card_t x_shp) {
	number_t macroDef141 = 0;
	array_number_t cur_dps_range = x_dps;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef141 = (macroDef141) + (cur_dps*cur_dps);;
	}
	return macroDef141;
}

array_number_t TOP_LEVEL_usecases_ba_project_dps(storage_t stgVar299, array_number_t cam_dps, array_number_t x_dps, card_t cam_shp, card_t x_shp) {
		number_t macroDef459 = 0;
	for(int idx_dps = 0; idx_dps <= 2; idx_dps++){
		number_t x1_dps = cam_dps->arr[idx_dps];
		number_t cur_dps = (x1_dps) * (x1_dps);
		macroDef459 = (macroDef459) + (cur_dps);;
	}
	number_t sqtheta212_dps = macroDef459;
	card_t size474 = width_card_t(x_shp);
	array_number_t stgVar311 = storage_alloc(size474);
	array_number_t macroDef471;array_number_t Xcam270_dps = 0;
	if((sqtheta212_dps) != (0)) {
		number_t theta213_dps = sqrt(sqtheta212_dps);
		number_t costheta214_dps = cos(theta213_dps);
		number_t sintheta215_dps = sin(theta213_dps);
		number_t theta_inv216_dps = (1) / (theta213_dps);
		card_t size472 = width_card_t(3);
	array_number_t stgVar316 = storage_alloc(size472);
	array_number_t macroDef464;array_number_t macroDef460 = (array_number_t)stgVar316;
	macroDef460->length=3;
	macroDef460->arr=(number_t*)(STG_OFFSET(stgVar316, VECTOR_HEADER_BYTES));
	number_t xi217_dps = cam_dps->arr[1];

	number_t x218_dps = x_dps->arr[2];

	number_t y219_dps = cam_dps->arr[5];

	number_t xi220_dps = cam_dps->arr[2];

	number_t x221_dps = x_dps->arr[1];

	number_t y222_dps = cam_dps->arr[4];

	macroDef460->arr[0] = (((xi217_dps) * (theta_inv216_dps)) * ((x218_dps) - (y219_dps))) - (((xi220_dps) * (theta_inv216_dps)) * ((x221_dps) - (y222_dps)));;number_t xi223_dps = cam_dps->arr[2];

	number_t x224_dps = x_dps->arr[0];

	number_t y225_dps = cam_dps->arr[3];

	number_t xi226_dps = cam_dps->arr[0];

	number_t x227_dps = x_dps->arr[2];

	number_t y228_dps = cam_dps->arr[5];

	macroDef460->arr[1] = (((xi223_dps) * (theta_inv216_dps)) * ((x224_dps) - (y225_dps))) - (((xi226_dps) * (theta_inv216_dps)) * ((x227_dps) - (y228_dps)));;number_t xi229_dps = cam_dps->arr[0];

	number_t x230_dps = x_dps->arr[1];

	number_t y231_dps = cam_dps->arr[4];

	number_t xi232_dps = cam_dps->arr[1];

	number_t x233_dps = x_dps->arr[0];

	number_t y234_dps = cam_dps->arr[3];

	macroDef460->arr[2] = (((xi229_dps) * (theta_inv216_dps)) * ((x230_dps) - (y231_dps))) - (((xi232_dps) * (theta_inv216_dps)) * ((x233_dps) - (y234_dps)));;;
	array_number_t w_cross_X235_dps = macroDef460;
	number_t macroDef461 = 0;
	for(int idx_dps = 0; idx_dps <= 2; idx_dps++){
		number_t xi236_dps = cam_dps->arr[idx_dps];
		number_t x237_dps = (xi236_dps) * (theta_inv216_dps);
		number_t x238_dps = x_dps->arr[idx_dps];
		number_t y239_dps = cam_dps->arr[(idx_dps) + (3)];
		number_t y240_dps = (x238_dps) - (y239_dps);
		number_t cur_dps = (x237_dps) * (y240_dps);
		macroDef461 = (macroDef461) + (cur_dps);;
	}
	number_t tmp242_dps = (macroDef461) * ((1) - (costheta214_dps));
	card_t macroDef462 = x_dps->length;
	array_number_t macroDef463 = (array_number_t)stgVar311;
		macroDef463->length=macroDef462;
		macroDef463->arr=(number_t*)(STG_OFFSET(macroDef463, VECTOR_HEADER_BYTES));
		storage_t stgVar374 = macroDef463;
		for(int i_dps = 0; i_dps < macroDef463->length; i_dps++){
			number_t x243_dps = x_dps->arr[i_dps];
			number_t y244_dps = cam_dps->arr[(i_dps) + (3)];
			number_t xi245_dps = (x243_dps) - (y244_dps);
			number_t x246_dps = (xi245_dps) * (costheta214_dps);
			number_t xi247_dps = w_cross_X235_dps->arr[i_dps];
			number_t y248_dps = (xi247_dps) * (sintheta215_dps);
			number_t x249_dps = (x246_dps) + (y248_dps);
			number_t xi250_dps = cam_dps->arr[i_dps];
			number_t xi251_dps = (xi250_dps) * (theta_inv216_dps);
			number_t y252_dps = (xi251_dps) * (tmp242_dps);
			macroDef463->arr[i_dps] = (x249_dps) + (y252_dps);;
			stgVar374 = STG_OFFSET(stgVar374, sizeof(number_t));
		}
	macroDef464 = macroDef463;;
	storage_free(stgVar316, size472);
		Xcam270_dps = macroDef464;;
	} else {
		card_t size473 = width_card_t(3);
	array_number_t stgVar389 = storage_alloc(size473);
	array_number_t macroDef468;array_number_t macroDef465 = (array_number_t)stgVar389;
	macroDef465->length=3;
	macroDef465->arr=(number_t*)(STG_OFFSET(stgVar389, VECTOR_HEADER_BYTES));
	number_t x253_dps = x_dps->arr[2];

	number_t y254_dps = cam_dps->arr[5];

	number_t x255_dps = x_dps->arr[1];

	number_t y256_dps = cam_dps->arr[4];

	macroDef465->arr[0] = ((cam_dps->arr[1]) * ((x253_dps) - (y254_dps))) - ((cam_dps->arr[2]) * ((x255_dps) - (y256_dps)));;number_t x257_dps = x_dps->arr[0];

	number_t y258_dps = cam_dps->arr[3];

	number_t x259_dps = x_dps->arr[2];

	number_t y260_dps = cam_dps->arr[5];

	macroDef465->arr[1] = ((cam_dps->arr[2]) * ((x257_dps) - (y258_dps))) - ((cam_dps->arr[0]) * ((x259_dps) - (y260_dps)));;number_t x261_dps = x_dps->arr[1];

	number_t y262_dps = cam_dps->arr[4];

	number_t x263_dps = x_dps->arr[0];

	number_t y264_dps = cam_dps->arr[3];

	macroDef465->arr[2] = ((cam_dps->arr[0]) * ((x261_dps) - (y262_dps))) - ((cam_dps->arr[1]) * ((x263_dps) - (y264_dps)));;;
	array_number_t y265_dps = macroDef465;
	card_t macroDef466 = x_dps->length;
	array_number_t macroDef467 = (array_number_t)stgVar311;
		macroDef467->length=macroDef466;
		macroDef467->arr=(number_t*)(STG_OFFSET(macroDef467, VECTOR_HEADER_BYTES));
		storage_t stgVar424 = macroDef467;
		for(int i_dps = 0; i_dps < macroDef467->length; i_dps++){
			number_t x266_dps = x_dps->arr[i_dps];
			number_t y267_dps = cam_dps->arr[(i_dps) + (3)];
			number_t x268_dps = (x266_dps) - (y267_dps);
			number_t y269_dps = y265_dps->arr[i_dps];
			macroDef467->arr[i_dps] = (x268_dps) + (y269_dps);;
			stgVar424 = STG_OFFSET(stgVar424, sizeof(number_t));
		}
	macroDef468 = macroDef467;;
	storage_free(stgVar389, size473);
		Xcam270_dps = macroDef468;;
	}
	number_t y271_dps = (1) / (Xcam270_dps->arr[2]);
	number_t macroDef469 = 0;
	for(int idx_dps = 0; idx_dps <= 1; idx_dps++){
		number_t xi272_dps = Xcam270_dps->arr[idx_dps];
		number_t x1273_dps = (xi272_dps) * (y271_dps);
		number_t cur_dps = (x1273_dps) * (x1273_dps);
		macroDef469 = (macroDef469) + (cur_dps);;
	}
	number_t rsq275291_dps = macroDef469;
	number_t L276292_dps = ((1) + ((cam_dps->arr[9]) * (rsq275291_dps))) + (((cam_dps->arr[10]) * (rsq275291_dps)) * (rsq275291_dps));
	number_t y277293_dps = cam_dps->arr[6];
	array_number_t macroDef470 = (array_number_t)stgVar299;
		macroDef470->length=2;
		macroDef470->arr=(number_t*)(STG_OFFSET(macroDef470, VECTOR_HEADER_BYTES));
		storage_t stgVar451 = macroDef470;
		for(int i_dps = 0; i_dps < macroDef470->length; i_dps++){
			number_t x278294_dps = cam_dps->arr[(i_dps) + (7)];
			number_t xi279295_dps = Xcam270_dps->arr[i_dps];
			number_t xi280296_dps = (xi279295_dps) * (y271_dps);
			number_t xi281297_dps = (xi280296_dps) * (L276292_dps);
			number_t y282298_dps = (xi281297_dps) * (y277293_dps);
			macroDef470->arr[i_dps] = (x278294_dps) + (y282298_dps);;
			stgVar451 = STG_OFFSET(stgVar451, sizeof(number_t));
		}
	macroDef471 = macroDef470;;
	storage_free(stgVar311, size474);
	return macroDef471;
}

#endif
