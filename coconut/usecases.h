#ifndef __USECASES_H__ 
#define __USECASES_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

array_number_t usecases_radial_distort(array_number_t rad_params, array_number_t proj) {
	number_t rsq = linalg_sqnorm(proj);
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	return linalg_mult_by_scalar(proj, L);
}

array_number_t usecases_rodrigues_rotate_point(array_number_t rot, array_number_t x) {
	number_t sqtheta = linalg_sqnorm(rot);
	array_number_t ite141 = 0;
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
		ite141 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite141 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite141;
}

array_number_t usecases_project(array_number_t cam, array_number_t x) {
	index_t N_CAM_PARAMS = 11;
	index_t ROT_IDX = 0;
	index_t CENTER_IDX = 3;
	index_t FOCAL_IDX = 6;
	index_t X0_IDX = 7;
	index_t RAD_IDX = 9;
	array_number_t Xcam = usecases_rodrigues_rotate_point(array_slice(cam, ROT_IDX, (ROT_IDX) + (2)), linalg_sub_vec(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2))));
	array_number_t distorted = usecases_radial_distort(array_slice(cam, RAD_IDX, (RAD_IDX) + (1)), linalg_mult_by_scalar(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2])));
	return linalg_add_vec(array_slice(cam, X0_IDX, (X0_IDX) + (1)), linalg_mult_by_scalar(distorted, cam->arr[FOCAL_IDX]));
}

array_number_t usecases_compute_reproj_err(array_number_t cam, array_number_t x, number_t w, array_number_t feat) {
	
	return linalg_mult_by_scalar(linalg_sub_vec(usecases_project(cam, x), feat), w);
}

number_t usecases_compute_zach_weight_error(number_t w) {
	
	return (1) - ((w) * (w));
}
typedef empty_env_t env_t_145;


value_t lambda145(env_t_145* env142, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	env_t_145 env_t_145_value = make_empty_env(); closure_t closure144 = make_closure(lambda145, &env_t_145_value);
	return linalg_vectorMap(closure144, w);
}
typedef struct env_t_154 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_154;
env_t_154 make_env_t_154(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_154 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda154(env_t_154* env151, number_t i) {
	array_array_number_t x150 = env151->x;
	array_number_t w149 = env151->w;
	array_array_number_t obs148 = env151->obs;
	array_array_number_t feat147 = env151->feat;
	array_array_number_t cams146 = env151->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams146->arr[(int)(obs148->arr[(int)(i)]->arr[0])], x150->arr[(int)(obs148->arr[(int)(i)]->arr[1])], w149->arr[(int)(i)], feat147->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	env_t_154 env_t_154_value = make_env_t_154(x,w,obs,feat,cams); closure_t closure153 = make_closure(lambda154, &env_t_154_value);
	return linalg_vectorMapToMatrix(closure153, range);
}
typedef struct env_t_178 {
	array_number_t one_cam;
} env_t_178;
env_t_178 make_env_t_178(array_number_t one_cam) {
	env_t_178 env;
	env.one_cam = one_cam;
	return env;
}

value_t lambda178(env_t_178* env156, number_t x) {
	array_number_t one_cam155 = env156->one_cam;
	value_t res;
	res.array_number_t_value = one_cam155;
	return res;
}
typedef struct env_t_179 {
	array_number_t one_x;
} env_t_179;
env_t_179 make_env_t_179(array_number_t one_x) {
	env_t_179 env;
	env.one_x = one_x;
	return env;
}

value_t lambda179(env_t_179* env160, number_t x) {
	array_number_t one_x159 = env160->one_x;
	value_t res;
	res.array_number_t_value = one_x159;
	return res;
}
typedef struct env_t_180 {
	number_t one_w;
} env_t_180;
env_t_180 make_env_t_180(number_t one_w) {
	env_t_180 env;
	env.one_w = one_w;
	return env;
}

value_t lambda180(env_t_180* env164, number_t x) {
	number_t one_w163 = env164->one_w;
	value_t res;
	res.number_t_value = one_w163;
	return res;
}
typedef struct env_t_181 {
	array_number_t one_feat;
} env_t_181;
env_t_181 make_env_t_181(array_number_t one_feat) {
	env_t_181 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda181(env_t_181* env168, number_t x) {
	array_number_t one_feat167 = env168->one_feat;
	value_t res;
	res.array_number_t_value = one_feat167;
	return res;
}
typedef struct env_t_182 {
	index_t n;
	index_t m;
} env_t_182;
env_t_182 make_env_t_182(index_t n,index_t m) {
	env_t_182 env;
	env.n = n;
	env.m = m;
	return env;
}

value_t lambda182(env_t_182* env173, number_t x) {
	index_t n172 = env173->n;
	index_t m171 = env173->m;
	array_number_t array176 = (array_number_t)malloc(sizeof(int) * 2);
	array176->length=2;
	array176->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array176->arr[0] = (double)(((int)(x)) % (n172));
	array176->arr[1] = (double)(((int)(x)) % (m171));;
	value_t res;
	res.array_number_t_value = array176;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	env_t_178 env_t_178_value = make_env_t_178(one_cam); closure_t closure158 = make_closure(lambda178, &env_t_178_value);
	array_array_number_t cam = linalg_vectorMapToMatrix(closure158, linalg_vectorRange(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	env_t_179 env_t_179_value = make_env_t_179(one_x); closure_t closure162 = make_closure(lambda179, &env_t_179_value);
	array_array_number_t x = linalg_vectorMapToMatrix(closure162, linalg_vectorRange(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	env_t_180 env_t_180_value = make_env_t_180(one_w); closure_t closure166 = make_closure(lambda180, &env_t_180_value);
	array_number_t w = linalg_vectorMap(closure166, linalg_vectorRange(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	env_t_181 env_t_181_value = make_env_t_181(one_feat); closure_t closure170 = make_closure(lambda181, &env_t_181_value);
	array_array_number_t feat = linalg_vectorMapToMatrix(closure170, linalg_vectorRange(1, p));
	env_t_182 env_t_182_value = make_env_t_182(n,m); closure_t closure175 = make_closure(lambda182, &env_t_182_value);
	array_array_number_t obs = linalg_vectorMapToMatrix(closure175, linalg_vectorRange(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_187 {
	number_t mx;
} env_t_187;
env_t_187 make_env_t_187(number_t mx) {
	env_t_187 env;
	env.mx = mx;
	return env;
}

value_t lambda187(env_t_187* env184, number_t x) {
	number_t mx183 = env184->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx183));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = linalg_arrayMax(arr);
	env_t_187 env_t_187_value = make_env_t_187(mx); closure_t closure186 = make_closure(lambda187, &env_t_187_value);
	number_t semx = linalg_arraySum(linalg_vectorMap(closure186, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_192 {
	number_t a;
} env_t_192;
env_t_192 make_env_t_192(number_t a) {
	env_t_192 env;
	env.a = a;
	return env;
}

value_t lambda192(env_t_192* env189, number_t j) {
	number_t a188 = env189->a;
	value_t res;
	res.number_t_value = gamma_ln((a188) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	env_t_192 env_t_192_value = make_env_t_192(a); closure_t closure191 = make_closure(lambda192, &env_t_192_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (linalg_arraySum(linalg_vectorMap(closure191, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array193 = (array_number_t)malloc(sizeof(int) * 2);
	array193->length=3;
	array193->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array193->arr[0] = 0;
	array193->arr[1] = 0;
	array193->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array193;;
	return res;
}

array_array_number_t usecases_to_pose_params(array_number_t theta, index_t n_bones) {
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
	array_number_t array194 = (array_number_t)malloc(sizeof(int) * 2);
	array194->length=3;
	array194->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array194->arr[0] = theta->arr[i1];
	array194->arr[1] = theta->arr[(i1) + (1)];
	array194->arr[2] = 0;;
	array_number_t array195 = (array_number_t)malloc(sizeof(int) * 2);
	array195->length=3;
	array195->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array195->arr[0] = theta->arr[(i1) + (2)];
	array195->arr[1] = 0;
	array195->arr[2] = 0;;
	array_number_t array196 = (array_number_t)malloc(sizeof(int) * 2);
	array196->length=3;
	array196->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array196->arr[0] = theta->arr[(i1) + (3)];
	array196->arr[1] = 0;
	array196->arr[2] = 0;;
	array_number_t array197 = (array_number_t)malloc(sizeof(int) * 2);
	array197->length=3;
	array197->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array197->arr[0] = 0;
	array197->arr[1] = 0;
	array197->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array194;
	finger1->arr[1] = array195;
	finger1->arr[2] = array196;
	finger1->arr[3] = array197;;
	index_t i2 = (i1) + (4);
	array_number_t array198 = (array_number_t)malloc(sizeof(int) * 2);
	array198->length=3;
	array198->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array198->arr[0] = theta->arr[i2];
	array198->arr[1] = theta->arr[(i2) + (1)];
	array198->arr[2] = 0;;
	array_number_t array199 = (array_number_t)malloc(sizeof(int) * 2);
	array199->length=3;
	array199->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array199->arr[0] = theta->arr[(i2) + (2)];
	array199->arr[1] = 0;
	array199->arr[2] = 0;;
	array_number_t array200 = (array_number_t)malloc(sizeof(int) * 2);
	array200->length=3;
	array200->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array200->arr[0] = theta->arr[(i2) + (3)];
	array200->arr[1] = 0;
	array200->arr[2] = 0;;
	array_number_t array201 = (array_number_t)malloc(sizeof(int) * 2);
	array201->length=3;
	array201->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array201->arr[0] = 0;
	array201->arr[1] = 0;
	array201->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array198;
	finger2->arr[1] = array199;
	finger2->arr[2] = array200;
	finger2->arr[3] = array201;;
	index_t i3 = (i2) + (4);
	array_number_t array202 = (array_number_t)malloc(sizeof(int) * 2);
	array202->length=3;
	array202->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array202->arr[0] = theta->arr[i3];
	array202->arr[1] = theta->arr[(i3) + (1)];
	array202->arr[2] = 0;;
	array_number_t array203 = (array_number_t)malloc(sizeof(int) * 2);
	array203->length=3;
	array203->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array203->arr[0] = theta->arr[(i3) + (2)];
	array203->arr[1] = 0;
	array203->arr[2] = 0;;
	array_number_t array204 = (array_number_t)malloc(sizeof(int) * 2);
	array204->length=3;
	array204->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array204->arr[0] = theta->arr[(i3) + (3)];
	array204->arr[1] = 0;
	array204->arr[2] = 0;;
	array_number_t array205 = (array_number_t)malloc(sizeof(int) * 2);
	array205->length=3;
	array205->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array205->arr[0] = 0;
	array205->arr[1] = 0;
	array205->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array202;
	finger3->arr[1] = array203;
	finger3->arr[2] = array204;
	finger3->arr[3] = array205;;
	index_t i4 = (i3) + (4);
	array_number_t array206 = (array_number_t)malloc(sizeof(int) * 2);
	array206->length=3;
	array206->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array206->arr[0] = theta->arr[i4];
	array206->arr[1] = theta->arr[(i4) + (1)];
	array206->arr[2] = 0;;
	array_number_t array207 = (array_number_t)malloc(sizeof(int) * 2);
	array207->length=3;
	array207->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array207->arr[0] = theta->arr[(i4) + (2)];
	array207->arr[1] = 0;
	array207->arr[2] = 0;;
	array_number_t array208 = (array_number_t)malloc(sizeof(int) * 2);
	array208->length=3;
	array208->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array208->arr[0] = theta->arr[(i4) + (3)];
	array208->arr[1] = 0;
	array208->arr[2] = 0;;
	array_number_t array209 = (array_number_t)malloc(sizeof(int) * 2);
	array209->length=3;
	array209->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array209->arr[0] = 0;
	array209->arr[1] = 0;
	array209->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array206;
	finger4->arr[1] = array207;
	finger4->arr[2] = array208;
	finger4->arr[3] = array209;;
	index_t i5 = (i4) + (4);
	array_number_t array210 = (array_number_t)malloc(sizeof(int) * 2);
	array210->length=3;
	array210->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array210->arr[0] = theta->arr[i5];
	array210->arr[1] = theta->arr[(i5) + (1)];
	array210->arr[2] = 0;;
	array_number_t array211 = (array_number_t)malloc(sizeof(int) * 2);
	array211->length=3;
	array211->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array211->arr[0] = theta->arr[(i5) + (2)];
	array211->arr[1] = 0;
	array211->arr[2] = 0;;
	array_number_t array212 = (array_number_t)malloc(sizeof(int) * 2);
	array212->length=3;
	array212->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array212->arr[0] = theta->arr[(i5) + (3)];
	array212->arr[1] = 0;
	array212->arr[2] = 0;;
	array_number_t array213 = (array_number_t)malloc(sizeof(int) * 2);
	array213->length=3;
	array213->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array213->arr[0] = 0;
	array213->arr[1] = 0;
	array213->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array210;
	finger5->arr[1] = array211;
	finger5->arr[2] = array212;
	finger5->arr[3] = array213;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array214 = (array_number_t)malloc(sizeof(int) * 2);
	array214->length=3;
	array214->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array214->arr[0] = 1;
	array214->arr[1] = 0;
	array214->arr[2] = 0;;
	array_number_t array215 = (array_number_t)malloc(sizeof(int) * 2);
	array215->length=3;
	array215->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array215->arr[0] = 0;
	array215->arr[1] = cos(tx);
	array215->arr[2] = -(sin(tx));;
	array_number_t array216 = (array_number_t)malloc(sizeof(int) * 2);
	array216->length=3;
	array216->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array216->arr[0] = 0;
	array216->arr[1] = sin(tx);
	array216->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array214;
	Rx->arr[1] = array215;
	Rx->arr[2] = array216;;
	array_number_t array217 = (array_number_t)malloc(sizeof(int) * 2);
	array217->length=3;
	array217->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array217->arr[0] = cos(ty);
	array217->arr[1] = 0;
	array217->arr[2] = sin(ty);;
	array_number_t array218 = (array_number_t)malloc(sizeof(int) * 2);
	array218->length=3;
	array218->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array218->arr[0] = 0;
	array218->arr[1] = 1;
	array218->arr[2] = 0;;
	array_number_t array219 = (array_number_t)malloc(sizeof(int) * 2);
	array219->length=3;
	array219->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array219->arr[0] = -(sin(ty));
	array219->arr[1] = 0;
	array219->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array217;
	Ry->arr[1] = array218;
	Ry->arr[2] = array219;;
	array_number_t array220 = (array_number_t)malloc(sizeof(int) * 2);
	array220->length=3;
	array220->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array220->arr[0] = cos(tz);
	array220->arr[1] = -(sin(tz));
	array220->arr[2] = 0;;
	array_number_t array221 = (array_number_t)malloc(sizeof(int) * 2);
	array221->length=3;
	array221->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array221->arr[0] = sin(tz);
	array221->arr[1] = cos(tz);
	array221->arr[2] = 0;;
	array_number_t array222 = (array_number_t)malloc(sizeof(int) * 2);
	array222->length=3;
	array222->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array222->arr[0] = 0;
	array222->arr[1] = 0;
	array222->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array220;
	Rz->arr[1] = array221;
	Rz->arr[2] = array222;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array223 = (array_number_t)malloc(sizeof(int) * 2);
	array223->length=1;
	array223->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array223->arr[0] = 0;;
	array_number_t array224 = (array_number_t)malloc(sizeof(int) * 2);
	array224->length=1;
	array224->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array224->arr[0] = 0;;
	array_number_t array225 = (array_number_t)malloc(sizeof(int) * 2);
	array225->length=1;
	array225->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array225->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array223;
	r1->arr[1] = array224;
	r1->arr[2] = array225;;
	array_number_t array226 = (array_number_t)malloc(sizeof(int) * 2);
	array226->length=4;
	array226->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array226->arr[0] = 0;
	array226->arr[1] = 0;
	array226->arr[2] = 0;
	array226->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array226;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_233 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_233;
env_t_233 make_env_t_233(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_233 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda233(env_t_233* env230, number_t i_bone) {
	array_array_number_t pose_params229 = env230->pose_params;
	index_t offset228 = env230->offset;
	array_array_array_number_t base_relatives227 = env230->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params229->arr[((int)(i_bone)) + (offset228)], base_relatives227->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_233 env_t_233_value = make_env_t_233(pose_params,offset,base_relatives); closure_t closure232 = make_closure(lambda233, &env_t_233_value);
	return linalg_vectorMapToMatrix3D(closure232, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite234 = 0;
	if((n) < (0.0001)) {
		array_number_t array236 = (array_number_t)malloc(sizeof(int) * 2);
	array236->length=3;
	array236->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array236->arr[0] = 1;
	array236->arr[1] = 0;
	array236->arr[2] = 0;;
		array_number_t array237 = (array_number_t)malloc(sizeof(int) * 2);
	array237->length=3;
	array237->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array237->arr[0] = 0;
	array237->arr[1] = 1;
	array237->arr[2] = 0;;
		array_number_t array238 = (array_number_t)malloc(sizeof(int) * 2);
	array238->length=3;
	array238->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array238->arr[0] = 0;
	array238->arr[1] = 0;
	array238->arr[2] = 1;;
		array_array_number_t array235 = (array_array_number_t)malloc(sizeof(int) * 2);
	array235->length=3;
	array235->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array235->arr[0] = array236;
	array235->arr[1] = array237;
	array235->arr[2] = array238;;
		ite234 = array235;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array240 = (array_number_t)malloc(sizeof(int) * 2);
	array240->length=3;
	array240->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array240->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array240->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array240->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array241 = (array_number_t)malloc(sizeof(int) * 2);
	array241->length=3;
	array241->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array241->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array241->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array241->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array242 = (array_number_t)malloc(sizeof(int) * 2);
	array242->length=3;
	array242->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array242->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array242->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array242->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array239 = (array_array_number_t)malloc(sizeof(int) * 2);
	array239->length=3;
	array239->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array239->arr[0] = array240;
	array239->arr[1] = array241;
	array239->arr[2] = array242;;
		ite234 = array239;
	}
	return ite234;
}
typedef struct env_t_251 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_251;
env_t_251 make_env_t_251(array_array_array_number_t relatives,array_number_t parents) {
	env_t_251 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda251(env_t_251* env245, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives244 = env245->relatives;
	array_number_t parents243 = env245->parents;
	array_array_array_number_t ite250 = 0;
	if((parents243->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives244->arr[i];;
		ite250 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents243->arr[i])], relatives244->arr[i]);;
		ite250 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite250;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array249 = (array_number_t)malloc(sizeof(int) * 2);
	array249->length=0;
	array249->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array248 = (array_array_number_t)malloc(sizeof(int) * 2);
	array248->length=1;
	array248->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array248->arr[0] = array249;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array248;;
	env_t_251 env_t_251_value = make_env_t_251(relatives,parents); closure_t closure247 = make_closure(lambda251, &env_t_251_value);
	return linalg_iterateMatrix3D(closure247, init, 0, (relatives->length) - (1));
}
typedef struct env_t_261 {
	array_number_t scale;
} env_t_261;
env_t_261 make_env_t_261(array_number_t scale) {
	env_t_261 env;
	env.scale = scale;
	return env;
}

value_t lambda261(env_t_261* env253, array_number_t row) {
	array_number_t scale252 = env253->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale252);
	return res;
}
typedef empty_env_t env_t_262;


value_t lambda262(env_t_262* env256, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_261 env_t_261_value = make_env_t_261(scale); closure_t closure255 = make_closure(lambda261, &env_t_261_value);
	array_array_number_t R1 = linalg_matrixMap(closure255, R);
	array_array_number_t array259 = (array_array_number_t)malloc(sizeof(int) * 2);
	array259->length=1;
	array259->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array259->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array259));
	env_t_262 env_t_262_value = make_empty_env(); closure_t closure258 = make_closure(lambda262, &env_t_262_value);
	array_number_t ones = linalg_vectorMap(closure258, linalg_vectorRange(1, positions->arr[0]->length));
	array_array_number_t array260 = (array_array_number_t)malloc(sizeof(int) * 2);
	array260->length=1;
	array260->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array260->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array260);
	return matrix_mult(T, positions_homog);
}
typedef empty_env_t env_t_275;


value_t lambda275(env_t_275* env263, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_276 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_276;
env_t_276 make_env_t_276(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_276 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda276(env_t_276* env269, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights268 = env269->weights;
	array_array_array_number_t transforms267 = env269->transforms;
	array_array_number_t base_positions266 = env269->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms267->arr[i_transform], 0, 2), base_positions266);
	array_array_number_t w = linalg_matrixFillFromVector(base_positions266->length, weights268->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	env_t_275 env_t_275_value = make_empty_env(); closure_t closure265 = make_closure(lambda275, &env_t_275_value);
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure265, absolutes, inverse_base_absolutes);
	index_t n_verts = base_positions->arr[0]->length;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	env_t_276 env_t_276_value = make_env_t_276(weights,transforms,base_positions); closure_t closure271 = make_closure(lambda276, &env_t_276_value);
	array_array_number_t positions = linalg_iterateMatrix(closure271, init_positions, 0, (transforms->length) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array272 = (array_number_t)malloc(sizeof(int) * 2);
	array272->length=3;
	array272->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array272->arr[0] = -1;
	array272->arr[1] = 0;
	array272->arr[2] = 0;;
		array_number_t array273 = (array_number_t)malloc(sizeof(int) * 2);
	array273->length=3;
	array273->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array273->arr[0] = 0;
	array273->arr[1] = 1;
	array273->arr[2] = 0;;
		array_number_t array274 = (array_number_t)malloc(sizeof(int) * 2);
	array274->length=3;
	array274->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array274->arr[0] = 0;
	array274->arr[1] = 0;
	array274->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array272;
	mirror_matrix->arr[1] = array273;
	mirror_matrix->arr[2] = array274;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_284 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_284;
env_t_284 make_env_t_284(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_284 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda284(env_t_284* env281, number_t i) {
	array_array_number_t vertex_positions280 = env281->vertex_positions;
	array_array_number_t points279 = env281->points;
	index_t n_corr278 = env281->n_corr;
	array_number_t correspondences277 = env281->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr278);
	index_t c = (ind) % (n_corr278);
	value_t res;
	res.number_t_value = (points279->arr[r]->arr[c]) - (vertex_positions280->arr[r]->arr[(int)(correspondences277->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, index_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_284 env_t_284_value = make_env_t_284(vertex_positions,points,n_corr,correspondences); closure_t closure283 = make_closure(lambda284, &env_t_284_value);
	array_number_t err = linalg_vectorMap(closure283, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_312;


value_t lambda312(env_t_312* env285, number_t r) {
	
	value_t res;
	res.array_number_t_value = linalg_vectorRange(((int)(r)) * (4), (((int)(r)) * (4)) + (3));
	return res;
}
void usecases_test1(array_number_t dum) {
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
	array_number_t j = usecases_radial_distort(a, b);
	array_print(j);
	array_number_t k = usecases_rodrigues_rotate_point(a, b);
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
	array_number_t m = usecases_project(cam, j);
	array_print(m);
	array_number_t array301 = (array_number_t)malloc(sizeof(int) * 2);
	array301->length=3;
	array301->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array301->arr[0] = 1;
	array301->arr[1] = 2;
	array301->arr[2] = 3;;
	array_number_t array302 = (array_number_t)malloc(sizeof(int) * 2);
	array302->length=3;
	array302->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array302->arr[0] = 4;
	array302->arr[1] = 5;
	array302->arr[2] = 6;;
	array_number_t array303 = (array_number_t)malloc(sizeof(int) * 2);
	array303->length=3;
	array303->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array303->arr[0] = 7;
	array303->arr[1] = 8;
	array303->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array301;
	mat1->arr[1] = array302;
	mat1->arr[2] = array303;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	env_t_312 env_t_312_value = make_empty_env(); closure_t closure287 = make_closure(lambda312, &env_t_312_value);
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure287, linalg_vectorRange(1, 4));
	array_array_number_t q = usecases_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = usecases_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	array_array_number_t s = usecases_apply_global_transform(mat1, mat1);
	matrix_print(s);
	array_array_number_t t = linalg_matrixAdd(mat1, mat1);
	matrix_print(t);
	array_array_number_t u = linalg_matrixFillFromVector(5, a);
	matrix_print(u);
	return ;
}
#endif
