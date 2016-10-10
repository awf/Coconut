#ifndef __USECASES_BA_H__ 
#define __USECASES_BA_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

array_number_t TOP_LEVEL_usecases_ba_radial_distort(array_number_t rad_params, array_number_t proj) {
	number_t rsq = TOP_LEVEL_linalg_sqnorm(proj);
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	return TOP_LEVEL_linalg_mult_by_scalar(proj, L);
}

array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point(array_number_t rot, array_number_t x) {
	number_t sqtheta = TOP_LEVEL_linalg_sqnorm(rot);
	array_number_t ite102 = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		array_number_t w = TOP_LEVEL_linalg_mult_by_scalar(rot, theta_inv);
		array_number_t w_cross_X = TOP_LEVEL_linalg_cross(w, x);
		number_t tmp = (TOP_LEVEL_linalg_dot_prod(w, x)) * ((1) - (costheta));
		array_number_t v1 = TOP_LEVEL_linalg_mult_by_scalar(x, costheta);
		array_number_t v2 = TOP_LEVEL_linalg_mult_by_scalar(w_cross_X, sintheta);
		ite102 = TOP_LEVEL_linalg_vectorAdd(TOP_LEVEL_linalg_vectorAdd(v1, v2), TOP_LEVEL_linalg_mult_by_scalar(w, tmp));;
	} else {
		
		ite102 = TOP_LEVEL_linalg_vectorAdd(x, TOP_LEVEL_linalg_cross(rot, x));;
	}
	return ite102;
}

array_number_t TOP_LEVEL_usecases_ba_project(array_number_t cam, array_number_t x) {
	index_t N_CAM_PARAMS = 11;
	index_t ROT_IDX = 0;
	index_t CENTER_IDX = 3;
	index_t FOCAL_IDX = 6;
	index_t X0_IDX = 7;
	index_t RAD_IDX = 9;
	array_number_t Xcam = TOP_LEVEL_usecases_ba_rodrigues_rotate_point(array_slice(cam, ROT_IDX, (ROT_IDX) + (2)), TOP_LEVEL_linalg_vectorSub(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2))));
	array_number_t distorted = TOP_LEVEL_usecases_ba_radial_distort(array_slice(cam, RAD_IDX, (RAD_IDX) + (1)), TOP_LEVEL_linalg_mult_by_scalar(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2])));
	return TOP_LEVEL_linalg_vectorAdd(array_slice(cam, X0_IDX, (X0_IDX) + (1)), TOP_LEVEL_linalg_mult_by_scalar(distorted, cam->arr[FOCAL_IDX]));
}

array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err(array_number_t cam, array_number_t x, number_t w, array_number_t feat) {
	
	return TOP_LEVEL_linalg_mult_by_scalar(TOP_LEVEL_linalg_vectorSub(TOP_LEVEL_usecases_ba_project(cam, x), feat), w);
}

number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error(number_t w) {
	
	return (1) - ((w) * (w));
}
typedef empty_env_t env_t_106;


value_t lambda106(env_t_106* env103, number_t w0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error(w0);
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err(array_number_t w) {
	env_t_106 env_t_106_value = make_empty_env(); closure_t closure105 = make_closure(lambda106, &env_t_106_value);
	return TOP_LEVEL_linalg_vectorMap(closure105, w);
}
typedef struct env_t_117 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_117;
env_t_117 make_env_t_117(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_117 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda117(env_t_117* env114, number_t i) {
	array_array_number_t x113 = env114->x;
	array_number_t w112 = env114->w;
	array_array_number_t obs111 = env114->obs;
	array_array_number_t feat110 = env114->feat;
	array_array_number_t cams109 = env114->cams;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err(cams109->arr[(int)(obs111->arr[(int)(i)]->arr[0])], x113->arr[(int)(obs111->arr[(int)(i)]->arr[1])], w112->arr[(int)(i)], feat110->arr[(int)(i)]);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef107 = cams->length;
	card_t n = macroDef107;
	card_t macroDef108 = w->length;
	card_t p = macroDef108;
	array_number_t range = TOP_LEVEL_linalg_vectorRange(0, (p) - (1));
	env_t_117 env_t_117_value = make_env_t_117(x,w,obs,feat,cams); closure_t closure116 = make_closure(lambda117, &env_t_117_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure116, range);
}
typedef struct env_t_133 {
	number_t one_w;
} env_t_133;
env_t_133 make_env_t_133(number_t one_w) {
	env_t_133 env;
	env.one_w = one_w;
	return env;
}

value_t lambda133(env_t_133* env121, number_t x0) {
	number_t one_w120 = env121->one_w;
	value_t res;
	res.number_t_value = one_w120;
	return res;
}
typedef struct env_t_134 {
	array_number_t one_feat;
} env_t_134;
env_t_134 make_env_t_134(array_number_t one_feat) {
	env_t_134 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda134(env_t_134* env125, number_t x0) {
	array_number_t one_feat124 = env125->one_feat;
	value_t res;
	res.array_number_t_value = one_feat124;
	return res;
}
void TOP_LEVEL_usecases_ba_run_ba_from_file(string_t fn, card_t n, card_t m, card_t p) {
	card_t oneCard = 1;
	array_number_t one_cam = TOP_LEVEL_linalg_vectorRead(fn, 1, 11);
	array_array_number_t macroDef118 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef118->length=n;
	macroDef118->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * n);
		for(int x = 0; x < macroDef118->length; x++){
			
			macroDef118->arr[x] = one_cam;;
		}
	array_array_number_t cam = macroDef118;
	array_number_t one_x = TOP_LEVEL_linalg_vectorRead(fn, 2, 3);
	array_array_number_t macroDef119 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef119->length=m;
	macroDef119->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * m);
		for(int x = 0; x < macroDef119->length; x++){
			
			macroDef119->arr[x] = one_x;;
		}
	array_array_number_t x = macroDef119;
	number_t one_w = TOP_LEVEL_linalg_numberRead(fn, 3);
	env_t_133 env_t_133_value = make_env_t_133(one_w); closure_t closure123 = make_closure(lambda133, &env_t_133_value);
	array_number_t w = TOP_LEVEL_linalg_vectorMap(closure123, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_number_t one_feat = TOP_LEVEL_linalg_vectorRead(fn, 4, 2);
	env_t_134 env_t_134_value = make_env_t_134(one_feat); closure_t closure127 = make_closure(lambda134, &env_t_134_value);
	array_array_number_t feat = TOP_LEVEL_linalg_vectorMapToMatrix(closure127, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_array_number_t macroDef128 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef128->length=p;
	macroDef128->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * p);
		for(int x0 = 0; x0 < macroDef128->length; x0++){
			array_number_t array130 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array130->length=2;
	array130->arr = (number_t*)storage_alloc(sizeof(number_t) * 2);
	array130->arr[0] = (double)(((int)(x0)) % ((n)));
	array130->arr[1] = (double)(((int)(x0)) % ((m)));;
			macroDef128->arr[x0] = array130;;
		}
	array_array_number_t obs = macroDef128;
	timer_t t = tic();
	array_number_t range = TOP_LEVEL_linalg_vectorRange(1, 10);
	
	for(int cur_idx = 0; cur_idx < range->length; cur_idx++){
		number_t cur = range->arr[cur_idx];
		array_array_number_t x0 = TOP_LEVEL_usecases_ba_reproj_err(cam, x, w, obs, feat);
		;
	}
	;
	toc(t, "BA");
	return ;
}

void TOP_LEVEL_usecases_ba_test_ba(array_number_t dum) {
	array_number_t a = (array_number_t)storage_alloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_number_t b = (array_number_t)storage_alloc(sizeof(int) * 2);
	b->length=3;
	b->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	b->arr[0] = 5;
	b->arr[1] = 6;
	b->arr[2] = 7;;
	array_print(a);
	array_print(b);
	array_number_t j = TOP_LEVEL_usecases_ba_radial_distort(a, b);
	array_print(j);
	array_number_t k = TOP_LEVEL_usecases_ba_rodrigues_rotate_point(a, b);
	array_print(k);
	array_number_t l = array_slice(k, 1, 2);
	array_print(l);
	array_number_t cam = (array_number_t)storage_alloc(sizeof(int) * 2);
	cam->length=11;
	cam->arr = (number_t*)storage_alloc(sizeof(number_t) * 11);
	cam->arr[0] = 0;
	cam->arr[1] = 2;
	cam->arr[2] = 4;
	cam->arr[3] = 6;
	cam->arr[4] = 8;
	cam->arr[5] = 10;
	cam->arr[6] = 12;
	cam->arr[7] = 14;
	cam->arr[8] = 16;
	cam->arr[9] = 18;
	cam->arr[10] = 20;;
	array_number_t m = TOP_LEVEL_usecases_ba_project(cam, j);
	array_print(m);
	return ;
}
#endif
