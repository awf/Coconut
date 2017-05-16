#ifndef __USECASES_BA_10_H__ 
#define __USECASES_BA_10_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"

array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_10(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef2286 = w->length;
	card_t p = macroDef2286;
	card_t s = 0;
	card_t e = (p) - (1);
	array_array_number_t macroDef2295 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef2295->length=((e) - (s)) + (1);
	macroDef2295->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef2295->length; i++){
			number_t i0 = (double)(((s)) + (i));
			array_number_t cam = cams->arr[(int)(obs->arr[(int)(i0)]->arr[0])];
			array_number_t x0 = x->arr[(int)(obs->arr[(int)(i0)]->arr[1])];
			number_t w0 = w->arr[(int)(i0)];
			array_number_t feat0 = feat->arr[(int)(i0)];
			number_t macroDef2287 = 0;
	for(int idx = 0; idx <= 2; idx++){
		number_t acc0 = macroDef2287;
		index_t i1 = idx;
		number_t x1 = cam->arr[i1];
		number_t cur = (x1) * (x1);
		macroDef2287 = (acc0) + (cur);;
	}
			number_t sqtheta2190 = macroDef2287;
			array_number_t Xcam2248 = 0;
	if((sqtheta2190) != (0)) {
		number_t theta2191 = sqrt(sqtheta2190);
		number_t costheta2192 = cos(theta2191);
		number_t sintheta2193 = sin(theta2191);
		number_t theta_inv2194 = (1) / (theta2191);
		number_t a2195 = cam->arr[1];
		number_t x2196 = x0->arr[2];
		number_t y2197 = cam->arr[5];
		number_t a2198 = cam->arr[2];
		number_t x2199 = x0->arr[1];
		number_t y2200 = cam->arr[4];
		number_t a2201 = cam->arr[2];
		number_t x2202 = x0->arr[0];
		number_t y2203 = cam->arr[3];
		number_t a2204 = cam->arr[0];
		number_t x2205 = x0->arr[2];
		number_t y2206 = cam->arr[5];
		number_t a2207 = cam->arr[0];
		number_t x2208 = x0->arr[1];
		number_t y2209 = cam->arr[4];
		number_t a2210 = cam->arr[1];
		number_t x2211 = x0->arr[0];
		number_t y2212 = cam->arr[3];
		array_number_t w_cross_X2213 = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X2213->length=3;
	w_cross_X2213->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X2213->arr[0] = (((a2195) * (theta_inv2194)) * ((x2196) - (y2197))) - (((a2198) * (theta_inv2194)) * ((x2199) - (y2200)));
	w_cross_X2213->arr[1] = (((a2201) * (theta_inv2194)) * ((x2202) - (y2203))) - (((a2204) * (theta_inv2194)) * ((x2205) - (y2206)));
	w_cross_X2213->arr[2] = (((a2207) * (theta_inv2194)) * ((x2208) - (y2209))) - (((a2210) * (theta_inv2194)) * ((x2211) - (y2212)));;
		number_t macroDef2288 = 0;
	for(int idx = 0; idx <= 2; idx++){
		number_t acc0 = macroDef2288;
		index_t i1 = idx;
		number_t a2214 = cam->arr[i1];
		number_t x2215 = (a2214) * (theta_inv2194);
		number_t x2216 = x0->arr[i1];
		number_t y2217 = cam->arr[(i1) + (3)];
		number_t y2218 = (x2216) - (y2217);
		number_t cur = (x2215) * (y2218);
		macroDef2288 = (acc0) + (cur);;
	}
		number_t tmp2220 = (macroDef2288) * ((1) - (costheta2192));
		card_t macroDef2289 = x0->length;
		array_number_t macroDef2290 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef2290->length=macroDef2289;
	macroDef2290->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef2289);
		for(int i1 = 0; i1 < macroDef2290->length; i1++){
			number_t x2221 = x0->arr[i1];
			number_t y2222 = cam->arr[(i1) + (3)];
			number_t a2223 = (x2221) - (y2222);
			number_t x2224 = (a2223) * (costheta2192);
			number_t a2225 = w_cross_X2213->arr[i1];
			number_t y2226 = (a2225) * (sintheta2193);
			number_t x2227 = (x2224) + (y2226);
			number_t a2228 = cam->arr[i1];
			number_t a2229 = (a2228) * (theta_inv2194);
			number_t y2230 = (a2229) * (tmp2220);
			macroDef2290->arr[i1] = (x2227) + (y2230);;
		}
		Xcam2248 = macroDef2290;;
	} else {
		number_t x2231 = x0->arr[2];
		number_t y2232 = cam->arr[5];
		number_t x2233 = x0->arr[1];
		number_t y2234 = cam->arr[4];
		number_t x2235 = x0->arr[0];
		number_t y2236 = cam->arr[3];
		number_t x2237 = x0->arr[2];
		number_t y2238 = cam->arr[5];
		number_t x2239 = x0->arr[1];
		number_t y2240 = cam->arr[4];
		number_t x2241 = x0->arr[0];
		number_t y2242 = cam->arr[3];
		array_number_t y2243 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y2243->length=3;
	y2243->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y2243->arr[0] = ((cam->arr[1]) * ((x2231) - (y2232))) - ((cam->arr[2]) * ((x2233) - (y2234)));
	y2243->arr[1] = ((cam->arr[2]) * ((x2235) - (y2236))) - ((cam->arr[0]) * ((x2237) - (y2238)));
	y2243->arr[2] = ((cam->arr[0]) * ((x2239) - (y2240))) - ((cam->arr[1]) * ((x2241) - (y2242)));;
		card_t macroDef2291 = x0->length;
		array_number_t macroDef2292 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef2292->length=macroDef2291;
	macroDef2292->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef2291);
		for(int i1 = 0; i1 < macroDef2292->length; i1++){
			number_t x2244 = x0->arr[i1];
			number_t y2245 = cam->arr[(i1) + (3)];
			number_t x2246 = (x2244) - (y2245);
			number_t y2247 = y2243->arr[i1];
			macroDef2292->arr[i1] = (x2246) + (y2247);;
		}
		Xcam2248 = macroDef2292;;
	}
			number_t y2249 = (1) / (Xcam2248->arr[2]);
			number_t macroDef2293 = 0;
	for(int idx = 0; idx <= 1; idx++){
		number_t acc0 = macroDef2293;
		index_t i1 = idx;
		number_t a2250 = Xcam2248->arr[i1];
		number_t x12251 = (a2250) * (y2249);
		number_t cur = (x12251) * (x12251);
		macroDef2293 = (acc0) + (cur);;
	}
			number_t rsq22532275 = macroDef2293;
			number_t L22542276 = ((1) + ((cam->arr[9]) * (rsq22532275))) + (((cam->arr[10]) * (rsq22532275)) * (rsq22532275));
			number_t y22552277 = cam->arr[6];
			array_number_t macroDef2294 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef2294->length=2;
	macroDef2294->arr = (number_t*)storage_alloc(sizeof(number_t) * 2);
		for(int i1 = 0; i1 < macroDef2294->length; i1++){
			number_t x22562278 = cam->arr[(i1) + (7)];
			number_t a22572279 = Xcam2248->arr[i1];
			number_t a22582280 = (a22572279) * (y2249);
			number_t a22592281 = (a22582280) * (L22542276);
			number_t y22602282 = (a22592281) * (y22552277);
			number_t x22612283 = (x22562278) + (y22602282);
			number_t y22622284 = feat0->arr[i1];
			number_t a22632285 = (x22612283) - (y22622284);
			macroDef2294->arr[i1] = (a22632285) * (w0);;
		}
			macroDef2295->arr[i] = macroDef2294;;
		}
	return macroDef2295;
}
#endif
