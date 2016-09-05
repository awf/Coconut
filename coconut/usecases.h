#ifndef __USECASES_H__ 
#define __USECASES_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

array_number_t TOP_LEVEL_usecases_radial_distort(array_number_t rad_params, array_number_t proj) {
	number_t rsq = TOP_LEVEL_linalg_sqnorm(proj);
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	return TOP_LEVEL_linalg_mult_by_scalar(proj, L);
}

array_number_t TOP_LEVEL_usecases_rodrigues_rotate_point(array_number_t rot, array_number_t x) {
	number_t sqtheta = TOP_LEVEL_linalg_sqnorm(rot);
	array_number_t ite97 = 0;
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
		ite97 = TOP_LEVEL_linalg_add_vec(TOP_LEVEL_linalg_add_vec(v1, v2), TOP_LEVEL_linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite97 = TOP_LEVEL_linalg_add_vec(x, TOP_LEVEL_linalg_cross(rot, x));
	}
	return ite97;
}

array_number_t TOP_LEVEL_usecases_project(array_number_t cam, array_number_t x) {
	index_t N_CAM_PARAMS = 11;
	index_t ROT_IDX = 0;
	index_t CENTER_IDX = 3;
	index_t FOCAL_IDX = 6;
	index_t X0_IDX = 7;
	index_t RAD_IDX = 9;
	array_number_t Xcam = TOP_LEVEL_usecases_rodrigues_rotate_point(array_slice(cam, ROT_IDX, (ROT_IDX) + (2)), TOP_LEVEL_linalg_sub_vec(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2))));
	array_number_t distorted = TOP_LEVEL_usecases_radial_distort(array_slice(cam, RAD_IDX, (RAD_IDX) + (1)), TOP_LEVEL_linalg_mult_by_scalar(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2])));
	return TOP_LEVEL_linalg_add_vec(array_slice(cam, X0_IDX, (X0_IDX) + (1)), TOP_LEVEL_linalg_mult_by_scalar(distorted, cam->arr[FOCAL_IDX]));
}

array_number_t TOP_LEVEL_usecases_compute_reproj_err(array_number_t cam, array_number_t x, number_t w, array_number_t feat) {
	
	return TOP_LEVEL_linalg_mult_by_scalar(TOP_LEVEL_linalg_sub_vec(TOP_LEVEL_usecases_project(cam, x), feat), w);
}

number_t TOP_LEVEL_usecases_compute_zach_weight_error(number_t w) {
	
	return (1) - ((w) * (w));
}
typedef empty_env_t env_t_101;


value_t lambda101(env_t_101* env98, number_t w) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t TOP_LEVEL_usecases_w_err(array_number_t w) {
	env_t_101 env_t_101_value = make_empty_env(); closure_t closure100 = make_closure(lambda101, &env_t_101_value);
	return TOP_LEVEL_linalg_vectorMap(closure100, w);
}
typedef struct env_t_112 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_112;
env_t_112 make_env_t_112(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_112 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda112(env_t_112* env109, number_t i) {
	array_array_number_t x108 = env109->x;
	array_number_t w107 = env109->w;
	array_array_number_t obs106 = env109->obs;
	array_array_number_t feat105 = env109->feat;
	array_array_number_t cams104 = env109->cams;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_usecases_compute_reproj_err(cams104->arr[(int)(obs106->arr[(int)(i)]->arr[0])], x108->arr[(int)(obs106->arr[(int)(i)]->arr[1])], w107->arr[(int)(i)], feat105->arr[(int)(i)]);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef102 = cams->length;
	card_t n = macroDef102;
	card_t macroDef103 = w->length;
	card_t p = macroDef103;
	array_number_t range = TOP_LEVEL_linalg_vectorRange(0, (p) - (1));
	env_t_112 env_t_112_value = make_env_t_112(x,w,obs,feat,cams); closure_t closure111 = make_closure(lambda112, &env_t_112_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure111, range);
}
typedef struct env_t_136 {
	array_number_t one_cam;
} env_t_136;
env_t_136 make_env_t_136(array_number_t one_cam) {
	env_t_136 env;
	env.one_cam = one_cam;
	return env;
}

value_t lambda136(env_t_136* env114, number_t x) {
	array_number_t one_cam113 = env114->one_cam;
	value_t res;
	res.array_number_t_value = one_cam113;
	return res;
}
typedef struct env_t_137 {
	array_number_t one_x;
} env_t_137;
env_t_137 make_env_t_137(array_number_t one_x) {
	env_t_137 env;
	env.one_x = one_x;
	return env;
}

value_t lambda137(env_t_137* env118, number_t x) {
	array_number_t one_x117 = env118->one_x;
	value_t res;
	res.array_number_t_value = one_x117;
	return res;
}
typedef struct env_t_138 {
	number_t one_w;
} env_t_138;
env_t_138 make_env_t_138(number_t one_w) {
	env_t_138 env;
	env.one_w = one_w;
	return env;
}

value_t lambda138(env_t_138* env122, number_t x) {
	number_t one_w121 = env122->one_w;
	value_t res;
	res.number_t_value = one_w121;
	return res;
}
typedef struct env_t_139 {
	array_number_t one_feat;
} env_t_139;
env_t_139 make_env_t_139(array_number_t one_feat) {
	env_t_139 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda139(env_t_139* env126, number_t x) {
	array_number_t one_feat125 = env126->one_feat;
	value_t res;
	res.array_number_t_value = one_feat125;
	return res;
}
typedef struct env_t_140 {
	card_t n;
	card_t m;
} env_t_140;
env_t_140 make_env_t_140(card_t n,card_t m) {
	env_t_140 env;
	env.n = n;
	env.m = m;
	return env;
}

value_t lambda140(env_t_140* env131, number_t x) {
	card_t n130 = env131->n;
	card_t m129 = env131->m;
	array_number_t array134 = (array_number_t)malloc(sizeof(int) * 2);
	array134->length=2;
	array134->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array134->arr[0] = (double)(((int)(x)) % ((n130)));
	array134->arr[1] = (double)(((int)(x)) % ((m129)));;
	value_t res;
	res.array_number_t_value = array134;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = TOP_LEVEL_linalg_vectorRead(fn, 0);
	card_t n = (int)(nmp->arr[0]);
	card_t m = (int)(nmp->arr[1]);
	card_t p = (int)(nmp->arr[2]);
	card_t oneCard = 1;
	array_number_t one_cam = TOP_LEVEL_linalg_vectorRead(fn, 1);
	env_t_136 env_t_136_value = make_env_t_136(one_cam); closure_t closure116 = make_closure(lambda136, &env_t_136_value);
	array_array_number_t cam = TOP_LEVEL_linalg_vectorMapToMatrix(closure116, TOP_LEVEL_linalg_vectorRange(oneCard, n));
	array_number_t one_x = TOP_LEVEL_linalg_vectorRead(fn, 2);
	env_t_137 env_t_137_value = make_env_t_137(one_x); closure_t closure120 = make_closure(lambda137, &env_t_137_value);
	array_array_number_t x = TOP_LEVEL_linalg_vectorMapToMatrix(closure120, TOP_LEVEL_linalg_vectorRange(oneCard, m));
	number_t one_w = TOP_LEVEL_linalg_numberRead(fn, 3);
	env_t_138 env_t_138_value = make_env_t_138(one_w); closure_t closure124 = make_closure(lambda138, &env_t_138_value);
	array_number_t w = TOP_LEVEL_linalg_vectorMap(closure124, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_number_t one_feat = TOP_LEVEL_linalg_vectorRead(fn, 4);
	env_t_139 env_t_139_value = make_env_t_139(one_feat); closure_t closure128 = make_closure(lambda139, &env_t_139_value);
	array_array_number_t feat = TOP_LEVEL_linalg_vectorMapToMatrix(closure128, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	env_t_140 env_t_140_value = make_env_t_140(n,m); closure_t closure133 = make_closure(lambda140, &env_t_140_value);
	array_array_number_t obs = TOP_LEVEL_linalg_vectorMapToMatrix(closure133, TOP_LEVEL_linalg_vectorRange(0, (p) - (oneCard)));
	timer_t t = tic();
	array_array_number_t res = TOP_LEVEL_usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_145 {
	number_t mx;
} env_t_145;
env_t_145 make_env_t_145(number_t mx) {
	env_t_145 env;
	env.mx = mx;
	return env;
}

value_t lambda145(env_t_145* env142, number_t x) {
	number_t mx141 = env142->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx141));
	return res;
}
number_t TOP_LEVEL_usecases_logsumexp(array_number_t arr) {
	number_t mx = TOP_LEVEL_linalg_arrayMax(arr);
	env_t_145 env_t_145_value = make_env_t_145(mx); closure_t closure144 = make_closure(lambda145, &env_t_145_value);
	number_t semx = TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure144, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_150 {
	number_t a;
} env_t_150;
env_t_150 make_env_t_150(number_t a) {
	env_t_150 env;
	env.a = a;
	return env;
}

value_t lambda150(env_t_150* env147, number_t j) {
	number_t a146 = env147->a;
	value_t res;
	res.number_t_value = (a146) + ((0.5) * ((1) - ((double)(j))));
	return res;
}
number_t TOP_LEVEL_usecases_log_gamma_distrib(number_t a, number_t p) {
	env_t_150 env_t_150_value = make_env_t_150(a); closure_t closure149 = make_closure(lambda150, &env_t_150_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure149, TOP_LEVEL_linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t TOP_LEVEL_usecases_new_matrix_test(array_number_t dum) {
	array_number_t array151 = (array_number_t)malloc(sizeof(int) * 2);
	array151->length=3;
	array151->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array151->arr[0] = 0;
	array151->arr[1] = 0;
	array151->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array151;;
	return res;
}

array_array_number_t TOP_LEVEL_usecases_to_pose_params(array_number_t theta, card_t n_bones) {
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
	array_number_t array152 = (array_number_t)malloc(sizeof(int) * 2);
	array152->length=3;
	array152->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array152->arr[0] = theta->arr[i1];
	array152->arr[1] = theta->arr[(i1) + (1)];
	array152->arr[2] = 0;;
	array_number_t array153 = (array_number_t)malloc(sizeof(int) * 2);
	array153->length=3;
	array153->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array153->arr[0] = theta->arr[(i1) + (2)];
	array153->arr[1] = 0;
	array153->arr[2] = 0;;
	array_number_t array154 = (array_number_t)malloc(sizeof(int) * 2);
	array154->length=3;
	array154->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array154->arr[0] = theta->arr[(i1) + (3)];
	array154->arr[1] = 0;
	array154->arr[2] = 0;;
	array_number_t array155 = (array_number_t)malloc(sizeof(int) * 2);
	array155->length=3;
	array155->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array155->arr[0] = 0;
	array155->arr[1] = 0;
	array155->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array152;
	finger1->arr[1] = array153;
	finger1->arr[2] = array154;
	finger1->arr[3] = array155;;
	index_t i2 = (i1) + (4);
	array_number_t array156 = (array_number_t)malloc(sizeof(int) * 2);
	array156->length=3;
	array156->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array156->arr[0] = theta->arr[i2];
	array156->arr[1] = theta->arr[(i2) + (1)];
	array156->arr[2] = 0;;
	array_number_t array157 = (array_number_t)malloc(sizeof(int) * 2);
	array157->length=3;
	array157->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array157->arr[0] = theta->arr[(i2) + (2)];
	array157->arr[1] = 0;
	array157->arr[2] = 0;;
	array_number_t array158 = (array_number_t)malloc(sizeof(int) * 2);
	array158->length=3;
	array158->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array158->arr[0] = theta->arr[(i2) + (3)];
	array158->arr[1] = 0;
	array158->arr[2] = 0;;
	array_number_t array159 = (array_number_t)malloc(sizeof(int) * 2);
	array159->length=3;
	array159->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array159->arr[0] = 0;
	array159->arr[1] = 0;
	array159->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array156;
	finger2->arr[1] = array157;
	finger2->arr[2] = array158;
	finger2->arr[3] = array159;;
	index_t i3 = (i2) + (4);
	array_number_t array160 = (array_number_t)malloc(sizeof(int) * 2);
	array160->length=3;
	array160->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array160->arr[0] = theta->arr[i3];
	array160->arr[1] = theta->arr[(i3) + (1)];
	array160->arr[2] = 0;;
	array_number_t array161 = (array_number_t)malloc(sizeof(int) * 2);
	array161->length=3;
	array161->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array161->arr[0] = theta->arr[(i3) + (2)];
	array161->arr[1] = 0;
	array161->arr[2] = 0;;
	array_number_t array162 = (array_number_t)malloc(sizeof(int) * 2);
	array162->length=3;
	array162->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array162->arr[0] = theta->arr[(i3) + (3)];
	array162->arr[1] = 0;
	array162->arr[2] = 0;;
	array_number_t array163 = (array_number_t)malloc(sizeof(int) * 2);
	array163->length=3;
	array163->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array163->arr[0] = 0;
	array163->arr[1] = 0;
	array163->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array160;
	finger3->arr[1] = array161;
	finger3->arr[2] = array162;
	finger3->arr[3] = array163;;
	index_t i4 = (i3) + (4);
	array_number_t array164 = (array_number_t)malloc(sizeof(int) * 2);
	array164->length=3;
	array164->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array164->arr[0] = theta->arr[i4];
	array164->arr[1] = theta->arr[(i4) + (1)];
	array164->arr[2] = 0;;
	array_number_t array165 = (array_number_t)malloc(sizeof(int) * 2);
	array165->length=3;
	array165->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array165->arr[0] = theta->arr[(i4) + (2)];
	array165->arr[1] = 0;
	array165->arr[2] = 0;;
	array_number_t array166 = (array_number_t)malloc(sizeof(int) * 2);
	array166->length=3;
	array166->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array166->arr[0] = theta->arr[(i4) + (3)];
	array166->arr[1] = 0;
	array166->arr[2] = 0;;
	array_number_t array167 = (array_number_t)malloc(sizeof(int) * 2);
	array167->length=3;
	array167->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array167->arr[0] = 0;
	array167->arr[1] = 0;
	array167->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array164;
	finger4->arr[1] = array165;
	finger4->arr[2] = array166;
	finger4->arr[3] = array167;;
	index_t i5 = (i4) + (4);
	array_number_t array168 = (array_number_t)malloc(sizeof(int) * 2);
	array168->length=3;
	array168->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array168->arr[0] = theta->arr[i5];
	array168->arr[1] = theta->arr[(i5) + (1)];
	array168->arr[2] = 0;;
	array_number_t array169 = (array_number_t)malloc(sizeof(int) * 2);
	array169->length=3;
	array169->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array169->arr[0] = theta->arr[(i5) + (2)];
	array169->arr[1] = 0;
	array169->arr[2] = 0;;
	array_number_t array170 = (array_number_t)malloc(sizeof(int) * 2);
	array170->length=3;
	array170->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array170->arr[0] = theta->arr[(i5) + (3)];
	array170->arr[1] = 0;
	array170->arr[2] = 0;;
	array_number_t array171 = (array_number_t)malloc(sizeof(int) * 2);
	array171->length=3;
	array171->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array171->arr[0] = 0;
	array171->arr[1] = 0;
	array171->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array168;
	finger5->arr[1] = array169;
	finger5->arr[2] = array170;
	finger5->arr[3] = array171;;
	return TOP_LEVEL_linalg_matrixConcat(pose_params, TOP_LEVEL_linalg_matrixConcat(finger1, TOP_LEVEL_linalg_matrixConcat(finger2, TOP_LEVEL_linalg_matrixConcat(finger3, TOP_LEVEL_linalg_matrixConcat(finger4, finger5)))));
}

array_array_number_t TOP_LEVEL_usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array172 = (array_number_t)malloc(sizeof(int) * 2);
	array172->length=3;
	array172->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array172->arr[0] = 1;
	array172->arr[1] = 0;
	array172->arr[2] = 0;;
	array_number_t array173 = (array_number_t)malloc(sizeof(int) * 2);
	array173->length=3;
	array173->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array173->arr[0] = 0;
	array173->arr[1] = cos(tx);
	array173->arr[2] = -(sin(tx));;
	array_number_t array174 = (array_number_t)malloc(sizeof(int) * 2);
	array174->length=3;
	array174->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array174->arr[0] = 0;
	array174->arr[1] = sin(tx);
	array174->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array172;
	Rx->arr[1] = array173;
	Rx->arr[2] = array174;;
	array_number_t array175 = (array_number_t)malloc(sizeof(int) * 2);
	array175->length=3;
	array175->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array175->arr[0] = cos(ty);
	array175->arr[1] = 0;
	array175->arr[2] = sin(ty);;
	array_number_t array176 = (array_number_t)malloc(sizeof(int) * 2);
	array176->length=3;
	array176->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array176->arr[0] = 0;
	array176->arr[1] = 1;
	array176->arr[2] = 0;;
	array_number_t array177 = (array_number_t)malloc(sizeof(int) * 2);
	array177->length=3;
	array177->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array177->arr[0] = -(sin(ty));
	array177->arr[1] = 0;
	array177->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array175;
	Ry->arr[1] = array176;
	Ry->arr[2] = array177;;
	array_number_t array178 = (array_number_t)malloc(sizeof(int) * 2);
	array178->length=3;
	array178->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array178->arr[0] = cos(tz);
	array178->arr[1] = -(sin(tz));
	array178->arr[2] = 0;;
	array_number_t array179 = (array_number_t)malloc(sizeof(int) * 2);
	array179->length=3;
	array179->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array179->arr[0] = sin(tz);
	array179->arr[1] = cos(tz);
	array179->arr[2] = 0;;
	array_number_t array180 = (array_number_t)malloc(sizeof(int) * 2);
	array180->length=3;
	array180->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array180->arr[0] = 0;
	array180->arr[1] = 0;
	array180->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array178;
	Rz->arr[1] = array179;
	Rz->arr[2] = array180;;
	return TOP_LEVEL_linalg_matrixMult(Rz, TOP_LEVEL_linalg_matrixMult(Ry, Rx));
}

array_array_number_t TOP_LEVEL_usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = TOP_LEVEL_usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array181 = (array_number_t)malloc(sizeof(int) * 2);
	array181->length=1;
	array181->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array181->arr[0] = 0;;
	array_number_t array182 = (array_number_t)malloc(sizeof(int) * 2);
	array182->length=1;
	array182->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array182->arr[0] = 0;;
	array_number_t array183 = (array_number_t)malloc(sizeof(int) * 2);
	array183->length=1;
	array183->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array183->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array181;
	r1->arr[1] = array182;
	r1->arr[2] = array183;;
	array_number_t array184 = (array_number_t)malloc(sizeof(int) * 2);
	array184->length=4;
	array184->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array184->arr[0] = 0;
	array184->arr[1] = 0;
	array184->arr[2] = 0;
	array184->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array184;;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcat(TOP_LEVEL_linalg_matrixConcatCol(R, r1), r2);
	return TOP_LEVEL_linalg_matrixMult(base_relative, T);
}
typedef struct env_t_191 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_191;
env_t_191 make_env_t_191(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_191 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda191(env_t_191* env188, number_t i_bone) {
	array_array_number_t pose_params187 = env188->pose_params;
	index_t offset186 = env188->offset;
	array_array_array_number_t base_relatives185 = env188->base_relatives;
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_usecases_make_relative(pose_params187->arr[((int)(i_bone)) + (offset186)], base_relatives185->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_get_posed_relatives(card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_191 env_t_191_value = make_env_t_191(pose_params,offset,base_relatives); closure_t closure190 = make_closure(lambda191, &env_t_191_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D(closure190, TOP_LEVEL_linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t TOP_LEVEL_usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(TOP_LEVEL_linalg_sqnorm(angle_axis));
	array_array_number_t ite192 = 0;
	if((n) < (0.0001)) {
		array_number_t array194 = (array_number_t)malloc(sizeof(int) * 2);
	array194->length=3;
	array194->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array194->arr[0] = 1;
	array194->arr[1] = 0;
	array194->arr[2] = 0;;
		array_number_t array195 = (array_number_t)malloc(sizeof(int) * 2);
	array195->length=3;
	array195->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array195->arr[0] = 0;
	array195->arr[1] = 1;
	array195->arr[2] = 0;;
		array_number_t array196 = (array_number_t)malloc(sizeof(int) * 2);
	array196->length=3;
	array196->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array196->arr[0] = 0;
	array196->arr[1] = 0;
	array196->arr[2] = 1;;
		array_array_number_t array193 = (array_array_number_t)malloc(sizeof(int) * 2);
	array193->length=3;
	array193->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array193->arr[0] = array194;
	array193->arr[1] = array195;
	array193->arr[2] = array196;;
		ite192 = array193;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array198 = (array_number_t)malloc(sizeof(int) * 2);
	array198->length=3;
	array198->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array198->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array198->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array198->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array199 = (array_number_t)malloc(sizeof(int) * 2);
	array199->length=3;
	array199->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array199->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array199->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array199->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array200 = (array_number_t)malloc(sizeof(int) * 2);
	array200->length=3;
	array200->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array200->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array200->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array200->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array197 = (array_array_number_t)malloc(sizeof(int) * 2);
	array197->length=3;
	array197->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array197->arr[0] = array198;
	array197->arr[1] = array199;
	array197->arr[2] = array200;;
		ite192 = array197;
	}
	return ite192;
}
typedef struct env_t_210 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_210;
env_t_210 make_env_t_210(array_array_array_number_t relatives,array_number_t parents) {
	env_t_210 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda210(env_t_210* env203, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives202 = env203->relatives;
	array_number_t parents201 = env203->parents;
	array_array_array_number_t ite209 = 0;
	if((parents201->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives202->arr[i];;
		ite209 = TOP_LEVEL_linalg_matrix3DConcat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = TOP_LEVEL_linalg_matrixMult(acc->arr[(int)(parents201->arr[i])], relatives202->arr[i]);;
		ite209 = TOP_LEVEL_linalg_matrix3DConcat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite209;
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array208 = (array_number_t)malloc(sizeof(int) * 2);
	array208->length=0;
	array208->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array207 = (array_array_number_t)malloc(sizeof(int) * 2);
	array207->length=1;
	array207->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array207->arr[0] = array208;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array207;;
	env_t_210 env_t_210_value = make_env_t_210(relatives,parents); closure_t closure205 = make_closure(lambda210, &env_t_210_value);
	card_t macroDef206 = relatives->length;
	return TOP_LEVEL_linalg_iterateMatrix3D(closure205, init, 0, (macroDef206) - (1));
}
typedef struct env_t_221 {
	array_number_t scale;
} env_t_221;
env_t_221 make_env_t_221(array_number_t scale) {
	env_t_221 env;
	env.scale = scale;
	return env;
}

value_t lambda221(env_t_221* env212, array_number_t row) {
	array_number_t scale211 = env212->scale;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(row, scale211);
	return res;
}
typedef empty_env_t env_t_222;


value_t lambda222(env_t_222* env215, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = TOP_LEVEL_usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_221 env_t_221_value = make_env_t_221(scale); closure_t closure214 = make_closure(lambda221, &env_t_221_value);
	array_array_number_t R1 = TOP_LEVEL_linalg_matrixMap(closure214, R);
	array_array_number_t array219 = (array_array_number_t)malloc(sizeof(int) * 2);
	array219->length=1;
	array219->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array219->arr[0] = pose_params->arr[2];;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcatCol(R1, TOP_LEVEL_linalg_matrixTranspose(array219));
	env_t_222 env_t_222_value = make_empty_env(); closure_t closure217 = make_closure(lambda222, &env_t_222_value);
	card_t macroDef218 = positions->arr[0]->length;
	array_number_t ones = TOP_LEVEL_linalg_vectorMap(closure217, TOP_LEVEL_linalg_vectorRange(1, macroDef218));
	array_array_number_t array220 = (array_array_number_t)malloc(sizeof(int) * 2);
	array220->length=1;
	array220->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array220->arr[0] = ones;;
	array_array_number_t positions_homog = TOP_LEVEL_linalg_matrixConcat(positions, array220);
	return TOP_LEVEL_linalg_matrixMult(T, positions_homog);
}
typedef empty_env_t env_t_238;


value_t lambda238(env_t_238* env223, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult(m1, m2);
	return res;
}
typedef struct env_t_239 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_239;
env_t_239 make_env_t_239(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_239 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda239(env_t_239* env231, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights230 = env231->weights;
	array_array_array_number_t transforms229 = env231->transforms;
	array_array_number_t base_positions228 = env231->base_positions;
	array_array_number_t curr_positions = TOP_LEVEL_linalg_matrixMult(matrix_slice(transforms229->arr[i_transform], 0, 2), base_positions228);
	card_t macroDef227 = base_positions228->length;
	array_array_number_t w = TOP_LEVEL_linalg_matrixFillFromVector(macroDef227, weights230->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixAdd(acc, TOP_LEVEL_linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t TOP_LEVEL_usecases_get_skinned_vertex_positions(index_t is_mirrored, card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = TOP_LEVEL_usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = TOP_LEVEL_usecases_relatives_to_absolutes(relatives, parents);
	env_t_238 env_t_238_value = make_empty_env(); closure_t closure225 = make_closure(lambda238, &env_t_238_value);
	array_array_array_number_t transforms = TOP_LEVEL_linalg_matrix3DMap2(closure225, absolutes, inverse_base_absolutes);
	card_t macroDef226 = base_positions->arr[0]->length;
	card_t n_verts = macroDef226;
	array_array_number_t init_positions = TOP_LEVEL_linalg_matrixFill(3, n_verts, 0);
	env_t_239 env_t_239_value = make_env_t_239(weights,transforms,base_positions); closure_t closure233 = make_closure(lambda239, &env_t_239_value);
	card_t macroDef234 = transforms->length;
	array_array_number_t positions = TOP_LEVEL_linalg_iterateMatrix(closure233, init_positions, 0, (macroDef234) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array235 = (array_number_t)malloc(sizeof(int) * 2);
	array235->length=3;
	array235->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array235->arr[0] = -1;
	array235->arr[1] = 0;
	array235->arr[2] = 0;;
		array_number_t array236 = (array_number_t)malloc(sizeof(int) * 2);
	array236->length=3;
	array236->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array236->arr[0] = 0;
	array236->arr[1] = 1;
	array236->arr[2] = 0;;
		array_number_t array237 = (array_number_t)malloc(sizeof(int) * 2);
	array237->length=3;
	array237->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array237->arr[0] = 0;
	array237->arr[1] = 0;
	array237->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array235;
	mirror_matrix->arr[1] = array236;
	mirror_matrix->arr[2] = array237;;
		mirrored_positions = TOP_LEVEL_linalg_matrixMult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return TOP_LEVEL_usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_247 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_247;
env_t_247 make_env_t_247(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_247 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda247(env_t_247* env244, number_t i) {
	array_array_number_t vertex_positions243 = env244->vertex_positions;
	array_array_number_t points242 = env244->points;
	index_t n_corr241 = env244->n_corr;
	array_number_t correspondences240 = env244->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr241);
	index_t c = (ind) % (n_corr241);
	value_t res;
	res.number_t_value = (points242->arr[r]->arr[c]) - (vertex_positions243->arr[r]->arr[(int)(correspondences240->arr[c])]);
	return res;
}
array_number_t TOP_LEVEL_usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, card_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = TOP_LEVEL_usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = TOP_LEVEL_usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_247 env_t_247_value = make_env_t_247(vertex_positions,points,n_corr,correspondences); closure_t closure246 = make_closure(lambda247, &env_t_247_value);
	array_number_t err = TOP_LEVEL_linalg_vectorMap(closure246, TOP_LEVEL_linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_275;


value_t lambda275(env_t_275* env248, number_t r) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorRange(((int)(r)) * (4), (((int)(r)) * (4)) + (3));
	return res;
}
void TOP_LEVEL_usecases_test1(array_number_t dum) {
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
	array_number_t c = TOP_LEVEL_linalg_cross(a, b);
	array_print(c);
	array_number_t d = TOP_LEVEL_linalg_mult_by_scalar(c, 15);
	array_print(d);
	array_number_t e = TOP_LEVEL_linalg_add_vec(a, b);
	array_print(e);
	array_number_t f = TOP_LEVEL_linalg_sub_vec(a, b);
	array_print(f);
	array_number_t g = TOP_LEVEL_linalg_add_vec3(a, b, c);
	array_print(g);
	number_t h = TOP_LEVEL_linalg_sqnorm(a);
	number_print(h);
	number_t i = TOP_LEVEL_linalg_dot_prod(a, b);
	number_print(i);
	array_number_t j = TOP_LEVEL_usecases_radial_distort(a, b);
	array_print(j);
	array_number_t k = TOP_LEVEL_usecases_rodrigues_rotate_point(a, b);
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
	array_number_t m = TOP_LEVEL_usecases_project(cam, j);
	array_print(m);
	array_number_t array264 = (array_number_t)malloc(sizeof(int) * 2);
	array264->length=3;
	array264->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array264->arr[0] = 1;
	array264->arr[1] = 2;
	array264->arr[2] = 3;;
	array_number_t array265 = (array_number_t)malloc(sizeof(int) * 2);
	array265->length=3;
	array265->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array265->arr[0] = 4;
	array265->arr[1] = 5;
	array265->arr[2] = 6;;
	array_number_t array266 = (array_number_t)malloc(sizeof(int) * 2);
	array266->length=3;
	array266->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array266->arr[0] = 7;
	array266->arr[1] = 8;
	array266->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array264;
	mat1->arr[1] = array265;
	mat1->arr[2] = array266;;
	array_array_number_t n = TOP_LEVEL_linalg_matrixMult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = TOP_LEVEL_linalg_matrixTranspose(n);
	matrix_print(o);
	array_array_number_t p = TOP_LEVEL_linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	env_t_275 env_t_275_value = make_empty_env(); closure_t closure250 = make_closure(lambda275, &env_t_275_value);
	array_array_number_t base_rel = TOP_LEVEL_linalg_vectorMapToMatrix(closure250, TOP_LEVEL_linalg_vectorRange(1, 4));
	array_array_number_t q = TOP_LEVEL_usecases_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = TOP_LEVEL_usecases_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	array_array_number_t s = TOP_LEVEL_usecases_apply_global_transform(mat1, mat1);
	matrix_print(s);
	array_array_number_t t = TOP_LEVEL_linalg_matrixAdd(mat1, mat1);
	matrix_print(t);
	array_array_number_t u = TOP_LEVEL_linalg_matrixFillFromVector(5, a);
	matrix_print(u);
	return ;
}
#endif
