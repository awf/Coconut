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
	array_number_t ite101 = 0;
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
		ite101 = TOP_LEVEL_linalg_vectorAdd(TOP_LEVEL_linalg_vectorAdd(v1, v2), TOP_LEVEL_linalg_mult_by_scalar(w, tmp));;
	} else {
		
		ite101 = TOP_LEVEL_linalg_vectorAdd(x, TOP_LEVEL_linalg_cross(rot, x));;
	}
	return ite101;
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
typedef empty_env_t env_t_105;


value_t lambda105(env_t_105* env102, number_t w0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error(w0);
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err(array_number_t w) {
	env_t_105 env_t_105_value = make_empty_env(); closure_t closure104 = make_closure(lambda105, &env_t_105_value);
	return TOP_LEVEL_linalg_vectorMap(closure104, w);
}
typedef struct env_t_116 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_116;
env_t_116 make_env_t_116(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_116 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda116(env_t_116* env113, number_t i) {
	array_array_number_t x112 = env113->x;
	array_number_t w111 = env113->w;
	array_array_number_t obs110 = env113->obs;
	array_array_number_t feat109 = env113->feat;
	array_array_number_t cams108 = env113->cams;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err(cams108->arr[(int)(obs110->arr[(int)(i)]->arr[0])], x112->arr[(int)(obs110->arr[(int)(i)]->arr[1])], w111->arr[(int)(i)], feat109->arr[(int)(i)]);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef106 = cams->length;
	card_t n = macroDef106;
	card_t macroDef107 = w->length;
	card_t p = macroDef107;
	array_number_t range = TOP_LEVEL_linalg_vectorRange(0, (p) - (1));
	env_t_116 env_t_116_value = make_env_t_116(x,w,obs,feat,cams); closure_t closure115 = make_closure(lambda116, &env_t_116_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure115, range);
}
typedef struct env_t_132 {
	number_t one_w;
} env_t_132;
env_t_132 make_env_t_132(number_t one_w) {
	env_t_132 env;
	env.one_w = one_w;
	return env;
}

value_t lambda132(env_t_132* env120, number_t x0) {
	number_t one_w119 = env120->one_w;
	value_t res;
	res.number_t_value = one_w119;
	return res;
}
typedef struct env_t_133 {
	array_number_t one_feat;
} env_t_133;
env_t_133 make_env_t_133(array_number_t one_feat) {
	env_t_133 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda133(env_t_133* env124, number_t x0) {
	array_number_t one_feat123 = env124->one_feat;
	value_t res;
	res.array_number_t_value = one_feat123;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file(string_t fn, card_t n, card_t m, card_t p) {
	card_t oneCard = 1;
	array_number_t one_cam = TOP_LEVEL_linalg_vectorRead(fn, 1, 11);
	array_array_number_t macroDef117 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef117->length=n;
	macroDef117->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * n);
		for(int x = 0; x < macroDef117->length; x++){
			
			macroDef117->arr[x] = one_cam;;
		}
	array_array_number_t cam = macroDef117;
	array_number_t one_x = TOP_LEVEL_linalg_vectorRead(fn, 2, 3);
	array_array_number_t macroDef118 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef118->length=m;
	macroDef118->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * m);
		for(int x = 0; x < macroDef118->length; x++){
			
			macroDef118->arr[x] = one_x;;
		}
	array_array_number_t x = macroDef118;
	number_t one_w = TOP_LEVEL_linalg_numberRead(fn, 3);
	env_t_132 env_t_132_value = make_env_t_132(one_w); closure_t closure122 = make_closure(lambda132, &env_t_132_value);
	array_number_t w = TOP_LEVEL_linalg_vectorMap(closure122, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_number_t one_feat = TOP_LEVEL_linalg_vectorRead(fn, 4, 2);
	env_t_133 env_t_133_value = make_env_t_133(one_feat); closure_t closure126 = make_closure(lambda133, &env_t_133_value);
	array_array_number_t feat = TOP_LEVEL_linalg_vectorMapToMatrix(closure126, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_array_number_t macroDef127 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef127->length=p;
	macroDef127->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * p);
		for(int x0 = 0; x0 < macroDef127->length; x0++){
			array_number_t array129 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array129->length=2;
	array129->arr = (number_t*)storage_alloc(sizeof(number_t) * 2);
	array129->arr[0] = (double)(((int)(x0)) % ((n)));
	array129->arr[1] = (double)(((int)(x0)) % ((m)));;
			macroDef127->arr[x0] = array129;;
		}
	array_array_number_t obs = macroDef127;
	timer_t t = tic();
	
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(1, 10)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(1, 10)->arr[cur_idx];
		array_array_number_t x0 = TOP_LEVEL_usecases_ba_reproj_err(cam, x, w, obs, feat);
		;
	}
	;
	toc(t, "BA");
	return TOP_LEVEL_usecases_ba_reproj_err(cam, x, w, obs, feat);
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
