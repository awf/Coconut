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
	array_number_t ite135 = 0;
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
		ite135 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite135 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite135;
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
typedef empty_env_t env_t_139;


value_t lambda139(env_t_139* env136, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	env_t_139 env_t_139_value = make_empty_env(); closure_t closure138 = make_closure(lambda139, &env_t_139_value);
	return linalg_vectorMap(closure138, w);
}
typedef struct env_t_148 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_148;
env_t_148 make_env_t_148(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_148 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda148(env_t_148* env145, number_t i) {
	array_array_number_t x144 = env145->x;
	array_number_t w143 = env145->w;
	array_array_number_t obs142 = env145->obs;
	array_array_number_t feat141 = env145->feat;
	array_array_number_t cams140 = env145->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams140->arr[(int)(obs142->arr[(int)(i)]->arr[0])], x144->arr[(int)(obs142->arr[(int)(i)]->arr[1])], w143->arr[(int)(i)], feat141->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	env_t_148 env_t_148_value = make_env_t_148(x,w,obs,feat,cams); closure_t closure147 = make_closure(lambda148, &env_t_148_value);
	return linalg_vectorMapToMatrix(closure147, range);
}
typedef struct env_t_172 {
	array_number_t one_cam;
} env_t_172;
env_t_172 make_env_t_172(array_number_t one_cam) {
	env_t_172 env;
	env.one_cam = one_cam;
	return env;
}

value_t lambda172(env_t_172* env150, number_t x) {
	array_number_t one_cam149 = env150->one_cam;
	value_t res;
	res.array_number_t_value = one_cam149;
	return res;
}
typedef struct env_t_173 {
	array_number_t one_x;
} env_t_173;
env_t_173 make_env_t_173(array_number_t one_x) {
	env_t_173 env;
	env.one_x = one_x;
	return env;
}

value_t lambda173(env_t_173* env154, number_t x) {
	array_number_t one_x153 = env154->one_x;
	value_t res;
	res.array_number_t_value = one_x153;
	return res;
}
typedef struct env_t_174 {
	number_t one_w;
} env_t_174;
env_t_174 make_env_t_174(number_t one_w) {
	env_t_174 env;
	env.one_w = one_w;
	return env;
}

value_t lambda174(env_t_174* env158, number_t x) {
	number_t one_w157 = env158->one_w;
	value_t res;
	res.number_t_value = one_w157;
	return res;
}
typedef struct env_t_175 {
	array_number_t one_feat;
} env_t_175;
env_t_175 make_env_t_175(array_number_t one_feat) {
	env_t_175 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda175(env_t_175* env162, number_t x) {
	array_number_t one_feat161 = env162->one_feat;
	value_t res;
	res.array_number_t_value = one_feat161;
	return res;
}
typedef struct env_t_176 {
	index_t n;
	index_t m;
} env_t_176;
env_t_176 make_env_t_176(index_t n,index_t m) {
	env_t_176 env;
	env.n = n;
	env.m = m;
	return env;
}

value_t lambda176(env_t_176* env167, number_t x) {
	index_t n166 = env167->n;
	index_t m165 = env167->m;
	array_number_t array170 = (array_number_t)malloc(sizeof(int) * 2);
	array170->length=2;
	array170->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array170->arr[0] = (double)(((int)(x)) % (n166));
	array170->arr[1] = (double)(((int)(x)) % (m165));;
	value_t res;
	res.array_number_t_value = array170;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	env_t_172 env_t_172_value = make_env_t_172(one_cam); closure_t closure152 = make_closure(lambda172, &env_t_172_value);
	array_array_number_t cam = linalg_vectorMapToMatrix(closure152, linalg_vectorRange(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	env_t_173 env_t_173_value = make_env_t_173(one_x); closure_t closure156 = make_closure(lambda173, &env_t_173_value);
	array_array_number_t x = linalg_vectorMapToMatrix(closure156, linalg_vectorRange(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	env_t_174 env_t_174_value = make_env_t_174(one_w); closure_t closure160 = make_closure(lambda174, &env_t_174_value);
	array_number_t w = linalg_vectorMap(closure160, linalg_vectorRange(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	env_t_175 env_t_175_value = make_env_t_175(one_feat); closure_t closure164 = make_closure(lambda175, &env_t_175_value);
	array_array_number_t feat = linalg_vectorMapToMatrix(closure164, linalg_vectorRange(1, p));
	env_t_176 env_t_176_value = make_env_t_176(n,m); closure_t closure169 = make_closure(lambda176, &env_t_176_value);
	array_array_number_t obs = linalg_vectorMapToMatrix(closure169, linalg_vectorRange(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_181 {
	number_t mx;
} env_t_181;
env_t_181 make_env_t_181(number_t mx) {
	env_t_181 env;
	env.mx = mx;
	return env;
}

value_t lambda181(env_t_181* env178, number_t x) {
	number_t mx177 = env178->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx177));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = linalg_arrayMax(arr);
	env_t_181 env_t_181_value = make_env_t_181(mx); closure_t closure180 = make_closure(lambda181, &env_t_181_value);
	number_t semx = linalg_arraySum(linalg_vectorMap(closure180, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_186 {
	number_t a;
} env_t_186;
env_t_186 make_env_t_186(number_t a) {
	env_t_186 env;
	env.a = a;
	return env;
}

value_t lambda186(env_t_186* env183, number_t j) {
	number_t a182 = env183->a;
	value_t res;
	res.number_t_value = gamma_ln((a182) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	env_t_186 env_t_186_value = make_env_t_186(a); closure_t closure185 = make_closure(lambda186, &env_t_186_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (linalg_arraySum(linalg_vectorMap(closure185, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array187 = (array_number_t)malloc(sizeof(int) * 2);
	array187->length=3;
	array187->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array187->arr[0] = 0;
	array187->arr[1] = 0;
	array187->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array187;;
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
	array_number_t array188 = (array_number_t)malloc(sizeof(int) * 2);
	array188->length=3;
	array188->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array188->arr[0] = theta->arr[i1];
	array188->arr[1] = theta->arr[(i1) + (1)];
	array188->arr[2] = 0;;
	array_number_t array189 = (array_number_t)malloc(sizeof(int) * 2);
	array189->length=3;
	array189->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array189->arr[0] = theta->arr[(i1) + (2)];
	array189->arr[1] = 0;
	array189->arr[2] = 0;;
	array_number_t array190 = (array_number_t)malloc(sizeof(int) * 2);
	array190->length=3;
	array190->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array190->arr[0] = theta->arr[(i1) + (3)];
	array190->arr[1] = 0;
	array190->arr[2] = 0;;
	array_number_t array191 = (array_number_t)malloc(sizeof(int) * 2);
	array191->length=3;
	array191->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array191->arr[0] = 0;
	array191->arr[1] = 0;
	array191->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array188;
	finger1->arr[1] = array189;
	finger1->arr[2] = array190;
	finger1->arr[3] = array191;;
	index_t i2 = (i1) + (4);
	array_number_t array192 = (array_number_t)malloc(sizeof(int) * 2);
	array192->length=3;
	array192->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array192->arr[0] = theta->arr[i2];
	array192->arr[1] = theta->arr[(i2) + (1)];
	array192->arr[2] = 0;;
	array_number_t array193 = (array_number_t)malloc(sizeof(int) * 2);
	array193->length=3;
	array193->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array193->arr[0] = theta->arr[(i2) + (2)];
	array193->arr[1] = 0;
	array193->arr[2] = 0;;
	array_number_t array194 = (array_number_t)malloc(sizeof(int) * 2);
	array194->length=3;
	array194->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array194->arr[0] = theta->arr[(i2) + (3)];
	array194->arr[1] = 0;
	array194->arr[2] = 0;;
	array_number_t array195 = (array_number_t)malloc(sizeof(int) * 2);
	array195->length=3;
	array195->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array195->arr[0] = 0;
	array195->arr[1] = 0;
	array195->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array192;
	finger2->arr[1] = array193;
	finger2->arr[2] = array194;
	finger2->arr[3] = array195;;
	index_t i3 = (i2) + (4);
	array_number_t array196 = (array_number_t)malloc(sizeof(int) * 2);
	array196->length=3;
	array196->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array196->arr[0] = theta->arr[i3];
	array196->arr[1] = theta->arr[(i3) + (1)];
	array196->arr[2] = 0;;
	array_number_t array197 = (array_number_t)malloc(sizeof(int) * 2);
	array197->length=3;
	array197->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array197->arr[0] = theta->arr[(i3) + (2)];
	array197->arr[1] = 0;
	array197->arr[2] = 0;;
	array_number_t array198 = (array_number_t)malloc(sizeof(int) * 2);
	array198->length=3;
	array198->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array198->arr[0] = theta->arr[(i3) + (3)];
	array198->arr[1] = 0;
	array198->arr[2] = 0;;
	array_number_t array199 = (array_number_t)malloc(sizeof(int) * 2);
	array199->length=3;
	array199->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array199->arr[0] = 0;
	array199->arr[1] = 0;
	array199->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array196;
	finger3->arr[1] = array197;
	finger3->arr[2] = array198;
	finger3->arr[3] = array199;;
	index_t i4 = (i3) + (4);
	array_number_t array200 = (array_number_t)malloc(sizeof(int) * 2);
	array200->length=3;
	array200->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array200->arr[0] = theta->arr[i4];
	array200->arr[1] = theta->arr[(i4) + (1)];
	array200->arr[2] = 0;;
	array_number_t array201 = (array_number_t)malloc(sizeof(int) * 2);
	array201->length=3;
	array201->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array201->arr[0] = theta->arr[(i4) + (2)];
	array201->arr[1] = 0;
	array201->arr[2] = 0;;
	array_number_t array202 = (array_number_t)malloc(sizeof(int) * 2);
	array202->length=3;
	array202->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array202->arr[0] = theta->arr[(i4) + (3)];
	array202->arr[1] = 0;
	array202->arr[2] = 0;;
	array_number_t array203 = (array_number_t)malloc(sizeof(int) * 2);
	array203->length=3;
	array203->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array203->arr[0] = 0;
	array203->arr[1] = 0;
	array203->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array200;
	finger4->arr[1] = array201;
	finger4->arr[2] = array202;
	finger4->arr[3] = array203;;
	index_t i5 = (i4) + (4);
	array_number_t array204 = (array_number_t)malloc(sizeof(int) * 2);
	array204->length=3;
	array204->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array204->arr[0] = theta->arr[i5];
	array204->arr[1] = theta->arr[(i5) + (1)];
	array204->arr[2] = 0;;
	array_number_t array205 = (array_number_t)malloc(sizeof(int) * 2);
	array205->length=3;
	array205->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array205->arr[0] = theta->arr[(i5) + (2)];
	array205->arr[1] = 0;
	array205->arr[2] = 0;;
	array_number_t array206 = (array_number_t)malloc(sizeof(int) * 2);
	array206->length=3;
	array206->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array206->arr[0] = theta->arr[(i5) + (3)];
	array206->arr[1] = 0;
	array206->arr[2] = 0;;
	array_number_t array207 = (array_number_t)malloc(sizeof(int) * 2);
	array207->length=3;
	array207->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array207->arr[0] = 0;
	array207->arr[1] = 0;
	array207->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array204;
	finger5->arr[1] = array205;
	finger5->arr[2] = array206;
	finger5->arr[3] = array207;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array208 = (array_number_t)malloc(sizeof(int) * 2);
	array208->length=3;
	array208->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array208->arr[0] = 1;
	array208->arr[1] = 0;
	array208->arr[2] = 0;;
	array_number_t array209 = (array_number_t)malloc(sizeof(int) * 2);
	array209->length=3;
	array209->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array209->arr[0] = 0;
	array209->arr[1] = cos(tx);
	array209->arr[2] = -(sin(tx));;
	array_number_t array210 = (array_number_t)malloc(sizeof(int) * 2);
	array210->length=3;
	array210->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array210->arr[0] = 0;
	array210->arr[1] = sin(tx);
	array210->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array208;
	Rx->arr[1] = array209;
	Rx->arr[2] = array210;;
	array_number_t array211 = (array_number_t)malloc(sizeof(int) * 2);
	array211->length=3;
	array211->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array211->arr[0] = cos(ty);
	array211->arr[1] = 0;
	array211->arr[2] = sin(ty);;
	array_number_t array212 = (array_number_t)malloc(sizeof(int) * 2);
	array212->length=3;
	array212->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array212->arr[0] = 0;
	array212->arr[1] = 1;
	array212->arr[2] = 0;;
	array_number_t array213 = (array_number_t)malloc(sizeof(int) * 2);
	array213->length=3;
	array213->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array213->arr[0] = -(sin(ty));
	array213->arr[1] = 0;
	array213->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array211;
	Ry->arr[1] = array212;
	Ry->arr[2] = array213;;
	array_number_t array214 = (array_number_t)malloc(sizeof(int) * 2);
	array214->length=3;
	array214->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array214->arr[0] = cos(tz);
	array214->arr[1] = -(sin(tz));
	array214->arr[2] = 0;;
	array_number_t array215 = (array_number_t)malloc(sizeof(int) * 2);
	array215->length=3;
	array215->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array215->arr[0] = sin(tz);
	array215->arr[1] = cos(tz);
	array215->arr[2] = 0;;
	array_number_t array216 = (array_number_t)malloc(sizeof(int) * 2);
	array216->length=3;
	array216->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array216->arr[0] = 0;
	array216->arr[1] = 0;
	array216->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array214;
	Rz->arr[1] = array215;
	Rz->arr[2] = array216;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array217 = (array_number_t)malloc(sizeof(int) * 2);
	array217->length=1;
	array217->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array217->arr[0] = 0;;
	array_number_t array218 = (array_number_t)malloc(sizeof(int) * 2);
	array218->length=1;
	array218->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array218->arr[0] = 0;;
	array_number_t array219 = (array_number_t)malloc(sizeof(int) * 2);
	array219->length=1;
	array219->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array219->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array217;
	r1->arr[1] = array218;
	r1->arr[2] = array219;;
	array_number_t array220 = (array_number_t)malloc(sizeof(int) * 2);
	array220->length=4;
	array220->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array220->arr[0] = 0;
	array220->arr[1] = 0;
	array220->arr[2] = 0;
	array220->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array220;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_227 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_227;
env_t_227 make_env_t_227(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_227 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda227(env_t_227* env224, number_t i_bone) {
	array_array_number_t pose_params223 = env224->pose_params;
	index_t offset222 = env224->offset;
	array_array_array_number_t base_relatives221 = env224->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params223->arr[((int)(i_bone)) + (offset222)], base_relatives221->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_227 env_t_227_value = make_env_t_227(pose_params,offset,base_relatives); closure_t closure226 = make_closure(lambda227, &env_t_227_value);
	return linalg_vectorMapToMatrix3D(closure226, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite228 = 0;
	if((n) < (0.0001)) {
		array_number_t array230 = (array_number_t)malloc(sizeof(int) * 2);
	array230->length=3;
	array230->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array230->arr[0] = 1;
	array230->arr[1] = 0;
	array230->arr[2] = 0;;
		array_number_t array231 = (array_number_t)malloc(sizeof(int) * 2);
	array231->length=3;
	array231->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array231->arr[0] = 0;
	array231->arr[1] = 1;
	array231->arr[2] = 0;;
		array_number_t array232 = (array_number_t)malloc(sizeof(int) * 2);
	array232->length=3;
	array232->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array232->arr[0] = 0;
	array232->arr[1] = 0;
	array232->arr[2] = 1;;
		array_array_number_t array229 = (array_array_number_t)malloc(sizeof(int) * 2);
	array229->length=3;
	array229->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array229->arr[0] = array230;
	array229->arr[1] = array231;
	array229->arr[2] = array232;;
		ite228 = array229;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array234 = (array_number_t)malloc(sizeof(int) * 2);
	array234->length=3;
	array234->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array234->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array234->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array234->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array235 = (array_number_t)malloc(sizeof(int) * 2);
	array235->length=3;
	array235->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array235->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array235->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array235->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array236 = (array_number_t)malloc(sizeof(int) * 2);
	array236->length=3;
	array236->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array236->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array236->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array236->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array233 = (array_array_number_t)malloc(sizeof(int) * 2);
	array233->length=3;
	array233->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array233->arr[0] = array234;
	array233->arr[1] = array235;
	array233->arr[2] = array236;;
		ite228 = array233;
	}
	return ite228;
}
typedef struct env_t_245 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_245;
env_t_245 make_env_t_245(array_array_array_number_t relatives,array_number_t parents) {
	env_t_245 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda245(env_t_245* env239, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives238 = env239->relatives;
	array_number_t parents237 = env239->parents;
	array_array_array_number_t ite244 = 0;
	if((parents237->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives238->arr[i];;
		ite244 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents237->arr[i])], relatives238->arr[i]);;
		ite244 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite244;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array243 = (array_number_t)malloc(sizeof(int) * 2);
	array243->length=0;
	array243->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array242 = (array_array_number_t)malloc(sizeof(int) * 2);
	array242->length=1;
	array242->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array242->arr[0] = array243;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array242;;
	env_t_245 env_t_245_value = make_env_t_245(relatives,parents); closure_t closure241 = make_closure(lambda245, &env_t_245_value);
	return linalg_iterateMatrix3D(closure241, init, 0, (relatives->length) - (1));
}
typedef struct env_t_255 {
	array_number_t scale;
} env_t_255;
env_t_255 make_env_t_255(array_number_t scale) {
	env_t_255 env;
	env.scale = scale;
	return env;
}

value_t lambda255(env_t_255* env247, array_number_t row) {
	array_number_t scale246 = env247->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale246);
	return res;
}
typedef empty_env_t env_t_256;


value_t lambda256(env_t_256* env250, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_255 env_t_255_value = make_env_t_255(scale); closure_t closure249 = make_closure(lambda255, &env_t_255_value);
	array_array_number_t R1 = linalg_matrixMap(closure249, R);
	array_array_number_t array253 = (array_array_number_t)malloc(sizeof(int) * 2);
	array253->length=1;
	array253->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array253->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array253));
	env_t_256 env_t_256_value = make_empty_env(); closure_t closure252 = make_closure(lambda256, &env_t_256_value);
	array_number_t ones = linalg_vectorMap(closure252, linalg_vectorRange(1, positions->arr[0]->length));
	array_array_number_t array254 = (array_array_number_t)malloc(sizeof(int) * 2);
	array254->length=1;
	array254->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array254->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array254);
	return matrix_mult(T, positions_homog);
}
typedef empty_env_t env_t_269;


value_t lambda269(env_t_269* env257, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_270 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_270;
env_t_270 make_env_t_270(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_270 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda270(env_t_270* env263, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights262 = env263->weights;
	array_array_array_number_t transforms261 = env263->transforms;
	array_array_number_t base_positions260 = env263->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms261->arr[i_transform], 0, 2), base_positions260);
	array_array_number_t w = linalg_matrixFillFromVector(base_positions260->length, weights262->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	env_t_269 env_t_269_value = make_empty_env(); closure_t closure259 = make_closure(lambda269, &env_t_269_value);
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure259, absolutes, inverse_base_absolutes);
	index_t n_verts = base_positions->arr[0]->length;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	env_t_270 env_t_270_value = make_env_t_270(weights,transforms,base_positions); closure_t closure265 = make_closure(lambda270, &env_t_270_value);
	array_array_number_t positions = linalg_iterateMatrix(closure265, init_positions, 0, (transforms->length) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array266 = (array_number_t)malloc(sizeof(int) * 2);
	array266->length=3;
	array266->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array266->arr[0] = -1;
	array266->arr[1] = 0;
	array266->arr[2] = 0;;
		array_number_t array267 = (array_number_t)malloc(sizeof(int) * 2);
	array267->length=3;
	array267->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array267->arr[0] = 0;
	array267->arr[1] = 1;
	array267->arr[2] = 0;;
		array_number_t array268 = (array_number_t)malloc(sizeof(int) * 2);
	array268->length=3;
	array268->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array268->arr[0] = 0;
	array268->arr[1] = 0;
	array268->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array266;
	mirror_matrix->arr[1] = array267;
	mirror_matrix->arr[2] = array268;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_278 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_278;
env_t_278 make_env_t_278(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_278 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda278(env_t_278* env275, number_t i) {
	array_array_number_t vertex_positions274 = env275->vertex_positions;
	array_array_number_t points273 = env275->points;
	index_t n_corr272 = env275->n_corr;
	array_number_t correspondences271 = env275->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr272);
	index_t c = (ind) % (n_corr272);
	value_t res;
	res.number_t_value = (points273->arr[r]->arr[c]) - (vertex_positions274->arr[r]->arr[(int)(correspondences271->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, index_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_278 env_t_278_value = make_env_t_278(vertex_positions,points,n_corr,correspondences); closure_t closure277 = make_closure(lambda278, &env_t_278_value);
	array_number_t err = linalg_vectorMap(closure277, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_306;


value_t lambda306(env_t_306* env279, number_t r) {
	
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
	array_number_t array295 = (array_number_t)malloc(sizeof(int) * 2);
	array295->length=3;
	array295->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array295->arr[0] = 1;
	array295->arr[1] = 2;
	array295->arr[2] = 3;;
	array_number_t array296 = (array_number_t)malloc(sizeof(int) * 2);
	array296->length=3;
	array296->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array296->arr[0] = 4;
	array296->arr[1] = 5;
	array296->arr[2] = 6;;
	array_number_t array297 = (array_number_t)malloc(sizeof(int) * 2);
	array297->length=3;
	array297->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array297->arr[0] = 7;
	array297->arr[1] = 8;
	array297->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array295;
	mat1->arr[1] = array296;
	mat1->arr[2] = array297;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	env_t_306 env_t_306_value = make_empty_env(); closure_t closure281 = make_closure(lambda306, &env_t_306_value);
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure281, linalg_vectorRange(1, 4));
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
