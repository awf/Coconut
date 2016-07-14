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
typedef struct env_t_69 {
	number_t mx;
} env_t_69;
env_t_69* make_env_t_69(number_t mx) {
	env_t_69* env = (env_t_69*)malloc(sizeof(env_t_69));
	env->mx = mx;
	return env;
}

value_t lambda69(env_t_69* env66, number_t x) {
	number_t mx65 = env66->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx65));
	return res;
}
number_t linalg_logsumexp(array_number_t arr) {
	number_t mx = array_max(arr);
	closure_t* closure68 = make_closure(lambda69, make_env_t_69(mx));
	number_t semx = array_sum(array_map(closure68, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_74 {
	number_t a;
} env_t_74;
env_t_74* make_env_t_74(number_t a) {
	env_t_74* env = (env_t_74*)malloc(sizeof(env_t_74));
	env->a = a;
	return env;
}

value_t lambda74(env_t_74* env71, number_t j) {
	number_t a70 = env71->a;
	value_t res;
	res.number_t_value = gamma_ln((a70) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t linalg_log_gamma_distrib(number_t a, number_t p) {
	closure_t* closure73 = make_closure(lambda74, make_env_t_74(a));
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (array_sum(array_map(closure73, array_range(1, (int)(p)))));
}

array_array_number_t linalg_new_matrix_test(array_number_t dum) {
	array_number_t array75 = (array_number_t)malloc(sizeof(int) * 2);
	array75->length=3;
	array75->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array75->arr[0] = 0;
	array75->arr[1] = 0;
	array75->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array75;;
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
	array_number_t array76 = (array_number_t)malloc(sizeof(int) * 2);
	array76->length=3;
	array76->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array76->arr[0] = theta->arr[i1];
	array76->arr[1] = theta->arr[(i1) + (1)];
	array76->arr[2] = 0;;
	array_number_t array77 = (array_number_t)malloc(sizeof(int) * 2);
	array77->length=3;
	array77->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array77->arr[0] = theta->arr[(i1) + (2)];
	array77->arr[1] = 0;
	array77->arr[2] = 0;;
	array_number_t array78 = (array_number_t)malloc(sizeof(int) * 2);
	array78->length=3;
	array78->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array78->arr[0] = theta->arr[(i1) + (3)];
	array78->arr[1] = 0;
	array78->arr[2] = 0;;
	array_number_t array79 = (array_number_t)malloc(sizeof(int) * 2);
	array79->length=3;
	array79->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array79->arr[0] = 0;
	array79->arr[1] = 0;
	array79->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array76;
	finger1->arr[1] = array77;
	finger1->arr[2] = array78;
	finger1->arr[3] = array79;;
	index_t i2 = (i1) + (4);
	array_number_t array80 = (array_number_t)malloc(sizeof(int) * 2);
	array80->length=3;
	array80->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array80->arr[0] = theta->arr[i2];
	array80->arr[1] = theta->arr[(i2) + (1)];
	array80->arr[2] = 0;;
	array_number_t array81 = (array_number_t)malloc(sizeof(int) * 2);
	array81->length=3;
	array81->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array81->arr[0] = theta->arr[(i2) + (2)];
	array81->arr[1] = 0;
	array81->arr[2] = 0;;
	array_number_t array82 = (array_number_t)malloc(sizeof(int) * 2);
	array82->length=3;
	array82->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array82->arr[0] = theta->arr[(i2) + (3)];
	array82->arr[1] = 0;
	array82->arr[2] = 0;;
	array_number_t array83 = (array_number_t)malloc(sizeof(int) * 2);
	array83->length=3;
	array83->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array83->arr[0] = 0;
	array83->arr[1] = 0;
	array83->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array80;
	finger2->arr[1] = array81;
	finger2->arr[2] = array82;
	finger2->arr[3] = array83;;
	index_t i3 = (i2) + (4);
	array_number_t array84 = (array_number_t)malloc(sizeof(int) * 2);
	array84->length=3;
	array84->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array84->arr[0] = theta->arr[i3];
	array84->arr[1] = theta->arr[(i3) + (1)];
	array84->arr[2] = 0;;
	array_number_t array85 = (array_number_t)malloc(sizeof(int) * 2);
	array85->length=3;
	array85->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array85->arr[0] = theta->arr[(i3) + (2)];
	array85->arr[1] = 0;
	array85->arr[2] = 0;;
	array_number_t array86 = (array_number_t)malloc(sizeof(int) * 2);
	array86->length=3;
	array86->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array86->arr[0] = theta->arr[(i3) + (3)];
	array86->arr[1] = 0;
	array86->arr[2] = 0;;
	array_number_t array87 = (array_number_t)malloc(sizeof(int) * 2);
	array87->length=3;
	array87->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array87->arr[0] = 0;
	array87->arr[1] = 0;
	array87->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array84;
	finger3->arr[1] = array85;
	finger3->arr[2] = array86;
	finger3->arr[3] = array87;;
	index_t i4 = (i3) + (4);
	array_number_t array88 = (array_number_t)malloc(sizeof(int) * 2);
	array88->length=3;
	array88->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array88->arr[0] = theta->arr[i4];
	array88->arr[1] = theta->arr[(i4) + (1)];
	array88->arr[2] = 0;;
	array_number_t array89 = (array_number_t)malloc(sizeof(int) * 2);
	array89->length=3;
	array89->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array89->arr[0] = theta->arr[(i4) + (2)];
	array89->arr[1] = 0;
	array89->arr[2] = 0;;
	array_number_t array90 = (array_number_t)malloc(sizeof(int) * 2);
	array90->length=3;
	array90->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array90->arr[0] = theta->arr[(i4) + (3)];
	array90->arr[1] = 0;
	array90->arr[2] = 0;;
	array_number_t array91 = (array_number_t)malloc(sizeof(int) * 2);
	array91->length=3;
	array91->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array91->arr[0] = 0;
	array91->arr[1] = 0;
	array91->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array88;
	finger4->arr[1] = array89;
	finger4->arr[2] = array90;
	finger4->arr[3] = array91;;
	index_t i5 = (i4) + (4);
	array_number_t array92 = (array_number_t)malloc(sizeof(int) * 2);
	array92->length=3;
	array92->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array92->arr[0] = theta->arr[i5];
	array92->arr[1] = theta->arr[(i5) + (1)];
	array92->arr[2] = 0;;
	array_number_t array93 = (array_number_t)malloc(sizeof(int) * 2);
	array93->length=3;
	array93->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array93->arr[0] = theta->arr[(i5) + (2)];
	array93->arr[1] = 0;
	array93->arr[2] = 0;;
	array_number_t array94 = (array_number_t)malloc(sizeof(int) * 2);
	array94->length=3;
	array94->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array94->arr[0] = theta->arr[(i5) + (3)];
	array94->arr[1] = 0;
	array94->arr[2] = 0;;
	array_number_t array95 = (array_number_t)malloc(sizeof(int) * 2);
	array95->length=3;
	array95->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array95->arr[0] = 0;
	array95->arr[1] = 0;
	array95->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array92;
	finger5->arr[1] = array93;
	finger5->arr[2] = array94;
	finger5->arr[3] = array95;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t linalg_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array96 = (array_number_t)malloc(sizeof(int) * 2);
	array96->length=3;
	array96->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array96->arr[0] = 1;
	array96->arr[1] = 0;
	array96->arr[2] = 0;;
	array_number_t array97 = (array_number_t)malloc(sizeof(int) * 2);
	array97->length=3;
	array97->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array97->arr[0] = 0;
	array97->arr[1] = cos(tx);
	array97->arr[2] = -(sin(tx));;
	array_number_t array98 = (array_number_t)malloc(sizeof(int) * 2);
	array98->length=3;
	array98->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array98->arr[0] = 0;
	array98->arr[1] = sin(tx);
	array98->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array96;
	Rx->arr[1] = array97;
	Rx->arr[2] = array98;;
	array_number_t array99 = (array_number_t)malloc(sizeof(int) * 2);
	array99->length=3;
	array99->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array99->arr[0] = cos(ty);
	array99->arr[1] = 0;
	array99->arr[2] = sin(ty);;
	array_number_t array100 = (array_number_t)malloc(sizeof(int) * 2);
	array100->length=3;
	array100->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array100->arr[0] = 0;
	array100->arr[1] = 1;
	array100->arr[2] = 0;;
	array_number_t array101 = (array_number_t)malloc(sizeof(int) * 2);
	array101->length=3;
	array101->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array101->arr[0] = -(sin(ty));
	array101->arr[1] = 0;
	array101->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array99;
	Ry->arr[1] = array100;
	Ry->arr[2] = array101;;
	array_number_t array102 = (array_number_t)malloc(sizeof(int) * 2);
	array102->length=3;
	array102->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array102->arr[0] = cos(tz);
	array102->arr[1] = -(sin(tz));
	array102->arr[2] = 0;;
	array_number_t array103 = (array_number_t)malloc(sizeof(int) * 2);
	array103->length=3;
	array103->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array103->arr[0] = sin(tz);
	array103->arr[1] = cos(tz);
	array103->arr[2] = 0;;
	array_number_t array104 = (array_number_t)malloc(sizeof(int) * 2);
	array104->length=3;
	array104->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array104->arr[0] = 0;
	array104->arr[1] = 0;
	array104->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array102;
	Rz->arr[1] = array103;
	Rz->arr[2] = array104;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = matrix_transpose(m1);
	array_array_number_t m2t = matrix_transpose(m2);
	return matrix_transpose(matrix_concat(m1t, m2t));
}

array_array_number_t linalg_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = linalg_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array106 = (array_number_t)malloc(sizeof(int) * 2);
	array106->length=1;
	array106->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array106->arr[0] = 0;;
	array_number_t array107 = (array_number_t)malloc(sizeof(int) * 2);
	array107->length=1;
	array107->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array107->arr[0] = 0;;
	array_number_t array108 = (array_number_t)malloc(sizeof(int) * 2);
	array108->length=1;
	array108->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array108->arr[0] = 0;;
	array_array_number_t array105 = (array_array_number_t)malloc(sizeof(int) * 2);
	array105->length=3;
	array105->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array105->arr[0] = array106;
	array105->arr[1] = array107;
	array105->arr[2] = array108;;
	array_number_t array110 = (array_number_t)malloc(sizeof(int) * 2);
	array110->length=4;
	array110->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array110->arr[0] = 0;
	array110->arr[1] = 0;
	array110->arr[2] = 0;
	array110->arr[3] = 1;;
	array_array_number_t array109 = (array_array_number_t)malloc(sizeof(int) * 2);
	array109->length=1;
	array109->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array109->arr[0] = array110;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, array105), array109);
	matrix_print(R);
	matrix_print(T);
	matrix_print(base_relative);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_120 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_120;
env_t_120* make_env_t_120(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_120* env = (env_t_120*)malloc(sizeof(env_t_120));
	env->pose_params = pose_params;
	env->offset = offset;
	env->base_relatives = base_relatives;
	return env;
}

value_t lambda120(env_t_120* env117, number_t i_bone) {
	array_array_number_t pose_params116 = env117->pose_params;
	index_t offset115 = env117->offset;
	array_array_array_number_t base_relatives114 = env117->base_relatives;
	value_t res;
	res.array_array_number_t_value = linalg_make_relative(pose_params116->arr[((int)(i_bone)) + (offset115)], base_relatives114->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t linalg_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	closure_t* closure119 = make_closure(lambda120, make_env_t_120(pose_params,offset,base_relatives));
	return array_map_to_matrix3d(closure119, array_range(0, (n_bones) - (1)));
}

array_array_number_t linalg_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite121 = NULL;
	if((n) < (0.0001)) {
		array_number_t array123 = (array_number_t)malloc(sizeof(int) * 2);
	array123->length=3;
	array123->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array123->arr[0] = 1;
	array123->arr[1] = 0;
	array123->arr[2] = 0;;
		array_number_t array124 = (array_number_t)malloc(sizeof(int) * 2);
	array124->length=3;
	array124->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array124->arr[0] = 0;
	array124->arr[1] = 1;
	array124->arr[2] = 0;;
		array_number_t array125 = (array_number_t)malloc(sizeof(int) * 2);
	array125->length=3;
	array125->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array125->arr[0] = 0;
	array125->arr[1] = 0;
	array125->arr[2] = 1;;
		array_array_number_t array122 = (array_array_number_t)malloc(sizeof(int) * 2);
	array122->length=3;
	array122->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array122->arr[0] = array123;
	array122->arr[1] = array124;
	array122->arr[2] = array125;;
		ite121 = array122;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array127 = (array_number_t)malloc(sizeof(int) * 2);
	array127->length=3;
	array127->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array127->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array127->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array127->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array128 = (array_number_t)malloc(sizeof(int) * 2);
	array128->length=3;
	array128->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array128->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array128->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array128->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array129 = (array_number_t)malloc(sizeof(int) * 2);
	array129->length=3;
	array129->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array129->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array129->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array129->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array126 = (array_array_number_t)malloc(sizeof(int) * 2);
	array126->length=3;
	array126->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array126->arr[0] = array127;
	array126->arr[1] = array128;
	array126->arr[2] = array129;;
		ite121 = array126;
	}
	return ite121;
}
typedef struct env_t_154 {
	value_t dummy_variable;
} env_t_154;
env_t_154* make_env_t_154() {
	env_t_154* env = (env_t_154*)malloc(sizeof(env_t_154));
	
	return env;
}

value_t lambda154(env_t_154* env130, number_t r) {
	
	value_t res;
	res.array_number_t_value = array_range(((int)(r)) * (4), (((int)(r)) * (4)) + (3));
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
	array_number_t array146 = (array_number_t)malloc(sizeof(int) * 2);
	array146->length=3;
	array146->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array146->arr[0] = 1;
	array146->arr[1] = 2;
	array146->arr[2] = 3;;
	array_number_t array147 = (array_number_t)malloc(sizeof(int) * 2);
	array147->length=3;
	array147->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array147->arr[0] = 4;
	array147->arr[1] = 5;
	array147->arr[2] = 6;;
	array_number_t array148 = (array_number_t)malloc(sizeof(int) * 2);
	array148->length=3;
	array148->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array148->arr[0] = 7;
	array148->arr[1] = 8;
	array148->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array146;
	mat1->arr[1] = array147;
	mat1->arr[2] = array148;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	closure_t* closure132 = make_closure(lambda154, make_env_t_154());
	array_array_number_t base_rel = array_map_to_matrix(closure132, array_range(1, 4));
	array_array_number_t q = linalg_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = linalg_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	return ;
}
