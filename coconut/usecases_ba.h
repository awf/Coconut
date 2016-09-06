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
	array_number_t ite85 = 0;
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
		ite85 = TOP_LEVEL_linalg_add_vec(TOP_LEVEL_linalg_add_vec(v1, v2), TOP_LEVEL_linalg_mult_by_scalar(w, tmp));;
	} else {
		
		ite85 = TOP_LEVEL_linalg_add_vec(x, TOP_LEVEL_linalg_cross(rot, x));;
	}
	return ite85;
}

array_number_t TOP_LEVEL_usecases_ba_project(array_number_t cam, array_number_t x) {
	index_t N_CAM_PARAMS = 11;
	index_t ROT_IDX = 0;
	index_t CENTER_IDX = 3;
	index_t FOCAL_IDX = 6;
	index_t X0_IDX = 7;
	index_t RAD_IDX = 9;
	array_number_t Xcam = TOP_LEVEL_usecases_ba_rodrigues_rotate_point(array_slice(cam, ROT_IDX, (ROT_IDX) + (2)), TOP_LEVEL_linalg_sub_vec(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2))));
	array_number_t distorted = TOP_LEVEL_usecases_ba_radial_distort(array_slice(cam, RAD_IDX, (RAD_IDX) + (1)), TOP_LEVEL_linalg_mult_by_scalar(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2])));
	return TOP_LEVEL_linalg_add_vec(array_slice(cam, X0_IDX, (X0_IDX) + (1)), TOP_LEVEL_linalg_mult_by_scalar(distorted, cam->arr[FOCAL_IDX]));
}

array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err(array_number_t cam, array_number_t x, number_t w, array_number_t feat) {
	
	return TOP_LEVEL_linalg_mult_by_scalar(TOP_LEVEL_linalg_sub_vec(TOP_LEVEL_usecases_ba_project(cam, x), feat), w);
}

number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error(number_t w) {
	
	return (1) - ((w) * (w));
}
typedef empty_env_t env_t_89;


value_t lambda89(env_t_89* env86, number_t w) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error(w);
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err(array_number_t w) {
	env_t_89 env_t_89_value = make_empty_env(); closure_t closure88 = make_closure(lambda89, &env_t_89_value);
	return TOP_LEVEL_linalg_vectorMap(closure88, w);
}
typedef struct env_t_100 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_100;
env_t_100 make_env_t_100(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_100 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda100(env_t_100* env97, number_t i) {
	array_array_number_t x96 = env97->x;
	array_number_t w95 = env97->w;
	array_array_number_t obs94 = env97->obs;
	array_array_number_t feat93 = env97->feat;
	array_array_number_t cams92 = env97->cams;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err(cams92->arr[(int)(obs94->arr[(int)(i)]->arr[0])], x96->arr[(int)(obs94->arr[(int)(i)]->arr[1])], w95->arr[(int)(i)], feat93->arr[(int)(i)]);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef90 = cams->length;
	card_t n = macroDef90;
	card_t macroDef91 = w->length;
	card_t p = macroDef91;
	array_number_t range = TOP_LEVEL_linalg_vectorRange(0, (p) - (1));
	env_t_100 env_t_100_value = make_env_t_100(x,w,obs,feat,cams); closure_t closure99 = make_closure(lambda100, &env_t_100_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure99, range);
}
typedef struct env_t_114 {
	number_t one_w;
} env_t_114;
env_t_114 make_env_t_114(number_t one_w) {
	env_t_114 env;
	env.one_w = one_w;
	return env;
}

value_t lambda114(env_t_114* env104, number_t x) {
	number_t one_w103 = env104->one_w;
	value_t res;
	res.number_t_value = one_w103;
	return res;
}
typedef struct env_t_115 {
	array_number_t one_feat;
} env_t_115;
env_t_115 make_env_t_115(array_number_t one_feat) {
	env_t_115 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda115(env_t_115* env108, number_t x) {
	array_number_t one_feat107 = env108->one_feat;
	value_t res;
	res.array_number_t_value = one_feat107;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file(string_t fn) {
	array_number_t nmp = TOP_LEVEL_linalg_vectorRead(fn, 0);
	card_t n = (int)(nmp->arr[0]);
	card_t m = (int)(nmp->arr[1]);
	card_t p = (int)(nmp->arr[2]);
	card_t oneCard = 1;
	array_number_t one_cam = TOP_LEVEL_linalg_vectorRead(fn, 1);
	array_array_number_t macroDef101 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef101->length=n;
	macroDef101->arr = (array_number_t*)malloc(sizeof(array_number_t) * n);
		for(int x = 0; x < macroDef101->length; x++){
			
			macroDef101->arr[x] = one_cam;;
		}
	array_array_number_t cam = macroDef101;
	array_number_t one_x = TOP_LEVEL_linalg_vectorRead(fn, 2);
	array_array_number_t macroDef102 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef102->length=m;
	macroDef102->arr = (array_number_t*)malloc(sizeof(array_number_t) * m);
		for(int x = 0; x < macroDef102->length; x++){
			
			macroDef102->arr[x] = one_x;;
		}
	array_array_number_t x = macroDef102;
	number_t one_w = TOP_LEVEL_linalg_numberRead(fn, 3);
	env_t_114 env_t_114_value = make_env_t_114(one_w); closure_t closure106 = make_closure(lambda114, &env_t_114_value);
	array_number_t w = TOP_LEVEL_linalg_vectorMap(closure106, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_number_t one_feat = TOP_LEVEL_linalg_vectorRead(fn, 4);
	env_t_115 env_t_115_value = make_env_t_115(one_feat); closure_t closure110 = make_closure(lambda115, &env_t_115_value);
	array_array_number_t feat = TOP_LEVEL_linalg_vectorMapToMatrix(closure110, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_array_number_t macroDef111 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef111->length=p;
	macroDef111->arr = (array_number_t*)malloc(sizeof(array_number_t) * p);
		for(int x = 0; x < macroDef111->length; x++){
			array_number_t array112 = (array_number_t)malloc(sizeof(int) * 2);
	array112->length=2;
	array112->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array112->arr[0] = (double)(((int)(x)) % ((n)));
	array112->arr[1] = (double)(((int)(x)) % ((m)));;
			macroDef111->arr[x] = array112;;
		}
	array_array_number_t obs = macroDef111;
	timer_t t = tic();
	array_array_number_t res = TOP_LEVEL_usecases_ba_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}

void TOP_LEVEL_usecases_ba_test_ba(array_number_t dum) {
	array_number_t a = (array_number_t)malloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)malloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_number_t b = (array_number_t)malloc(sizeof(int) * 2);
	b->length=3;
	b->arr = (number_t*)malloc(sizeof(number_t) * 3);
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
	array_number_t cam = (array_number_t)malloc(sizeof(int) * 2);
	cam->length=11;
	cam->arr = (number_t*)malloc(sizeof(number_t) * 11);
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
