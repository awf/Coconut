#ifndef __USECASES_BA_5_H__ 
#define __USECASES_BA_5_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"

array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_5(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef1498 = cams->length;
	card_t n = macroDef1498;
	card_t macroDef1499 = w->length;
	card_t p = macroDef1499;
	card_t s = 0;
	card_t e = (p) - (1);
	array_number_t macroDef1500 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1500->length=((e) - (s)) + (1);
	macroDef1500->arr = (number_t*)storage_alloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef1500->length; i++){
			
			macroDef1500->arr[i] = (double)(((s)) + (i));;
		}
	array_number_t range = macroDef1500;
	array_array_number_t macroDef1532 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1532->length=((e) - (s)) + (1);
	macroDef1532->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef1532->length; i++){
			number_t i0 = (double)(((s)) + (i));
			array_number_t cam = cams->arr[(int)(obs->arr[(int)(i0)]->arr[0])];
			array_number_t x0 = x->arr[(int)(obs->arr[(int)(i0)]->arr[1])];
			number_t w0 = w->arr[(int)(i0)];
			array_number_t feat0 = feat->arr[(int)(i0)];
			array_number_t macroDef1501 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1501->length=(((0) + (2)) - (0)) + (1);
	macroDef1501->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1501->length; i1++){
			
			macroDef1501->arr[i1] = cam->arr[(i1) + (0)];;
		}
			array_number_t rot = macroDef1501;
			array_number_t macroDef1502 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1502->length=(((3) + (2)) - (3)) + (1);
	macroDef1502->arr = (number_t*)storage_alloc(sizeof(number_t) * (((3) + (2)) - (3)) + (1));
		for(int i1 = 0; i1 < macroDef1502->length; i1++){
			
			macroDef1502->arr[i1] = cam->arr[(i1) + (3)];;
		}
			array_number_t y = macroDef1502;
			card_t macroDef1503 = x0->length;
			array_number_t macroDef1504 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1504->length=macroDef1503;
	macroDef1504->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1503);
		for(int i1 = 0; i1 < macroDef1504->length; i1++){
			number_t x1 = x0->arr[i1];
			number_t y0 = cam->arr[(i1) + (3)];
			macroDef1504->arr[i1] = (x1) - (y0);;
		}
			array_number_t x1 = macroDef1504;
			array_number_t macroDef1505 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1505->length=(((0) + (2)) - (0)) + (1);
	macroDef1505->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1505->length; i1++){
			number_t x10 = cam->arr[(i1) + (0)];
			macroDef1505->arr[i1] = (x10) * (x10);;
		}
			array_number_t v = macroDef1505;
			number_t macroDef1506 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef1506 = (macroDef1506) + (cur);;
	}
			number_t sqtheta = macroDef1506;
			array_number_t Xcam = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		array_number_t macroDef1507 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1507->length=(((0) + (2)) - (0)) + (1);
	macroDef1507->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1507->length; i1++){
			number_t a = cam->arr[(i1) + (0)];
			macroDef1507->arr[i1] = (a) * (theta_inv);;
		}
		array_number_t w1 = macroDef1507;
		number_t a = cam->arr[(1) + (0)];
		number_t x2 = x0->arr[2];
		number_t y0 = cam->arr[(2) + (3)];
		number_t a0 = cam->arr[(2) + (0)];
		number_t x20 = x0->arr[1];
		number_t y00 = cam->arr[(1) + (3)];
		number_t a1 = cam->arr[(2) + (0)];
		number_t x21 = x0->arr[0];
		number_t y01 = cam->arr[(0) + (3)];
		number_t a2 = cam->arr[(0) + (0)];
		number_t x22 = x0->arr[2];
		number_t y02 = cam->arr[(2) + (3)];
		number_t a3 = cam->arr[(0) + (0)];
		number_t x23 = x0->arr[1];
		number_t y03 = cam->arr[(1) + (3)];
		number_t a4 = cam->arr[(1) + (0)];
		number_t x24 = x0->arr[0];
		number_t y04 = cam->arr[(0) + (3)];
		array_number_t w_cross_X = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X->length=3;
	w_cross_X->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X->arr[0] = (((a4) * (theta_inv)) * ((x2) - (y0))) - (((a4) * (theta_inv)) * ((x20) - (y00)));
	w_cross_X->arr[1] = (((a4) * (theta_inv)) * ((x21) - (y01))) - (((a4) * (theta_inv)) * ((x22) - (y02)));
	w_cross_X->arr[2] = (((a4) * (theta_inv)) * ((x23) - (y03))) - (((a4) * (theta_inv)) * ((x24) - (y04)));;
		array_number_t macroDef1508 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1508->length=(((0) + (2)) - (0)) + (1);
	macroDef1508->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1508->length; i1++){
			number_t a5 = cam->arr[(i1) + (0)];
			number_t x25 = (a5) * (theta_inv);
			number_t x3 = x0->arr[i1];
			number_t y05 = cam->arr[(i1) + (3)];
			number_t y1 = (x3) - (y05);
			macroDef1508->arr[i1] = (x25) * (y1);;
		}
		array_number_t v0 = macroDef1508;
		number_t macroDef1509 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef1509 = (macroDef1509) + (cur);;
	}
		number_t tmp = (macroDef1509) * ((1) - (costheta));
		card_t macroDef1510 = x0->length;
		array_number_t macroDef1511 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1511->length=macroDef1510;
	macroDef1511->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1510);
		for(int i1 = 0; i1 < macroDef1511->length; i1++){
			number_t x25 = x0->arr[i1];
			number_t y05 = cam->arr[(i1) + (3)];
			number_t a5 = (x25) - (y05);
			macroDef1511->arr[i1] = (a5) * (costheta);;
		}
		array_number_t v1 = macroDef1511;
		card_t macroDef1512 = w_cross_X->length;
		array_number_t macroDef1513 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1513->length=macroDef1512;
	macroDef1513->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1512);
		for(int i1 = 0; i1 < macroDef1513->length; i1++){
			number_t a5 = w_cross_X->arr[i1];
			macroDef1513->arr[i1] = (a5) * (sintheta);;
		}
		array_number_t v2 = macroDef1513;
		card_t macroDef1514 = x0->length;
		array_number_t macroDef1515 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1515->length=macroDef1514;
	macroDef1515->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1514);
		for(int i1 = 0; i1 < macroDef1515->length; i1++){
			number_t x25 = x0->arr[i1];
			number_t y05 = cam->arr[(i1) + (3)];
			number_t a5 = (x25) - (y05);
			number_t x3 = (a5) * (costheta);
			number_t a00 = w_cross_X->arr[i1];
			number_t y1 = (a00) * (sintheta);
			macroDef1515->arr[i1] = (x3) + (y1);;
		}
		array_number_t x25 = macroDef1515;
		array_number_t macroDef1516 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1516->length=(((0) + (2)) - (0)) + (1);
	macroDef1516->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1516->length; i1++){
			number_t a5 = cam->arr[(i1) + (0)];
			number_t a00 = (a5) * (theta_inv);
			macroDef1516->arr[i1] = (a00) * (tmp);;
		}
		array_number_t y05 = macroDef1516;
		card_t macroDef1517 = x0->length;
		array_number_t macroDef1518 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1518->length=macroDef1517;
	macroDef1518->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1517);
		for(int i1 = 0; i1 < macroDef1518->length; i1++){
			number_t x3 = x0->arr[i1];
			number_t y1 = cam->arr[(i1) + (3)];
			number_t a5 = (x3) - (y1);
			number_t x4 = (a5) * (costheta);
			number_t a00 = w_cross_X->arr[i1];
			number_t y2 = (a00) * (sintheta);
			number_t x5 = (x4) + (y2);
			number_t a10 = cam->arr[(i1) + (0)];
			number_t a20 = (a10) * (theta_inv);
			number_t y3 = (a20) * (tmp);
			macroDef1518->arr[i1] = (x5) + (y3);;
		}
		Xcam = macroDef1518;;
	} else {
		number_t x2 = x0->arr[2];
		number_t y0 = cam->arr[(2) + (3)];
		number_t x20 = x0->arr[1];
		number_t y00 = cam->arr[(1) + (3)];
		number_t x21 = x0->arr[0];
		number_t y01 = cam->arr[(0) + (3)];
		number_t x22 = x0->arr[2];
		number_t y02 = cam->arr[(2) + (3)];
		number_t x23 = x0->arr[1];
		number_t y03 = cam->arr[(1) + (3)];
		number_t x24 = x0->arr[0];
		number_t y04 = cam->arr[(0) + (3)];
		array_number_t y05 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y05->length=3;
	y05->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y05->arr[0] = ((cam->arr[(1) + (0)]) * ((x2) - (y0))) - ((cam->arr[(2) + (0)]) * ((x20) - (y00)));
	y05->arr[1] = ((cam->arr[(2) + (0)]) * ((x21) - (y01))) - ((cam->arr[(0) + (0)]) * ((x22) - (y02)));
	y05->arr[2] = ((cam->arr[(0) + (0)]) * ((x23) - (y03))) - ((cam->arr[(1) + (0)]) * ((x24) - (y04)));;
		card_t macroDef1519 = x0->length;
		array_number_t macroDef1520 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1520->length=macroDef1519;
	macroDef1520->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1519);
		for(int i1 = 0; i1 < macroDef1520->length; i1++){
			number_t x25 = x0->arr[i1];
			number_t y1 = cam->arr[(i1) + (3)];
			number_t x3 = (x25) - (y1);
			number_t y2 = y05->arr[i1];
			macroDef1520->arr[i1] = (x3) + (y2);;
		}
		Xcam = macroDef1520;;
	}
			array_number_t macroDef1521 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1521->length=(((9) + (1)) - (9)) + (1);
	macroDef1521->arr = (number_t*)storage_alloc(sizeof(number_t) * (((9) + (1)) - (9)) + (1));
		for(int i1 = 0; i1 < macroDef1521->length; i1++){
			
			macroDef1521->arr[i1] = cam->arr[(i1) + (9)];;
		}
			array_number_t rad_params = macroDef1521;
			array_number_t macroDef1522 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1522->length=((1) - (0)) + (1);
	macroDef1522->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1522->length; i1++){
			
			macroDef1522->arr[i1] = Xcam->arr[(i1) + (0)];;
		}
			array_number_t x2 = macroDef1522;
			number_t y0 = (1) / (Xcam->arr[2]);
			array_number_t macroDef1523 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1523->length=((1) - (0)) + (1);
	macroDef1523->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1523->length; i1++){
			number_t a = Xcam->arr[(i1) + (0)];
			macroDef1523->arr[i1] = (a) * (y0);;
		}
			array_number_t proj = macroDef1523;
			array_number_t macroDef1524 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1524->length=((1) - (0)) + (1);
	macroDef1524->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1524->length; i1++){
			number_t a = Xcam->arr[(i1) + (0)];
			number_t x10 = (a) * (y0);
			macroDef1524->arr[i1] = (x10) * (x10);;
		}
			array_number_t v0 = macroDef1524;
			number_t macroDef1525 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef1525 = (macroDef1525) + (cur);;
	}
			number_t rsq = macroDef1525;
			number_t L = ((1) + ((cam->arr[(0) + (9)]) * (rsq))) + (((cam->arr[(1) + (9)]) * (rsq)) * (rsq));
			array_number_t macroDef1526 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1526->length=((1) - (0)) + (1);
	macroDef1526->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1526->length; i1++){
			number_t a = Xcam->arr[(i1) + (0)];
			number_t a0 = (a) * (y0);
			macroDef1526->arr[i1] = (a0) * (L);;
		}
			array_number_t distorted = macroDef1526;
			array_number_t macroDef1527 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1527->length=(((7) + (1)) - (7)) + (1);
	macroDef1527->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1527->length; i1++){
			
			macroDef1527->arr[i1] = cam->arr[(i1) + (7)];;
		}
			array_number_t x3 = macroDef1527;
			number_t y1 = cam->arr[6];
			array_number_t macroDef1528 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1528->length=((1) - (0)) + (1);
	macroDef1528->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1528->length; i1++){
			number_t a = Xcam->arr[(i1) + (0)];
			number_t a0 = (a) * (y0);
			number_t a1 = (a0) * (L);
			macroDef1528->arr[i1] = (a1) * (y1);;
		}
			array_number_t y2 = macroDef1528;
			array_number_t macroDef1529 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1529->length=(((7) + (1)) - (7)) + (1);
	macroDef1529->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1529->length; i1++){
			number_t x4 = cam->arr[(i1) + (7)];
			number_t a = Xcam->arr[(i1) + (0)];
			number_t a0 = (a) * (y0);
			number_t a1 = (a0) * (L);
			number_t y3 = (a1) * (y1);
			macroDef1529->arr[i1] = (x4) + (y3);;
		}
			array_number_t x4 = macroDef1529;
			array_number_t macroDef1530 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1530->length=(((7) + (1)) - (7)) + (1);
	macroDef1530->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1530->length; i1++){
			number_t x5 = cam->arr[(i1) + (7)];
			number_t a = Xcam->arr[(i1) + (0)];
			number_t a0 = (a) * (y0);
			number_t a1 = (a0) * (L);
			number_t y3 = (a1) * (y1);
			number_t x6 = (x5) + (y3);
			number_t y4 = feat0->arr[i1];
			macroDef1530->arr[i1] = (x6) - (y4);;
		}
			array_number_t x5 = macroDef1530;
			array_number_t macroDef1531 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1531->length=(((7) + (1)) - (7)) + (1);
	macroDef1531->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1531->length; i1++){
			number_t x6 = cam->arr[(i1) + (7)];
			number_t a = Xcam->arr[(i1) + (0)];
			number_t a0 = (a) * (y0);
			number_t a1 = (a0) * (L);
			number_t y3 = (a1) * (y1);
			number_t x7 = (x6) + (y3);
			number_t y4 = feat0->arr[i1];
			number_t a2 = (x7) - (y4);
			macroDef1531->arr[i1] = (a2) * (w0);;
		}
			macroDef1532->arr[i] = macroDef1531;;
		}
	return macroDef1532;
}
#endif
