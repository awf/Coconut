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
	array_number_t ite87 = 0;
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
		ite87 = TOP_LEVEL_linalg_add_vec(TOP_LEVEL_linalg_add_vec(v1, v2), TOP_LEVEL_linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite87 = TOP_LEVEL_linalg_add_vec(x, TOP_LEVEL_linalg_cross(rot, x));
	}
	return ite87;
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
typedef empty_env_t env_t_91;


value_t lambda91(env_t_91* env88, number_t w) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t TOP_LEVEL_usecases_w_err(array_number_t w) {
	env_t_91 env_t_91_value = make_empty_env(); closure_t closure90 = make_closure(lambda91, &env_t_91_value);
	return TOP_LEVEL_linalg_vectorMap(closure90, w);
}
typedef struct env_t_102 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_102;
env_t_102 make_env_t_102(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_102 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda102(env_t_102* env99, number_t i) {
	array_array_number_t x98 = env99->x;
	array_number_t w97 = env99->w;
	array_array_number_t obs96 = env99->obs;
	array_array_number_t feat95 = env99->feat;
	array_array_number_t cams94 = env99->cams;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_usecases_compute_reproj_err(cams94->arr[(int)(obs96->arr[(int)(i)]->arr[0])], x98->arr[(int)(obs96->arr[(int)(i)]->arr[1])], w97->arr[(int)(i)], feat95->arr[(int)(i)]);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef92 = cams->length;
	card_t n = macroDef92;
	card_t macroDef93 = w->length;
	card_t p = macroDef93;
	array_number_t range = TOP_LEVEL_linalg_vectorRange(0, (p) - (1));
	env_t_102 env_t_102_value = make_env_t_102(x,w,obs,feat,cams); closure_t closure101 = make_closure(lambda102, &env_t_102_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure101, range);
}
typedef struct env_t_126 {
	array_number_t one_cam;
} env_t_126;
env_t_126 make_env_t_126(array_number_t one_cam) {
	env_t_126 env;
	env.one_cam = one_cam;
	return env;
}

value_t lambda126(env_t_126* env104, number_t x) {
	array_number_t one_cam103 = env104->one_cam;
	value_t res;
	res.array_number_t_value = one_cam103;
	return res;
}
typedef struct env_t_127 {
	array_number_t one_x;
} env_t_127;
env_t_127 make_env_t_127(array_number_t one_x) {
	env_t_127 env;
	env.one_x = one_x;
	return env;
}

value_t lambda127(env_t_127* env108, number_t x) {
	array_number_t one_x107 = env108->one_x;
	value_t res;
	res.array_number_t_value = one_x107;
	return res;
}
typedef struct env_t_128 {
	number_t one_w;
} env_t_128;
env_t_128 make_env_t_128(number_t one_w) {
	env_t_128 env;
	env.one_w = one_w;
	return env;
}

value_t lambda128(env_t_128* env112, number_t x) {
	number_t one_w111 = env112->one_w;
	value_t res;
	res.number_t_value = one_w111;
	return res;
}
typedef struct env_t_129 {
	array_number_t one_feat;
} env_t_129;
env_t_129 make_env_t_129(array_number_t one_feat) {
	env_t_129 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda129(env_t_129* env116, number_t x) {
	array_number_t one_feat115 = env116->one_feat;
	value_t res;
	res.array_number_t_value = one_feat115;
	return res;
}
typedef struct env_t_130 {
	card_t n;
	card_t m;
} env_t_130;
env_t_130 make_env_t_130(card_t n,card_t m) {
	env_t_130 env;
	env.n = n;
	env.m = m;
	return env;
}

value_t lambda130(env_t_130* env121, number_t x) {
	card_t n120 = env121->n;
	card_t m119 = env121->m;
	array_number_t array124 = (array_number_t)malloc(sizeof(int) * 2);
	array124->length=2;
	array124->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array124->arr[0] = (double)(((int)(x)) % ((n120)));
	array124->arr[1] = (double)(((int)(x)) % ((m119)));;
	value_t res;
	res.array_number_t_value = array124;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = TOP_LEVEL_linalg_vectorRead(fn, 0);
	card_t n = (int)(nmp->arr[0]);
	card_t m = (int)(nmp->arr[1]);
	card_t p = (int)(nmp->arr[2]);
	card_t oneCard = 1;
	array_number_t one_cam = TOP_LEVEL_linalg_vectorRead(fn, 1);
	env_t_126 env_t_126_value = make_env_t_126(one_cam); closure_t closure106 = make_closure(lambda126, &env_t_126_value);
	array_array_number_t cam = TOP_LEVEL_linalg_vectorMapToMatrix(closure106, TOP_LEVEL_linalg_vectorRange(oneCard, n));
	array_number_t one_x = TOP_LEVEL_linalg_vectorRead(fn, 2);
	env_t_127 env_t_127_value = make_env_t_127(one_x); closure_t closure110 = make_closure(lambda127, &env_t_127_value);
	array_array_number_t x = TOP_LEVEL_linalg_vectorMapToMatrix(closure110, TOP_LEVEL_linalg_vectorRange(oneCard, m));
	number_t one_w = TOP_LEVEL_linalg_numberRead(fn, 3);
	env_t_128 env_t_128_value = make_env_t_128(one_w); closure_t closure114 = make_closure(lambda128, &env_t_128_value);
	array_number_t w = TOP_LEVEL_linalg_vectorMap(closure114, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_number_t one_feat = TOP_LEVEL_linalg_vectorRead(fn, 4);
	env_t_129 env_t_129_value = make_env_t_129(one_feat); closure_t closure118 = make_closure(lambda129, &env_t_129_value);
	array_array_number_t feat = TOP_LEVEL_linalg_vectorMapToMatrix(closure118, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	env_t_130 env_t_130_value = make_env_t_130(n,m); closure_t closure123 = make_closure(lambda130, &env_t_130_value);
	array_array_number_t obs = TOP_LEVEL_linalg_vectorMapToMatrix(closure123, TOP_LEVEL_linalg_vectorRange(0, (p) - (oneCard)));
	timer_t t = tic();
	array_array_number_t res = TOP_LEVEL_usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_135 {
	number_t mx;
} env_t_135;
env_t_135 make_env_t_135(number_t mx) {
	env_t_135 env;
	env.mx = mx;
	return env;
}

value_t lambda135(env_t_135* env132, number_t x) {
	number_t mx131 = env132->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx131));
	return res;
}
number_t TOP_LEVEL_usecases_logsumexp(array_number_t arr) {
	number_t mx = TOP_LEVEL_linalg_arrayMax(arr);
	env_t_135 env_t_135_value = make_env_t_135(mx); closure_t closure134 = make_closure(lambda135, &env_t_135_value);
	number_t semx = TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure134, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_140 {
	number_t a;
} env_t_140;
env_t_140 make_env_t_140(number_t a) {
	env_t_140 env;
	env.a = a;
	return env;
}

value_t lambda140(env_t_140* env137, number_t j) {
	number_t a136 = env137->a;
	value_t res;
	res.number_t_value = (a136) + ((0.5) * ((1) - ((double)(j))));
	return res;
}
number_t TOP_LEVEL_usecases_log_gamma_distrib(number_t a, number_t p) {
	env_t_140 env_t_140_value = make_env_t_140(a); closure_t closure139 = make_closure(lambda140, &env_t_140_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure139, TOP_LEVEL_linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t TOP_LEVEL_usecases_new_matrix_test(array_number_t dum) {
	array_number_t array141 = (array_number_t)malloc(sizeof(int) * 2);
	array141->length=3;
	array141->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array141->arr[0] = 0;
	array141->arr[1] = 0;
	array141->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array141;;
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
	array_number_t array142 = (array_number_t)malloc(sizeof(int) * 2);
	array142->length=3;
	array142->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array142->arr[0] = theta->arr[i1];
	array142->arr[1] = theta->arr[(i1) + (1)];
	array142->arr[2] = 0;;
	array_number_t array143 = (array_number_t)malloc(sizeof(int) * 2);
	array143->length=3;
	array143->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array143->arr[0] = theta->arr[(i1) + (2)];
	array143->arr[1] = 0;
	array143->arr[2] = 0;;
	array_number_t array144 = (array_number_t)malloc(sizeof(int) * 2);
	array144->length=3;
	array144->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array144->arr[0] = theta->arr[(i1) + (3)];
	array144->arr[1] = 0;
	array144->arr[2] = 0;;
	array_number_t array145 = (array_number_t)malloc(sizeof(int) * 2);
	array145->length=3;
	array145->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array145->arr[0] = 0;
	array145->arr[1] = 0;
	array145->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array142;
	finger1->arr[1] = array143;
	finger1->arr[2] = array144;
	finger1->arr[3] = array145;;
	index_t i2 = (i1) + (4);
	array_number_t array146 = (array_number_t)malloc(sizeof(int) * 2);
	array146->length=3;
	array146->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array146->arr[0] = theta->arr[i2];
	array146->arr[1] = theta->arr[(i2) + (1)];
	array146->arr[2] = 0;;
	array_number_t array147 = (array_number_t)malloc(sizeof(int) * 2);
	array147->length=3;
	array147->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array147->arr[0] = theta->arr[(i2) + (2)];
	array147->arr[1] = 0;
	array147->arr[2] = 0;;
	array_number_t array148 = (array_number_t)malloc(sizeof(int) * 2);
	array148->length=3;
	array148->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array148->arr[0] = theta->arr[(i2) + (3)];
	array148->arr[1] = 0;
	array148->arr[2] = 0;;
	array_number_t array149 = (array_number_t)malloc(sizeof(int) * 2);
	array149->length=3;
	array149->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array149->arr[0] = 0;
	array149->arr[1] = 0;
	array149->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array146;
	finger2->arr[1] = array147;
	finger2->arr[2] = array148;
	finger2->arr[3] = array149;;
	index_t i3 = (i2) + (4);
	array_number_t array150 = (array_number_t)malloc(sizeof(int) * 2);
	array150->length=3;
	array150->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array150->arr[0] = theta->arr[i3];
	array150->arr[1] = theta->arr[(i3) + (1)];
	array150->arr[2] = 0;;
	array_number_t array151 = (array_number_t)malloc(sizeof(int) * 2);
	array151->length=3;
	array151->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array151->arr[0] = theta->arr[(i3) + (2)];
	array151->arr[1] = 0;
	array151->arr[2] = 0;;
	array_number_t array152 = (array_number_t)malloc(sizeof(int) * 2);
	array152->length=3;
	array152->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array152->arr[0] = theta->arr[(i3) + (3)];
	array152->arr[1] = 0;
	array152->arr[2] = 0;;
	array_number_t array153 = (array_number_t)malloc(sizeof(int) * 2);
	array153->length=3;
	array153->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array153->arr[0] = 0;
	array153->arr[1] = 0;
	array153->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array150;
	finger3->arr[1] = array151;
	finger3->arr[2] = array152;
	finger3->arr[3] = array153;;
	index_t i4 = (i3) + (4);
	array_number_t array154 = (array_number_t)malloc(sizeof(int) * 2);
	array154->length=3;
	array154->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array154->arr[0] = theta->arr[i4];
	array154->arr[1] = theta->arr[(i4) + (1)];
	array154->arr[2] = 0;;
	array_number_t array155 = (array_number_t)malloc(sizeof(int) * 2);
	array155->length=3;
	array155->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array155->arr[0] = theta->arr[(i4) + (2)];
	array155->arr[1] = 0;
	array155->arr[2] = 0;;
	array_number_t array156 = (array_number_t)malloc(sizeof(int) * 2);
	array156->length=3;
	array156->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array156->arr[0] = theta->arr[(i4) + (3)];
	array156->arr[1] = 0;
	array156->arr[2] = 0;;
	array_number_t array157 = (array_number_t)malloc(sizeof(int) * 2);
	array157->length=3;
	array157->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array157->arr[0] = 0;
	array157->arr[1] = 0;
	array157->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array154;
	finger4->arr[1] = array155;
	finger4->arr[2] = array156;
	finger4->arr[3] = array157;;
	index_t i5 = (i4) + (4);
	array_number_t array158 = (array_number_t)malloc(sizeof(int) * 2);
	array158->length=3;
	array158->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array158->arr[0] = theta->arr[i5];
	array158->arr[1] = theta->arr[(i5) + (1)];
	array158->arr[2] = 0;;
	array_number_t array159 = (array_number_t)malloc(sizeof(int) * 2);
	array159->length=3;
	array159->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array159->arr[0] = theta->arr[(i5) + (2)];
	array159->arr[1] = 0;
	array159->arr[2] = 0;;
	array_number_t array160 = (array_number_t)malloc(sizeof(int) * 2);
	array160->length=3;
	array160->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array160->arr[0] = theta->arr[(i5) + (3)];
	array160->arr[1] = 0;
	array160->arr[2] = 0;;
	array_number_t array161 = (array_number_t)malloc(sizeof(int) * 2);
	array161->length=3;
	array161->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array161->arr[0] = 0;
	array161->arr[1] = 0;
	array161->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array158;
	finger5->arr[1] = array159;
	finger5->arr[2] = array160;
	finger5->arr[3] = array161;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t TOP_LEVEL_usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array162 = (array_number_t)malloc(sizeof(int) * 2);
	array162->length=3;
	array162->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array162->arr[0] = 1;
	array162->arr[1] = 0;
	array162->arr[2] = 0;;
	array_number_t array163 = (array_number_t)malloc(sizeof(int) * 2);
	array163->length=3;
	array163->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array163->arr[0] = 0;
	array163->arr[1] = cos(tx);
	array163->arr[2] = -(sin(tx));;
	array_number_t array164 = (array_number_t)malloc(sizeof(int) * 2);
	array164->length=3;
	array164->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array164->arr[0] = 0;
	array164->arr[1] = sin(tx);
	array164->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array162;
	Rx->arr[1] = array163;
	Rx->arr[2] = array164;;
	array_number_t array165 = (array_number_t)malloc(sizeof(int) * 2);
	array165->length=3;
	array165->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array165->arr[0] = cos(ty);
	array165->arr[1] = 0;
	array165->arr[2] = sin(ty);;
	array_number_t array166 = (array_number_t)malloc(sizeof(int) * 2);
	array166->length=3;
	array166->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array166->arr[0] = 0;
	array166->arr[1] = 1;
	array166->arr[2] = 0;;
	array_number_t array167 = (array_number_t)malloc(sizeof(int) * 2);
	array167->length=3;
	array167->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array167->arr[0] = -(sin(ty));
	array167->arr[1] = 0;
	array167->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array165;
	Ry->arr[1] = array166;
	Ry->arr[2] = array167;;
	array_number_t array168 = (array_number_t)malloc(sizeof(int) * 2);
	array168->length=3;
	array168->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array168->arr[0] = cos(tz);
	array168->arr[1] = -(sin(tz));
	array168->arr[2] = 0;;
	array_number_t array169 = (array_number_t)malloc(sizeof(int) * 2);
	array169->length=3;
	array169->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array169->arr[0] = sin(tz);
	array169->arr[1] = cos(tz);
	array169->arr[2] = 0;;
	array_number_t array170 = (array_number_t)malloc(sizeof(int) * 2);
	array170->length=3;
	array170->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array170->arr[0] = 0;
	array170->arr[1] = 0;
	array170->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array168;
	Rz->arr[1] = array169;
	Rz->arr[2] = array170;;
	return TOP_LEVEL_linalg_matrixMult(Rz, TOP_LEVEL_linalg_matrixMult(Ry, Rx));
}

array_array_number_t TOP_LEVEL_usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = TOP_LEVEL_usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array171 = (array_number_t)malloc(sizeof(int) * 2);
	array171->length=1;
	array171->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array171->arr[0] = 0;;
	array_number_t array172 = (array_number_t)malloc(sizeof(int) * 2);
	array172->length=1;
	array172->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array172->arr[0] = 0;;
	array_number_t array173 = (array_number_t)malloc(sizeof(int) * 2);
	array173->length=1;
	array173->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array173->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array171;
	r1->arr[1] = array172;
	r1->arr[2] = array173;;
	array_number_t array174 = (array_number_t)malloc(sizeof(int) * 2);
	array174->length=4;
	array174->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array174->arr[0] = 0;
	array174->arr[1] = 0;
	array174->arr[2] = 0;
	array174->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array174;;
	array_array_number_t T = matrix_concat(TOP_LEVEL_linalg_matrixConcatCol(R, r1), r2);
	return TOP_LEVEL_linalg_matrixMult(base_relative, T);
}
typedef struct env_t_181 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_181;
env_t_181 make_env_t_181(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_181 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda181(env_t_181* env178, number_t i_bone) {
	array_array_number_t pose_params177 = env178->pose_params;
	index_t offset176 = env178->offset;
	array_array_array_number_t base_relatives175 = env178->base_relatives;
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_usecases_make_relative(pose_params177->arr[((int)(i_bone)) + (offset176)], base_relatives175->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_get_posed_relatives(card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_181 env_t_181_value = make_env_t_181(pose_params,offset,base_relatives); closure_t closure180 = make_closure(lambda181, &env_t_181_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D(closure180, TOP_LEVEL_linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t TOP_LEVEL_usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(TOP_LEVEL_linalg_sqnorm(angle_axis));
	array_array_number_t ite182 = 0;
	if((n) < (0.0001)) {
		array_number_t array184 = (array_number_t)malloc(sizeof(int) * 2);
	array184->length=3;
	array184->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array184->arr[0] = 1;
	array184->arr[1] = 0;
	array184->arr[2] = 0;;
		array_number_t array185 = (array_number_t)malloc(sizeof(int) * 2);
	array185->length=3;
	array185->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array185->arr[0] = 0;
	array185->arr[1] = 1;
	array185->arr[2] = 0;;
		array_number_t array186 = (array_number_t)malloc(sizeof(int) * 2);
	array186->length=3;
	array186->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array186->arr[0] = 0;
	array186->arr[1] = 0;
	array186->arr[2] = 1;;
		array_array_number_t array183 = (array_array_number_t)malloc(sizeof(int) * 2);
	array183->length=3;
	array183->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array183->arr[0] = array184;
	array183->arr[1] = array185;
	array183->arr[2] = array186;;
		ite182 = array183;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array188 = (array_number_t)malloc(sizeof(int) * 2);
	array188->length=3;
	array188->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array188->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array188->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array188->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array189 = (array_number_t)malloc(sizeof(int) * 2);
	array189->length=3;
	array189->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array189->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array189->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array189->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array190 = (array_number_t)malloc(sizeof(int) * 2);
	array190->length=3;
	array190->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array190->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array190->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array190->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array187 = (array_array_number_t)malloc(sizeof(int) * 2);
	array187->length=3;
	array187->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array187->arr[0] = array188;
	array187->arr[1] = array189;
	array187->arr[2] = array190;;
		ite182 = array187;
	}
	return ite182;
}
typedef struct env_t_200 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_200;
env_t_200 make_env_t_200(array_array_array_number_t relatives,array_number_t parents) {
	env_t_200 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda200(env_t_200* env193, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives192 = env193->relatives;
	array_number_t parents191 = env193->parents;
	array_array_array_number_t ite199 = 0;
	if((parents191->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives192->arr[i];;
		ite199 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = TOP_LEVEL_linalg_matrixMult(acc->arr[(int)(parents191->arr[i])], relatives192->arr[i]);;
		ite199 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite199;
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array198 = (array_number_t)malloc(sizeof(int) * 2);
	array198->length=0;
	array198->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array197 = (array_array_number_t)malloc(sizeof(int) * 2);
	array197->length=1;
	array197->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array197->arr[0] = array198;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array197;;
	env_t_200 env_t_200_value = make_env_t_200(relatives,parents); closure_t closure195 = make_closure(lambda200, &env_t_200_value);
	card_t macroDef196 = relatives->length;
	return TOP_LEVEL_linalg_iterateMatrix3D(closure195, init, 0, (macroDef196) - (1));
}
typedef struct env_t_211 {
	array_number_t scale;
} env_t_211;
env_t_211 make_env_t_211(array_number_t scale) {
	env_t_211 env;
	env.scale = scale;
	return env;
}

value_t lambda211(env_t_211* env202, array_number_t row) {
	array_number_t scale201 = env202->scale;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(row, scale201);
	return res;
}
typedef empty_env_t env_t_212;


value_t lambda212(env_t_212* env205, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = TOP_LEVEL_usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_211 env_t_211_value = make_env_t_211(scale); closure_t closure204 = make_closure(lambda211, &env_t_211_value);
	array_array_number_t R1 = TOP_LEVEL_linalg_matrixMap(closure204, R);
	array_array_number_t array209 = (array_array_number_t)malloc(sizeof(int) * 2);
	array209->length=1;
	array209->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array209->arr[0] = pose_params->arr[2];;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcatCol(R1, TOP_LEVEL_linalg_matrixTranspose(array209));
	env_t_212 env_t_212_value = make_empty_env(); closure_t closure207 = make_closure(lambda212, &env_t_212_value);
	card_t macroDef208 = positions->arr[0]->length;
	array_number_t ones = TOP_LEVEL_linalg_vectorMap(closure207, TOP_LEVEL_linalg_vectorRange(1, macroDef208));
	array_array_number_t array210 = (array_array_number_t)malloc(sizeof(int) * 2);
	array210->length=1;
	array210->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array210->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array210);
	return TOP_LEVEL_linalg_matrixMult(T, positions_homog);
}
typedef empty_env_t env_t_228;


value_t lambda228(env_t_228* env213, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult(m1, m2);
	return res;
}
typedef struct env_t_229 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_229;
env_t_229 make_env_t_229(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_229 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda229(env_t_229* env221, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights220 = env221->weights;
	array_array_array_number_t transforms219 = env221->transforms;
	array_array_number_t base_positions218 = env221->base_positions;
	array_array_number_t curr_positions = TOP_LEVEL_linalg_matrixMult(matrix_slice(transforms219->arr[i_transform], 0, 2), base_positions218);
	card_t macroDef217 = base_positions218->length;
	array_array_number_t w = TOP_LEVEL_linalg_matrixFillFromVector(macroDef217, weights220->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixAdd(acc, TOP_LEVEL_linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t TOP_LEVEL_usecases_get_skinned_vertex_positions(index_t is_mirrored, card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = TOP_LEVEL_usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = TOP_LEVEL_usecases_relatives_to_absolutes(relatives, parents);
	env_t_228 env_t_228_value = make_empty_env(); closure_t closure215 = make_closure(lambda228, &env_t_228_value);
	array_array_array_number_t transforms = TOP_LEVEL_linalg_matrix3DMap2(closure215, absolutes, inverse_base_absolutes);
	card_t macroDef216 = base_positions->arr[0]->length;
	card_t n_verts = macroDef216;
	array_array_number_t init_positions = TOP_LEVEL_linalg_matrixFill(3, n_verts, 0);
	env_t_229 env_t_229_value = make_env_t_229(weights,transforms,base_positions); closure_t closure223 = make_closure(lambda229, &env_t_229_value);
	card_t macroDef224 = transforms->length;
	array_array_number_t positions = TOP_LEVEL_linalg_iterateMatrix(closure223, init_positions, 0, (macroDef224) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array225 = (array_number_t)malloc(sizeof(int) * 2);
	array225->length=3;
	array225->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array225->arr[0] = -1;
	array225->arr[1] = 0;
	array225->arr[2] = 0;;
		array_number_t array226 = (array_number_t)malloc(sizeof(int) * 2);
	array226->length=3;
	array226->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array226->arr[0] = 0;
	array226->arr[1] = 1;
	array226->arr[2] = 0;;
		array_number_t array227 = (array_number_t)malloc(sizeof(int) * 2);
	array227->length=3;
	array227->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array227->arr[0] = 0;
	array227->arr[1] = 0;
	array227->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array225;
	mirror_matrix->arr[1] = array226;
	mirror_matrix->arr[2] = array227;;
		mirrored_positions = TOP_LEVEL_linalg_matrixMult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return TOP_LEVEL_usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_237 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_237;
env_t_237 make_env_t_237(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_237 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda237(env_t_237* env234, number_t i) {
	array_array_number_t vertex_positions233 = env234->vertex_positions;
	array_array_number_t points232 = env234->points;
	index_t n_corr231 = env234->n_corr;
	array_number_t correspondences230 = env234->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr231);
	index_t c = (ind) % (n_corr231);
	value_t res;
	res.number_t_value = (points232->arr[r]->arr[c]) - (vertex_positions233->arr[r]->arr[(int)(correspondences230->arr[c])]);
	return res;
}
array_number_t TOP_LEVEL_usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, card_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = TOP_LEVEL_usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = TOP_LEVEL_usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_237 env_t_237_value = make_env_t_237(vertex_positions,points,n_corr,correspondences); closure_t closure236 = make_closure(lambda237, &env_t_237_value);
	array_number_t err = TOP_LEVEL_linalg_vectorMap(closure236, TOP_LEVEL_linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_265;


value_t lambda265(env_t_265* env238, number_t r) {
	
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
	array_number_t array254 = (array_number_t)malloc(sizeof(int) * 2);
	array254->length=3;
	array254->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array254->arr[0] = 1;
	array254->arr[1] = 2;
	array254->arr[2] = 3;;
	array_number_t array255 = (array_number_t)malloc(sizeof(int) * 2);
	array255->length=3;
	array255->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array255->arr[0] = 4;
	array255->arr[1] = 5;
	array255->arr[2] = 6;;
	array_number_t array256 = (array_number_t)malloc(sizeof(int) * 2);
	array256->length=3;
	array256->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array256->arr[0] = 7;
	array256->arr[1] = 8;
	array256->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array254;
	mat1->arr[1] = array255;
	mat1->arr[2] = array256;;
	array_array_number_t n = TOP_LEVEL_linalg_matrixMult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = TOP_LEVEL_linalg_matrixTranspose(n);
	matrix_print(o);
	array_array_number_t p = TOP_LEVEL_linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	env_t_265 env_t_265_value = make_empty_env(); closure_t closure240 = make_closure(lambda265, &env_t_265_value);
	array_array_number_t base_rel = TOP_LEVEL_linalg_vectorMapToMatrix(closure240, TOP_LEVEL_linalg_vectorRange(1, 4));
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
