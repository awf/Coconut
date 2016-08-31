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
	array_number_t ite269 = 0;
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
		ite269 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite269 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite269;
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
typedef empty_env_t env_t_298;


value_t lambda298(env_t_298* env294, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	env_t_298 env_t_298_value = make_empty_env(); closure_t closure296 = make_closure(lambda298, &env_t_298_value);
	return linalg_vectorMap(closure296, w);
}
typedef struct env_t_327 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_327;
env_t_327 make_env_t_327(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_327 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda327(env_t_327* env323, number_t i) {
	array_array_number_t x322 = env323->x;
	array_number_t w321 = env323->w;
	array_array_number_t obs320 = env323->obs;
	array_array_number_t feat319 = env323->feat;
	array_array_number_t cams318 = env323->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams318->arr[(int)(obs320->arr[(int)(i)]->arr[0])], x322->arr[(int)(obs320->arr[(int)(i)]->arr[1])], w321->arr[(int)(i)], feat319->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef299 = cams->length;
	card_t n = macroDef299;
	card_t macroDef300 = w->length;
	card_t p = macroDef300;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	env_t_327 env_t_327_value = make_env_t_327(x,w,obs,feat,cams); closure_t closure325 = make_closure(lambda327, &env_t_327_value);
	return linalg_vectorMapToMatrix(closure325, range);
}
typedef struct env_t_384 {
	array_number_t one_cam;
} env_t_384;
env_t_384 make_env_t_384(array_number_t one_cam) {
	env_t_384 env;
	env.one_cam = one_cam;
	return env;
}

value_t lambda384(env_t_384* env337, number_t x) {
	array_number_t one_cam336 = env337->one_cam;
	value_t res;
	res.array_number_t_value = one_cam336;
	return res;
}
typedef struct env_t_385 {
	array_number_t one_x;
} env_t_385;
env_t_385 make_env_t_385(array_number_t one_x) {
	env_t_385 env;
	env.one_x = one_x;
	return env;
}

value_t lambda385(env_t_385* env344, number_t x) {
	array_number_t one_x343 = env344->one_x;
	value_t res;
	res.array_number_t_value = one_x343;
	return res;
}
typedef struct env_t_386 {
	number_t one_w;
} env_t_386;
env_t_386 make_env_t_386(number_t one_w) {
	env_t_386 env;
	env.one_w = one_w;
	return env;
}

value_t lambda386(env_t_386* env351, number_t x) {
	number_t one_w350 = env351->one_w;
	value_t res;
	res.number_t_value = one_w350;
	return res;
}
typedef struct env_t_387 {
	array_number_t one_feat;
} env_t_387;
env_t_387 make_env_t_387(array_number_t one_feat) {
	env_t_387 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda387(env_t_387* env358, number_t x) {
	array_number_t one_feat357 = env358->one_feat;
	value_t res;
	res.array_number_t_value = one_feat357;
	return res;
}
typedef struct env_t_388 {
	card_t n;
	card_t m;
} env_t_388;
env_t_388 make_env_t_388(card_t n,card_t m) {
	env_t_388 env;
	env.n = n;
	env.m = m;
	return env;
}

value_t lambda388(env_t_388* env373, number_t x) {
	card_t n372 = env373->n;
	card_t m371 = env373->m;
	array_number_t array382 = (array_number_t)malloc(sizeof(int) * 2);
	array382->length=2;
	array382->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array382->arr[0] = (double)(((int)(x)) % ((n372)));
	array382->arr[1] = (double)(((int)(x)) % ((m371)));;
	value_t res;
	res.array_number_t_value = array382;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	card_t n = (int)(nmp->arr[0]);
	card_t m = (int)(nmp->arr[1]);
	card_t p = (int)(nmp->arr[2]);
	card_t oneCard = 1;
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	env_t_384 env_t_384_value = make_env_t_384(one_cam); closure_t closure339 = make_closure(lambda384, &env_t_384_value);
	array_array_number_t cam = linalg_vectorMapToMatrix(closure339, linalg_vectorRange(oneCard, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	env_t_385 env_t_385_value = make_env_t_385(one_x); closure_t closure346 = make_closure(lambda385, &env_t_385_value);
	array_array_number_t x = linalg_vectorMapToMatrix(closure346, linalg_vectorRange(oneCard, m));
	number_t one_w = linalg_numberRead(fn, 3);
	env_t_386 env_t_386_value = make_env_t_386(one_w); closure_t closure353 = make_closure(lambda386, &env_t_386_value);
	array_number_t w = linalg_vectorMap(closure353, linalg_vectorRange(oneCard, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	env_t_387 env_t_387_value = make_env_t_387(one_feat); closure_t closure360 = make_closure(lambda387, &env_t_387_value);
	array_array_number_t feat = linalg_vectorMapToMatrix(closure360, linalg_vectorRange(oneCard, p));
	env_t_388 env_t_388_value = make_env_t_388(n,m); closure_t closure375 = make_closure(lambda388, &env_t_388_value);
	array_array_number_t obs = linalg_vectorMapToMatrix(closure375, linalg_vectorRange(0, (p) - (oneCard)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_400 {
	number_t mx;
} env_t_400;
env_t_400 make_env_t_400(number_t mx) {
	env_t_400 env;
	env.mx = mx;
	return env;
}

value_t lambda400(env_t_400* env393, number_t x) {
	number_t mx392 = env393->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx392));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = linalg_arrayMax(arr);
	env_t_400 env_t_400_value = make_env_t_400(mx); closure_t closure395 = make_closure(lambda400, &env_t_400_value);
	number_t semx = linalg_arraySum(linalg_vectorMap(closure395, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_419 {
	number_t a;
} env_t_419;
env_t_419 make_env_t_419(number_t a) {
	env_t_419 env;
	env.a = a;
	return env;
}

value_t lambda419(env_t_419* env411, number_t j) {
	number_t a410 = env411->a;
	value_t res;
	res.number_t_value = (a410) + ((0.5) * ((1) - ((double)(j))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	env_t_419 env_t_419_value = make_env_t_419(a); closure_t closure413 = make_closure(lambda419, &env_t_419_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (linalg_arraySum(linalg_vectorMap(closure413, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array420 = (array_number_t)malloc(sizeof(int) * 2);
	array420->length=3;
	array420->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array420->arr[0] = 0;
	array420->arr[1] = 0;
	array420->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array420;;
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
	array_number_t array467 = (array_number_t)malloc(sizeof(int) * 2);
	array467->length=3;
	array467->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array467->arr[0] = theta->arr[i1];
	array467->arr[1] = theta->arr[(i1) + (1)];
	array467->arr[2] = 0;;
	array_number_t array468 = (array_number_t)malloc(sizeof(int) * 2);
	array468->length=3;
	array468->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array468->arr[0] = theta->arr[(i1) + (2)];
	array468->arr[1] = 0;
	array468->arr[2] = 0;;
	array_number_t array469 = (array_number_t)malloc(sizeof(int) * 2);
	array469->length=3;
	array469->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array469->arr[0] = theta->arr[(i1) + (3)];
	array469->arr[1] = 0;
	array469->arr[2] = 0;;
	array_number_t array470 = (array_number_t)malloc(sizeof(int) * 2);
	array470->length=3;
	array470->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array470->arr[0] = 0;
	array470->arr[1] = 0;
	array470->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array467;
	finger1->arr[1] = array468;
	finger1->arr[2] = array469;
	finger1->arr[3] = array470;;
	index_t i2 = (i1) + (4);
	array_number_t array471 = (array_number_t)malloc(sizeof(int) * 2);
	array471->length=3;
	array471->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array471->arr[0] = theta->arr[i2];
	array471->arr[1] = theta->arr[(i2) + (1)];
	array471->arr[2] = 0;;
	array_number_t array472 = (array_number_t)malloc(sizeof(int) * 2);
	array472->length=3;
	array472->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array472->arr[0] = theta->arr[(i2) + (2)];
	array472->arr[1] = 0;
	array472->arr[2] = 0;;
	array_number_t array473 = (array_number_t)malloc(sizeof(int) * 2);
	array473->length=3;
	array473->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array473->arr[0] = theta->arr[(i2) + (3)];
	array473->arr[1] = 0;
	array473->arr[2] = 0;;
	array_number_t array474 = (array_number_t)malloc(sizeof(int) * 2);
	array474->length=3;
	array474->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array474->arr[0] = 0;
	array474->arr[1] = 0;
	array474->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array471;
	finger2->arr[1] = array472;
	finger2->arr[2] = array473;
	finger2->arr[3] = array474;;
	index_t i3 = (i2) + (4);
	array_number_t array475 = (array_number_t)malloc(sizeof(int) * 2);
	array475->length=3;
	array475->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array475->arr[0] = theta->arr[i3];
	array475->arr[1] = theta->arr[(i3) + (1)];
	array475->arr[2] = 0;;
	array_number_t array476 = (array_number_t)malloc(sizeof(int) * 2);
	array476->length=3;
	array476->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array476->arr[0] = theta->arr[(i3) + (2)];
	array476->arr[1] = 0;
	array476->arr[2] = 0;;
	array_number_t array477 = (array_number_t)malloc(sizeof(int) * 2);
	array477->length=3;
	array477->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array477->arr[0] = theta->arr[(i3) + (3)];
	array477->arr[1] = 0;
	array477->arr[2] = 0;;
	array_number_t array478 = (array_number_t)malloc(sizeof(int) * 2);
	array478->length=3;
	array478->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array478->arr[0] = 0;
	array478->arr[1] = 0;
	array478->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array475;
	finger3->arr[1] = array476;
	finger3->arr[2] = array477;
	finger3->arr[3] = array478;;
	index_t i4 = (i3) + (4);
	array_number_t array479 = (array_number_t)malloc(sizeof(int) * 2);
	array479->length=3;
	array479->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array479->arr[0] = theta->arr[i4];
	array479->arr[1] = theta->arr[(i4) + (1)];
	array479->arr[2] = 0;;
	array_number_t array480 = (array_number_t)malloc(sizeof(int) * 2);
	array480->length=3;
	array480->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array480->arr[0] = theta->arr[(i4) + (2)];
	array480->arr[1] = 0;
	array480->arr[2] = 0;;
	array_number_t array481 = (array_number_t)malloc(sizeof(int) * 2);
	array481->length=3;
	array481->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array481->arr[0] = theta->arr[(i4) + (3)];
	array481->arr[1] = 0;
	array481->arr[2] = 0;;
	array_number_t array482 = (array_number_t)malloc(sizeof(int) * 2);
	array482->length=3;
	array482->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array482->arr[0] = 0;
	array482->arr[1] = 0;
	array482->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array479;
	finger4->arr[1] = array480;
	finger4->arr[2] = array481;
	finger4->arr[3] = array482;;
	index_t i5 = (i4) + (4);
	array_number_t array483 = (array_number_t)malloc(sizeof(int) * 2);
	array483->length=3;
	array483->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array483->arr[0] = theta->arr[i5];
	array483->arr[1] = theta->arr[(i5) + (1)];
	array483->arr[2] = 0;;
	array_number_t array484 = (array_number_t)malloc(sizeof(int) * 2);
	array484->length=3;
	array484->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array484->arr[0] = theta->arr[(i5) + (2)];
	array484->arr[1] = 0;
	array484->arr[2] = 0;;
	array_number_t array485 = (array_number_t)malloc(sizeof(int) * 2);
	array485->length=3;
	array485->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array485->arr[0] = theta->arr[(i5) + (3)];
	array485->arr[1] = 0;
	array485->arr[2] = 0;;
	array_number_t array486 = (array_number_t)malloc(sizeof(int) * 2);
	array486->length=3;
	array486->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array486->arr[0] = 0;
	array486->arr[1] = 0;
	array486->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array483;
	finger5->arr[1] = array484;
	finger5->arr[2] = array485;
	finger5->arr[3] = array486;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array507 = (array_number_t)malloc(sizeof(int) * 2);
	array507->length=3;
	array507->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array507->arr[0] = 1;
	array507->arr[1] = 0;
	array507->arr[2] = 0;;
	array_number_t array508 = (array_number_t)malloc(sizeof(int) * 2);
	array508->length=3;
	array508->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array508->arr[0] = 0;
	array508->arr[1] = cos(tx);
	array508->arr[2] = -(sin(tx));;
	array_number_t array509 = (array_number_t)malloc(sizeof(int) * 2);
	array509->length=3;
	array509->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array509->arr[0] = 0;
	array509->arr[1] = sin(tx);
	array509->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array507;
	Rx->arr[1] = array508;
	Rx->arr[2] = array509;;
	array_number_t array510 = (array_number_t)malloc(sizeof(int) * 2);
	array510->length=3;
	array510->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array510->arr[0] = cos(ty);
	array510->arr[1] = 0;
	array510->arr[2] = sin(ty);;
	array_number_t array511 = (array_number_t)malloc(sizeof(int) * 2);
	array511->length=3;
	array511->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array511->arr[0] = 0;
	array511->arr[1] = 1;
	array511->arr[2] = 0;;
	array_number_t array512 = (array_number_t)malloc(sizeof(int) * 2);
	array512->length=3;
	array512->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array512->arr[0] = -(sin(ty));
	array512->arr[1] = 0;
	array512->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array510;
	Ry->arr[1] = array511;
	Ry->arr[2] = array512;;
	array_number_t array513 = (array_number_t)malloc(sizeof(int) * 2);
	array513->length=3;
	array513->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array513->arr[0] = cos(tz);
	array513->arr[1] = -(sin(tz));
	array513->arr[2] = 0;;
	array_number_t array514 = (array_number_t)malloc(sizeof(int) * 2);
	array514->length=3;
	array514->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array514->arr[0] = sin(tz);
	array514->arr[1] = cos(tz);
	array514->arr[2] = 0;;
	array_number_t array515 = (array_number_t)malloc(sizeof(int) * 2);
	array515->length=3;
	array515->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array515->arr[0] = 0;
	array515->arr[1] = 0;
	array515->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array513;
	Rz->arr[1] = array514;
	Rz->arr[2] = array515;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array520 = (array_number_t)malloc(sizeof(int) * 2);
	array520->length=1;
	array520->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array520->arr[0] = 0;;
	array_number_t array521 = (array_number_t)malloc(sizeof(int) * 2);
	array521->length=1;
	array521->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array521->arr[0] = 0;;
	array_number_t array522 = (array_number_t)malloc(sizeof(int) * 2);
	array522->length=1;
	array522->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array522->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array520;
	r1->arr[1] = array521;
	r1->arr[2] = array522;;
	array_number_t array523 = (array_number_t)malloc(sizeof(int) * 2);
	array523->length=4;
	array523->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array523->arr[0] = 0;
	array523->arr[1] = 0;
	array523->arr[2] = 0;
	array523->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array523;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_539 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_539;
env_t_539 make_env_t_539(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_539 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda539(env_t_539* env533, number_t i_bone) {
	array_array_number_t pose_params532 = env533->pose_params;
	index_t offset531 = env533->offset;
	array_array_array_number_t base_relatives530 = env533->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params532->arr[((int)(i_bone)) + (offset531)], base_relatives530->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_539 env_t_539_value = make_env_t_539(pose_params,offset,base_relatives); closure_t closure535 = make_closure(lambda539, &env_t_539_value);
	return linalg_vectorMapToMatrix3D(closure535, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite596 = 0;
	if((n) < (0.0001)) {
		array_number_t array598 = (array_number_t)malloc(sizeof(int) * 2);
	array598->length=3;
	array598->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array598->arr[0] = 1;
	array598->arr[1] = 0;
	array598->arr[2] = 0;;
		array_number_t array599 = (array_number_t)malloc(sizeof(int) * 2);
	array599->length=3;
	array599->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array599->arr[0] = 0;
	array599->arr[1] = 1;
	array599->arr[2] = 0;;
		array_number_t array600 = (array_number_t)malloc(sizeof(int) * 2);
	array600->length=3;
	array600->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array600->arr[0] = 0;
	array600->arr[1] = 0;
	array600->arr[2] = 1;;
		array_array_number_t array597 = (array_array_number_t)malloc(sizeof(int) * 2);
	array597->length=3;
	array597->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array597->arr[0] = array598;
	array597->arr[1] = array599;
	array597->arr[2] = array600;;
		ite596 = array597;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array602 = (array_number_t)malloc(sizeof(int) * 2);
	array602->length=3;
	array602->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array602->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array602->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array602->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array603 = (array_number_t)malloc(sizeof(int) * 2);
	array603->length=3;
	array603->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array603->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array603->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array603->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array604 = (array_number_t)malloc(sizeof(int) * 2);
	array604->length=3;
	array604->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array604->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array604->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array604->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array601 = (array_array_number_t)malloc(sizeof(int) * 2);
	array601->length=3;
	array601->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array601->arr[0] = array602;
	array601->arr[1] = array603;
	array601->arr[2] = array604;;
		ite596 = array601;
	}
	return ite596;
}
typedef struct env_t_626 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_626;
env_t_626 make_env_t_626(array_array_array_number_t relatives,array_number_t parents) {
	env_t_626 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda626(env_t_626* env617, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives616 = env617->relatives;
	array_number_t parents615 = env617->parents;
	array_array_array_number_t ite625 = 0;
	if((parents615->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives616->arr[i];;
		ite625 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents615->arr[i])], relatives616->arr[i]);;
		ite625 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite625;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array624 = (array_number_t)malloc(sizeof(int) * 2);
	array624->length=0;
	array624->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array623 = (array_array_number_t)malloc(sizeof(int) * 2);
	array623->length=1;
	array623->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array623->arr[0] = array624;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array623;;
	env_t_626 env_t_626_value = make_env_t_626(relatives,parents); closure_t closure619 = make_closure(lambda626, &env_t_626_value);
	card_t macroDef620 = relatives->length;
	return linalg_iterateMatrix3D(closure619, init, 0, (macroDef620) - (1));
}
typedef struct env_t_650 {
	array_number_t scale;
} env_t_650;
env_t_650 make_env_t_650(array_number_t scale) {
	env_t_650 env;
	env.scale = scale;
	return env;
}

value_t lambda650(env_t_650* env632, array_number_t row) {
	array_number_t scale631 = env632->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale631);
	return res;
}
typedef empty_env_t env_t_651;


value_t lambda651(env_t_651* env639, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_650 env_t_650_value = make_env_t_650(scale); closure_t closure634 = make_closure(lambda650, &env_t_650_value);
	array_array_number_t R1 = linalg_matrixMap(closure634, R);
	array_array_number_t array648 = (array_array_number_t)malloc(sizeof(int) * 2);
	array648->length=1;
	array648->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array648->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array648));
	env_t_651 env_t_651_value = make_empty_env(); closure_t closure641 = make_closure(lambda651, &env_t_651_value);
	card_t macroDef643 = positions->arr[0]->length;
	array_number_t ones = linalg_vectorMap(closure641, linalg_vectorRange(1, macroDef643));
	array_array_number_t array649 = (array_array_number_t)malloc(sizeof(int) * 2);
	array649->length=1;
	array649->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array649->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array649);
	return matrix_mult(T, positions_homog);
}
typedef empty_env_t env_t_685;


value_t lambda685(env_t_685* env655, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_686 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_686;
env_t_686 make_env_t_686(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_686 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda686(env_t_686* env673, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights672 = env673->weights;
	array_array_array_number_t transforms671 = env673->transforms;
	array_array_number_t base_positions670 = env673->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms671->arr[i_transform], 0, 2), base_positions670);
	card_t macroDef665 = base_positions670->length;
	array_array_number_t w = linalg_matrixFillFromVector(macroDef665, weights672->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	env_t_685 env_t_685_value = make_empty_env(); closure_t closure657 = make_closure(lambda685, &env_t_685_value);
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure657, absolutes, inverse_base_absolutes);
	card_t macroDef660 = base_positions->arr[0]->length;
	card_t n_verts = macroDef660;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	env_t_686 env_t_686_value = make_env_t_686(weights,transforms,base_positions); closure_t closure675 = make_closure(lambda686, &env_t_686_value);
	card_t macroDef676 = transforms->length;
	array_array_number_t positions = linalg_iterateMatrix(closure675, init_positions, 0, (macroDef676) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array682 = (array_number_t)malloc(sizeof(int) * 2);
	array682->length=3;
	array682->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array682->arr[0] = -1;
	array682->arr[1] = 0;
	array682->arr[2] = 0;;
		array_number_t array683 = (array_number_t)malloc(sizeof(int) * 2);
	array683->length=3;
	array683->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array683->arr[0] = 0;
	array683->arr[1] = 1;
	array683->arr[2] = 0;;
		array_number_t array684 = (array_number_t)malloc(sizeof(int) * 2);
	array684->length=3;
	array684->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array684->arr[0] = 0;
	array684->arr[1] = 0;
	array684->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array682;
	mirror_matrix->arr[1] = array683;
	mirror_matrix->arr[2] = array684;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_710 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_710;
env_t_710 make_env_t_710(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_710 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda710(env_t_710* env703, number_t i) {
	array_array_number_t vertex_positions702 = env703->vertex_positions;
	array_array_number_t points701 = env703->points;
	index_t n_corr700 = env703->n_corr;
	array_number_t correspondences699 = env703->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr700);
	index_t c = (ind) % (n_corr700);
	value_t res;
	res.number_t_value = (points701->arr[r]->arr[c]) - (vertex_positions702->arr[r]->arr[(int)(correspondences699->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, card_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_710 env_t_710_value = make_env_t_710(vertex_positions,points,n_corr,correspondences); closure_t closure705 = make_closure(lambda710, &env_t_710_value);
	array_number_t err = linalg_vectorMap(closure705, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_786;


value_t lambda786(env_t_786* env747, number_t r) {
	
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
	array_number_t array775 = (array_number_t)malloc(sizeof(int) * 2);
	array775->length=3;
	array775->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array775->arr[0] = 1;
	array775->arr[1] = 2;
	array775->arr[2] = 3;;
	array_number_t array776 = (array_number_t)malloc(sizeof(int) * 2);
	array776->length=3;
	array776->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array776->arr[0] = 4;
	array776->arr[1] = 5;
	array776->arr[2] = 6;;
	array_number_t array777 = (array_number_t)malloc(sizeof(int) * 2);
	array777->length=3;
	array777->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array777->arr[0] = 7;
	array777->arr[1] = 8;
	array777->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array775;
	mat1->arr[1] = array776;
	mat1->arr[2] = array777;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	env_t_786 env_t_786_value = make_empty_env(); closure_t closure749 = make_closure(lambda786, &env_t_786_value);
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure749, linalg_vectorRange(1, 4));
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
