#ifndef __USECASES_BA_D_H__ 
#define __USECASES_BA_D_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "usecases_ba.h"
#include "linalg_d.h"

array_number_t TOP_LEVEL_usecases_ba_project_d(array_number_t cam, array_number_t x, array_number_t cam_d, array_number_t x_d) {
	card_t l = 3;
	number_t macroDef1292 = 0;
	for(int idx = 0; idx < l; idx++){
		number_t x1 = cam->arr[idx];
		number_t cur = (x1) * (x1);
		macroDef1292 = (macroDef1292) + (cur);;
	}
	number_t sqtheta = macroDef1292;
	number_t macroDef1293 = 0;
	for(int idx = 0; idx < l; idx++){
		number_t x1 = cam->arr[idx];
		number_t x1_d = cam_d->arr[idx];
		number_t cur_d = ((x1_d) * (x1)) + ((x1) * (x1_d));
		macroDef1293 = (macroDef1293) + (cur_d);;
	}
	number_t sqtheta_d = macroDef1293;
	array_number_t Xcam = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		number_t xi = cam->arr[1];
		number_t x0 = x->arr[2];
		number_t y = cam->arr[5];
		number_t xi0 = cam->arr[2];
		number_t x00 = x->arr[1];
		number_t y0 = cam->arr[4];
		number_t x01 = x->arr[0];
		number_t y1 = cam->arr[3];
		number_t xi2 = cam->arr[0];
		number_t x02 = x->arr[2];
		number_t x03 = x->arr[1];
		number_t x04 = x->arr[0];
		array_number_t w_cross_X = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X->length=3;
	w_cross_X->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X->arr[0] = (((xi) * (theta_inv)) * ((x0) - (y1))) - (((xi) * (theta_inv)) * ((x00) - (y1)));
	w_cross_X->arr[1] = (((xi) * (theta_inv)) * ((x01) - (y1))) - (((xi) * (theta_inv)) * ((x02) - (y1)));
	w_cross_X->arr[2] = (((xi) * (theta_inv)) * ((x03) - (y1))) - (((xi) * (theta_inv)) * ((x04) - (y1)));;
		number_t macroDef1294 = 0;
	for(int idx = 0; idx < l; idx++){
		number_t xi5 = cam->arr[idx];
		number_t x05 = (xi5) * (theta_inv);
		number_t x1 = x->arr[idx];
		number_t y5 = cam->arr[(idx) + (3)];
		number_t y00 = (x1) - (y5);
		number_t cur = (x05) * (y00);
		macroDef1294 = (macroDef1294) + (cur);;
	}
		number_t tmp = (macroDef1294) * ((1) - (costheta));
		card_t macroDef1295 = x->length;
		array_number_t macroDef1296 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1296->length=macroDef1295;
	macroDef1296->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1295);
		for(int i = 0; i < macroDef1296->length; i++){
			number_t x05 = x->arr[i];
			number_t y5 = cam->arr[(i) + (3)];
			number_t xi5 = (x05) - (y5);
			number_t x1 = (xi5) * (costheta);
			number_t xi00 = w_cross_X->arr[i];
			number_t y00 = (xi00) * (sintheta);
			number_t x2 = (x1) + (y00);
			number_t xi10 = cam->arr[i];
			number_t xi20 = (xi10) * (theta_inv);
			number_t y10 = (xi20) * (tmp);
			macroDef1296->arr[i] = (x2) + (y10);;
		}
		Xcam = macroDef1296;;
	} else {
		number_t x0 = x->arr[2];
		number_t y = cam->arr[5];
		number_t x00 = x->arr[1];
		number_t y0 = cam->arr[4];
		number_t x01 = x->arr[0];
		number_t y1 = cam->arr[3];
		number_t x02 = x->arr[2];
		number_t x03 = x->arr[1];
		number_t x04 = x->arr[0];
		array_number_t y5 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y5->length=3;
	y5->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y5->arr[0] = ((cam->arr[1]) * ((x0) - (y1))) - ((cam->arr[2]) * ((x00) - (y1)));
	y5->arr[1] = ((cam->arr[2]) * ((x01) - (y1))) - ((cam->arr[0]) * ((x02) - (y1)));
	y5->arr[2] = ((cam->arr[0]) * ((x03) - (y1))) - ((cam->arr[1]) * ((x04) - (y1)));;
		card_t macroDef1297 = x->length;
		array_number_t macroDef1298 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1298->length=macroDef1297;
	macroDef1298->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1297);
		for(int i = 0; i < macroDef1298->length; i++){
			number_t x05 = x->arr[i];
			number_t y00 = cam->arr[(i) + (3)];
			number_t x1 = (x05) - (y00);
			number_t y10 = y5->arr[i];
			macroDef1298->arr[i] = (x1) + (y10);;
		}
		Xcam = macroDef1298;;
	}
	array_number_t Xcam_d = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t theta_d = (sqtheta_d) / ((2) * (sqtheta));
		number_t costheta = cos(theta);
		number_t costheta_d = (theta_d) * (-(sin(theta)));
		number_t sintheta = sin(theta);
		number_t sintheta_d = (theta_d) * (costheta);
		number_t theta_inv = (1) / (theta);
		number_t theta_inv_d = (((0) * (theta)) - ((1) * (theta_d))) / ((theta) * (theta));
		number_t xi = cam->arr[1];
		number_t x0 = x->arr[2];
		number_t y = cam->arr[5];
		number_t xi0 = cam->arr[2];
		number_t x00 = x->arr[1];
		number_t y0 = cam->arr[4];
		number_t x01 = x->arr[0];
		number_t y1 = cam->arr[3];
		number_t xi2 = cam->arr[0];
		number_t x02 = x->arr[2];
		number_t x03 = x->arr[1];
		number_t x04 = x->arr[0];
		array_number_t w_cross_X = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X->length=3;
	w_cross_X->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X->arr[0] = (((xi) * (theta_inv)) * ((x0) - (y1))) - (((xi) * (theta_inv)) * ((x00) - (y1)));
	w_cross_X->arr[1] = (((xi) * (theta_inv)) * ((x01) - (y1))) - (((xi) * (theta_inv)) * ((x02) - (y1)));
	w_cross_X->arr[2] = (((xi) * (theta_inv)) * ((x03) - (y1))) - (((xi) * (theta_inv)) * ((x04) - (y1)));;
		number_t xi_d = cam_d->arr[1];
		number_t x0_d = x_d->arr[2];
		number_t y_d = cam_d->arr[5];
		number_t xi_d0 = cam_d->arr[2];
		number_t x0_d0 = x_d->arr[1];
		number_t y_d0 = cam_d->arr[4];
		number_t x0_d1 = x_d->arr[0];
		number_t y_d1 = cam_d->arr[3];
		number_t xi_d2 = cam_d->arr[0];
		number_t x0_d2 = x_d->arr[2];
		number_t x0_d3 = x_d->arr[1];
		number_t x0_d4 = x_d->arr[0];
		array_number_t w_cross_X_d = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X_d->length=3;
	w_cross_X_d->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X_d->arr[0] = (((((xi_d) * (theta_inv)) + ((xi) * (theta_inv_d))) * ((x0) - (y1))) + (((xi) * (theta_inv)) * ((x0_d) - (y_d1)))) - (((((xi_d) * (theta_inv)) + ((xi) * (theta_inv_d))) * ((x00) - (y1))) + (((xi) * (theta_inv)) * ((x0_d0) - (y_d1))));
	w_cross_X_d->arr[1] = (((((xi_d) * (theta_inv)) + ((xi) * (theta_inv_d))) * ((x01) - (y1))) + (((xi) * (theta_inv)) * ((x0_d1) - (y_d1)))) - (((((xi_d) * (theta_inv)) + ((xi) * (theta_inv_d))) * ((x02) - (y1))) + (((xi) * (theta_inv)) * ((x0_d2) - (y_d1))));
	w_cross_X_d->arr[2] = (((((xi_d) * (theta_inv)) + ((xi) * (theta_inv_d))) * ((x03) - (y1))) + (((xi) * (theta_inv)) * ((x0_d3) - (y_d1)))) - (((((xi_d) * (theta_inv)) + ((xi) * (theta_inv_d))) * ((x04) - (y1))) + (((xi) * (theta_inv)) * ((x0_d4) - (y_d1))));;
		number_t macroDef1299 = 0;
	for(int idx = 0; idx < l; idx++){
		number_t xi17 = cam->arr[idx];
		number_t x011 = (xi17) * (theta_inv);
		number_t x1 = x->arr[idx];
		number_t y11 = cam->arr[(idx) + (3)];
		number_t y00 = (x1) - (y11);
		number_t cur = (x011) * (y00);
		macroDef1299 = (macroDef1299) + (cur);;
	}
		number_t tmp = (macroDef1299) * ((1) - (costheta));
		number_t macroDef1300 = 0;
	for(int idx = 0; idx < l; idx++){
		number_t xi17 = cam->arr[idx];
		number_t xi_d5 = cam_d->arr[idx];
		number_t x011 = (xi17) * (theta_inv);
		number_t x0_d5 = ((xi_d5) * (theta_inv)) + ((xi17) * (theta_inv_d));
		number_t x1 = x->arr[idx];
		number_t x1_d = x_d->arr[idx];
		number_t y11 = cam->arr[(idx) + (3)];
		number_t y_d5 = cam_d->arr[(idx) + (3)];
		number_t y00 = (x1) - (y11);
		number_t y0_d = (x1_d) - (y_d5);
		number_t cur_d = ((x0_d5) * (y00)) + ((x011) * (y0_d));
		macroDef1300 = (macroDef1300) + (cur_d);;
	}
		number_t macroDef1301 = 0;
	for(int idx = 0; idx < l; idx++){
		number_t xi17 = cam->arr[idx];
		number_t x011 = (xi17) * (theta_inv);
		number_t x1 = x->arr[idx];
		number_t y11 = cam->arr[(idx) + (3)];
		number_t y00 = (x1) - (y11);
		number_t cur = (x011) * (y00);
		macroDef1301 = (macroDef1301) + (cur);;
	}
		number_t tmp_d = ((macroDef1300) * ((1) - (costheta))) + ((macroDef1301) * ((0) - (costheta_d)));
		card_t macroDef1302 = x->length;
		array_number_t macroDef1303 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1303->length=macroDef1302;
	macroDef1303->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1302);
		for(int i = 0; i < macroDef1303->length; i++){
			number_t x011 = x->arr[i];
			number_t x0_d5 = x_d->arr[i];
			number_t y11 = cam->arr[(i) + (3)];
			number_t y_d5 = cam_d->arr[(i) + (3)];
			number_t xi17 = (x011) - (y11);
			number_t xi_d5 = (x0_d5) - (y_d5);
			number_t x1_d = ((xi_d5) * (costheta)) + ((xi17) * (costheta_d));
			number_t xi00 = w_cross_X->arr[i];
			number_t xi0_d = w_cross_X_d->arr[i];
			number_t y0_d = ((xi0_d) * (sintheta)) + ((xi00) * (sintheta_d));
			number_t x2_d = (x1_d) + (y0_d);
			number_t xi18 = cam->arr[i];
			number_t xi1_d = cam_d->arr[i];
			number_t xi20 = (xi18) * (theta_inv);
			number_t xi2_d = ((xi1_d) * (theta_inv)) + ((xi18) * (theta_inv_d));
			number_t y1_d = ((xi2_d) * (tmp)) + ((xi20) * (tmp_d));
			macroDef1303->arr[i] = (x2_d) + (y1_d);;
		}
		Xcam_d = macroDef1303;;
	} else {
		number_t x0 = x->arr[2];
		number_t y = cam->arr[5];
		number_t x0_d = x_d->arr[2];
		number_t y_d = cam_d->arr[5];
		number_t x00 = x->arr[1];
		number_t y0 = cam->arr[4];
		number_t x0_d0 = x_d->arr[1];
		number_t y_d0 = cam_d->arr[4];
		number_t x01 = x->arr[0];
		number_t y1 = cam->arr[3];
		number_t x0_d1 = x_d->arr[0];
		number_t y_d1 = cam_d->arr[3];
		number_t x02 = x->arr[2];
		number_t x0_d2 = x_d->arr[2];
		number_t x03 = x->arr[1];
		number_t x0_d3 = x_d->arr[1];
		number_t x04 = x->arr[0];
		number_t x0_d4 = x_d->arr[0];
		array_number_t y_d5 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y_d5->length=3;
	y_d5->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y_d5->arr[0] = (((cam_d->arr[1]) * ((x0) - (y1))) + ((cam->arr[1]) * ((x0_d) - (y_d1)))) - (((cam_d->arr[2]) * ((x00) - (y1))) + ((cam->arr[2]) * ((x0_d0) - (y_d1))));
	y_d5->arr[1] = (((cam_d->arr[2]) * ((x01) - (y1))) + ((cam->arr[2]) * ((x0_d1) - (y_d1)))) - (((cam_d->arr[0]) * ((x02) - (y1))) + ((cam->arr[0]) * ((x0_d2) - (y_d1))));
	y_d5->arr[2] = (((cam_d->arr[0]) * ((x03) - (y1))) + ((cam->arr[0]) * ((x0_d3) - (y_d1)))) - (((cam_d->arr[1]) * ((x04) - (y1))) + ((cam->arr[1]) * ((x0_d4) - (y_d1))));;
		card_t macroDef1304 = x->length;
		array_number_t macroDef1305 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1305->length=macroDef1304;
	macroDef1305->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1304);
		for(int i = 0; i < macroDef1305->length; i++){
			number_t x0_d5 = x_d->arr[i];
			number_t y0_d = cam_d->arr[(i) + (3)];
			number_t x1_d = (x0_d5) - (y0_d);
			number_t y1_d = y_d5->arr[i];
			macroDef1305->arr[i] = (x1_d) + (y1_d);;
		}
		Xcam_d = macroDef1305;;
	}
	number_t y = (1) / (Xcam->arr[2]);
	number_t y_d = (((0) * (Xcam->arr[2])) - ((1) * (Xcam_d->arr[2]))) / ((Xcam->arr[2]) * (Xcam->arr[2]));
	card_t l0 = 2;
	number_t macroDef1306 = 0;
	for(int idx = 0; idx < l0; idx++){
		number_t xi = Xcam->arr[idx];
		number_t x1 = (xi) * (y);
		number_t cur = (x1) * (x1);
		macroDef1306 = (macroDef1306) + (cur);;
	}
	number_t rsq = macroDef1306;
	number_t macroDef1307 = 0;
	for(int idx = 0; idx < l0; idx++){
		number_t xi = Xcam->arr[idx];
		number_t xi_d = Xcam_d->arr[idx];
		number_t x1 = (xi) * (y);
		number_t x1_d = ((xi_d) * (y)) + ((xi) * (y_d));
		number_t cur_d = ((x1_d) * (x1)) + ((x1) * (x1_d));
		macroDef1307 = (macroDef1307) + (cur_d);;
	}
	number_t rsq_d = macroDef1307;
	number_t L = ((1) + ((cam->arr[9]) * (rsq))) + (((cam->arr[10]) * (rsq)) * (rsq));
	number_t L_d = ((0) + (((cam_d->arr[9]) * (rsq)) + ((cam->arr[9]) * (rsq_d)))) + (((((cam_d->arr[10]) * (rsq)) + ((cam->arr[10]) * (rsq_d))) * (rsq)) + (((cam->arr[10]) * (rsq)) * (rsq_d)));
	number_t y0 = cam->arr[6];
	number_t y0_d = cam_d->arr[6];
	array_number_t macroDef1308 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1308->length=l0;
	macroDef1308->arr = (number_t*)storage_alloc(sizeof(number_t) * l0);
		for(int i = 0; i < macroDef1308->length; i++){
			number_t x0_d = cam_d->arr[(i) + (7)];
			number_t xi = Xcam->arr[i];
			number_t xi_d = Xcam_d->arr[i];
			number_t xi0 = (xi) * (y);
			number_t xi0_d = ((xi_d) * (y)) + ((xi) * (y_d));
			number_t xi1 = (xi0) * (L);
			number_t xi1_d = ((xi0_d) * (L)) + ((xi0) * (L_d));
			number_t y1_d = ((xi1_d) * (y0)) + ((xi1) * (y0_d));
			macroDef1308->arr[i] = (x0_d) + (y1_d);;
		}
	return macroDef1308;
}

#endif