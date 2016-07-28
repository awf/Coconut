#ifndef __LINALG_H__ 
#define __LINALG_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_number_t linalg_vectorMap(closure_t* f, array_number_t arr) {
	
	return array_map(f, arr);
}

array_number_t linalg_vectorRange(index_t s, index_t e) {
	
	return array_range(s, e);
}
typedef struct env_t_5 {
	number_t y;
} env_t_5;
env_t_5* make_env_t_5(number_t y) {
	env_t_5* env = (env_t_5*)malloc(sizeof(env_t_5));
	env->y = y;
	return env;
}

value_t lambda5(env_t_5* env2, number_t a) {
	number_t y1 = env2->y;
	value_t res;
	res.number_t_value = (a) * (y1);
	return res;
}
array_number_t linalg_mult_by_scalar(array_number_t x, number_t y) {
	closure_t* closure4 = make_closure(lambda5, make_env_t_5(y));
	return linalg_vectorMap(closure4, x);
}

array_number_t linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array6 = (array_number_t)malloc(sizeof(int) * 2);
	array6->length=3;
	array6->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array6->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array6->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array6->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array6;
}
typedef struct env_t_10 {
	value_t dummy_variable;
} env_t_10;
env_t_10* make_env_t_10() {
	env_t_10* env = (env_t_10*)malloc(sizeof(env_t_10));
	
	return env;
}

value_t lambda10(env_t_10* env7, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vec(array_number_t x, array_number_t y) {
	closure_t* closure9 = make_closure(lambda10, make_env_t_10());
	return array_map2(closure9, x, y);
}
typedef struct env_t_14 {
	value_t dummy_variable;
} env_t_14;
env_t_14* make_env_t_14() {
	env_t_14* env = (env_t_14*)malloc(sizeof(env_t_14));
	
	return env;
}

value_t lambda14(env_t_14* env11, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	closure_t* closure13 = make_closure(lambda14, make_env_t_14());
	return array_map2(closure13, x, y);
}

array_number_t linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
}
typedef struct env_t_18 {
	value_t dummy_variable;
} env_t_18;
env_t_18* make_env_t_18() {
	env_t_18* env = (env_t_18*)malloc(sizeof(env_t_18));
	
	return env;
}

value_t lambda18(env_t_18* env15, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t linalg_sub_vec(array_number_t x, array_number_t y) {
	closure_t* closure17 = make_closure(lambda18, make_env_t_18());
	return array_map2(closure17, x, y);
}
typedef struct env_t_22 {
	value_t dummy_variable;
} env_t_22;
env_t_22* make_env_t_22() {
	env_t_22* env = (env_t_22*)malloc(sizeof(env_t_22));
	
	return env;
}

value_t lambda22(env_t_22* env19, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_add_vec(x, y);
	return res;
}
array_array_number_t linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	closure_t* closure21 = make_closure(lambda22, make_env_t_22());
	return matrix_map2(closure21, x, y);
}
typedef struct env_t_26 {
	value_t dummy_variable;
} env_t_26;
env_t_26* make_env_t_26() {
	env_t_26* env = (env_t_26*)malloc(sizeof(env_t_26));
	
	return env;
}

value_t lambda26(env_t_26* env23, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	closure_t* closure25 = make_closure(lambda26, make_env_t_26());
	return matrix_map2(closure25, x, y);
}
typedef struct env_t_30 {
	value_t dummy_variable;
} env_t_30;
env_t_30* make_env_t_30() {
	env_t_30* env = (env_t_30*)malloc(sizeof(env_t_30));
	
	return env;
}

value_t lambda30(env_t_30* env27, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t linalg_sqnorm(array_number_t x) {
	closure_t* closure29 = make_closure(lambda30, make_env_t_30());
	return array_sum(linalg_vectorMap(closure29, x));
}
typedef struct env_t_34 {
	value_t dummy_variable;
} env_t_34;
env_t_34* make_env_t_34() {
	env_t_34* env = (env_t_34*)malloc(sizeof(env_t_34));
	
	return env;
}

value_t lambda34(env_t_34* env31, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t linalg_dot_prod(array_number_t x, array_number_t y) {
	closure_t* closure33 = make_closure(lambda34, make_env_t_34());
	return array_sum(array_map2(closure33, x, y));
}
typedef struct env_t_39 {
	array_number_t row;
} env_t_39;
env_t_39* make_env_t_39(array_number_t row) {
	env_t_39* env = (env_t_39*)malloc(sizeof(env_t_39));
	env->row = row;
	return env;
}

value_t lambda39(env_t_39* env36, number_t r) {
	array_number_t row35 = env36->row;
	value_t res;
	res.array_number_t_value = row35;
	return res;
}
array_array_number_t linalg_matrixFillFromVector(index_t rows, array_number_t row) {
	closure_t* closure38 = make_closure(lambda39, make_env_t_39(row));
	return array_map_to_matrix(closure38, linalg_vectorRange(1, rows));
}
typedef struct env_t_44 {
	number_t value;
} env_t_44;
env_t_44* make_env_t_44(number_t value) {
	env_t_44* env = (env_t_44*)malloc(sizeof(env_t_44));
	env->value = value;
	return env;
}

value_t lambda44(env_t_44* env41, number_t c) {
	number_t value40 = env41->value;
	value_t res;
	res.number_t_value = value40;
	return res;
}
array_array_number_t linalg_matrixFill(index_t rows, index_t cols, number_t value) {
	closure_t* closure43 = make_closure(lambda44, make_env_t_44(value));
	array_number_t row = linalg_vectorMap(closure43, linalg_vectorRange(1, cols));
	return linalg_matrixFillFromVector(rows, row);
}

array_array_number_t linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = matrix_transpose(m1);
	array_array_number_t m2t = matrix_transpose(m2);
	return matrix_transpose(matrix_concat(m1t, m2t));
}

array_number_t linalg_vectorRead(string_t fn, index_t startLine) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1);
	return matrix->arr[0];
}

number_t linalg_numberRead(string_t fn, index_t startLine) {
	array_number_t vector = linalg_vectorRead(fn, startLine);
	return vector->arr[0];
}

array_number_t linalg_radial_distort(array_number_t rad_params, array_number_t proj) {
	number_t rsq = linalg_sqnorm(proj);
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	return linalg_mult_by_scalar(proj, L);
}

array_number_t linalg_rodrigues_rotate_point(array_number_t rot, array_number_t x) {
	number_t sqtheta = linalg_sqnorm(rot);
	array_number_t ite45 = NULL;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		array_number_t w = linalg_mult_by_scalar(rot, theta_inv);
		array_number_t w_cross_X = linalg_cross(w, x);
		number_t tmp = (linalg_dot_prod(w, x)) * ((1) - (costheta));
		array_number_t v1 = linalg_mult_by_scalar(x, costheta);
		array_number_t v2 = linalg_mult_by_scalar(w_cross_X, sintheta);
		ite45 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite45 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite45;
}

array_number_t linalg_project(array_number_t cam, array_number_t x) {
	index_t N_CAM_PARAMS = 11;
	index_t ROT_IDX = 0;
	index_t CENTER_IDX = 3;
	index_t FOCAL_IDX = 6;
	index_t X0_IDX = 7;
	index_t RAD_IDX = 9;
	array_number_t Xcam = linalg_rodrigues_rotate_point(array_slice(cam, ROT_IDX, (ROT_IDX) + (2)), linalg_sub_vec(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2))));
	array_number_t distorted = linalg_radial_distort(array_slice(cam, RAD_IDX, (RAD_IDX) + (1)), linalg_mult_by_scalar(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2])));
	return linalg_add_vec(array_slice(cam, X0_IDX, (X0_IDX) + (1)), linalg_mult_by_scalar(distorted, cam->arr[FOCAL_IDX]));
}

array_number_t linalg_compute_reproj_err(array_number_t cam, array_number_t x, number_t w, array_number_t feat) {
	
	return linalg_mult_by_scalar(linalg_sub_vec(linalg_project(cam, x), feat), w);
}

number_t linalg_compute_zach_weight_error(number_t w) {
	
	return (1) - ((w) * (w));
}
typedef struct env_t_49 {
	value_t dummy_variable;
} env_t_49;
env_t_49* make_env_t_49() {
	env_t_49* env = (env_t_49*)malloc(sizeof(env_t_49));
	
	return env;
}

value_t lambda49(env_t_49* env46, number_t w) {
	
	value_t res;
	res.number_t_value = linalg_compute_zach_weight_error(w);
	return res;
}
array_number_t linalg_w_err(array_number_t w) {
	closure_t* closure48 = make_closure(lambda49, make_env_t_49());
	return linalg_vectorMap(closure48, w);
}
typedef struct env_t_58 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_58;
env_t_58* make_env_t_58(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_58* env = (env_t_58*)malloc(sizeof(env_t_58));
	env->x = x;
	env->w = w;
	env->obs = obs;
	env->feat = feat;
	env->cams = cams;
	return env;
}

value_t lambda58(env_t_58* env55, number_t i) {
	array_array_number_t x54 = env55->x;
	array_number_t w53 = env55->w;
	array_array_number_t obs52 = env55->obs;
	array_array_number_t feat51 = env55->feat;
	array_array_number_t cams50 = env55->cams;
	value_t res;
	res.array_number_t_value = linalg_compute_reproj_err(cams50->arr[(int)(obs52->arr[(int)(i)]->arr[0])], x54->arr[(int)(obs52->arr[(int)(i)]->arr[1])], w53->arr[(int)(i)], feat51->arr[(int)(i)]);
	return res;
}
array_array_number_t linalg_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	closure_t* closure57 = make_closure(lambda58, make_env_t_58(x,w,obs,feat,cams));
	return array_map_to_matrix(closure57, range);
}
typedef struct env_t_82 {
	array_number_t one_cam;
} env_t_82;
env_t_82* make_env_t_82(array_number_t one_cam) {
	env_t_82* env = (env_t_82*)malloc(sizeof(env_t_82));
	env->one_cam = one_cam;
	return env;
}

value_t lambda82(env_t_82* env60, number_t x) {
	array_number_t one_cam59 = env60->one_cam;
	value_t res;
	res.array_number_t_value = one_cam59;
	return res;
}
typedef struct env_t_83 {
	array_number_t one_x;
} env_t_83;
env_t_83* make_env_t_83(array_number_t one_x) {
	env_t_83* env = (env_t_83*)malloc(sizeof(env_t_83));
	env->one_x = one_x;
	return env;
}

value_t lambda83(env_t_83* env64, number_t x) {
	array_number_t one_x63 = env64->one_x;
	value_t res;
	res.array_number_t_value = one_x63;
	return res;
}
typedef struct env_t_84 {
	number_t one_w;
} env_t_84;
env_t_84* make_env_t_84(number_t one_w) {
	env_t_84* env = (env_t_84*)malloc(sizeof(env_t_84));
	env->one_w = one_w;
	return env;
}

value_t lambda84(env_t_84* env68, number_t x) {
	number_t one_w67 = env68->one_w;
	value_t res;
	res.number_t_value = one_w67;
	return res;
}
typedef struct env_t_85 {
	array_number_t one_feat;
} env_t_85;
env_t_85* make_env_t_85(array_number_t one_feat) {
	env_t_85* env = (env_t_85*)malloc(sizeof(env_t_85));
	env->one_feat = one_feat;
	return env;
}

value_t lambda85(env_t_85* env72, number_t x) {
	array_number_t one_feat71 = env72->one_feat;
	value_t res;
	res.array_number_t_value = one_feat71;
	return res;
}
typedef struct env_t_86 {
	index_t n;
	index_t m;
} env_t_86;
env_t_86* make_env_t_86(index_t n,index_t m) {
	env_t_86* env = (env_t_86*)malloc(sizeof(env_t_86));
	env->n = n;
	env->m = m;
	return env;
}

value_t lambda86(env_t_86* env77, number_t x) {
	index_t n76 = env77->n;
	index_t m75 = env77->m;
	array_number_t array80 = (array_number_t)malloc(sizeof(int) * 2);
	array80->length=2;
	array80->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array80->arr[0] = (double)(((int)(x)) % (n76));
	array80->arr[1] = (double)(((int)(x)) % (m75));;
	value_t res;
	res.array_number_t_value = array80;
	return res;
}
array_array_number_t linalg_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	closure_t* closure62 = make_closure(lambda82, make_env_t_82(one_cam));
	array_array_number_t cam = array_map_to_matrix(closure62, linalg_vectorRange(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	closure_t* closure66 = make_closure(lambda83, make_env_t_83(one_x));
	array_array_number_t x = array_map_to_matrix(closure66, linalg_vectorRange(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	closure_t* closure70 = make_closure(lambda84, make_env_t_84(one_w));
	array_number_t w = linalg_vectorMap(closure70, linalg_vectorRange(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	closure_t* closure74 = make_closure(lambda85, make_env_t_85(one_feat));
	array_array_number_t feat = array_map_to_matrix(closure74, linalg_vectorRange(1, p));
	closure_t* closure79 = make_closure(lambda86, make_env_t_86(n,m));
	array_array_number_t obs = array_map_to_matrix(closure79, linalg_vectorRange(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = linalg_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_91 {
	number_t mx;
} env_t_91;
env_t_91* make_env_t_91(number_t mx) {
	env_t_91* env = (env_t_91*)malloc(sizeof(env_t_91));
	env->mx = mx;
	return env;
}

value_t lambda91(env_t_91* env88, number_t x) {
	number_t mx87 = env88->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx87));
	return res;
}
number_t linalg_logsumexp(array_number_t arr) {
	number_t mx = array_max(arr);
	closure_t* closure90 = make_closure(lambda91, make_env_t_91(mx));
	number_t semx = array_sum(linalg_vectorMap(closure90, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_96 {
	number_t a;
} env_t_96;
env_t_96* make_env_t_96(number_t a) {
	env_t_96* env = (env_t_96*)malloc(sizeof(env_t_96));
	env->a = a;
	return env;
}

value_t lambda96(env_t_96* env93, number_t j) {
	number_t a92 = env93->a;
	value_t res;
	res.number_t_value = gamma_ln((a92) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t linalg_log_gamma_distrib(number_t a, number_t p) {
	closure_t* closure95 = make_closure(lambda96, make_env_t_96(a));
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (array_sum(linalg_vectorMap(closure95, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t linalg_new_matrix_test(array_number_t dum) {
	array_number_t array97 = (array_number_t)malloc(sizeof(int) * 2);
	array97->length=3;
	array97->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array97->arr[0] = 0;
	array97->arr[1] = 0;
	array97->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array97;;
	return res;
}

array_array_number_t linalg_to_pose_params(array_number_t theta, index_t n_bones) {
	array_number_t row1 = array_slice(theta, 0, 2);
	array_number_t row2 = (array_number_t)malloc(sizeof(int) * 2);
	row2->length=3;
	row2->arr = (number_t*)malloc(sizeof(number_t) * 3);
	row2->arr[0] = 1;
	row2->arr[1] = 1;
	row2->arr[2] = 1;;
	array_number_t row3 = array_slice(theta, 3, 5);
	array_number_t zeroRow = (array_number_t)malloc(sizeof(int) * 2);
	zeroRow->length=3;
	zeroRow->arr = (number_t*)malloc(sizeof(number_t) * 3);
	zeroRow->arr[0] = 0;
	zeroRow->arr[1] = 0;
	zeroRow->arr[2] = 0;;
	array_array_number_t pose_params = (array_array_number_t)malloc(sizeof(int) * 2);
	pose_params->length=5;
	pose_params->arr = (array_number_t*)malloc(sizeof(array_number_t) * 5);
	pose_params->arr[0] = row1;
	pose_params->arr[1] = row2;
	pose_params->arr[2] = row3;
	pose_params->arr[3] = zeroRow;
	pose_params->arr[4] = zeroRow;;
	index_t i1 = 5;
	array_number_t array98 = (array_number_t)malloc(sizeof(int) * 2);
	array98->length=3;
	array98->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array98->arr[0] = theta->arr[i1];
	array98->arr[1] = theta->arr[(i1) + (1)];
	array98->arr[2] = 0;;
	array_number_t array99 = (array_number_t)malloc(sizeof(int) * 2);
	array99->length=3;
	array99->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array99->arr[0] = theta->arr[(i1) + (2)];
	array99->arr[1] = 0;
	array99->arr[2] = 0;;
	array_number_t array100 = (array_number_t)malloc(sizeof(int) * 2);
	array100->length=3;
	array100->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array100->arr[0] = theta->arr[(i1) + (3)];
	array100->arr[1] = 0;
	array100->arr[2] = 0;;
	array_number_t array101 = (array_number_t)malloc(sizeof(int) * 2);
	array101->length=3;
	array101->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array101->arr[0] = 0;
	array101->arr[1] = 0;
	array101->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array98;
	finger1->arr[1] = array99;
	finger1->arr[2] = array100;
	finger1->arr[3] = array101;;
	index_t i2 = (i1) + (4);
	array_number_t array102 = (array_number_t)malloc(sizeof(int) * 2);
	array102->length=3;
	array102->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array102->arr[0] = theta->arr[i2];
	array102->arr[1] = theta->arr[(i2) + (1)];
	array102->arr[2] = 0;;
	array_number_t array103 = (array_number_t)malloc(sizeof(int) * 2);
	array103->length=3;
	array103->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array103->arr[0] = theta->arr[(i2) + (2)];
	array103->arr[1] = 0;
	array103->arr[2] = 0;;
	array_number_t array104 = (array_number_t)malloc(sizeof(int) * 2);
	array104->length=3;
	array104->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array104->arr[0] = theta->arr[(i2) + (3)];
	array104->arr[1] = 0;
	array104->arr[2] = 0;;
	array_number_t array105 = (array_number_t)malloc(sizeof(int) * 2);
	array105->length=3;
	array105->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array105->arr[0] = 0;
	array105->arr[1] = 0;
	array105->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array102;
	finger2->arr[1] = array103;
	finger2->arr[2] = array104;
	finger2->arr[3] = array105;;
	index_t i3 = (i2) + (4);
	array_number_t array106 = (array_number_t)malloc(sizeof(int) * 2);
	array106->length=3;
	array106->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array106->arr[0] = theta->arr[i3];
	array106->arr[1] = theta->arr[(i3) + (1)];
	array106->arr[2] = 0;;
	array_number_t array107 = (array_number_t)malloc(sizeof(int) * 2);
	array107->length=3;
	array107->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array107->arr[0] = theta->arr[(i3) + (2)];
	array107->arr[1] = 0;
	array107->arr[2] = 0;;
	array_number_t array108 = (array_number_t)malloc(sizeof(int) * 2);
	array108->length=3;
	array108->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array108->arr[0] = theta->arr[(i3) + (3)];
	array108->arr[1] = 0;
	array108->arr[2] = 0;;
	array_number_t array109 = (array_number_t)malloc(sizeof(int) * 2);
	array109->length=3;
	array109->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array109->arr[0] = 0;
	array109->arr[1] = 0;
	array109->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array106;
	finger3->arr[1] = array107;
	finger3->arr[2] = array108;
	finger3->arr[3] = array109;;
	index_t i4 = (i3) + (4);
	array_number_t array110 = (array_number_t)malloc(sizeof(int) * 2);
	array110->length=3;
	array110->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array110->arr[0] = theta->arr[i4];
	array110->arr[1] = theta->arr[(i4) + (1)];
	array110->arr[2] = 0;;
	array_number_t array111 = (array_number_t)malloc(sizeof(int) * 2);
	array111->length=3;
	array111->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array111->arr[0] = theta->arr[(i4) + (2)];
	array111->arr[1] = 0;
	array111->arr[2] = 0;;
	array_number_t array112 = (array_number_t)malloc(sizeof(int) * 2);
	array112->length=3;
	array112->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array112->arr[0] = theta->arr[(i4) + (3)];
	array112->arr[1] = 0;
	array112->arr[2] = 0;;
	array_number_t array113 = (array_number_t)malloc(sizeof(int) * 2);
	array113->length=3;
	array113->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array113->arr[0] = 0;
	array113->arr[1] = 0;
	array113->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array110;
	finger4->arr[1] = array111;
	finger4->arr[2] = array112;
	finger4->arr[3] = array113;;
	index_t i5 = (i4) + (4);
	array_number_t array114 = (array_number_t)malloc(sizeof(int) * 2);
	array114->length=3;
	array114->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array114->arr[0] = theta->arr[i5];
	array114->arr[1] = theta->arr[(i5) + (1)];
	array114->arr[2] = 0;;
	array_number_t array115 = (array_number_t)malloc(sizeof(int) * 2);
	array115->length=3;
	array115->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array115->arr[0] = theta->arr[(i5) + (2)];
	array115->arr[1] = 0;
	array115->arr[2] = 0;;
	array_number_t array116 = (array_number_t)malloc(sizeof(int) * 2);
	array116->length=3;
	array116->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array116->arr[0] = theta->arr[(i5) + (3)];
	array116->arr[1] = 0;
	array116->arr[2] = 0;;
	array_number_t array117 = (array_number_t)malloc(sizeof(int) * 2);
	array117->length=3;
	array117->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array117->arr[0] = 0;
	array117->arr[1] = 0;
	array117->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array114;
	finger5->arr[1] = array115;
	finger5->arr[2] = array116;
	finger5->arr[3] = array117;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t linalg_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array118 = (array_number_t)malloc(sizeof(int) * 2);
	array118->length=3;
	array118->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array118->arr[0] = 1;
	array118->arr[1] = 0;
	array118->arr[2] = 0;;
	array_number_t array119 = (array_number_t)malloc(sizeof(int) * 2);
	array119->length=3;
	array119->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array119->arr[0] = 0;
	array119->arr[1] = cos(tx);
	array119->arr[2] = -(sin(tx));;
	array_number_t array120 = (array_number_t)malloc(sizeof(int) * 2);
	array120->length=3;
	array120->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array120->arr[0] = 0;
	array120->arr[1] = sin(tx);
	array120->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array118;
	Rx->arr[1] = array119;
	Rx->arr[2] = array120;;
	array_number_t array121 = (array_number_t)malloc(sizeof(int) * 2);
	array121->length=3;
	array121->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array121->arr[0] = cos(ty);
	array121->arr[1] = 0;
	array121->arr[2] = sin(ty);;
	array_number_t array122 = (array_number_t)malloc(sizeof(int) * 2);
	array122->length=3;
	array122->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array122->arr[0] = 0;
	array122->arr[1] = 1;
	array122->arr[2] = 0;;
	array_number_t array123 = (array_number_t)malloc(sizeof(int) * 2);
	array123->length=3;
	array123->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array123->arr[0] = -(sin(ty));
	array123->arr[1] = 0;
	array123->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array121;
	Ry->arr[1] = array122;
	Ry->arr[2] = array123;;
	array_number_t array124 = (array_number_t)malloc(sizeof(int) * 2);
	array124->length=3;
	array124->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array124->arr[0] = cos(tz);
	array124->arr[1] = -(sin(tz));
	array124->arr[2] = 0;;
	array_number_t array125 = (array_number_t)malloc(sizeof(int) * 2);
	array125->length=3;
	array125->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array125->arr[0] = sin(tz);
	array125->arr[1] = cos(tz);
	array125->arr[2] = 0;;
	array_number_t array126 = (array_number_t)malloc(sizeof(int) * 2);
	array126->length=3;
	array126->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array126->arr[0] = 0;
	array126->arr[1] = 0;
	array126->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array124;
	Rz->arr[1] = array125;
	Rz->arr[2] = array126;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t linalg_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = linalg_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array127 = (array_number_t)malloc(sizeof(int) * 2);
	array127->length=1;
	array127->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array127->arr[0] = 0;;
	array_number_t array128 = (array_number_t)malloc(sizeof(int) * 2);
	array128->length=1;
	array128->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array128->arr[0] = 0;;
	array_number_t array129 = (array_number_t)malloc(sizeof(int) * 2);
	array129->length=1;
	array129->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array129->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array127;
	r1->arr[1] = array128;
	r1->arr[2] = array129;;
	array_number_t array130 = (array_number_t)malloc(sizeof(int) * 2);
	array130->length=4;
	array130->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array130->arr[0] = 0;
	array130->arr[1] = 0;
	array130->arr[2] = 0;
	array130->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array130;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_137 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_137;
env_t_137* make_env_t_137(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_137* env = (env_t_137*)malloc(sizeof(env_t_137));
	env->pose_params = pose_params;
	env->offset = offset;
	env->base_relatives = base_relatives;
	return env;
}

value_t lambda137(env_t_137* env134, number_t i_bone) {
	array_array_number_t pose_params133 = env134->pose_params;
	index_t offset132 = env134->offset;
	array_array_array_number_t base_relatives131 = env134->base_relatives;
	value_t res;
	res.array_array_number_t_value = linalg_make_relative(pose_params133->arr[((int)(i_bone)) + (offset132)], base_relatives131->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t linalg_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	closure_t* closure136 = make_closure(lambda137, make_env_t_137(pose_params,offset,base_relatives));
	return array_map_to_matrix3d(closure136, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t linalg_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite138 = NULL;
	if((n) < (0.0001)) {
		array_number_t array140 = (array_number_t)malloc(sizeof(int) * 2);
	array140->length=3;
	array140->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array140->arr[0] = 1;
	array140->arr[1] = 0;
	array140->arr[2] = 0;;
		array_number_t array141 = (array_number_t)malloc(sizeof(int) * 2);
	array141->length=3;
	array141->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array141->arr[0] = 0;
	array141->arr[1] = 1;
	array141->arr[2] = 0;;
		array_number_t array142 = (array_number_t)malloc(sizeof(int) * 2);
	array142->length=3;
	array142->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array142->arr[0] = 0;
	array142->arr[1] = 0;
	array142->arr[2] = 1;;
		array_array_number_t array139 = (array_array_number_t)malloc(sizeof(int) * 2);
	array139->length=3;
	array139->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array139->arr[0] = array140;
	array139->arr[1] = array141;
	array139->arr[2] = array142;;
		ite138 = array139;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array144 = (array_number_t)malloc(sizeof(int) * 2);
	array144->length=3;
	array144->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array144->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array144->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array144->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array145 = (array_number_t)malloc(sizeof(int) * 2);
	array145->length=3;
	array145->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array145->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array145->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array145->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array146 = (array_number_t)malloc(sizeof(int) * 2);
	array146->length=3;
	array146->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array146->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array146->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array146->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array143 = (array_array_number_t)malloc(sizeof(int) * 2);
	array143->length=3;
	array143->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array143->arr[0] = array144;
	array143->arr[1] = array145;
	array143->arr[2] = array146;;
		ite138 = array143;
	}
	return ite138;
}
typedef struct env_t_155 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_155;
env_t_155* make_env_t_155(array_array_array_number_t relatives,array_number_t parents) {
	env_t_155* env = (env_t_155*)malloc(sizeof(env_t_155));
	env->relatives = relatives;
	env->parents = parents;
	return env;
}

value_t lambda155(env_t_155* env149, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives148 = env149->relatives;
	array_number_t parents147 = env149->parents;
	array_array_array_number_t ite154 = NULL;
	if((parents147->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives148->arr[i];;
		ite154 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents147->arr[i])], relatives148->arr[i]);;
		ite154 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite154;
	return res;
}
array_array_array_number_t linalg_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array153 = (array_number_t)malloc(sizeof(int) * 2);
	array153->length=0;
	array153->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array152 = (array_array_number_t)malloc(sizeof(int) * 2);
	array152->length=1;
	array152->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array152->arr[0] = array153;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array152;;
	closure_t* closure151 = make_closure(lambda155, make_env_t_155(relatives,parents));
	return iterate_matrix3d(closure151, init, 0, (relatives->length) - (1));
}
typedef struct env_t_165 {
	array_number_t scale;
} env_t_165;
env_t_165* make_env_t_165(array_number_t scale) {
	env_t_165* env = (env_t_165*)malloc(sizeof(env_t_165));
	env->scale = scale;
	return env;
}

value_t lambda165(env_t_165* env157, array_number_t row) {
	array_number_t scale156 = env157->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale156);
	return res;
}
typedef struct env_t_166 {
	value_t dummy_variable;
} env_t_166;
env_t_166* make_env_t_166() {
	env_t_166* env = (env_t_166*)malloc(sizeof(env_t_166));
	
	return env;
}

value_t lambda166(env_t_166* env160, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t linalg_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = linalg_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	closure_t* closure159 = make_closure(lambda165, make_env_t_165(scale));
	array_array_number_t R1 = matrix_map(closure159, R);
	array_array_number_t array163 = (array_array_number_t)malloc(sizeof(int) * 2);
	array163->length=1;
	array163->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array163->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array163));
	closure_t* closure162 = make_closure(lambda166, make_env_t_166());
	array_number_t ones = linalg_vectorMap(closure162, linalg_vectorRange(1, positions->arr[0]->length));
	array_array_number_t array164 = (array_array_number_t)malloc(sizeof(int) * 2);
	array164->length=1;
	array164->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array164->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array164);
	return matrix_mult(T, positions_homog);
}
typedef struct env_t_179 {
	value_t dummy_variable;
} env_t_179;
env_t_179* make_env_t_179() {
	env_t_179* env = (env_t_179*)malloc(sizeof(env_t_179));
	
	return env;
}

value_t lambda179(env_t_179* env167, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_180 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_180;
env_t_180* make_env_t_180(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_180* env = (env_t_180*)malloc(sizeof(env_t_180));
	env->weights = weights;
	env->transforms = transforms;
	env->base_positions = base_positions;
	return env;
}

value_t lambda180(env_t_180* env173, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights172 = env173->weights;
	array_array_array_number_t transforms171 = env173->transforms;
	array_array_number_t base_positions170 = env173->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms171->arr[i_transform], 0, 2), base_positions170);
	array_array_number_t w = linalg_matrixFillFromVector(base_positions170->length, weights172->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t linalg_get_skinned_vertex_positions(index_t is_mirrored, index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = linalg_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = linalg_relatives_to_absolutes(relatives, parents);
	closure_t* closure169 = make_closure(lambda179, make_env_t_179());
	array_array_array_number_t transforms = matrix3d_map2(closure169, absolutes, inverse_base_absolutes);
	index_t n_verts = base_positions->arr[0]->length;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	closure_t* closure175 = make_closure(lambda180, make_env_t_180(weights,transforms,base_positions));
	array_array_number_t positions = iterate_matrix(closure175, init_positions, 0, (transforms->length) - (1));
	array_array_number_t mirrored_positions = NULL;
	if((is_mirrored) == (1)) {
		array_number_t array176 = (array_number_t)malloc(sizeof(int) * 2);
	array176->length=3;
	array176->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array176->arr[0] = -1;
	array176->arr[1] = 0;
	array176->arr[2] = 0;;
		array_number_t array177 = (array_number_t)malloc(sizeof(int) * 2);
	array177->length=3;
	array177->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array177->arr[0] = 0;
	array177->arr[1] = 1;
	array177->arr[2] = 0;;
		array_number_t array178 = (array_number_t)malloc(sizeof(int) * 2);
	array178->length=3;
	array178->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array178->arr[0] = 0;
	array178->arr[1] = 0;
	array178->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array176;
	mirror_matrix->arr[1] = array177;
	mirror_matrix->arr[2] = array178;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return linalg_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_188 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_188;
env_t_188* make_env_t_188(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_188* env = (env_t_188*)malloc(sizeof(env_t_188));
	env->vertex_positions = vertex_positions;
	env->points = points;
	env->n_corr = n_corr;
	env->correspondences = correspondences;
	return env;
}

value_t lambda188(env_t_188* env185, number_t i) {
	array_array_number_t vertex_positions184 = env185->vertex_positions;
	array_array_number_t points183 = env185->points;
	index_t n_corr182 = env185->n_corr;
	array_number_t correspondences181 = env185->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr182);
	index_t c = (ind) % (n_corr182);
	value_t res;
	res.number_t_value = (points183->arr[r]->arr[c]) - (vertex_positions184->arr[r]->arr[(int)(correspondences181->arr[c])]);
	return res;
}
array_number_t linalg_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, index_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = linalg_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = linalg_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	closure_t* closure187 = make_closure(lambda188, make_env_t_188(vertex_positions,points,n_corr,correspondences));
	array_number_t err = linalg_vectorMap(closure187, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef struct env_t_216 {
	value_t dummy_variable;
} env_t_216;
env_t_216* make_env_t_216() {
	env_t_216* env = (env_t_216*)malloc(sizeof(env_t_216));
	
	return env;
}

value_t lambda216(env_t_216* env189, number_t r) {
	
	value_t res;
	res.array_number_t_value = linalg_vectorRange(((int)(r)) * (4), (((int)(r)) * (4)) + (3));
	return res;
}
void linalg_test1(array_number_t dum) {
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
	array_number_t c = linalg_cross(a, b);
	array_print(c);
	array_number_t d = linalg_mult_by_scalar(c, 15);
	array_print(d);
	array_number_t e = linalg_add_vec(a, b);
	array_print(e);
	array_number_t f = linalg_sub_vec(a, b);
	array_print(f);
	array_number_t g = linalg_add_vec3(a, b, c);
	array_print(g);
	number_t h = linalg_sqnorm(a);
	number_print(h);
	number_t i = linalg_dot_prod(a, b);
	number_print(i);
	array_number_t j = linalg_radial_distort(a, b);
	array_print(j);
	array_number_t k = linalg_rodrigues_rotate_point(a, b);
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
	array_number_t m = linalg_project(cam, j);
	array_print(m);
	array_number_t array205 = (array_number_t)malloc(sizeof(int) * 2);
	array205->length=3;
	array205->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array205->arr[0] = 1;
	array205->arr[1] = 2;
	array205->arr[2] = 3;;
	array_number_t array206 = (array_number_t)malloc(sizeof(int) * 2);
	array206->length=3;
	array206->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array206->arr[0] = 4;
	array206->arr[1] = 5;
	array206->arr[2] = 6;;
	array_number_t array207 = (array_number_t)malloc(sizeof(int) * 2);
	array207->length=3;
	array207->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array207->arr[0] = 7;
	array207->arr[1] = 8;
	array207->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array205;
	mat1->arr[1] = array206;
	mat1->arr[2] = array207;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	closure_t* closure191 = make_closure(lambda216, make_env_t_216());
	array_array_number_t base_rel = array_map_to_matrix(closure191, linalg_vectorRange(1, 4));
	array_array_number_t q = linalg_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = linalg_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	array_array_number_t s = linalg_apply_global_transform(mat1, mat1);
	matrix_print(s);
	array_array_number_t t = linalg_matrixAdd(mat1, mat1);
	matrix_print(t);
	array_array_number_t u = linalg_matrixFillFromVector(5, a);
	matrix_print(u);
	return ;
}
#endif
