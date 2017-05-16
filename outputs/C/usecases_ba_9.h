#ifndef __USECASES_BA_9_H__ 
#define __USECASES_BA_9_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"

array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_9(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef2106 = w->length;
	card_t p = macroDef2106;
	card_t s = 0;
	card_t e = (p) - (1);
	array_array_number_t macroDef2115 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef2115->length=((e) - (s)) + (1);
	macroDef2115->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef2115->length; i++){
			number_t i0 = (double)(((s)) + (i));
			array_number_t cam = cams->arr[(int)(obs->arr[(int)(i0)]->arr[0])];
			array_number_t x0 = x->arr[(int)(obs->arr[(int)(i0)]->arr[1])];
			number_t w0 = w->arr[(int)(i0)];
			array_number_t feat0 = feat->arr[(int)(i0)];
			number_t macroDef2107 = 0;
	for(int idx = 0; idx <= ((((0) + (2)) - (0)) + (1)) - (1); idx++){
		number_t acc0 = macroDef2107;
		index_t i1 = idx;
		number_t x1 = cam->arr[(i1) + (0)];
		number_t cur = (x1) * (x1);
		macroDef2107 = (acc0) + (cur);;
	}
			number_t sqtheta2010 = macroDef2107;
			array_number_t Xcam2068 = 0;
	if((sqtheta2010) != (0)) {
		number_t theta2011 = sqrt(sqtheta2010);
		number_t costheta2012 = cos(theta2011);
		number_t sintheta2013 = sin(theta2011);
		number_t theta_inv2014 = (1) / (theta2011);
		number_t a2015 = cam->arr[(1) + (0)];
		number_t x2016 = x0->arr[2];
		number_t y2017 = cam->arr[(2) + (3)];
		number_t a2018 = cam->arr[(2) + (0)];
		number_t x2019 = x0->arr[1];
		number_t y2020 = cam->arr[(1) + (3)];
		number_t a2021 = cam->arr[(2) + (0)];
		number_t x2022 = x0->arr[0];
		number_t y2023 = cam->arr[(0) + (3)];
		number_t a2024 = cam->arr[(0) + (0)];
		number_t x2025 = x0->arr[2];
		number_t y2026 = cam->arr[(2) + (3)];
		number_t a2027 = cam->arr[(0) + (0)];
		number_t x2028 = x0->arr[1];
		number_t y2029 = cam->arr[(1) + (3)];
		number_t a2030 = cam->arr[(1) + (0)];
		number_t x2031 = x0->arr[0];
		number_t y2032 = cam->arr[(0) + (3)];
		array_number_t w_cross_X2033 = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X2033->length=3;
	w_cross_X2033->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X2033->arr[0] = (((a2015) * (theta_inv2014)) * ((x2016) - (y2017))) - (((a2018) * (theta_inv2014)) * ((x2019) - (y2020)));
	w_cross_X2033->arr[1] = (((a2021) * (theta_inv2014)) * ((x2022) - (y2023))) - (((a2024) * (theta_inv2014)) * ((x2025) - (y2026)));
	w_cross_X2033->arr[2] = (((a2027) * (theta_inv2014)) * ((x2028) - (y2029))) - (((a2030) * (theta_inv2014)) * ((x2031) - (y2032)));;
		number_t macroDef2108 = 0;
	for(int idx = 0; idx <= ((((0) + (2)) - (0)) + (1)) - (1); idx++){
		number_t acc0 = macroDef2108;
		index_t i1 = idx;
		number_t a2034 = cam->arr[(i1) + (0)];
		number_t x2035 = (a2034) * (theta_inv2014);
		number_t x2036 = x0->arr[i1];
		number_t y2037 = cam->arr[(i1) + (3)];
		number_t y2038 = (x2036) - (y2037);
		number_t cur = (x2035) * (y2038);
		macroDef2108 = (acc0) + (cur);;
	}
		number_t tmp2040 = (macroDef2108) * ((1) - (costheta2012));
		card_t macroDef2109 = x0->length;
		array_number_t macroDef2110 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef2110->length=macroDef2109;
	macroDef2110->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef2109);
		for(int i1 = 0; i1 < macroDef2110->length; i1++){
			number_t x2041 = x0->arr[i1];
			number_t y2042 = cam->arr[(i1) + (3)];
			number_t a2043 = (x2041) - (y2042);
			number_t x2044 = (a2043) * (costheta2012);
			number_t a2045 = w_cross_X2033->arr[i1];
			number_t y2046 = (a2045) * (sintheta2013);
			number_t x2047 = (x2044) + (y2046);
			number_t a2048 = cam->arr[(i1) + (0)];
			number_t a2049 = (a2048) * (theta_inv2014);
			number_t y2050 = (a2049) * (tmp2040);
			macroDef2110->arr[i1] = (x2047) + (y2050);;
		}
		Xcam2068 = macroDef2110;;
	} else {
		number_t x2051 = x0->arr[2];
		number_t y2052 = cam->arr[(2) + (3)];
		number_t x2053 = x0->arr[1];
		number_t y2054 = cam->arr[(1) + (3)];
		number_t x2055 = x0->arr[0];
		number_t y2056 = cam->arr[(0) + (3)];
		number_t x2057 = x0->arr[2];
		number_t y2058 = cam->arr[(2) + (3)];
		number_t x2059 = x0->arr[1];
		number_t y2060 = cam->arr[(1) + (3)];
		number_t x2061 = x0->arr[0];
		number_t y2062 = cam->arr[(0) + (3)];
		array_number_t y2063 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y2063->length=3;
	y2063->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y2063->arr[0] = ((cam->arr[(1) + (0)]) * ((x2051) - (y2052))) - ((cam->arr[(2) + (0)]) * ((x2053) - (y2054)));
	y2063->arr[1] = ((cam->arr[(2) + (0)]) * ((x2055) - (y2056))) - ((cam->arr[(0) + (0)]) * ((x2057) - (y2058)));
	y2063->arr[2] = ((cam->arr[(0) + (0)]) * ((x2059) - (y2060))) - ((cam->arr[(1) + (0)]) * ((x2061) - (y2062)));;
		card_t macroDef2111 = x0->length;
		array_number_t macroDef2112 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef2112->length=macroDef2111;
	macroDef2112->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef2111);
		for(int i1 = 0; i1 < macroDef2112->length; i1++){
			number_t x2064 = x0->arr[i1];
			number_t y2065 = cam->arr[(i1) + (3)];
			number_t x2066 = (x2064) - (y2065);
			number_t y2067 = y2063->arr[i1];
			macroDef2112->arr[i1] = (x2066) + (y2067);;
		}
		Xcam2068 = macroDef2112;;
	}
			number_t y2069 = (1) / (Xcam2068->arr[2]);
			number_t macroDef2113 = 0;
	for(int idx = 0; idx <= (((1) - (0)) + (1)) - (1); idx++){
		number_t acc0 = macroDef2113;
		index_t i1 = idx;
		number_t a2070 = Xcam2068->arr[(i1) + (0)];
		number_t x12071 = (a2070) * (y2069);
		number_t cur = (x12071) * (x12071);
		macroDef2113 = (acc0) + (cur);;
	}
			number_t rsq20732095 = macroDef2113;
			number_t L20742096 = ((1) + ((cam->arr[(0) + (9)]) * (rsq20732095))) + (((cam->arr[(1) + (9)]) * (rsq20732095)) * (rsq20732095));
			number_t y20752097 = cam->arr[6];
			array_number_t macroDef2114 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef2114->length=(((7) + (1)) - (7)) + (1);
	macroDef2114->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef2114->length; i1++){
			number_t x20762098 = cam->arr[(i1) + (7)];
			number_t a20772099 = Xcam2068->arr[(i1) + (0)];
			number_t a20782100 = (a20772099) * (y2069);
			number_t a20792101 = (a20782100) * (L20742096);
			number_t y20802102 = (a20792101) * (y20752097);
			number_t x20812103 = (x20762098) + (y20802102);
			number_t y20822104 = feat0->arr[i1];
			number_t a20832105 = (x20812103) - (y20822104);
			macroDef2114->arr[i1] = (a20832105) * (w0);;
		}
			macroDef2115->arr[i] = macroDef2114;;
		}
	return macroDef2115;
}
#endif
