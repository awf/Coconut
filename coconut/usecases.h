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
	array_number_t ite260 = 0;
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
		ite260 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite260 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite260;
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
typedef empty_env_t env_t_289;


value_t lambda289(env_t_289* env285, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	env_t_289 env_t_289_value = make_empty_env(); closure_t closure287 = make_closure(lambda289, &env_t_289_value);
	return linalg_vectorMap(closure287, w);
}
typedef struct env_t_318 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_318;
env_t_318 make_env_t_318(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_318 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda318(env_t_318* env314, number_t i) {
	array_array_number_t x313 = env314->x;
	array_number_t w312 = env314->w;
	array_array_number_t obs311 = env314->obs;
	array_array_number_t feat310 = env314->feat;
	array_array_number_t cams309 = env314->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams309->arr[(int)(obs311->arr[(int)(i)]->arr[0])], x313->arr[(int)(obs311->arr[(int)(i)]->arr[1])], w312->arr[(int)(i)], feat310->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef290 = cams->length;
	card_t n = macroDef290;
	card_t macroDef291 = w->length;
	card_t p = macroDef291;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	env_t_318 env_t_318_value = make_env_t_318(x,w,obs,feat,cams); closure_t closure316 = make_closure(lambda318, &env_t_318_value);
	return linalg_vectorMapToMatrix(closure316, range);
}
typedef struct env_t_375 {
	array_number_t one_cam;
} env_t_375;
env_t_375 make_env_t_375(array_number_t one_cam) {
	env_t_375 env;
	env.one_cam = one_cam;
	return env;
}

value_t lambda375(env_t_375* env328, number_t x) {
	array_number_t one_cam327 = env328->one_cam;
	value_t res;
	res.array_number_t_value = one_cam327;
	return res;
}
typedef struct env_t_376 {
	array_number_t one_x;
} env_t_376;
env_t_376 make_env_t_376(array_number_t one_x) {
	env_t_376 env;
	env.one_x = one_x;
	return env;
}

value_t lambda376(env_t_376* env335, number_t x) {
	array_number_t one_x334 = env335->one_x;
	value_t res;
	res.array_number_t_value = one_x334;
	return res;
}
typedef struct env_t_377 {
	number_t one_w;
} env_t_377;
env_t_377 make_env_t_377(number_t one_w) {
	env_t_377 env;
	env.one_w = one_w;
	return env;
}

value_t lambda377(env_t_377* env342, number_t x) {
	number_t one_w341 = env342->one_w;
	value_t res;
	res.number_t_value = one_w341;
	return res;
}
typedef struct env_t_378 {
	array_number_t one_feat;
} env_t_378;
env_t_378 make_env_t_378(array_number_t one_feat) {
	env_t_378 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda378(env_t_378* env349, number_t x) {
	array_number_t one_feat348 = env349->one_feat;
	value_t res;
	res.array_number_t_value = one_feat348;
	return res;
}
typedef struct env_t_379 {
	card_t n;
	card_t m;
} env_t_379;
env_t_379 make_env_t_379(card_t n,card_t m) {
	env_t_379 env;
	env.n = n;
	env.m = m;
	return env;
}

value_t lambda379(env_t_379* env364, number_t x) {
	card_t n363 = env364->n;
	card_t m362 = env364->m;
	array_number_t array373 = (array_number_t)malloc(sizeof(int) * 2);
	array373->length=2;
	array373->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array373->arr[0] = (double)(((int)(x)) % ((n363)));
	array373->arr[1] = (double)(((int)(x)) % ((m362)));;
	value_t res;
	res.array_number_t_value = array373;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	card_t n = (int)(nmp->arr[0]);
	card_t m = (int)(nmp->arr[1]);
	card_t p = (int)(nmp->arr[2]);
	card_t oneCard = 1;
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	env_t_375 env_t_375_value = make_env_t_375(one_cam); closure_t closure330 = make_closure(lambda375, &env_t_375_value);
	array_array_number_t cam = linalg_vectorMapToMatrix(closure330, linalg_vectorRange(oneCard, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	env_t_376 env_t_376_value = make_env_t_376(one_x); closure_t closure337 = make_closure(lambda376, &env_t_376_value);
	array_array_number_t x = linalg_vectorMapToMatrix(closure337, linalg_vectorRange(oneCard, m));
	number_t one_w = linalg_numberRead(fn, 3);
	env_t_377 env_t_377_value = make_env_t_377(one_w); closure_t closure344 = make_closure(lambda377, &env_t_377_value);
	array_number_t w = linalg_vectorMap(closure344, linalg_vectorRange(oneCard, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	env_t_378 env_t_378_value = make_env_t_378(one_feat); closure_t closure351 = make_closure(lambda378, &env_t_378_value);
	array_array_number_t feat = linalg_vectorMapToMatrix(closure351, linalg_vectorRange(oneCard, p));
	env_t_379 env_t_379_value = make_env_t_379(n,m); closure_t closure366 = make_closure(lambda379, &env_t_379_value);
	array_array_number_t obs = linalg_vectorMapToMatrix(closure366, linalg_vectorRange(0, (p) - (oneCard)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_391 {
	number_t mx;
} env_t_391;
env_t_391 make_env_t_391(number_t mx) {
	env_t_391 env;
	env.mx = mx;
	return env;
}

value_t lambda391(env_t_391* env384, number_t x) {
	number_t mx383 = env384->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx383));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = linalg_arrayMax(arr);
	env_t_391 env_t_391_value = make_env_t_391(mx); closure_t closure386 = make_closure(lambda391, &env_t_391_value);
	number_t semx = linalg_arraySum(linalg_vectorMap(closure386, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_410 {
	number_t a;
} env_t_410;
env_t_410 make_env_t_410(number_t a) {
	env_t_410 env;
	env.a = a;
	return env;
}

value_t lambda410(env_t_410* env402, number_t j) {
	number_t a401 = env402->a;
	value_t res;
	res.number_t_value = (a401) + ((0.5) * ((1) - ((double)(j))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	env_t_410 env_t_410_value = make_env_t_410(a); closure_t closure404 = make_closure(lambda410, &env_t_410_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (linalg_arraySum(linalg_vectorMap(closure404, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array411 = (array_number_t)malloc(sizeof(int) * 2);
	array411->length=3;
	array411->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array411->arr[0] = 0;
	array411->arr[1] = 0;
	array411->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array411;;
	return res;
}

array_array_number_t usecases_to_pose_params(array_number_t theta, card_t n_bones) {
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
	array_number_t array458 = (array_number_t)malloc(sizeof(int) * 2);
	array458->length=3;
	array458->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array458->arr[0] = theta->arr[i1];
	array458->arr[1] = theta->arr[(i1) + (1)];
	array458->arr[2] = 0;;
	array_number_t array459 = (array_number_t)malloc(sizeof(int) * 2);
	array459->length=3;
	array459->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array459->arr[0] = theta->arr[(i1) + (2)];
	array459->arr[1] = 0;
	array459->arr[2] = 0;;
	array_number_t array460 = (array_number_t)malloc(sizeof(int) * 2);
	array460->length=3;
	array460->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array460->arr[0] = theta->arr[(i1) + (3)];
	array460->arr[1] = 0;
	array460->arr[2] = 0;;
	array_number_t array461 = (array_number_t)malloc(sizeof(int) * 2);
	array461->length=3;
	array461->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array461->arr[0] = 0;
	array461->arr[1] = 0;
	array461->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array458;
	finger1->arr[1] = array459;
	finger1->arr[2] = array460;
	finger1->arr[3] = array461;;
	index_t i2 = (i1) + (4);
	array_number_t array462 = (array_number_t)malloc(sizeof(int) * 2);
	array462->length=3;
	array462->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array462->arr[0] = theta->arr[i2];
	array462->arr[1] = theta->arr[(i2) + (1)];
	array462->arr[2] = 0;;
	array_number_t array463 = (array_number_t)malloc(sizeof(int) * 2);
	array463->length=3;
	array463->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array463->arr[0] = theta->arr[(i2) + (2)];
	array463->arr[1] = 0;
	array463->arr[2] = 0;;
	array_number_t array464 = (array_number_t)malloc(sizeof(int) * 2);
	array464->length=3;
	array464->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array464->arr[0] = theta->arr[(i2) + (3)];
	array464->arr[1] = 0;
	array464->arr[2] = 0;;
	array_number_t array465 = (array_number_t)malloc(sizeof(int) * 2);
	array465->length=3;
	array465->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array465->arr[0] = 0;
	array465->arr[1] = 0;
	array465->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array462;
	finger2->arr[1] = array463;
	finger2->arr[2] = array464;
	finger2->arr[3] = array465;;
	index_t i3 = (i2) + (4);
	array_number_t array466 = (array_number_t)malloc(sizeof(int) * 2);
	array466->length=3;
	array466->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array466->arr[0] = theta->arr[i3];
	array466->arr[1] = theta->arr[(i3) + (1)];
	array466->arr[2] = 0;;
	array_number_t array467 = (array_number_t)malloc(sizeof(int) * 2);
	array467->length=3;
	array467->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array467->arr[0] = theta->arr[(i3) + (2)];
	array467->arr[1] = 0;
	array467->arr[2] = 0;;
	array_number_t array468 = (array_number_t)malloc(sizeof(int) * 2);
	array468->length=3;
	array468->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array468->arr[0] = theta->arr[(i3) + (3)];
	array468->arr[1] = 0;
	array468->arr[2] = 0;;
	array_number_t array469 = (array_number_t)malloc(sizeof(int) * 2);
	array469->length=3;
	array469->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array469->arr[0] = 0;
	array469->arr[1] = 0;
	array469->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array466;
	finger3->arr[1] = array467;
	finger3->arr[2] = array468;
	finger3->arr[3] = array469;;
	index_t i4 = (i3) + (4);
	array_number_t array470 = (array_number_t)malloc(sizeof(int) * 2);
	array470->length=3;
	array470->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array470->arr[0] = theta->arr[i4];
	array470->arr[1] = theta->arr[(i4) + (1)];
	array470->arr[2] = 0;;
	array_number_t array471 = (array_number_t)malloc(sizeof(int) * 2);
	array471->length=3;
	array471->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array471->arr[0] = theta->arr[(i4) + (2)];
	array471->arr[1] = 0;
	array471->arr[2] = 0;;
	array_number_t array472 = (array_number_t)malloc(sizeof(int) * 2);
	array472->length=3;
	array472->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array472->arr[0] = theta->arr[(i4) + (3)];
	array472->arr[1] = 0;
	array472->arr[2] = 0;;
	array_number_t array473 = (array_number_t)malloc(sizeof(int) * 2);
	array473->length=3;
	array473->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array473->arr[0] = 0;
	array473->arr[1] = 0;
	array473->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array470;
	finger4->arr[1] = array471;
	finger4->arr[2] = array472;
	finger4->arr[3] = array473;;
	index_t i5 = (i4) + (4);
	array_number_t array474 = (array_number_t)malloc(sizeof(int) * 2);
	array474->length=3;
	array474->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array474->arr[0] = theta->arr[i5];
	array474->arr[1] = theta->arr[(i5) + (1)];
	array474->arr[2] = 0;;
	array_number_t array475 = (array_number_t)malloc(sizeof(int) * 2);
	array475->length=3;
	array475->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array475->arr[0] = theta->arr[(i5) + (2)];
	array475->arr[1] = 0;
	array475->arr[2] = 0;;
	array_number_t array476 = (array_number_t)malloc(sizeof(int) * 2);
	array476->length=3;
	array476->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array476->arr[0] = theta->arr[(i5) + (3)];
	array476->arr[1] = 0;
	array476->arr[2] = 0;;
	array_number_t array477 = (array_number_t)malloc(sizeof(int) * 2);
	array477->length=3;
	array477->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array477->arr[0] = 0;
	array477->arr[1] = 0;
	array477->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array474;
	finger5->arr[1] = array475;
	finger5->arr[2] = array476;
	finger5->arr[3] = array477;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array498 = (array_number_t)malloc(sizeof(int) * 2);
	array498->length=3;
	array498->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array498->arr[0] = 1;
	array498->arr[1] = 0;
	array498->arr[2] = 0;;
	array_number_t array499 = (array_number_t)malloc(sizeof(int) * 2);
	array499->length=3;
	array499->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array499->arr[0] = 0;
	array499->arr[1] = cos(tx);
	array499->arr[2] = -(sin(tx));;
	array_number_t array500 = (array_number_t)malloc(sizeof(int) * 2);
	array500->length=3;
	array500->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array500->arr[0] = 0;
	array500->arr[1] = sin(tx);
	array500->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array498;
	Rx->arr[1] = array499;
	Rx->arr[2] = array500;;
	array_number_t array501 = (array_number_t)malloc(sizeof(int) * 2);
	array501->length=3;
	array501->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array501->arr[0] = cos(ty);
	array501->arr[1] = 0;
	array501->arr[2] = sin(ty);;
	array_number_t array502 = (array_number_t)malloc(sizeof(int) * 2);
	array502->length=3;
	array502->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array502->arr[0] = 0;
	array502->arr[1] = 1;
	array502->arr[2] = 0;;
	array_number_t array503 = (array_number_t)malloc(sizeof(int) * 2);
	array503->length=3;
	array503->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array503->arr[0] = -(sin(ty));
	array503->arr[1] = 0;
	array503->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array501;
	Ry->arr[1] = array502;
	Ry->arr[2] = array503;;
	array_number_t array504 = (array_number_t)malloc(sizeof(int) * 2);
	array504->length=3;
	array504->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array504->arr[0] = cos(tz);
	array504->arr[1] = -(sin(tz));
	array504->arr[2] = 0;;
	array_number_t array505 = (array_number_t)malloc(sizeof(int) * 2);
	array505->length=3;
	array505->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array505->arr[0] = sin(tz);
	array505->arr[1] = cos(tz);
	array505->arr[2] = 0;;
	array_number_t array506 = (array_number_t)malloc(sizeof(int) * 2);
	array506->length=3;
	array506->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array506->arr[0] = 0;
	array506->arr[1] = 0;
	array506->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array504;
	Rz->arr[1] = array505;
	Rz->arr[2] = array506;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array511 = (array_number_t)malloc(sizeof(int) * 2);
	array511->length=1;
	array511->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array511->arr[0] = 0;;
	array_number_t array512 = (array_number_t)malloc(sizeof(int) * 2);
	array512->length=1;
	array512->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array512->arr[0] = 0;;
	array_number_t array513 = (array_number_t)malloc(sizeof(int) * 2);
	array513->length=1;
	array513->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array513->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array511;
	r1->arr[1] = array512;
	r1->arr[2] = array513;;
	array_number_t array514 = (array_number_t)malloc(sizeof(int) * 2);
	array514->length=4;
	array514->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array514->arr[0] = 0;
	array514->arr[1] = 0;
	array514->arr[2] = 0;
	array514->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array514;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_530 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_530;
env_t_530 make_env_t_530(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_530 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda530(env_t_530* env524, number_t i_bone) {
	array_array_number_t pose_params523 = env524->pose_params;
	index_t offset522 = env524->offset;
	array_array_array_number_t base_relatives521 = env524->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params523->arr[((int)(i_bone)) + (offset522)], base_relatives521->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_530 env_t_530_value = make_env_t_530(pose_params,offset,base_relatives); closure_t closure526 = make_closure(lambda530, &env_t_530_value);
	return linalg_vectorMapToMatrix3D(closure526, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite587 = 0;
	if((n) < (0.0001)) {
		array_number_t array589 = (array_number_t)malloc(sizeof(int) * 2);
	array589->length=3;
	array589->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array589->arr[0] = 1;
	array589->arr[1] = 0;
	array589->arr[2] = 0;;
		array_number_t array590 = (array_number_t)malloc(sizeof(int) * 2);
	array590->length=3;
	array590->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array590->arr[0] = 0;
	array590->arr[1] = 1;
	array590->arr[2] = 0;;
		array_number_t array591 = (array_number_t)malloc(sizeof(int) * 2);
	array591->length=3;
	array591->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array591->arr[0] = 0;
	array591->arr[1] = 0;
	array591->arr[2] = 1;;
		array_array_number_t array588 = (array_array_number_t)malloc(sizeof(int) * 2);
	array588->length=3;
	array588->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array588->arr[0] = array589;
	array588->arr[1] = array590;
	array588->arr[2] = array591;;
		ite587 = array588;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array593 = (array_number_t)malloc(sizeof(int) * 2);
	array593->length=3;
	array593->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array593->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array593->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array593->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array594 = (array_number_t)malloc(sizeof(int) * 2);
	array594->length=3;
	array594->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array594->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array594->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array594->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array595 = (array_number_t)malloc(sizeof(int) * 2);
	array595->length=3;
	array595->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array595->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array595->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array595->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array592 = (array_array_number_t)malloc(sizeof(int) * 2);
	array592->length=3;
	array592->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array592->arr[0] = array593;
	array592->arr[1] = array594;
	array592->arr[2] = array595;;
		ite587 = array592;
	}
	return ite587;
}
typedef struct env_t_617 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_617;
env_t_617 make_env_t_617(array_array_array_number_t relatives,array_number_t parents) {
	env_t_617 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda617(env_t_617* env608, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives607 = env608->relatives;
	array_number_t parents606 = env608->parents;
	array_array_array_number_t ite616 = 0;
	if((parents606->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives607->arr[i];;
		ite616 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents606->arr[i])], relatives607->arr[i]);;
		ite616 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite616;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array615 = (array_number_t)malloc(sizeof(int) * 2);
	array615->length=0;
	array615->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array614 = (array_array_number_t)malloc(sizeof(int) * 2);
	array614->length=1;
	array614->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array614->arr[0] = array615;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array614;;
	env_t_617 env_t_617_value = make_env_t_617(relatives,parents); closure_t closure610 = make_closure(lambda617, &env_t_617_value);
	card_t macroDef611 = relatives->length;
	return linalg_iterateMatrix3D(closure610, init, 0, (macroDef611) - (1));
}
typedef struct env_t_641 {
	array_number_t scale;
} env_t_641;
env_t_641 make_env_t_641(array_number_t scale) {
	env_t_641 env;
	env.scale = scale;
	return env;
}

value_t lambda641(env_t_641* env623, array_number_t row) {
	array_number_t scale622 = env623->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale622);
	return res;
}
typedef empty_env_t env_t_642;


value_t lambda642(env_t_642* env630, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_641 env_t_641_value = make_env_t_641(scale); closure_t closure625 = make_closure(lambda641, &env_t_641_value);
	array_array_number_t R1 = linalg_matrixMap(closure625, R);
	array_array_number_t array639 = (array_array_number_t)malloc(sizeof(int) * 2);
	array639->length=1;
	array639->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array639->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array639));
	env_t_642 env_t_642_value = make_empty_env(); closure_t closure632 = make_closure(lambda642, &env_t_642_value);
	card_t macroDef634 = positions->arr[0]->length;
	array_number_t ones = linalg_vectorMap(closure632, linalg_vectorRange(1, macroDef634));
	array_array_number_t array640 = (array_array_number_t)malloc(sizeof(int) * 2);
	array640->length=1;
	array640->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array640->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array640);
	return matrix_mult(T, positions_homog);
}
typedef empty_env_t env_t_676;


value_t lambda676(env_t_676* env646, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_677 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_677;
env_t_677 make_env_t_677(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_677 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda677(env_t_677* env664, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights663 = env664->weights;
	array_array_array_number_t transforms662 = env664->transforms;
	array_array_number_t base_positions661 = env664->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms662->arr[i_transform], 0, 2), base_positions661);
	card_t macroDef656 = base_positions661->length;
	array_array_number_t w = linalg_matrixFillFromVector(macroDef656, weights663->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	env_t_676 env_t_676_value = make_empty_env(); closure_t closure648 = make_closure(lambda676, &env_t_676_value);
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure648, absolutes, inverse_base_absolutes);
	card_t macroDef651 = base_positions->arr[0]->length;
	card_t n_verts = macroDef651;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	env_t_677 env_t_677_value = make_env_t_677(weights,transforms,base_positions); closure_t closure666 = make_closure(lambda677, &env_t_677_value);
	card_t macroDef667 = transforms->length;
	array_array_number_t positions = linalg_iterateMatrix(closure666, init_positions, 0, (macroDef667) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array673 = (array_number_t)malloc(sizeof(int) * 2);
	array673->length=3;
	array673->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array673->arr[0] = -1;
	array673->arr[1] = 0;
	array673->arr[2] = 0;;
		array_number_t array674 = (array_number_t)malloc(sizeof(int) * 2);
	array674->length=3;
	array674->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array674->arr[0] = 0;
	array674->arr[1] = 1;
	array674->arr[2] = 0;;
		array_number_t array675 = (array_number_t)malloc(sizeof(int) * 2);
	array675->length=3;
	array675->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array675->arr[0] = 0;
	array675->arr[1] = 0;
	array675->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array673;
	mirror_matrix->arr[1] = array674;
	mirror_matrix->arr[2] = array675;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_701 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_701;
env_t_701 make_env_t_701(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_701 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda701(env_t_701* env694, number_t i) {
	array_array_number_t vertex_positions693 = env694->vertex_positions;
	array_array_number_t points692 = env694->points;
	index_t n_corr691 = env694->n_corr;
	array_number_t correspondences690 = env694->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr691);
	index_t c = (ind) % (n_corr691);
	value_t res;
	res.number_t_value = (points692->arr[r]->arr[c]) - (vertex_positions693->arr[r]->arr[(int)(correspondences690->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, card_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_701 env_t_701_value = make_env_t_701(vertex_positions,points,n_corr,correspondences); closure_t closure696 = make_closure(lambda701, &env_t_701_value);
	array_number_t err = linalg_vectorMap(closure696, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_777;


value_t lambda777(env_t_777* env738, number_t r) {
	
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
	array_number_t array766 = (array_number_t)malloc(sizeof(int) * 2);
	array766->length=3;
	array766->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array766->arr[0] = 1;
	array766->arr[1] = 2;
	array766->arr[2] = 3;;
	array_number_t array767 = (array_number_t)malloc(sizeof(int) * 2);
	array767->length=3;
	array767->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array767->arr[0] = 4;
	array767->arr[1] = 5;
	array767->arr[2] = 6;;
	array_number_t array768 = (array_number_t)malloc(sizeof(int) * 2);
	array768->length=3;
	array768->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array768->arr[0] = 7;
	array768->arr[1] = 8;
	array768->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array766;
	mat1->arr[1] = array767;
	mat1->arr[2] = array768;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	env_t_777 env_t_777_value = make_empty_env(); closure_t closure740 = make_closure(lambda777, &env_t_777_value);
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure740, linalg_vectorRange(1, 4));
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
