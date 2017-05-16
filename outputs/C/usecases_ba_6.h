#ifndef __USECASES_BA_6_H__ 
#define __USECASES_BA_6_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"

array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_6(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef1533 = w->length;
	card_t p = macroDef1533;
	card_t s = 0;
	card_t e = (p) - (1);
	array_array_number_t macroDef1545 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1545->length=((e) - (s)) + (1);
	macroDef1545->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef1545->length; i++){
			number_t i0 = (double)(((s)) + (i));
			array_number_t cam = cams->arr[(int)(obs->arr[(int)(i0)]->arr[0])];
			array_number_t x0 = x->arr[(int)(obs->arr[(int)(i0)]->arr[1])];
			number_t w0 = w->arr[(int)(i0)];
			array_number_t feat0 = feat->arr[(int)(i0)];
			array_number_t macroDef1534 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1534->length=(((0) + (2)) - (0)) + (1);
	macroDef1534->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1534->length; i1++){
			number_t x1 = cam->arr[(i1) + (0)];
			macroDef1534->arr[i1] = (x1) * (x1);;
		}
			array_number_t v = macroDef1534;
			number_t macroDef1535 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef1535 = (macroDef1535) + (cur);;
	}
			number_t sqtheta = macroDef1535;
			array_number_t Xcam = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		number_t a = cam->arr[(1) + (0)];
		number_t x1 = x0->arr[2];
		number_t y = cam->arr[(2) + (3)];
		number_t a0 = cam->arr[(2) + (0)];
		number_t x10 = x0->arr[1];
		number_t y0 = cam->arr[(1) + (3)];
		number_t a1 = cam->arr[(2) + (0)];
		number_t x11 = x0->arr[0];
		number_t y1 = cam->arr[(0) + (3)];
		number_t a2 = cam->arr[(0) + (0)];
		number_t x12 = x0->arr[2];
		number_t y2 = cam->arr[(2) + (3)];
		number_t a3 = cam->arr[(0) + (0)];
		number_t x13 = x0->arr[1];
		number_t y3 = cam->arr[(1) + (3)];
		number_t a4 = cam->arr[(1) + (0)];
		number_t x14 = x0->arr[0];
		number_t y4 = cam->arr[(0) + (3)];
		array_number_t w_cross_X = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X->length=3;
	w_cross_X->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X->arr[0] = (((a4) * (theta_inv)) * ((x1) - (y4))) - (((a4) * (theta_inv)) * ((x10) - (y4)));
	w_cross_X->arr[1] = (((a4) * (theta_inv)) * ((x11) - (y4))) - (((a4) * (theta_inv)) * ((x12) - (y4)));
	w_cross_X->arr[2] = (((a4) * (theta_inv)) * ((x13) - (y4))) - (((a4) * (theta_inv)) * ((x14) - (y4)));;
		array_number_t macroDef1536 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1536->length=(((0) + (2)) - (0)) + (1);
	macroDef1536->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1536->length; i1++){
			number_t a5 = cam->arr[(i1) + (0)];
			number_t x15 = (a5) * (theta_inv);
			number_t x2 = x0->arr[i1];
			number_t y5 = cam->arr[(i1) + (3)];
			number_t y00 = (x2) - (y5);
			macroDef1536->arr[i1] = (x15) * (y00);;
		}
		array_number_t v0 = macroDef1536;
		number_t macroDef1537 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef1537 = (macroDef1537) + (cur);;
	}
		number_t tmp = (macroDef1537) * ((1) - (costheta));
		card_t macroDef1538 = x0->length;
		array_number_t macroDef1539 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1539->length=macroDef1538;
	macroDef1539->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1538);
		for(int i1 = 0; i1 < macroDef1539->length; i1++){
			number_t x15 = x0->arr[i1];
			number_t y5 = cam->arr[(i1) + (3)];
			number_t a5 = (x15) - (y5);
			number_t x2 = (a5) * (costheta);
			number_t a00 = w_cross_X->arr[i1];
			number_t y00 = (a00) * (sintheta);
			number_t x3 = (x2) + (y00);
			number_t a10 = cam->arr[(i1) + (0)];
			number_t a20 = (a10) * (theta_inv);
			number_t y10 = (a20) * (tmp);
			macroDef1539->arr[i1] = (x3) + (y10);;
		}
		Xcam = macroDef1539;;
	} else {
		number_t x1 = x0->arr[2];
		number_t y = cam->arr[(2) + (3)];
		number_t x10 = x0->arr[1];
		number_t y0 = cam->arr[(1) + (3)];
		number_t x11 = x0->arr[0];
		number_t y1 = cam->arr[(0) + (3)];
		number_t x12 = x0->arr[2];
		number_t y2 = cam->arr[(2) + (3)];
		number_t x13 = x0->arr[1];
		number_t y3 = cam->arr[(1) + (3)];
		number_t x14 = x0->arr[0];
		number_t y4 = cam->arr[(0) + (3)];
		array_number_t y5 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y5->length=3;
	y5->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y5->arr[0] = ((cam->arr[(1) + (0)]) * ((x1) - (y4))) - ((cam->arr[(2) + (0)]) * ((x10) - (y4)));
	y5->arr[1] = ((cam->arr[(2) + (0)]) * ((x11) - (y4))) - ((cam->arr[(0) + (0)]) * ((x12) - (y4)));
	y5->arr[2] = ((cam->arr[(0) + (0)]) * ((x13) - (y4))) - ((cam->arr[(1) + (0)]) * ((x14) - (y4)));;
		card_t macroDef1540 = x0->length;
		array_number_t macroDef1541 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1541->length=macroDef1540;
	macroDef1541->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1540);
		for(int i1 = 0; i1 < macroDef1541->length; i1++){
			number_t x15 = x0->arr[i1];
			number_t y00 = cam->arr[(i1) + (3)];
			number_t x2 = (x15) - (y00);
			number_t y10 = y5->arr[i1];
			macroDef1541->arr[i1] = (x2) + (y10);;
		}
		Xcam = macroDef1541;;
	}
			number_t y = (1) / (Xcam->arr[2]);
			array_number_t macroDef1542 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1542->length=((1) - (0)) + (1);
	macroDef1542->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1542->length; i1++){
			number_t a = Xcam->arr[(i1) + (0)];
			number_t x1 = (a) * (y);
			macroDef1542->arr[i1] = (x1) * (x1);;
		}
			array_number_t v0 = macroDef1542;
			number_t macroDef1543 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef1543 = (macroDef1543) + (cur);;
	}
			number_t rsq = macroDef1543;
			number_t L = ((1) + ((cam->arr[(0) + (9)]) * (rsq))) + (((cam->arr[(1) + (9)]) * (rsq)) * (rsq));
			number_t y0 = cam->arr[6];
			array_number_t macroDef1544 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1544->length=(((7) + (1)) - (7)) + (1);
	macroDef1544->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1544->length; i1++){
			number_t x1 = cam->arr[(i1) + (7)];
			number_t a = Xcam->arr[(i1) + (0)];
			number_t a0 = (a) * (y);
			number_t a1 = (a0) * (L);
			number_t y1 = (a1) * (y0);
			number_t x2 = (x1) + (y1);
			number_t y2 = feat0->arr[i1];
			number_t a2 = (x2) - (y2);
			macroDef1544->arr[i1] = (a2) * (w0);;
		}
			macroDef1545->arr[i] = macroDef1544;;
		}
	return macroDef1545;
}
#endif
