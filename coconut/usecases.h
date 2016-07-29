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
	array_number_t ite124 = 0;
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
		ite124 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite124 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite124;
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
typedef struct env_t_128 {
	value_t dummy_variable;
} env_t_128;
env_t_128* make_env_t_128() {
	env_t_128* env = (env_t_128*)malloc(sizeof(env_t_128));
	
	return env;
}

value_t lambda128(env_t_128* env125, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	closure_t* closure127 = make_closure(lambda128, make_env_t_128());
	return linalg_vectorMap(closure127, w);
}
typedef struct env_t_137 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_137;
env_t_137* make_env_t_137(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_137* env = (env_t_137*)malloc(sizeof(env_t_137));
	env->x = x;
	env->w = w;
	env->obs = obs;
	env->feat = feat;
	env->cams = cams;
	return env;
}

value_t lambda137(env_t_137* env134, number_t i) {
	array_array_number_t x133 = env134->x;
	array_number_t w132 = env134->w;
	array_array_number_t obs131 = env134->obs;
	array_array_number_t feat130 = env134->feat;
	array_array_number_t cams129 = env134->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams129->arr[(int)(obs131->arr[(int)(i)]->arr[0])], x133->arr[(int)(obs131->arr[(int)(i)]->arr[1])], w132->arr[(int)(i)], feat130->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	closure_t* closure136 = make_closure(lambda137, make_env_t_137(x,w,obs,feat,cams));
	return linalg_vectorMapToMatrix(closure136, range);
}
typedef struct env_t_161 {
	array_number_t one_cam;
} env_t_161;
env_t_161* make_env_t_161(array_number_t one_cam) {
	env_t_161* env = (env_t_161*)malloc(sizeof(env_t_161));
	env->one_cam = one_cam;
	return env;
}

value_t lambda161(env_t_161* env139, number_t x) {
	array_number_t one_cam138 = env139->one_cam;
	value_t res;
	res.array_number_t_value = one_cam138;
	return res;
}
typedef struct env_t_162 {
	array_number_t one_x;
} env_t_162;
env_t_162* make_env_t_162(array_number_t one_x) {
	env_t_162* env = (env_t_162*)malloc(sizeof(env_t_162));
	env->one_x = one_x;
	return env;
}

value_t lambda162(env_t_162* env143, number_t x) {
	array_number_t one_x142 = env143->one_x;
	value_t res;
	res.array_number_t_value = one_x142;
	return res;
}
typedef struct env_t_163 {
	number_t one_w;
} env_t_163;
env_t_163* make_env_t_163(number_t one_w) {
	env_t_163* env = (env_t_163*)malloc(sizeof(env_t_163));
	env->one_w = one_w;
	return env;
}

value_t lambda163(env_t_163* env147, number_t x) {
	number_t one_w146 = env147->one_w;
	value_t res;
	res.number_t_value = one_w146;
	return res;
}
typedef struct env_t_164 {
	array_number_t one_feat;
} env_t_164;
env_t_164* make_env_t_164(array_number_t one_feat) {
	env_t_164* env = (env_t_164*)malloc(sizeof(env_t_164));
	env->one_feat = one_feat;
	return env;
}

value_t lambda164(env_t_164* env151, number_t x) {
	array_number_t one_feat150 = env151->one_feat;
	value_t res;
	res.array_number_t_value = one_feat150;
	return res;
}
typedef struct env_t_165 {
	index_t n;
	index_t m;
} env_t_165;
env_t_165* make_env_t_165(index_t n,index_t m) {
	env_t_165* env = (env_t_165*)malloc(sizeof(env_t_165));
	env->n = n;
	env->m = m;
	return env;
}

value_t lambda165(env_t_165* env156, number_t x) {
	index_t n155 = env156->n;
	index_t m154 = env156->m;
	array_number_t array159 = (array_number_t)malloc(sizeof(int) * 2);
	array159->length=2;
	array159->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array159->arr[0] = (double)(((int)(x)) % (n155));
	array159->arr[1] = (double)(((int)(x)) % (m154));;
	value_t res;
	res.array_number_t_value = array159;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	closure_t* closure141 = make_closure(lambda161, make_env_t_161(one_cam));
	array_array_number_t cam = linalg_vectorMapToMatrix(closure141, linalg_vectorRange(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	closure_t* closure145 = make_closure(lambda162, make_env_t_162(one_x));
	array_array_number_t x = linalg_vectorMapToMatrix(closure145, linalg_vectorRange(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	closure_t* closure149 = make_closure(lambda163, make_env_t_163(one_w));
	array_number_t w = linalg_vectorMap(closure149, linalg_vectorRange(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	closure_t* closure153 = make_closure(lambda164, make_env_t_164(one_feat));
	array_array_number_t feat = linalg_vectorMapToMatrix(closure153, linalg_vectorRange(1, p));
	closure_t* closure158 = make_closure(lambda165, make_env_t_165(n,m));
	array_array_number_t obs = linalg_vectorMapToMatrix(closure158, linalg_vectorRange(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_170 {
	number_t mx;
} env_t_170;
env_t_170* make_env_t_170(number_t mx) {
	env_t_170* env = (env_t_170*)malloc(sizeof(env_t_170));
	env->mx = mx;
	return env;
}

value_t lambda170(env_t_170* env167, number_t x) {
	number_t mx166 = env167->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx166));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = linalg_arrayMax(arr);
	closure_t* closure169 = make_closure(lambda170, make_env_t_170(mx));
	number_t semx = linalg_arraySum(linalg_vectorMap(closure169, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_175 {
	number_t a;
} env_t_175;
env_t_175* make_env_t_175(number_t a) {
	env_t_175* env = (env_t_175*)malloc(sizeof(env_t_175));
	env->a = a;
	return env;
}

value_t lambda175(env_t_175* env172, number_t j) {
	number_t a171 = env172->a;
	value_t res;
	res.number_t_value = gamma_ln((a171) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	closure_t* closure174 = make_closure(lambda175, make_env_t_175(a));
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (linalg_arraySum(linalg_vectorMap(closure174, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array176 = (array_number_t)malloc(sizeof(int) * 2);
	array176->length=3;
	array176->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array176->arr[0] = 0;
	array176->arr[1] = 0;
	array176->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array176;;
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
	array_number_t array177 = (array_number_t)malloc(sizeof(int) * 2);
	array177->length=3;
	array177->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array177->arr[0] = theta->arr[i1];
	array177->arr[1] = theta->arr[(i1) + (1)];
	array177->arr[2] = 0;;
	array_number_t array178 = (array_number_t)malloc(sizeof(int) * 2);
	array178->length=3;
	array178->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array178->arr[0] = theta->arr[(i1) + (2)];
	array178->arr[1] = 0;
	array178->arr[2] = 0;;
	array_number_t array179 = (array_number_t)malloc(sizeof(int) * 2);
	array179->length=3;
	array179->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array179->arr[0] = theta->arr[(i1) + (3)];
	array179->arr[1] = 0;
	array179->arr[2] = 0;;
	array_number_t array180 = (array_number_t)malloc(sizeof(int) * 2);
	array180->length=3;
	array180->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array180->arr[0] = 0;
	array180->arr[1] = 0;
	array180->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array177;
	finger1->arr[1] = array178;
	finger1->arr[2] = array179;
	finger1->arr[3] = array180;;
	index_t i2 = (i1) + (4);
	array_number_t array181 = (array_number_t)malloc(sizeof(int) * 2);
	array181->length=3;
	array181->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array181->arr[0] = theta->arr[i2];
	array181->arr[1] = theta->arr[(i2) + (1)];
	array181->arr[2] = 0;;
	array_number_t array182 = (array_number_t)malloc(sizeof(int) * 2);
	array182->length=3;
	array182->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array182->arr[0] = theta->arr[(i2) + (2)];
	array182->arr[1] = 0;
	array182->arr[2] = 0;;
	array_number_t array183 = (array_number_t)malloc(sizeof(int) * 2);
	array183->length=3;
	array183->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array183->arr[0] = theta->arr[(i2) + (3)];
	array183->arr[1] = 0;
	array183->arr[2] = 0;;
	array_number_t array184 = (array_number_t)malloc(sizeof(int) * 2);
	array184->length=3;
	array184->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array184->arr[0] = 0;
	array184->arr[1] = 0;
	array184->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array181;
	finger2->arr[1] = array182;
	finger2->arr[2] = array183;
	finger2->arr[3] = array184;;
	index_t i3 = (i2) + (4);
	array_number_t array185 = (array_number_t)malloc(sizeof(int) * 2);
	array185->length=3;
	array185->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array185->arr[0] = theta->arr[i3];
	array185->arr[1] = theta->arr[(i3) + (1)];
	array185->arr[2] = 0;;
	array_number_t array186 = (array_number_t)malloc(sizeof(int) * 2);
	array186->length=3;
	array186->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array186->arr[0] = theta->arr[(i3) + (2)];
	array186->arr[1] = 0;
	array186->arr[2] = 0;;
	array_number_t array187 = (array_number_t)malloc(sizeof(int) * 2);
	array187->length=3;
	array187->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array187->arr[0] = theta->arr[(i3) + (3)];
	array187->arr[1] = 0;
	array187->arr[2] = 0;;
	array_number_t array188 = (array_number_t)malloc(sizeof(int) * 2);
	array188->length=3;
	array188->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array188->arr[0] = 0;
	array188->arr[1] = 0;
	array188->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array185;
	finger3->arr[1] = array186;
	finger3->arr[2] = array187;
	finger3->arr[3] = array188;;
	index_t i4 = (i3) + (4);
	array_number_t array189 = (array_number_t)malloc(sizeof(int) * 2);
	array189->length=3;
	array189->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array189->arr[0] = theta->arr[i4];
	array189->arr[1] = theta->arr[(i4) + (1)];
	array189->arr[2] = 0;;
	array_number_t array190 = (array_number_t)malloc(sizeof(int) * 2);
	array190->length=3;
	array190->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array190->arr[0] = theta->arr[(i4) + (2)];
	array190->arr[1] = 0;
	array190->arr[2] = 0;;
	array_number_t array191 = (array_number_t)malloc(sizeof(int) * 2);
	array191->length=3;
	array191->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array191->arr[0] = theta->arr[(i4) + (3)];
	array191->arr[1] = 0;
	array191->arr[2] = 0;;
	array_number_t array192 = (array_number_t)malloc(sizeof(int) * 2);
	array192->length=3;
	array192->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array192->arr[0] = 0;
	array192->arr[1] = 0;
	array192->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array189;
	finger4->arr[1] = array190;
	finger4->arr[2] = array191;
	finger4->arr[3] = array192;;
	index_t i5 = (i4) + (4);
	array_number_t array193 = (array_number_t)malloc(sizeof(int) * 2);
	array193->length=3;
	array193->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array193->arr[0] = theta->arr[i5];
	array193->arr[1] = theta->arr[(i5) + (1)];
	array193->arr[2] = 0;;
	array_number_t array194 = (array_number_t)malloc(sizeof(int) * 2);
	array194->length=3;
	array194->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array194->arr[0] = theta->arr[(i5) + (2)];
	array194->arr[1] = 0;
	array194->arr[2] = 0;;
	array_number_t array195 = (array_number_t)malloc(sizeof(int) * 2);
	array195->length=3;
	array195->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array195->arr[0] = theta->arr[(i5) + (3)];
	array195->arr[1] = 0;
	array195->arr[2] = 0;;
	array_number_t array196 = (array_number_t)malloc(sizeof(int) * 2);
	array196->length=3;
	array196->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array196->arr[0] = 0;
	array196->arr[1] = 0;
	array196->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array193;
	finger5->arr[1] = array194;
	finger5->arr[2] = array195;
	finger5->arr[3] = array196;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array197 = (array_number_t)malloc(sizeof(int) * 2);
	array197->length=3;
	array197->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array197->arr[0] = 1;
	array197->arr[1] = 0;
	array197->arr[2] = 0;;
	array_number_t array198 = (array_number_t)malloc(sizeof(int) * 2);
	array198->length=3;
	array198->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array198->arr[0] = 0;
	array198->arr[1] = cos(tx);
	array198->arr[2] = -(sin(tx));;
	array_number_t array199 = (array_number_t)malloc(sizeof(int) * 2);
	array199->length=3;
	array199->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array199->arr[0] = 0;
	array199->arr[1] = sin(tx);
	array199->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array197;
	Rx->arr[1] = array198;
	Rx->arr[2] = array199;;
	array_number_t array200 = (array_number_t)malloc(sizeof(int) * 2);
	array200->length=3;
	array200->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array200->arr[0] = cos(ty);
	array200->arr[1] = 0;
	array200->arr[2] = sin(ty);;
	array_number_t array201 = (array_number_t)malloc(sizeof(int) * 2);
	array201->length=3;
	array201->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array201->arr[0] = 0;
	array201->arr[1] = 1;
	array201->arr[2] = 0;;
	array_number_t array202 = (array_number_t)malloc(sizeof(int) * 2);
	array202->length=3;
	array202->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array202->arr[0] = -(sin(ty));
	array202->arr[1] = 0;
	array202->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array200;
	Ry->arr[1] = array201;
	Ry->arr[2] = array202;;
	array_number_t array203 = (array_number_t)malloc(sizeof(int) * 2);
	array203->length=3;
	array203->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array203->arr[0] = cos(tz);
	array203->arr[1] = -(sin(tz));
	array203->arr[2] = 0;;
	array_number_t array204 = (array_number_t)malloc(sizeof(int) * 2);
	array204->length=3;
	array204->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array204->arr[0] = sin(tz);
	array204->arr[1] = cos(tz);
	array204->arr[2] = 0;;
	array_number_t array205 = (array_number_t)malloc(sizeof(int) * 2);
	array205->length=3;
	array205->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array205->arr[0] = 0;
	array205->arr[1] = 0;
	array205->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array203;
	Rz->arr[1] = array204;
	Rz->arr[2] = array205;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array206 = (array_number_t)malloc(sizeof(int) * 2);
	array206->length=1;
	array206->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array206->arr[0] = 0;;
	array_number_t array207 = (array_number_t)malloc(sizeof(int) * 2);
	array207->length=1;
	array207->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array207->arr[0] = 0;;
	array_number_t array208 = (array_number_t)malloc(sizeof(int) * 2);
	array208->length=1;
	array208->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array208->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array206;
	r1->arr[1] = array207;
	r1->arr[2] = array208;;
	array_number_t array209 = (array_number_t)malloc(sizeof(int) * 2);
	array209->length=4;
	array209->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array209->arr[0] = 0;
	array209->arr[1] = 0;
	array209->arr[2] = 0;
	array209->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array209;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_216 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_216;
env_t_216* make_env_t_216(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_216* env = (env_t_216*)malloc(sizeof(env_t_216));
	env->pose_params = pose_params;
	env->offset = offset;
	env->base_relatives = base_relatives;
	return env;
}

value_t lambda216(env_t_216* env213, number_t i_bone) {
	array_array_number_t pose_params212 = env213->pose_params;
	index_t offset211 = env213->offset;
	array_array_array_number_t base_relatives210 = env213->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params212->arr[((int)(i_bone)) + (offset211)], base_relatives210->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	closure_t* closure215 = make_closure(lambda216, make_env_t_216(pose_params,offset,base_relatives));
	return linalg_vectorMapToMatrix3D(closure215, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite217 = 0;
	if((n) < (0.0001)) {
		array_number_t array219 = (array_number_t)malloc(sizeof(int) * 2);
	array219->length=3;
	array219->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array219->arr[0] = 1;
	array219->arr[1] = 0;
	array219->arr[2] = 0;;
		array_number_t array220 = (array_number_t)malloc(sizeof(int) * 2);
	array220->length=3;
	array220->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array220->arr[0] = 0;
	array220->arr[1] = 1;
	array220->arr[2] = 0;;
		array_number_t array221 = (array_number_t)malloc(sizeof(int) * 2);
	array221->length=3;
	array221->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array221->arr[0] = 0;
	array221->arr[1] = 0;
	array221->arr[2] = 1;;
		array_array_number_t array218 = (array_array_number_t)malloc(sizeof(int) * 2);
	array218->length=3;
	array218->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array218->arr[0] = array219;
	array218->arr[1] = array220;
	array218->arr[2] = array221;;
		ite217 = array218;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array223 = (array_number_t)malloc(sizeof(int) * 2);
	array223->length=3;
	array223->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array223->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array223->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array223->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array224 = (array_number_t)malloc(sizeof(int) * 2);
	array224->length=3;
	array224->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array224->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array224->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array224->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array225 = (array_number_t)malloc(sizeof(int) * 2);
	array225->length=3;
	array225->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array225->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array225->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array225->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array222 = (array_array_number_t)malloc(sizeof(int) * 2);
	array222->length=3;
	array222->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array222->arr[0] = array223;
	array222->arr[1] = array224;
	array222->arr[2] = array225;;
		ite217 = array222;
	}
	return ite217;
}
typedef struct env_t_234 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_234;
env_t_234* make_env_t_234(array_array_array_number_t relatives,array_number_t parents) {
	env_t_234* env = (env_t_234*)malloc(sizeof(env_t_234));
	env->relatives = relatives;
	env->parents = parents;
	return env;
}

value_t lambda234(env_t_234* env228, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives227 = env228->relatives;
	array_number_t parents226 = env228->parents;
	array_array_array_number_t ite233 = 0;
	if((parents226->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives227->arr[i];;
		ite233 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents226->arr[i])], relatives227->arr[i]);;
		ite233 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite233;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array232 = (array_number_t)malloc(sizeof(int) * 2);
	array232->length=0;
	array232->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array231 = (array_array_number_t)malloc(sizeof(int) * 2);
	array231->length=1;
	array231->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array231->arr[0] = array232;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array231;;
	closure_t* closure230 = make_closure(lambda234, make_env_t_234(relatives,parents));
	return linalg_iterateMatrix3D(closure230, init, 0, (relatives->length) - (1));
}
typedef struct env_t_244 {
	array_number_t scale;
} env_t_244;
env_t_244* make_env_t_244(array_number_t scale) {
	env_t_244* env = (env_t_244*)malloc(sizeof(env_t_244));
	env->scale = scale;
	return env;
}

value_t lambda244(env_t_244* env236, array_number_t row) {
	array_number_t scale235 = env236->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale235);
	return res;
}
typedef struct env_t_245 {
	value_t dummy_variable;
} env_t_245;
env_t_245* make_env_t_245() {
	env_t_245* env = (env_t_245*)malloc(sizeof(env_t_245));
	
	return env;
}

value_t lambda245(env_t_245* env239, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	closure_t* closure238 = make_closure(lambda244, make_env_t_244(scale));
	array_array_number_t R1 = linalg_matrixMap(closure238, R);
	array_array_number_t array242 = (array_array_number_t)malloc(sizeof(int) * 2);
	array242->length=1;
	array242->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array242->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array242));
	closure_t* closure241 = make_closure(lambda245, make_env_t_245());
	array_number_t ones = linalg_vectorMap(closure241, linalg_vectorRange(1, positions->arr[0]->length));
	array_array_number_t array243 = (array_array_number_t)malloc(sizeof(int) * 2);
	array243->length=1;
	array243->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array243->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array243);
	return matrix_mult(T, positions_homog);
}
typedef struct env_t_258 {
	value_t dummy_variable;
} env_t_258;
env_t_258* make_env_t_258() {
	env_t_258* env = (env_t_258*)malloc(sizeof(env_t_258));
	
	return env;
}

value_t lambda258(env_t_258* env246, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_259 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_259;
env_t_259* make_env_t_259(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_259* env = (env_t_259*)malloc(sizeof(env_t_259));
	env->weights = weights;
	env->transforms = transforms;
	env->base_positions = base_positions;
	return env;
}

value_t lambda259(env_t_259* env252, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights251 = env252->weights;
	array_array_array_number_t transforms250 = env252->transforms;
	array_array_number_t base_positions249 = env252->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms250->arr[i_transform], 0, 2), base_positions249);
	array_array_number_t w = linalg_matrixFillFromVector(base_positions249->length, weights251->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	closure_t* closure248 = make_closure(lambda258, make_env_t_258());
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure248, absolutes, inverse_base_absolutes);
	index_t n_verts = base_positions->arr[0]->length;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	closure_t* closure254 = make_closure(lambda259, make_env_t_259(weights,transforms,base_positions));
	array_array_number_t positions = linalg_iterateMatrix(closure254, init_positions, 0, (transforms->length) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array255 = (array_number_t)malloc(sizeof(int) * 2);
	array255->length=3;
	array255->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array255->arr[0] = -1;
	array255->arr[1] = 0;
	array255->arr[2] = 0;;
		array_number_t array256 = (array_number_t)malloc(sizeof(int) * 2);
	array256->length=3;
	array256->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array256->arr[0] = 0;
	array256->arr[1] = 1;
	array256->arr[2] = 0;;
		array_number_t array257 = (array_number_t)malloc(sizeof(int) * 2);
	array257->length=3;
	array257->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array257->arr[0] = 0;
	array257->arr[1] = 0;
	array257->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array255;
	mirror_matrix->arr[1] = array256;
	mirror_matrix->arr[2] = array257;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_267 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_267;
env_t_267* make_env_t_267(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_267* env = (env_t_267*)malloc(sizeof(env_t_267));
	env->vertex_positions = vertex_positions;
	env->points = points;
	env->n_corr = n_corr;
	env->correspondences = correspondences;
	return env;
}

value_t lambda267(env_t_267* env264, number_t i) {
	array_array_number_t vertex_positions263 = env264->vertex_positions;
	array_array_number_t points262 = env264->points;
	index_t n_corr261 = env264->n_corr;
	array_number_t correspondences260 = env264->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr261);
	index_t c = (ind) % (n_corr261);
	value_t res;
	res.number_t_value = (points262->arr[r]->arr[c]) - (vertex_positions263->arr[r]->arr[(int)(correspondences260->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, index_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	closure_t* closure266 = make_closure(lambda267, make_env_t_267(vertex_positions,points,n_corr,correspondences));
	array_number_t err = linalg_vectorMap(closure266, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef struct env_t_295 {
	value_t dummy_variable;
} env_t_295;
env_t_295* make_env_t_295() {
	env_t_295* env = (env_t_295*)malloc(sizeof(env_t_295));
	
	return env;
}

value_t lambda295(env_t_295* env268, number_t r) {
	
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
	array_number_t array284 = (array_number_t)malloc(sizeof(int) * 2);
	array284->length=3;
	array284->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array284->arr[0] = 1;
	array284->arr[1] = 2;
	array284->arr[2] = 3;;
	array_number_t array285 = (array_number_t)malloc(sizeof(int) * 2);
	array285->length=3;
	array285->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array285->arr[0] = 4;
	array285->arr[1] = 5;
	array285->arr[2] = 6;;
	array_number_t array286 = (array_number_t)malloc(sizeof(int) * 2);
	array286->length=3;
	array286->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array286->arr[0] = 7;
	array286->arr[1] = 8;
	array286->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array284;
	mat1->arr[1] = array285;
	mat1->arr[2] = array286;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	closure_t* closure270 = make_closure(lambda295, make_env_t_295());
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure270, linalg_vectorRange(1, 4));
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
