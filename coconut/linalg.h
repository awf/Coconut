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

value_t lambda5(env_t_5* env2, number_t a) {
	number_t y1 = env2->y;
	value_t res;
	res.number_t_value = (a) * (y1);
	return res;
}
array_number_t linalg_mult_by_scalar(array_number_t x, number_t y) {
	closure_t* closure4 = make_closure(lambda5, make_env_t_5(y));
	return array_map(closure4, x);
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

array_number_t linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
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
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t linalg_sub_vec(array_number_t x, array_number_t y) {
	closure_t* closure13 = make_closure(lambda14, make_env_t_14());
	return array_map2(closure13, x, y);
}
typedef struct env_t_18 {
	value_t dummy_variable;
} env_t_18;
env_t_18* make_env_t_18() {
	env_t_18* env = (env_t_18*)malloc(sizeof(env_t_18));
	
	return env;
}

value_t lambda18(env_t_18* env15, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t linalg_sqnorm(array_number_t x) {
	closure_t* closure17 = make_closure(lambda18, make_env_t_18());
	return array_sum(array_map(closure17, x));
}
typedef struct env_t_22 {
	value_t dummy_variable;
} env_t_22;
env_t_22* make_env_t_22() {
	env_t_22* env = (env_t_22*)malloc(sizeof(env_t_22));
	
	return env;
}

value_t lambda22(env_t_22* env19, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t linalg_dot_prod(array_number_t x, array_number_t y) {
	closure_t* closure21 = make_closure(lambda22, make_env_t_22());
	return array_sum(array_map2(closure21, x, y));
}

array_number_t linalg_radial_distort(array_number_t rad_params, array_number_t proj) {
	number_t rsq = linalg_sqnorm(proj);
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	return linalg_mult_by_scalar(proj, L);
}

array_number_t linalg_rodrigues_rotate_point(array_number_t rot, array_number_t x) {
	number_t sqtheta = linalg_sqnorm(rot);
	array_number_t ite23 = NULL;
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
		ite23 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite23 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite23;
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
typedef struct env_t_27 {
	value_t dummy_variable;
} env_t_27;
env_t_27* make_env_t_27() {
	env_t_27* env = (env_t_27*)malloc(sizeof(env_t_27));
	
	return env;
}

value_t lambda27(env_t_27* env24, number_t w) {
	
	value_t res;
	res.number_t_value = linalg_compute_zach_weight_error(w);
	return res;
}
array_number_t linalg_w_err(array_number_t w) {
	closure_t* closure26 = make_closure(lambda27, make_env_t_27());
	return array_map(closure26, w);
}
typedef struct env_t_36 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_36;
env_t_36* make_env_t_36(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_36* env = (env_t_36*)malloc(sizeof(env_t_36));
	env->x = x;
	env->w = w;
	env->obs = obs;
	env->feat = feat;
	env->cams = cams;
	return env;
}

value_t lambda36(env_t_36* env33, number_t i) {
	array_array_number_t x32 = env33->x;
	array_number_t w31 = env33->w;
	array_array_number_t obs30 = env33->obs;
	array_array_number_t feat29 = env33->feat;
	array_array_number_t cams28 = env33->cams;
	value_t res;
	res.array_number_t_value = linalg_compute_reproj_err(cams28->arr[(int)(obs30->arr[(int)(i)]->arr[0])], x32->arr[(int)(obs30->arr[(int)(i)]->arr[1])], w31->arr[(int)(i)], feat29->arr[(int)(i)]);
	return res;
}
array_array_number_t linalg_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = array_range(0, (p) - (1));
	closure_t* closure35 = make_closure(lambda36, make_env_t_36(x,w,obs,feat,cams));
	return array_map_to_matrix(closure35, range);
}

array_number_t linalg_vectorRead(string_t fn, index_t startLine) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1);
	return matrix->arr[0];
}

number_t linalg_numberRead(string_t fn, index_t startLine) {
	array_number_t vector = linalg_vectorRead(fn, startLine);
	return vector->arr[0];
}
typedef struct env_t_60 {
	array_number_t one_cam;
} env_t_60;
env_t_60* make_env_t_60(array_number_t one_cam) {
	env_t_60* env = (env_t_60*)malloc(sizeof(env_t_60));
	env->one_cam = one_cam;
	return env;
}

value_t lambda60(env_t_60* env38, number_t x) {
	array_number_t one_cam37 = env38->one_cam;
	value_t res;
	res.array_number_t_value = one_cam37;
	return res;
}
typedef struct env_t_61 {
	array_number_t one_x;
} env_t_61;
env_t_61* make_env_t_61(array_number_t one_x) {
	env_t_61* env = (env_t_61*)malloc(sizeof(env_t_61));
	env->one_x = one_x;
	return env;
}

value_t lambda61(env_t_61* env42, number_t x) {
	array_number_t one_x41 = env42->one_x;
	value_t res;
	res.array_number_t_value = one_x41;
	return res;
}
typedef struct env_t_62 {
	number_t one_w;
} env_t_62;
env_t_62* make_env_t_62(number_t one_w) {
	env_t_62* env = (env_t_62*)malloc(sizeof(env_t_62));
	env->one_w = one_w;
	return env;
}

value_t lambda62(env_t_62* env46, number_t x) {
	number_t one_w45 = env46->one_w;
	value_t res;
	res.number_t_value = one_w45;
	return res;
}
typedef struct env_t_63 {
	array_number_t one_feat;
} env_t_63;
env_t_63* make_env_t_63(array_number_t one_feat) {
	env_t_63* env = (env_t_63*)malloc(sizeof(env_t_63));
	env->one_feat = one_feat;
	return env;
}

value_t lambda63(env_t_63* env50, number_t x) {
	array_number_t one_feat49 = env50->one_feat;
	value_t res;
	res.array_number_t_value = one_feat49;
	return res;
}
typedef struct env_t_64 {
	index_t n;
	index_t m;
} env_t_64;
env_t_64* make_env_t_64(index_t n,index_t m) {
	env_t_64* env = (env_t_64*)malloc(sizeof(env_t_64));
	env->n = n;
	env->m = m;
	return env;
}

value_t lambda64(env_t_64* env55, number_t x) {
	index_t n54 = env55->n;
	index_t m53 = env55->m;
	array_number_t array58 = (array_number_t)malloc(sizeof(int) * 2);
	array58->length=2;
	array58->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array58->arr[0] = (double)(((int)(x)) % (n54));
	array58->arr[1] = (double)(((int)(x)) % (m53));;
	value_t res;
	res.array_number_t_value = array58;
	return res;
}
array_array_number_t linalg_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	closure_t* closure40 = make_closure(lambda60, make_env_t_60(one_cam));
	array_array_number_t cam = array_map_to_matrix(closure40, array_range(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	closure_t* closure44 = make_closure(lambda61, make_env_t_61(one_x));
	array_array_number_t x = array_map_to_matrix(closure44, array_range(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	closure_t* closure48 = make_closure(lambda62, make_env_t_62(one_w));
	array_number_t w = array_map(closure48, array_range(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	closure_t* closure52 = make_closure(lambda63, make_env_t_63(one_feat));
	array_array_number_t feat = array_map_to_matrix(closure52, array_range(1, p));
	closure_t* closure57 = make_closure(lambda64, make_env_t_64(n,m));
	array_array_number_t obs = array_map_to_matrix(closure57, array_range(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = linalg_reproj_err(cam, x, w, obs, feat);
	toc(t);
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
	array_number_t array78 = (array_number_t)malloc(sizeof(int) * 2);
	array78->length=3;
	array78->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array78->arr[0] = 1;
	array78->arr[1] = 2;
	array78->arr[2] = 3;;
	array_number_t array79 = (array_number_t)malloc(sizeof(int) * 2);
	array79->length=3;
	array79->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array79->arr[0] = 4;
	array79->arr[1] = 5;
	array79->arr[2] = 6;;
	array_number_t array80 = (array_number_t)malloc(sizeof(int) * 2);
	array80->length=3;
	array80->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array80->arr[0] = 7;
	array80->arr[1] = 8;
	array80->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array78;
	mat1->arr[1] = array79;
	mat1->arr[2] = array80;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	return ;
}
typedef struct env_t_87 {
	number_t mx;
} env_t_87;
env_t_87* make_env_t_87(number_t mx) {
	env_t_87* env = (env_t_87*)malloc(sizeof(env_t_87));
	env->mx = mx;
	return env;
}

value_t lambda87(env_t_87* env84, number_t x) {
	number_t mx83 = env84->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx83));
	return res;
}
number_t linalg_logsumexp(array_number_t arr) {
	number_t mx = array_max(arr);
	closure_t* closure86 = make_closure(lambda87, make_env_t_87(mx));
	number_t semx = array_sum(array_map(closure86, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_92 {
	number_t a;
} env_t_92;
env_t_92* make_env_t_92(number_t a) {
	env_t_92* env = (env_t_92*)malloc(sizeof(env_t_92));
	env->a = a;
	return env;
}

value_t lambda92(env_t_92* env89, number_t j) {
	number_t a88 = env89->a;
	value_t res;
	res.number_t_value = gamma_ln((a88) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t linalg_log_gamma_distrib(number_t a, number_t p) {
	closure_t* closure91 = make_closure(lambda92, make_env_t_92(a));
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (array_sum(array_map(closure91, array_range(1, (int)(p)))));
}

array_array_number_t linalg_new_matrix_test(array_number_t dum) {
	array_number_t array93 = (array_number_t)malloc(sizeof(int) * 2);
	array93->length=3;
	array93->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array93->arr[0] = 0;
	array93->arr[1] = 0;
	array93->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array93;;
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
	array_number_t array94 = (array_number_t)malloc(sizeof(int) * 2);
	array94->length=3;
	array94->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array94->arr[0] = theta->arr[i1];
	array94->arr[1] = theta->arr[(i1) + (1)];
	array94->arr[2] = 0;;
	array_number_t array95 = (array_number_t)malloc(sizeof(int) * 2);
	array95->length=3;
	array95->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array95->arr[0] = theta->arr[(i1) + (2)];
	array95->arr[1] = 0;
	array95->arr[2] = 0;;
	array_number_t array96 = (array_number_t)malloc(sizeof(int) * 2);
	array96->length=3;
	array96->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array96->arr[0] = theta->arr[(i1) + (3)];
	array96->arr[1] = 0;
	array96->arr[2] = 0;;
	array_number_t array97 = (array_number_t)malloc(sizeof(int) * 2);
	array97->length=3;
	array97->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array97->arr[0] = 0;
	array97->arr[1] = 0;
	array97->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array94;
	finger1->arr[1] = array95;
	finger1->arr[2] = array96;
	finger1->arr[3] = array97;;
	index_t i2 = (i1) + (4);
	array_number_t array98 = (array_number_t)malloc(sizeof(int) * 2);
	array98->length=3;
	array98->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array98->arr[0] = theta->arr[i2];
	array98->arr[1] = theta->arr[(i2) + (1)];
	array98->arr[2] = 0;;
	array_number_t array99 = (array_number_t)malloc(sizeof(int) * 2);
	array99->length=3;
	array99->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array99->arr[0] = theta->arr[(i2) + (2)];
	array99->arr[1] = 0;
	array99->arr[2] = 0;;
	array_number_t array100 = (array_number_t)malloc(sizeof(int) * 2);
	array100->length=3;
	array100->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array100->arr[0] = theta->arr[(i2) + (3)];
	array100->arr[1] = 0;
	array100->arr[2] = 0;;
	array_number_t array101 = (array_number_t)malloc(sizeof(int) * 2);
	array101->length=3;
	array101->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array101->arr[0] = 0;
	array101->arr[1] = 0;
	array101->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array98;
	finger2->arr[1] = array99;
	finger2->arr[2] = array100;
	finger2->arr[3] = array101;;
	index_t i3 = (i2) + (4);
	array_number_t array102 = (array_number_t)malloc(sizeof(int) * 2);
	array102->length=3;
	array102->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array102->arr[0] = theta->arr[i3];
	array102->arr[1] = theta->arr[(i3) + (1)];
	array102->arr[2] = 0;;
	array_number_t array103 = (array_number_t)malloc(sizeof(int) * 2);
	array103->length=3;
	array103->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array103->arr[0] = theta->arr[(i3) + (2)];
	array103->arr[1] = 0;
	array103->arr[2] = 0;;
	array_number_t array104 = (array_number_t)malloc(sizeof(int) * 2);
	array104->length=3;
	array104->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array104->arr[0] = theta->arr[(i3) + (3)];
	array104->arr[1] = 0;
	array104->arr[2] = 0;;
	array_number_t array105 = (array_number_t)malloc(sizeof(int) * 2);
	array105->length=3;
	array105->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array105->arr[0] = 0;
	array105->arr[1] = 0;
	array105->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array102;
	finger3->arr[1] = array103;
	finger3->arr[2] = array104;
	finger3->arr[3] = array105;;
	index_t i4 = (i3) + (4);
	array_number_t array106 = (array_number_t)malloc(sizeof(int) * 2);
	array106->length=3;
	array106->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array106->arr[0] = theta->arr[i4];
	array106->arr[1] = theta->arr[(i4) + (1)];
	array106->arr[2] = 0;;
	array_number_t array107 = (array_number_t)malloc(sizeof(int) * 2);
	array107->length=3;
	array107->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array107->arr[0] = theta->arr[(i4) + (2)];
	array107->arr[1] = 0;
	array107->arr[2] = 0;;
	array_number_t array108 = (array_number_t)malloc(sizeof(int) * 2);
	array108->length=3;
	array108->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array108->arr[0] = theta->arr[(i4) + (3)];
	array108->arr[1] = 0;
	array108->arr[2] = 0;;
	array_number_t array109 = (array_number_t)malloc(sizeof(int) * 2);
	array109->length=3;
	array109->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array109->arr[0] = 0;
	array109->arr[1] = 0;
	array109->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array106;
	finger4->arr[1] = array107;
	finger4->arr[2] = array108;
	finger4->arr[3] = array109;;
	index_t i5 = (i4) + (4);
	array_number_t array110 = (array_number_t)malloc(sizeof(int) * 2);
	array110->length=3;
	array110->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array110->arr[0] = theta->arr[i5];
	array110->arr[1] = theta->arr[(i5) + (1)];
	array110->arr[2] = 0;;
	array_number_t array111 = (array_number_t)malloc(sizeof(int) * 2);
	array111->length=3;
	array111->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array111->arr[0] = theta->arr[(i5) + (2)];
	array111->arr[1] = 0;
	array111->arr[2] = 0;;
	array_number_t array112 = (array_number_t)malloc(sizeof(int) * 2);
	array112->length=3;
	array112->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array112->arr[0] = theta->arr[(i5) + (3)];
	array112->arr[1] = 0;
	array112->arr[2] = 0;;
	array_number_t array113 = (array_number_t)malloc(sizeof(int) * 2);
	array113->length=3;
	array113->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array113->arr[0] = 0;
	array113->arr[1] = 0;
	array113->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array110;
	finger5->arr[1] = array111;
	finger5->arr[2] = array112;
	finger5->arr[3] = array113;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}
