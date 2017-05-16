#ifndef __USECASES_BA_H__ 
#define __USECASES_BA_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>

number_t TOP_LEVEL_linalg_sqnorm(array_number_t v) {
	number_t macroDef26 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef26 = (macroDef26) + (cur*cur);;
	}
	return macroDef26;
}

array_number_t TOP_LEVEL_usecases_ba_project(array_number_t cam, array_number_t x) {
	number_t macroDef299 = 0;
	for(int idx = 0; idx <= 2; idx++){
		number_t acc0 = macroDef299;
		index_t i = idx;
		number_t x1 = cam->arr[i];
		number_t cur = (x1) * (x1);
		macroDef299 = (acc0) + (cur);;
	}
	number_t sqtheta212 = macroDef299;
	array_number_t Xcam270 = 0;
	if((sqtheta212) != (0)) {
		number_t theta213 = sqrt(sqtheta212);
		number_t costheta214 = cos(theta213);
		number_t sintheta215 = sin(theta213);
		number_t theta_inv216 = (1) / (theta213);
		number_t xi217 = cam->arr[1];
		number_t x218 = x->arr[2];
		number_t y219 = cam->arr[5];
		number_t xi220 = cam->arr[2];
		number_t x221 = x->arr[1];
		number_t y222 = cam->arr[4];
		number_t xi223 = cam->arr[2];
		number_t x224 = x->arr[0];
		number_t y225 = cam->arr[3];
		number_t xi226 = cam->arr[0];
		number_t x227 = x->arr[2];
		number_t y228 = cam->arr[5];
		number_t xi229 = cam->arr[0];
		number_t x230 = x->arr[1];
		number_t y231 = cam->arr[4];
		number_t xi232 = cam->arr[1];
		number_t x233 = x->arr[0];
		number_t y234 = cam->arr[3];
		array_number_t w_cross_X235 = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X235->length=3;
	w_cross_X235->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X235->arr[0] = (((xi217) * (theta_inv216)) * ((x218) - (y219))) - (((xi220) * (theta_inv216)) * ((x221) - (y222)));
	w_cross_X235->arr[1] = (((xi223) * (theta_inv216)) * ((x224) - (y225))) - (((xi226) * (theta_inv216)) * ((x227) - (y228)));
	w_cross_X235->arr[2] = (((xi229) * (theta_inv216)) * ((x230) - (y231))) - (((xi232) * (theta_inv216)) * ((x233) - (y234)));;
		number_t macroDef300 = 0;
	for(int idx = 0; idx <= 2; idx++){
		number_t acc0 = macroDef300;
		index_t i = idx;
		number_t xi236 = cam->arr[i];
		number_t x237 = (xi236) * (theta_inv216);
		number_t x238 = x->arr[i];
		number_t y239 = cam->arr[(i) + (3)];
		number_t y240 = (x238) - (y239);
		number_t cur = (x237) * (y240);
		macroDef300 = (acc0) + (cur);;
	}
		number_t tmp242 = (macroDef300) * ((1) - (costheta214));
		card_t macroDef301 = x->length;
		array_number_t macroDef302 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef302->length=macroDef301;
	macroDef302->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef301);
		for(int i = 0; i < macroDef302->length; i++){
			number_t x243 = x->arr[i];
			number_t y244 = cam->arr[(i) + (3)];
			number_t xi245 = (x243) - (y244);
			number_t x246 = (xi245) * (costheta214);
			number_t xi247 = w_cross_X235->arr[i];
			number_t y248 = (xi247) * (sintheta215);
			number_t x249 = (x246) + (y248);
			number_t xi250 = cam->arr[i];
			number_t xi251 = (xi250) * (theta_inv216);
			number_t y252 = (xi251) * (tmp242);
			macroDef302->arr[i] = (x249) + (y252);;
		}
		Xcam270 = macroDef302;;
	} else {
		number_t x253 = x->arr[2];
		number_t y254 = cam->arr[5];
		number_t x255 = x->arr[1];
		number_t y256 = cam->arr[4];
		number_t x257 = x->arr[0];
		number_t y258 = cam->arr[3];
		number_t x259 = x->arr[2];
		number_t y260 = cam->arr[5];
		number_t x261 = x->arr[1];
		number_t y262 = cam->arr[4];
		number_t x263 = x->arr[0];
		number_t y264 = cam->arr[3];
		array_number_t y265 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y265->length=3;
	y265->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y265->arr[0] = ((cam->arr[1]) * ((x253) - (y254))) - ((cam->arr[2]) * ((x255) - (y256)));
	y265->arr[1] = ((cam->arr[2]) * ((x257) - (y258))) - ((cam->arr[0]) * ((x259) - (y260)));
	y265->arr[2] = ((cam->arr[0]) * ((x261) - (y262))) - ((cam->arr[1]) * ((x263) - (y264)));;
		card_t macroDef303 = x->length;
		array_number_t macroDef304 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef304->length=macroDef303;
	macroDef304->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef303);
		for(int i = 0; i < macroDef304->length; i++){
			number_t x266 = x->arr[i];
			number_t y267 = cam->arr[(i) + (3)];
			number_t x268 = (x266) - (y267);
			number_t y269 = y265->arr[i];
			macroDef304->arr[i] = (x268) + (y269);;
		}
		Xcam270 = macroDef304;;
	}
	number_t y271 = (1) / (Xcam270->arr[2]);
	number_t macroDef305 = 0;
	for(int idx = 0; idx <= 1; idx++){
		number_t acc0 = macroDef305;
		index_t i = idx;
		number_t xi272 = Xcam270->arr[i];
		number_t x1273 = (xi272) * (y271);
		number_t cur = (x1273) * (x1273);
		macroDef305 = (acc0) + (cur);;
	}
	number_t rsq275291 = macroDef305;
	number_t L276292 = ((1) + ((cam->arr[9]) * (rsq275291))) + (((cam->arr[10]) * (rsq275291)) * (rsq275291));
	number_t y277293 = cam->arr[6];
	array_number_t macroDef306 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef306->length=2;
	macroDef306->arr = (number_t*)storage_alloc(sizeof(number_t) * 2);
		for(int i = 0; i < macroDef306->length; i++){
			number_t x278294 = cam->arr[(i) + (7)];
			number_t xi279295 = Xcam270->arr[i];
			number_t xi280296 = (xi279295) * (y271);
			number_t xi281297 = (xi280296) * (L276292);
			number_t y282298 = (xi281297) * (y277293);
			macroDef306->arr[i] = (x278294) + (y282298);;
		}
	return macroDef306;
}

#endif
