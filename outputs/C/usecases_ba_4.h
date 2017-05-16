#ifndef __USECASES_BA_4_H__ 
#define __USECASES_BA_4_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"

array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_4(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef1463 = cams->length;
	card_t n = macroDef1463;
	card_t macroDef1464 = w->length;
	card_t p = macroDef1464;
	card_t s = 0;
	card_t e = (p) - (1);
	array_number_t macroDef1465 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1465->length=((e) - (s)) + (1);
	macroDef1465->arr = (number_t*)storage_alloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef1465->length; i++){
			
			macroDef1465->arr[i] = (double)(((s)) + (i));;
		}
	array_number_t range = macroDef1465;
	array_array_number_t macroDef1497 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1497->length=((e) - (s)) + (1);
	macroDef1497->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef1497->length; i++){
			index_t i0 = i;
			number_t i00 = (double)(((s)) + (i0));
			array_number_t cam = cams->arr[(int)(obs->arr[(int)(i00)]->arr[0])];
			array_number_t x0 = x->arr[(int)(obs->arr[(int)(i00)]->arr[1])];
			number_t w0 = w->arr[(int)(i00)];
			array_number_t feat0 = feat->arr[(int)(i00)];
			array_number_t macroDef1466 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1466->length=(((0) + (2)) - (0)) + (1);
	macroDef1466->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1466->length; i1++){
			
			macroDef1466->arr[i1] = cam->arr[(i1) + (0)];;
		}
			array_number_t rot = macroDef1466;
			array_number_t macroDef1467 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1467->length=(((3) + (2)) - (3)) + (1);
	macroDef1467->arr = (number_t*)storage_alloc(sizeof(number_t) * (((3) + (2)) - (3)) + (1));
		for(int i1 = 0; i1 < macroDef1467->length; i1++){
			
			macroDef1467->arr[i1] = cam->arr[(i1) + (3)];;
		}
			array_number_t y = macroDef1467;
			card_t macroDef1468 = x0->length;
			array_number_t macroDef1469 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1469->length=macroDef1468;
	macroDef1469->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1468);
		for(int i1 = 0; i1 < macroDef1469->length; i1++){
			number_t x1 = x0->arr[i1];
			index_t i2 = i1;
			number_t y0 = cam->arr[(i2) + (3)];
			macroDef1469->arr[i1] = (x1) - (y0);;
		}
			array_number_t x1 = macroDef1469;
			array_number_t macroDef1470 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1470->length=(((0) + (2)) - (0)) + (1);
	macroDef1470->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1470->length; i1++){
			index_t i2 = i1;
			number_t x10 = cam->arr[(i2) + (0)];
			macroDef1470->arr[i1] = (x10) * (x10);;
		}
			array_number_t v = macroDef1470;
			number_t macroDef1471 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef1471 = (macroDef1471) + (cur);;
	}
			number_t sqtheta = macroDef1471;
			array_number_t Xcam = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		array_number_t macroDef1472 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1472->length=(((0) + (2)) - (0)) + (1);
	macroDef1472->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1472->length; i1++){
			index_t i2 = i1;
			number_t a = cam->arr[(i2) + (0)];
			macroDef1472->arr[i1] = (a) * (theta_inv);;
		}
		array_number_t w1 = macroDef1472;
		index_t i1 = 1;
		index_t i2 = i1;
		number_t a = cam->arr[(i2) + (0)];
		index_t i10 = 2;
		number_t x2 = x0->arr[i10];
		index_t i20 = i10;
		number_t y0 = cam->arr[(i20) + (3)];
		index_t i11 = 2;
		index_t i21 = i11;
		number_t a0 = cam->arr[(i21) + (0)];
		index_t i12 = 1;
		number_t x20 = x0->arr[i12];
		index_t i22 = i12;
		number_t y00 = cam->arr[(i22) + (3)];
		index_t i13 = 2;
		index_t i23 = i13;
		number_t a1 = cam->arr[(i23) + (0)];
		index_t i14 = 0;
		number_t x21 = x0->arr[i14];
		index_t i24 = i14;
		number_t y01 = cam->arr[(i24) + (3)];
		index_t i15 = 0;
		index_t i25 = i15;
		number_t a2 = cam->arr[(i25) + (0)];
		index_t i16 = 2;
		number_t x22 = x0->arr[i16];
		index_t i26 = i16;
		number_t y02 = cam->arr[(i26) + (3)];
		index_t i17 = 0;
		index_t i27 = i17;
		number_t a3 = cam->arr[(i27) + (0)];
		index_t i18 = 1;
		number_t x23 = x0->arr[i18];
		index_t i28 = i18;
		number_t y03 = cam->arr[(i28) + (3)];
		index_t i19 = 1;
		index_t i29 = i19;
		number_t a4 = cam->arr[(i29) + (0)];
		index_t i110 = 0;
		number_t x24 = x0->arr[i110];
		index_t i210 = i110;
		number_t y04 = cam->arr[(i210) + (3)];
		array_number_t w_cross_X = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X->length=3;
	w_cross_X->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X->arr[0] = (((a4) * (theta_inv)) * ((x2) - (y0))) - (((a4) * (theta_inv)) * ((x20) - (y00)));
	w_cross_X->arr[1] = (((a4) * (theta_inv)) * ((x21) - (y01))) - (((a4) * (theta_inv)) * ((x22) - (y02)));
	w_cross_X->arr[2] = (((a4) * (theta_inv)) * ((x23) - (y03))) - (((a4) * (theta_inv)) * ((x24) - (y04)));;
		array_number_t macroDef1473 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1473->length=(((0) + (2)) - (0)) + (1);
	macroDef1473->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i111 = 0; i111 < macroDef1473->length; i111++){
			index_t i211 = i111;
			index_t i3 = i211;
			number_t a5 = cam->arr[(i3) + (0)];
			number_t x25 = (a5) * (theta_inv);
			index_t i212 = i111;
			number_t x3 = x0->arr[i212];
			index_t i30 = i212;
			number_t y05 = cam->arr[(i30) + (3)];
			number_t y06 = (x3) - (y05);
			macroDef1473->arr[i111] = (x25) * (y06);;
		}
		array_number_t v0 = macroDef1473;
		number_t macroDef1474 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef1474 = (macroDef1474) + (cur);;
	}
		number_t tmp = (macroDef1474) * ((1) - (costheta));
		card_t macroDef1475 = x0->length;
		array_number_t macroDef1476 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1476->length=macroDef1475;
	macroDef1476->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1475);
		for(int i111 = 0; i111 < macroDef1476->length; i111++){
			index_t i211 = i111;
			number_t x25 = x0->arr[i211];
			index_t i3 = i211;
			number_t y05 = cam->arr[(i3) + (3)];
			number_t a5 = (x25) - (y05);
			macroDef1476->arr[i111] = (a5) * (costheta);;
		}
		array_number_t v1 = macroDef1476;
		card_t macroDef1477 = w_cross_X->length;
		array_number_t macroDef1478 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1478->length=macroDef1477;
	macroDef1478->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1477);
		for(int i111 = 0; i111 < macroDef1478->length; i111++){
			number_t a5 = w_cross_X->arr[i111];
			macroDef1478->arr[i111] = (a5) * (sintheta);;
		}
		array_number_t v2 = macroDef1478;
		card_t macroDef1479 = x0->length;
		array_number_t macroDef1480 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1480->length=macroDef1479;
	macroDef1480->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1479);
		for(int i111 = 0; i111 < macroDef1480->length; i111++){
			index_t i211 = i111;
			index_t i3 = i211;
			number_t x25 = x0->arr[i3];
			index_t i4 = i3;
			number_t y05 = cam->arr[(i4) + (3)];
			number_t a5 = (x25) - (y05);
			number_t x26 = (a5) * (costheta);
			index_t i212 = i111;
			number_t a6 = w_cross_X->arr[i212];
			number_t y06 = (a6) * (sintheta);
			macroDef1480->arr[i111] = (x26) + (y06);;
		}
		array_number_t x25 = macroDef1480;
		array_number_t macroDef1481 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1481->length=(((0) + (2)) - (0)) + (1);
	macroDef1481->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i111 = 0; i111 < macroDef1481->length; i111++){
			index_t i211 = i111;
			index_t i3 = i211;
			number_t a5 = cam->arr[(i3) + (0)];
			number_t a6 = (a5) * (theta_inv);
			macroDef1481->arr[i111] = (a6) * (tmp);;
		}
		array_number_t y05 = macroDef1481;
		card_t macroDef1482 = x0->length;
		array_number_t macroDef1483 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1483->length=macroDef1482;
	macroDef1483->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1482);
		for(int i111 = 0; i111 < macroDef1483->length; i111++){
			index_t i211 = i111;
			index_t i3 = i211;
			index_t i4 = i3;
			number_t x3 = x0->arr[i4];
			index_t i5 = i4;
			number_t y1 = cam->arr[(i5) + (3)];
			number_t a5 = (x3) - (y1);
			number_t x30 = (a5) * (costheta);
			index_t i30 = i211;
			number_t a6 = w_cross_X->arr[i30];
			number_t y10 = (a6) * (sintheta);
			number_t x31 = (x30) + (y10);
			index_t i212 = i111;
			index_t i31 = i212;
			index_t i40 = i31;
			number_t a7 = cam->arr[(i40) + (0)];
			number_t a8 = (a7) * (theta_inv);
			number_t y11 = (a8) * (tmp);
			macroDef1483->arr[i111] = (x31) + (y11);;
		}
		Xcam = macroDef1483;;
	} else {
		index_t i1 = 1;
		index_t i10 = 2;
		number_t x2 = x0->arr[i10];
		index_t i2 = i10;
		number_t y0 = cam->arr[(i2) + (3)];
		index_t i11 = 2;
		index_t i12 = 1;
		number_t x20 = x0->arr[i12];
		index_t i20 = i12;
		number_t y00 = cam->arr[(i20) + (3)];
		index_t i13 = 2;
		index_t i14 = 0;
		number_t x21 = x0->arr[i14];
		index_t i21 = i14;
		number_t y01 = cam->arr[(i21) + (3)];
		index_t i15 = 0;
		index_t i16 = 2;
		number_t x22 = x0->arr[i16];
		index_t i22 = i16;
		number_t y02 = cam->arr[(i22) + (3)];
		index_t i17 = 0;
		index_t i18 = 1;
		number_t x23 = x0->arr[i18];
		index_t i23 = i18;
		number_t y03 = cam->arr[(i23) + (3)];
		index_t i19 = 1;
		index_t i110 = 0;
		number_t x24 = x0->arr[i110];
		index_t i24 = i110;
		number_t y04 = cam->arr[(i24) + (3)];
		array_number_t y05 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y05->length=3;
	y05->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y05->arr[0] = ((cam->arr[(i1) + (0)]) * ((x2) - (y0))) - ((cam->arr[(i11) + (0)]) * ((x20) - (y00)));
	y05->arr[1] = ((cam->arr[(i13) + (0)]) * ((x21) - (y01))) - ((cam->arr[(i15) + (0)]) * ((x22) - (y02)));
	y05->arr[2] = ((cam->arr[(i17) + (0)]) * ((x23) - (y03))) - ((cam->arr[(i19) + (0)]) * ((x24) - (y04)));;
		card_t macroDef1484 = x0->length;
		array_number_t macroDef1485 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1485->length=macroDef1484;
	macroDef1485->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1484);
		for(int i111 = 0; i111 < macroDef1485->length; i111++){
			index_t i25 = i111;
			number_t x25 = x0->arr[i25];
			index_t i3 = i25;
			number_t y1 = cam->arr[(i3) + (3)];
			number_t x26 = (x25) - (y1);
			number_t y10 = y05->arr[i111];
			macroDef1485->arr[i111] = (x26) + (y10);;
		}
		Xcam = macroDef1485;;
	}
			array_number_t macroDef1486 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1486->length=(((9) + (1)) - (9)) + (1);
	macroDef1486->arr = (number_t*)storage_alloc(sizeof(number_t) * (((9) + (1)) - (9)) + (1));
		for(int i1 = 0; i1 < macroDef1486->length; i1++){
			
			macroDef1486->arr[i1] = cam->arr[(i1) + (9)];;
		}
			array_number_t rad_params = macroDef1486;
			array_number_t macroDef1487 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1487->length=((1) - (0)) + (1);
	macroDef1487->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1487->length; i1++){
			
			macroDef1487->arr[i1] = Xcam->arr[(i1) + (0)];;
		}
			array_number_t x2 = macroDef1487;
			number_t y0 = (1) / (Xcam->arr[2]);
			array_number_t macroDef1488 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1488->length=((1) - (0)) + (1);
	macroDef1488->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1488->length; i1++){
			index_t i2 = i1;
			number_t a = Xcam->arr[(i2) + (0)];
			macroDef1488->arr[i1] = (a) * (y0);;
		}
			array_number_t proj = macroDef1488;
			array_number_t macroDef1489 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1489->length=((1) - (0)) + (1);
	macroDef1489->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1489->length; i1++){
			index_t i2 = i1;
			index_t i3 = i2;
			number_t a = Xcam->arr[(i3) + (0)];
			number_t x10 = (a) * (y0);
			macroDef1489->arr[i1] = (x10) * (x10);;
		}
			array_number_t v0 = macroDef1489;
			number_t macroDef1490 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef1490 = (macroDef1490) + (cur);;
	}
			number_t rsq = macroDef1490;
			index_t i1 = 0;
			index_t i10 = 1;
			number_t L = ((1) + ((cam->arr[(i1) + (9)]) * (rsq))) + (((cam->arr[(i10) + (9)]) * (rsq)) * (rsq));
			array_number_t macroDef1491 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1491->length=((1) - (0)) + (1);
	macroDef1491->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i11 = 0; i11 < macroDef1491->length; i11++){
			index_t i2 = i11;
			index_t i3 = i2;
			number_t a = Xcam->arr[(i3) + (0)];
			number_t a0 = (a) * (y0);
			macroDef1491->arr[i11] = (a0) * (L);;
		}
			array_number_t distorted = macroDef1491;
			array_number_t macroDef1492 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1492->length=(((7) + (1)) - (7)) + (1);
	macroDef1492->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i11 = 0; i11 < macroDef1492->length; i11++){
			
			macroDef1492->arr[i11] = cam->arr[(i11) + (7)];;
		}
			array_number_t x3 = macroDef1492;
			number_t y1 = cam->arr[6];
			array_number_t macroDef1493 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1493->length=((1) - (0)) + (1);
	macroDef1493->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i11 = 0; i11 < macroDef1493->length; i11++){
			index_t i2 = i11;
			index_t i3 = i2;
			index_t i4 = i3;
			number_t a = Xcam->arr[(i4) + (0)];
			number_t a0 = (a) * (y0);
			number_t a1 = (a0) * (L);
			macroDef1493->arr[i11] = (a1) * (y1);;
		}
			array_number_t y2 = macroDef1493;
			array_number_t macroDef1494 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1494->length=(((7) + (1)) - (7)) + (1);
	macroDef1494->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i11 = 0; i11 < macroDef1494->length; i11++){
			index_t i2 = i11;
			number_t x4 = cam->arr[(i2) + (7)];
			index_t i20 = i11;
			index_t i3 = i20;
			index_t i4 = i3;
			index_t i5 = i4;
			number_t a = Xcam->arr[(i5) + (0)];
			number_t a0 = (a) * (y0);
			number_t a1 = (a0) * (L);
			number_t y3 = (a1) * (y1);
			macroDef1494->arr[i11] = (x4) + (y3);;
		}
			array_number_t x4 = macroDef1494;
			array_number_t macroDef1495 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1495->length=(((7) + (1)) - (7)) + (1);
	macroDef1495->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i11 = 0; i11 < macroDef1495->length; i11++){
			index_t i2 = i11;
			index_t i3 = i2;
			number_t x5 = cam->arr[(i3) + (7)];
			index_t i30 = i2;
			index_t i4 = i30;
			index_t i5 = i4;
			index_t i6 = i5;
			number_t a = Xcam->arr[(i6) + (0)];
			number_t a0 = (a) * (y0);
			number_t a1 = (a0) * (L);
			number_t y3 = (a1) * (y1);
			number_t x50 = (x5) + (y3);
			number_t y30 = feat0->arr[i11];
			macroDef1495->arr[i11] = (x50) - (y30);;
		}
			array_number_t x5 = macroDef1495;
			array_number_t macroDef1496 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1496->length=(((7) + (1)) - (7)) + (1);
	macroDef1496->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i11 = 0; i11 < macroDef1496->length; i11++){
			index_t i2 = i11;
			index_t i3 = i2;
			index_t i4 = i3;
			number_t x6 = cam->arr[(i4) + (7)];
			index_t i40 = i3;
			index_t i5 = i40;
			index_t i6 = i5;
			index_t i7 = i6;
			number_t a = Xcam->arr[(i7) + (0)];
			number_t a0 = (a) * (y0);
			number_t a1 = (a0) * (L);
			number_t y3 = (a1) * (y1);
			number_t x60 = (x6) + (y3);
			number_t y30 = feat0->arr[i2];
			number_t a2 = (x60) - (y30);
			macroDef1496->arr[i11] = (a2) * (w0);;
		}
			macroDef1497->arr[i] = macroDef1496;;
		}
	return macroDef1497;
}
#endif
