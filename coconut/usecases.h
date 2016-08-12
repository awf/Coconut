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
	array_number_t ite252 = 0;
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
		ite252 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite252 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite252;
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
typedef empty_env_t env_t_281;


value_t lambda281(env_t_281* env277, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	env_t_281 env_t_281_value = make_empty_env(); closure_t closure279 = make_closure(lambda281, &env_t_281_value);
	return linalg_vectorMap(closure279, w);
}
typedef struct env_t_308 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_308;
env_t_308 make_env_t_308(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_308 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda308(env_t_308* env304, number_t i) {
	array_array_number_t x303 = env304->x;
	array_number_t w302 = env304->w;
	array_array_number_t obs301 = env304->obs;
	array_array_number_t feat300 = env304->feat;
	array_array_number_t cams299 = env304->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams299->arr[(int)(obs301->arr[(int)(i)]->arr[0])], x303->arr[(int)(obs301->arr[(int)(i)]->arr[1])], w302->arr[(int)(i)], feat300->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	env_t_308 env_t_308_value = make_env_t_308(x,w,obs,feat,cams); closure_t closure306 = make_closure(lambda308, &env_t_308_value);
	return linalg_vectorMapToMatrix(closure306, range);
}
typedef struct env_t_363 {
	array_number_t one_cam;
} env_t_363;
env_t_363 make_env_t_363(array_number_t one_cam) {
	env_t_363 env;
	env.one_cam = one_cam;
	return env;
}

value_t lambda363(env_t_363* env318, number_t x) {
	array_number_t one_cam317 = env318->one_cam;
	value_t res;
	res.array_number_t_value = one_cam317;
	return res;
}
typedef struct env_t_364 {
	array_number_t one_x;
} env_t_364;
env_t_364 make_env_t_364(array_number_t one_x) {
	env_t_364 env;
	env.one_x = one_x;
	return env;
}

value_t lambda364(env_t_364* env325, number_t x) {
	array_number_t one_x324 = env325->one_x;
	value_t res;
	res.array_number_t_value = one_x324;
	return res;
}
typedef struct env_t_365 {
	number_t one_w;
} env_t_365;
env_t_365 make_env_t_365(number_t one_w) {
	env_t_365 env;
	env.one_w = one_w;
	return env;
}

value_t lambda365(env_t_365* env332, number_t x) {
	number_t one_w331 = env332->one_w;
	value_t res;
	res.number_t_value = one_w331;
	return res;
}
typedef struct env_t_366 {
	array_number_t one_feat;
} env_t_366;
env_t_366 make_env_t_366(array_number_t one_feat) {
	env_t_366 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda366(env_t_366* env339, number_t x) {
	array_number_t one_feat338 = env339->one_feat;
	value_t res;
	res.array_number_t_value = one_feat338;
	return res;
}
typedef struct env_t_367 {
	index_t n;
	index_t m;
} env_t_367;
env_t_367 make_env_t_367(index_t n,index_t m) {
	env_t_367 env;
	env.n = n;
	env.m = m;
	return env;
}

value_t lambda367(env_t_367* env352, number_t x) {
	index_t n351 = env352->n;
	index_t m350 = env352->m;
	array_number_t array361 = (array_number_t)malloc(sizeof(int) * 2);
	array361->length=2;
	array361->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array361->arr[0] = (double)(((int)(x)) % (n351));
	array361->arr[1] = (double)(((int)(x)) % (m350));;
	value_t res;
	res.array_number_t_value = array361;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	env_t_363 env_t_363_value = make_env_t_363(one_cam); closure_t closure320 = make_closure(lambda363, &env_t_363_value);
	array_array_number_t cam = linalg_vectorMapToMatrix(closure320, linalg_vectorRange(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	env_t_364 env_t_364_value = make_env_t_364(one_x); closure_t closure327 = make_closure(lambda364, &env_t_364_value);
	array_array_number_t x = linalg_vectorMapToMatrix(closure327, linalg_vectorRange(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	env_t_365 env_t_365_value = make_env_t_365(one_w); closure_t closure334 = make_closure(lambda365, &env_t_365_value);
	array_number_t w = linalg_vectorMap(closure334, linalg_vectorRange(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	env_t_366 env_t_366_value = make_env_t_366(one_feat); closure_t closure341 = make_closure(lambda366, &env_t_366_value);
	array_array_number_t feat = linalg_vectorMapToMatrix(closure341, linalg_vectorRange(1, p));
	env_t_367 env_t_367_value = make_env_t_367(n,m); closure_t closure354 = make_closure(lambda367, &env_t_367_value);
	array_array_number_t obs = linalg_vectorMapToMatrix(closure354, linalg_vectorRange(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_379 {
	number_t mx;
} env_t_379;
env_t_379 make_env_t_379(number_t mx) {
	env_t_379 env;
	env.mx = mx;
	return env;
}

value_t lambda379(env_t_379* env372, number_t x) {
	number_t mx371 = env372->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx371));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = linalg_arrayMax(arr);
	env_t_379 env_t_379_value = make_env_t_379(mx); closure_t closure374 = make_closure(lambda379, &env_t_379_value);
	number_t semx = linalg_arraySum(linalg_vectorMap(closure374, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_398 {
	number_t a;
} env_t_398;
env_t_398 make_env_t_398(number_t a) {
	env_t_398 env;
	env.a = a;
	return env;
}

value_t lambda398(env_t_398* env390, number_t j) {
	number_t a389 = env390->a;
	value_t res;
	res.number_t_value = (a389) + ((0.5) * ((1) - ((double)(j))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	env_t_398 env_t_398_value = make_env_t_398(a); closure_t closure392 = make_closure(lambda398, &env_t_398_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (linalg_arraySum(linalg_vectorMap(closure392, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array399 = (array_number_t)malloc(sizeof(int) * 2);
	array399->length=3;
	array399->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array399->arr[0] = 0;
	array399->arr[1] = 0;
	array399->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array399;;
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
	array_number_t array446 = (array_number_t)malloc(sizeof(int) * 2);
	array446->length=3;
	array446->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array446->arr[0] = theta->arr[i1];
	array446->arr[1] = theta->arr[(i1) + (1)];
	array446->arr[2] = 0;;
	array_number_t array447 = (array_number_t)malloc(sizeof(int) * 2);
	array447->length=3;
	array447->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array447->arr[0] = theta->arr[(i1) + (2)];
	array447->arr[1] = 0;
	array447->arr[2] = 0;;
	array_number_t array448 = (array_number_t)malloc(sizeof(int) * 2);
	array448->length=3;
	array448->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array448->arr[0] = theta->arr[(i1) + (3)];
	array448->arr[1] = 0;
	array448->arr[2] = 0;;
	array_number_t array449 = (array_number_t)malloc(sizeof(int) * 2);
	array449->length=3;
	array449->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array449->arr[0] = 0;
	array449->arr[1] = 0;
	array449->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array446;
	finger1->arr[1] = array447;
	finger1->arr[2] = array448;
	finger1->arr[3] = array449;;
	index_t i2 = (i1) + (4);
	array_number_t array450 = (array_number_t)malloc(sizeof(int) * 2);
	array450->length=3;
	array450->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array450->arr[0] = theta->arr[i2];
	array450->arr[1] = theta->arr[(i2) + (1)];
	array450->arr[2] = 0;;
	array_number_t array451 = (array_number_t)malloc(sizeof(int) * 2);
	array451->length=3;
	array451->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array451->arr[0] = theta->arr[(i2) + (2)];
	array451->arr[1] = 0;
	array451->arr[2] = 0;;
	array_number_t array452 = (array_number_t)malloc(sizeof(int) * 2);
	array452->length=3;
	array452->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array452->arr[0] = theta->arr[(i2) + (3)];
	array452->arr[1] = 0;
	array452->arr[2] = 0;;
	array_number_t array453 = (array_number_t)malloc(sizeof(int) * 2);
	array453->length=3;
	array453->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array453->arr[0] = 0;
	array453->arr[1] = 0;
	array453->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array450;
	finger2->arr[1] = array451;
	finger2->arr[2] = array452;
	finger2->arr[3] = array453;;
	index_t i3 = (i2) + (4);
	array_number_t array454 = (array_number_t)malloc(sizeof(int) * 2);
	array454->length=3;
	array454->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array454->arr[0] = theta->arr[i3];
	array454->arr[1] = theta->arr[(i3) + (1)];
	array454->arr[2] = 0;;
	array_number_t array455 = (array_number_t)malloc(sizeof(int) * 2);
	array455->length=3;
	array455->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array455->arr[0] = theta->arr[(i3) + (2)];
	array455->arr[1] = 0;
	array455->arr[2] = 0;;
	array_number_t array456 = (array_number_t)malloc(sizeof(int) * 2);
	array456->length=3;
	array456->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array456->arr[0] = theta->arr[(i3) + (3)];
	array456->arr[1] = 0;
	array456->arr[2] = 0;;
	array_number_t array457 = (array_number_t)malloc(sizeof(int) * 2);
	array457->length=3;
	array457->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array457->arr[0] = 0;
	array457->arr[1] = 0;
	array457->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array454;
	finger3->arr[1] = array455;
	finger3->arr[2] = array456;
	finger3->arr[3] = array457;;
	index_t i4 = (i3) + (4);
	array_number_t array458 = (array_number_t)malloc(sizeof(int) * 2);
	array458->length=3;
	array458->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array458->arr[0] = theta->arr[i4];
	array458->arr[1] = theta->arr[(i4) + (1)];
	array458->arr[2] = 0;;
	array_number_t array459 = (array_number_t)malloc(sizeof(int) * 2);
	array459->length=3;
	array459->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array459->arr[0] = theta->arr[(i4) + (2)];
	array459->arr[1] = 0;
	array459->arr[2] = 0;;
	array_number_t array460 = (array_number_t)malloc(sizeof(int) * 2);
	array460->length=3;
	array460->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array460->arr[0] = theta->arr[(i4) + (3)];
	array460->arr[1] = 0;
	array460->arr[2] = 0;;
	array_number_t array461 = (array_number_t)malloc(sizeof(int) * 2);
	array461->length=3;
	array461->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array461->arr[0] = 0;
	array461->arr[1] = 0;
	array461->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array458;
	finger4->arr[1] = array459;
	finger4->arr[2] = array460;
	finger4->arr[3] = array461;;
	index_t i5 = (i4) + (4);
	array_number_t array462 = (array_number_t)malloc(sizeof(int) * 2);
	array462->length=3;
	array462->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array462->arr[0] = theta->arr[i5];
	array462->arr[1] = theta->arr[(i5) + (1)];
	array462->arr[2] = 0;;
	array_number_t array463 = (array_number_t)malloc(sizeof(int) * 2);
	array463->length=3;
	array463->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array463->arr[0] = theta->arr[(i5) + (2)];
	array463->arr[1] = 0;
	array463->arr[2] = 0;;
	array_number_t array464 = (array_number_t)malloc(sizeof(int) * 2);
	array464->length=3;
	array464->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array464->arr[0] = theta->arr[(i5) + (3)];
	array464->arr[1] = 0;
	array464->arr[2] = 0;;
	array_number_t array465 = (array_number_t)malloc(sizeof(int) * 2);
	array465->length=3;
	array465->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array465->arr[0] = 0;
	array465->arr[1] = 0;
	array465->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array462;
	finger5->arr[1] = array463;
	finger5->arr[2] = array464;
	finger5->arr[3] = array465;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array486 = (array_number_t)malloc(sizeof(int) * 2);
	array486->length=3;
	array486->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array486->arr[0] = 1;
	array486->arr[1] = 0;
	array486->arr[2] = 0;;
	array_number_t array487 = (array_number_t)malloc(sizeof(int) * 2);
	array487->length=3;
	array487->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array487->arr[0] = 0;
	array487->arr[1] = cos(tx);
	array487->arr[2] = -(sin(tx));;
	array_number_t array488 = (array_number_t)malloc(sizeof(int) * 2);
	array488->length=3;
	array488->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array488->arr[0] = 0;
	array488->arr[1] = sin(tx);
	array488->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array486;
	Rx->arr[1] = array487;
	Rx->arr[2] = array488;;
	array_number_t array489 = (array_number_t)malloc(sizeof(int) * 2);
	array489->length=3;
	array489->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array489->arr[0] = cos(ty);
	array489->arr[1] = 0;
	array489->arr[2] = sin(ty);;
	array_number_t array490 = (array_number_t)malloc(sizeof(int) * 2);
	array490->length=3;
	array490->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array490->arr[0] = 0;
	array490->arr[1] = 1;
	array490->arr[2] = 0;;
	array_number_t array491 = (array_number_t)malloc(sizeof(int) * 2);
	array491->length=3;
	array491->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array491->arr[0] = -(sin(ty));
	array491->arr[1] = 0;
	array491->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array489;
	Ry->arr[1] = array490;
	Ry->arr[2] = array491;;
	array_number_t array492 = (array_number_t)malloc(sizeof(int) * 2);
	array492->length=3;
	array492->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array492->arr[0] = cos(tz);
	array492->arr[1] = -(sin(tz));
	array492->arr[2] = 0;;
	array_number_t array493 = (array_number_t)malloc(sizeof(int) * 2);
	array493->length=3;
	array493->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array493->arr[0] = sin(tz);
	array493->arr[1] = cos(tz);
	array493->arr[2] = 0;;
	array_number_t array494 = (array_number_t)malloc(sizeof(int) * 2);
	array494->length=3;
	array494->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array494->arr[0] = 0;
	array494->arr[1] = 0;
	array494->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array492;
	Rz->arr[1] = array493;
	Rz->arr[2] = array494;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array499 = (array_number_t)malloc(sizeof(int) * 2);
	array499->length=1;
	array499->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array499->arr[0] = 0;;
	array_number_t array500 = (array_number_t)malloc(sizeof(int) * 2);
	array500->length=1;
	array500->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array500->arr[0] = 0;;
	array_number_t array501 = (array_number_t)malloc(sizeof(int) * 2);
	array501->length=1;
	array501->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array501->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array499;
	r1->arr[1] = array500;
	r1->arr[2] = array501;;
	array_number_t array502 = (array_number_t)malloc(sizeof(int) * 2);
	array502->length=4;
	array502->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array502->arr[0] = 0;
	array502->arr[1] = 0;
	array502->arr[2] = 0;
	array502->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array502;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_518 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_518;
env_t_518 make_env_t_518(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_518 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda518(env_t_518* env512, number_t i_bone) {
	array_array_number_t pose_params511 = env512->pose_params;
	index_t offset510 = env512->offset;
	array_array_array_number_t base_relatives509 = env512->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params511->arr[((int)(i_bone)) + (offset510)], base_relatives509->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_518 env_t_518_value = make_env_t_518(pose_params,offset,base_relatives); closure_t closure514 = make_closure(lambda518, &env_t_518_value);
	return linalg_vectorMapToMatrix3D(closure514, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite575 = 0;
	if((n) < (0.0001)) {
		array_number_t array577 = (array_number_t)malloc(sizeof(int) * 2);
	array577->length=3;
	array577->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array577->arr[0] = 1;
	array577->arr[1] = 0;
	array577->arr[2] = 0;;
		array_number_t array578 = (array_number_t)malloc(sizeof(int) * 2);
	array578->length=3;
	array578->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array578->arr[0] = 0;
	array578->arr[1] = 1;
	array578->arr[2] = 0;;
		array_number_t array579 = (array_number_t)malloc(sizeof(int) * 2);
	array579->length=3;
	array579->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array579->arr[0] = 0;
	array579->arr[1] = 0;
	array579->arr[2] = 1;;
		array_array_number_t array576 = (array_array_number_t)malloc(sizeof(int) * 2);
	array576->length=3;
	array576->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array576->arr[0] = array577;
	array576->arr[1] = array578;
	array576->arr[2] = array579;;
		ite575 = array576;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array581 = (array_number_t)malloc(sizeof(int) * 2);
	array581->length=3;
	array581->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array581->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array581->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array581->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array582 = (array_number_t)malloc(sizeof(int) * 2);
	array582->length=3;
	array582->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array582->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array582->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array582->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array583 = (array_number_t)malloc(sizeof(int) * 2);
	array583->length=3;
	array583->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array583->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array583->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array583->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array580 = (array_array_number_t)malloc(sizeof(int) * 2);
	array580->length=3;
	array580->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array580->arr[0] = array581;
	array580->arr[1] = array582;
	array580->arr[2] = array583;;
		ite575 = array580;
	}
	return ite575;
}
typedef struct env_t_604 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_604;
env_t_604 make_env_t_604(array_array_array_number_t relatives,array_number_t parents) {
	env_t_604 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda604(env_t_604* env596, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives595 = env596->relatives;
	array_number_t parents594 = env596->parents;
	array_array_array_number_t ite603 = 0;
	if((parents594->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives595->arr[i];;
		ite603 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents594->arr[i])], relatives595->arr[i]);;
		ite603 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite603;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array602 = (array_number_t)malloc(sizeof(int) * 2);
	array602->length=0;
	array602->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array601 = (array_array_number_t)malloc(sizeof(int) * 2);
	array601->length=1;
	array601->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array601->arr[0] = array602;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array601;;
	env_t_604 env_t_604_value = make_env_t_604(relatives,parents); closure_t closure598 = make_closure(lambda604, &env_t_604_value);
	return linalg_iterateMatrix3D(closure598, init, 0, (relatives->length) - (1));
}
typedef struct env_t_627 {
	array_number_t scale;
} env_t_627;
env_t_627 make_env_t_627(array_number_t scale) {
	env_t_627 env;
	env.scale = scale;
	return env;
}

value_t lambda627(env_t_627* env610, array_number_t row) {
	array_number_t scale609 = env610->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale609);
	return res;
}
typedef empty_env_t env_t_628;


value_t lambda628(env_t_628* env617, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_627 env_t_627_value = make_env_t_627(scale); closure_t closure612 = make_closure(lambda627, &env_t_627_value);
	array_array_number_t R1 = linalg_matrixMap(closure612, R);
	array_array_number_t array625 = (array_array_number_t)malloc(sizeof(int) * 2);
	array625->length=1;
	array625->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array625->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array625));
	env_t_628 env_t_628_value = make_empty_env(); closure_t closure619 = make_closure(lambda628, &env_t_628_value);
	array_number_t ones = linalg_vectorMap(closure619, linalg_vectorRange(1, positions->arr[0]->length));
	array_array_number_t array626 = (array_array_number_t)malloc(sizeof(int) * 2);
	array626->length=1;
	array626->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array626->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array626);
	return matrix_mult(T, positions_homog);
}
typedef empty_env_t env_t_659;


value_t lambda659(env_t_659* env632, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_660 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_660;
env_t_660 make_env_t_660(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_660 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda660(env_t_660* env648, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights647 = env648->weights;
	array_array_array_number_t transforms646 = env648->transforms;
	array_array_number_t base_positions645 = env648->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms646->arr[i_transform], 0, 2), base_positions645);
	array_array_number_t w = linalg_matrixFillFromVector(base_positions645->length, weights647->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	env_t_659 env_t_659_value = make_empty_env(); closure_t closure634 = make_closure(lambda659, &env_t_659_value);
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure634, absolutes, inverse_base_absolutes);
	index_t n_verts = base_positions->arr[0]->length;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	env_t_660 env_t_660_value = make_env_t_660(weights,transforms,base_positions); closure_t closure650 = make_closure(lambda660, &env_t_660_value);
	array_array_number_t positions = linalg_iterateMatrix(closure650, init_positions, 0, (transforms->length) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array656 = (array_number_t)malloc(sizeof(int) * 2);
	array656->length=3;
	array656->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array656->arr[0] = -1;
	array656->arr[1] = 0;
	array656->arr[2] = 0;;
		array_number_t array657 = (array_number_t)malloc(sizeof(int) * 2);
	array657->length=3;
	array657->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array657->arr[0] = 0;
	array657->arr[1] = 1;
	array657->arr[2] = 0;;
		array_number_t array658 = (array_number_t)malloc(sizeof(int) * 2);
	array658->length=3;
	array658->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array658->arr[0] = 0;
	array658->arr[1] = 0;
	array658->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array656;
	mirror_matrix->arr[1] = array657;
	mirror_matrix->arr[2] = array658;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_684 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_684;
env_t_684 make_env_t_684(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_684 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda684(env_t_684* env677, number_t i) {
	array_array_number_t vertex_positions676 = env677->vertex_positions;
	array_array_number_t points675 = env677->points;
	index_t n_corr674 = env677->n_corr;
	array_number_t correspondences673 = env677->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr674);
	index_t c = (ind) % (n_corr674);
	value_t res;
	res.number_t_value = (points675->arr[r]->arr[c]) - (vertex_positions676->arr[r]->arr[(int)(correspondences673->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, index_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_684 env_t_684_value = make_env_t_684(vertex_positions,points,n_corr,correspondences); closure_t closure679 = make_closure(lambda684, &env_t_684_value);
	array_number_t err = linalg_vectorMap(closure679, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_760;


value_t lambda760(env_t_760* env721, number_t r) {
	
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
	array_number_t array749 = (array_number_t)malloc(sizeof(int) * 2);
	array749->length=3;
	array749->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array749->arr[0] = 1;
	array749->arr[1] = 2;
	array749->arr[2] = 3;;
	array_number_t array750 = (array_number_t)malloc(sizeof(int) * 2);
	array750->length=3;
	array750->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array750->arr[0] = 4;
	array750->arr[1] = 5;
	array750->arr[2] = 6;;
	array_number_t array751 = (array_number_t)malloc(sizeof(int) * 2);
	array751->length=3;
	array751->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array751->arr[0] = 7;
	array751->arr[1] = 8;
	array751->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array749;
	mat1->arr[1] = array750;
	mat1->arr[2] = array751;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	env_t_760 env_t_760_value = make_empty_env(); closure_t closure723 = make_closure(lambda760, &env_t_760_value);
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure723, linalg_vectorRange(1, 4));
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
