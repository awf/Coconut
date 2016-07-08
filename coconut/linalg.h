#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

typedef struct env_t_5 {
	number_t y;
} env_t_5;
env_t_5* make_env_t_5(number_t y) {
	env_t_5* env = (env_t_5*)malloc(sizeof(env_t_5));
	env->y = y;
	return env;
}

number_t lambda5(env_t_5* env2, number_t a) {
	number_t y1 = env2->y;
	return a * y1;
}
array_number_t* linalg_mult_by_scalar(array_number_t* x, number_t y) {
	closure_t* closure4 = make_closure(lambda5, make_env_t_5(y));
	return array_map(closure4, x);
}

array_number_t* linalg_cross(array_number_t* a, array_number_t* b) {
	array_number_t* array6 = (array_number_t*)malloc(sizeof(array_number_t));
	array6->length=3;
	array6->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array6->arr[0] = a->arr[1] * b->arr[2] - a->arr[2] * b->arr[1];
	array6->arr[1] = a->arr[2] * b->arr[0] - a->arr[0] * b->arr[2];
	array6->arr[2] = a->arr[0] * b->arr[1] - a->arr[1] * b->arr[0];;
	return array6;
}
typedef struct env_t_10 {
	number_t dummy_variable;
} env_t_10;
env_t_10* make_env_t_10() {
	env_t_10* env = (env_t_10*)malloc(sizeof(env_t_10));
	
	return env;
}

number_t lambda10(env_t_10* env7, number_t x, number_t y) {
	
	return x + y;
}
array_number_t* linalg_add_vec(array_number_t* x, array_number_t* y) {
	closure_t* closure9 = make_closure(lambda10, make_env_t_10());
	return array_map2(closure9, x, y);
}

array_number_t* linalg_add_vec3(array_number_t* x, array_number_t* y, array_number_t* z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
}
typedef struct env_t_14 {
	number_t dummy_variable;
} env_t_14;
env_t_14* make_env_t_14() {
	env_t_14* env = (env_t_14*)malloc(sizeof(env_t_14));
	
	return env;
}

number_t lambda14(env_t_14* env11, number_t x, number_t y) {
	
	return x - y;
}
array_number_t* linalg_sub_vec(array_number_t* x, array_number_t* y) {
	closure_t* closure13 = make_closure(lambda14, make_env_t_14());
	return array_map2(closure13, x, y);
}
typedef struct env_t_18 {
	number_t dummy_variable;
} env_t_18;
env_t_18* make_env_t_18() {
	env_t_18* env = (env_t_18*)malloc(sizeof(env_t_18));
	
	return env;
}

number_t lambda18(env_t_18* env15, number_t x) {
	
	return x * x;
}
number_t linalg_sqnorm(array_number_t* x) {
	closure_t* closure17 = make_closure(lambda18, make_env_t_18());
	return array_sum(array_map(closure17, x));
}
typedef struct env_t_22 {
	number_t dummy_variable;
} env_t_22;
env_t_22* make_env_t_22() {
	env_t_22* env = (env_t_22*)malloc(sizeof(env_t_22));
	
	return env;
}

number_t lambda22(env_t_22* env19, number_t x, number_t y) {
	
	return x * y;
}
number_t linalg_dot_prod(array_number_t* x, array_number_t* y) {
	closure_t* closure21 = make_closure(lambda22, make_env_t_22());
	return array_sum(array_map2(closure21, x, y));
}

array_number_t* linalg_radial_distort(array_number_t* rad_params, array_number_t* proj) {
	number_t rsq = linalg_sqnorm(proj);
	number_t L = 1 + rad_params->arr[0] * rsq + rad_params->arr[1] * rsq * rsq;
	return linalg_mult_by_scalar(proj, L);
}

array_number_t* linalg_rodrigues_rotate_point(array_number_t* rot, array_number_t* x) {
	number_t sqtheta = linalg_sqnorm(rot);
	array_number_t* ite23 = NULL;
	if(sqtheta != 0) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = 1 / theta;
		array_number_t* w = linalg_mult_by_scalar(rot, theta_inv);
		array_number_t* w_cross_X = linalg_cross(w, x);
		number_t tmp = linalg_dot_prod(w, x) * 1 - costheta;
		array_number_t* v1 = linalg_mult_by_scalar(x, costheta);
		array_number_t* v2 = linalg_mult_by_scalar(w_cross_X, sintheta);
		ite23 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite23 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite23;
}

array_number_t* linalg_project(array_number_t* cam, array_number_t* x) {
	index_t N_CAM_PARAMS = 11;
	index_t ROT_IDX = 0;
	index_t CENTER_IDX = 3;
	index_t FOCAL_IDX = 6;
	index_t X0_IDX = 7;
	index_t RAD_IDX = 9;
	array_number_t* Xcam = linalg_rodrigues_rotate_point(array_slice(cam, ROT_IDX, ROT_IDX + 2), linalg_sub_vec(x, array_slice(cam, CENTER_IDX, CENTER_IDX + 2)));
	array_number_t* distorted = linalg_radial_distort(array_slice(cam, RAD_IDX, RAD_IDX + 1), linalg_mult_by_scalar(array_slice(Xcam, 0, 1), 1 / Xcam->arr[2]));
	return linalg_add_vec(array_slice(cam, X0_IDX, X0_IDX + 1), linalg_mult_by_scalar(distorted, cam->arr[FOCAL_IDX]));
}

array_number_t* linalg_compute_reproj_err(array_number_t* cam, array_number_t* x, number_t w, array_number_t* feat) {
	
	return linalg_mult_by_scalar(linalg_sub_vec(linalg_project(cam, x), feat), w);
}

number_t linalg_compute_zach_weight_error(number_t w) {
	
	return 1 - w * w;
}

void linalg_test1(array_number_t* dum) {
	array_number_t* a = (array_number_t*)malloc(sizeof(array_number_t));
	a->length=3;
	a->arr = (number_t*)malloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_number_t* b = (array_number_t*)malloc(sizeof(array_number_t));
	b->length=3;
	b->arr = (number_t*)malloc(sizeof(number_t) * 3);
	b->arr[0] = 5;
	b->arr[1] = 6;
	b->arr[2] = 7;;
	array_print(a);
	array_print(b);
	array_number_t* c = linalg_cross(a, b);
	array_print(c);
	array_number_t* d = linalg_mult_by_scalar(c, 15);
	array_print(d);
	array_number_t* e = linalg_add_vec(a, b);
	array_print(e);
	array_number_t* f = linalg_sub_vec(a, b);
	array_print(f);
	array_number_t* g = linalg_add_vec3(a, b, c);
	array_print(g);
	number_t h = linalg_sqnorm(a);
	number_print(h);
	number_t i = linalg_dot_prod(a, b);
	number_print(i);
	array_number_t* j = linalg_radial_distort(a, b);
	array_print(j);
	array_number_t* k = linalg_rodrigues_rotate_point(a, b);
	array_print(k);
	array_number_t* l = array_slice(k, 1, 2);
	array_print(l);
	array_number_t* cam = (array_number_t*)malloc(sizeof(array_number_t));
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
	array_number_t* m = linalg_project(cam, j);
	array_print(m);
	return ;
}
