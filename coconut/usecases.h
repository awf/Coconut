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
	array_number_t ite259 = 0;
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
		ite259 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite259 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite259;
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
typedef empty_env_t env_t_288;


value_t lambda288(env_t_288* env284, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	env_t_288 env_t_288_value = make_empty_env(); closure_t closure286 = make_closure(lambda288, &env_t_288_value);
	return linalg_vectorMap(closure286, w);
}
typedef struct env_t_315 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_315;
env_t_315 make_env_t_315(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_315 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda315(env_t_315* env311, number_t i) {
	array_array_number_t x310 = env311->x;
	array_number_t w309 = env311->w;
	array_array_number_t obs308 = env311->obs;
	array_array_number_t feat307 = env311->feat;
	array_array_number_t cams306 = env311->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams306->arr[(int)(obs308->arr[(int)(i)]->arr[0])], x310->arr[(int)(obs308->arr[(int)(i)]->arr[1])], w309->arr[(int)(i)], feat307->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	env_t_315 env_t_315_value = make_env_t_315(x,w,obs,feat,cams); closure_t closure313 = make_closure(lambda315, &env_t_315_value);
	return linalg_vectorMapToMatrix(closure313, range);
}
typedef struct env_t_370 {
	array_number_t one_cam;
} env_t_370;
env_t_370 make_env_t_370(array_number_t one_cam) {
	env_t_370 env;
	env.one_cam = one_cam;
	return env;
}

value_t lambda370(env_t_370* env325, number_t x) {
	array_number_t one_cam324 = env325->one_cam;
	value_t res;
	res.array_number_t_value = one_cam324;
	return res;
}
typedef struct env_t_371 {
	array_number_t one_x;
} env_t_371;
env_t_371 make_env_t_371(array_number_t one_x) {
	env_t_371 env;
	env.one_x = one_x;
	return env;
}

value_t lambda371(env_t_371* env332, number_t x) {
	array_number_t one_x331 = env332->one_x;
	value_t res;
	res.array_number_t_value = one_x331;
	return res;
}
typedef struct env_t_372 {
	number_t one_w;
} env_t_372;
env_t_372 make_env_t_372(number_t one_w) {
	env_t_372 env;
	env.one_w = one_w;
	return env;
}

value_t lambda372(env_t_372* env339, number_t x) {
	number_t one_w338 = env339->one_w;
	value_t res;
	res.number_t_value = one_w338;
	return res;
}
typedef struct env_t_373 {
	array_number_t one_feat;
} env_t_373;
env_t_373 make_env_t_373(array_number_t one_feat) {
	env_t_373 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda373(env_t_373* env346, number_t x) {
	array_number_t one_feat345 = env346->one_feat;
	value_t res;
	res.array_number_t_value = one_feat345;
	return res;
}
typedef struct env_t_374 {
	index_t n;
	index_t m;
} env_t_374;
env_t_374 make_env_t_374(index_t n,index_t m) {
	env_t_374 env;
	env.n = n;
	env.m = m;
	return env;
}

value_t lambda374(env_t_374* env359, number_t x) {
	index_t n358 = env359->n;
	index_t m357 = env359->m;
	array_number_t array368 = (array_number_t)malloc(sizeof(int) * 2);
	array368->length=2;
	array368->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array368->arr[0] = (double)(((int)(x)) % (n358));
	array368->arr[1] = (double)(((int)(x)) % (m357));;
	value_t res;
	res.array_number_t_value = array368;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	env_t_370 env_t_370_value = make_env_t_370(one_cam); closure_t closure327 = make_closure(lambda370, &env_t_370_value);
	array_array_number_t cam = linalg_vectorMapToMatrix(closure327, linalg_vectorRange(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	env_t_371 env_t_371_value = make_env_t_371(one_x); closure_t closure334 = make_closure(lambda371, &env_t_371_value);
	array_array_number_t x = linalg_vectorMapToMatrix(closure334, linalg_vectorRange(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	env_t_372 env_t_372_value = make_env_t_372(one_w); closure_t closure341 = make_closure(lambda372, &env_t_372_value);
	array_number_t w = linalg_vectorMap(closure341, linalg_vectorRange(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	env_t_373 env_t_373_value = make_env_t_373(one_feat); closure_t closure348 = make_closure(lambda373, &env_t_373_value);
	array_array_number_t feat = linalg_vectorMapToMatrix(closure348, linalg_vectorRange(1, p));
	env_t_374 env_t_374_value = make_env_t_374(n,m); closure_t closure361 = make_closure(lambda374, &env_t_374_value);
	array_array_number_t obs = linalg_vectorMapToMatrix(closure361, linalg_vectorRange(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_386 {
	number_t mx;
} env_t_386;
env_t_386 make_env_t_386(number_t mx) {
	env_t_386 env;
	env.mx = mx;
	return env;
}

value_t lambda386(env_t_386* env379, number_t x) {
	number_t mx378 = env379->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx378));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = linalg_arrayMax(arr);
	env_t_386 env_t_386_value = make_env_t_386(mx); closure_t closure381 = make_closure(lambda386, &env_t_386_value);
	number_t semx = linalg_arraySum(linalg_vectorMap(closure381, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_406 {
	number_t a;
} env_t_406;
env_t_406 make_env_t_406(number_t a) {
	env_t_406 env;
	env.a = a;
	return env;
}

value_t lambda406(env_t_406* env398, number_t j) {
	number_t a397 = env398->a;
	value_t res;
	res.number_t_value = gamma_ln((a397) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	env_t_406 env_t_406_value = make_env_t_406(a); closure_t closure400 = make_closure(lambda406, &env_t_406_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (linalg_arraySum(linalg_vectorMap(closure400, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array407 = (array_number_t)malloc(sizeof(int) * 2);
	array407->length=3;
	array407->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array407->arr[0] = 0;
	array407->arr[1] = 0;
	array407->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array407;;
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
	array_number_t array454 = (array_number_t)malloc(sizeof(int) * 2);
	array454->length=3;
	array454->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array454->arr[0] = theta->arr[i1];
	array454->arr[1] = theta->arr[(i1) + (1)];
	array454->arr[2] = 0;;
	array_number_t array455 = (array_number_t)malloc(sizeof(int) * 2);
	array455->length=3;
	array455->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array455->arr[0] = theta->arr[(i1) + (2)];
	array455->arr[1] = 0;
	array455->arr[2] = 0;;
	array_number_t array456 = (array_number_t)malloc(sizeof(int) * 2);
	array456->length=3;
	array456->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array456->arr[0] = theta->arr[(i1) + (3)];
	array456->arr[1] = 0;
	array456->arr[2] = 0;;
	array_number_t array457 = (array_number_t)malloc(sizeof(int) * 2);
	array457->length=3;
	array457->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array457->arr[0] = 0;
	array457->arr[1] = 0;
	array457->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array454;
	finger1->arr[1] = array455;
	finger1->arr[2] = array456;
	finger1->arr[3] = array457;;
	index_t i2 = (i1) + (4);
	array_number_t array458 = (array_number_t)malloc(sizeof(int) * 2);
	array458->length=3;
	array458->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array458->arr[0] = theta->arr[i2];
	array458->arr[1] = theta->arr[(i2) + (1)];
	array458->arr[2] = 0;;
	array_number_t array459 = (array_number_t)malloc(sizeof(int) * 2);
	array459->length=3;
	array459->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array459->arr[0] = theta->arr[(i2) + (2)];
	array459->arr[1] = 0;
	array459->arr[2] = 0;;
	array_number_t array460 = (array_number_t)malloc(sizeof(int) * 2);
	array460->length=3;
	array460->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array460->arr[0] = theta->arr[(i2) + (3)];
	array460->arr[1] = 0;
	array460->arr[2] = 0;;
	array_number_t array461 = (array_number_t)malloc(sizeof(int) * 2);
	array461->length=3;
	array461->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array461->arr[0] = 0;
	array461->arr[1] = 0;
	array461->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array458;
	finger2->arr[1] = array459;
	finger2->arr[2] = array460;
	finger2->arr[3] = array461;;
	index_t i3 = (i2) + (4);
	array_number_t array462 = (array_number_t)malloc(sizeof(int) * 2);
	array462->length=3;
	array462->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array462->arr[0] = theta->arr[i3];
	array462->arr[1] = theta->arr[(i3) + (1)];
	array462->arr[2] = 0;;
	array_number_t array463 = (array_number_t)malloc(sizeof(int) * 2);
	array463->length=3;
	array463->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array463->arr[0] = theta->arr[(i3) + (2)];
	array463->arr[1] = 0;
	array463->arr[2] = 0;;
	array_number_t array464 = (array_number_t)malloc(sizeof(int) * 2);
	array464->length=3;
	array464->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array464->arr[0] = theta->arr[(i3) + (3)];
	array464->arr[1] = 0;
	array464->arr[2] = 0;;
	array_number_t array465 = (array_number_t)malloc(sizeof(int) * 2);
	array465->length=3;
	array465->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array465->arr[0] = 0;
	array465->arr[1] = 0;
	array465->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array462;
	finger3->arr[1] = array463;
	finger3->arr[2] = array464;
	finger3->arr[3] = array465;;
	index_t i4 = (i3) + (4);
	array_number_t array466 = (array_number_t)malloc(sizeof(int) * 2);
	array466->length=3;
	array466->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array466->arr[0] = theta->arr[i4];
	array466->arr[1] = theta->arr[(i4) + (1)];
	array466->arr[2] = 0;;
	array_number_t array467 = (array_number_t)malloc(sizeof(int) * 2);
	array467->length=3;
	array467->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array467->arr[0] = theta->arr[(i4) + (2)];
	array467->arr[1] = 0;
	array467->arr[2] = 0;;
	array_number_t array468 = (array_number_t)malloc(sizeof(int) * 2);
	array468->length=3;
	array468->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array468->arr[0] = theta->arr[(i4) + (3)];
	array468->arr[1] = 0;
	array468->arr[2] = 0;;
	array_number_t array469 = (array_number_t)malloc(sizeof(int) * 2);
	array469->length=3;
	array469->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array469->arr[0] = 0;
	array469->arr[1] = 0;
	array469->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array466;
	finger4->arr[1] = array467;
	finger4->arr[2] = array468;
	finger4->arr[3] = array469;;
	index_t i5 = (i4) + (4);
	array_number_t array470 = (array_number_t)malloc(sizeof(int) * 2);
	array470->length=3;
	array470->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array470->arr[0] = theta->arr[i5];
	array470->arr[1] = theta->arr[(i5) + (1)];
	array470->arr[2] = 0;;
	array_number_t array471 = (array_number_t)malloc(sizeof(int) * 2);
	array471->length=3;
	array471->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array471->arr[0] = theta->arr[(i5) + (2)];
	array471->arr[1] = 0;
	array471->arr[2] = 0;;
	array_number_t array472 = (array_number_t)malloc(sizeof(int) * 2);
	array472->length=3;
	array472->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array472->arr[0] = theta->arr[(i5) + (3)];
	array472->arr[1] = 0;
	array472->arr[2] = 0;;
	array_number_t array473 = (array_number_t)malloc(sizeof(int) * 2);
	array473->length=3;
	array473->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array473->arr[0] = 0;
	array473->arr[1] = 0;
	array473->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array470;
	finger5->arr[1] = array471;
	finger5->arr[2] = array472;
	finger5->arr[3] = array473;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array494 = (array_number_t)malloc(sizeof(int) * 2);
	array494->length=3;
	array494->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array494->arr[0] = 1;
	array494->arr[1] = 0;
	array494->arr[2] = 0;;
	array_number_t array495 = (array_number_t)malloc(sizeof(int) * 2);
	array495->length=3;
	array495->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array495->arr[0] = 0;
	array495->arr[1] = cos(tx);
	array495->arr[2] = -(sin(tx));;
	array_number_t array496 = (array_number_t)malloc(sizeof(int) * 2);
	array496->length=3;
	array496->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array496->arr[0] = 0;
	array496->arr[1] = sin(tx);
	array496->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array494;
	Rx->arr[1] = array495;
	Rx->arr[2] = array496;;
	array_number_t array497 = (array_number_t)malloc(sizeof(int) * 2);
	array497->length=3;
	array497->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array497->arr[0] = cos(ty);
	array497->arr[1] = 0;
	array497->arr[2] = sin(ty);;
	array_number_t array498 = (array_number_t)malloc(sizeof(int) * 2);
	array498->length=3;
	array498->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array498->arr[0] = 0;
	array498->arr[1] = 1;
	array498->arr[2] = 0;;
	array_number_t array499 = (array_number_t)malloc(sizeof(int) * 2);
	array499->length=3;
	array499->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array499->arr[0] = -(sin(ty));
	array499->arr[1] = 0;
	array499->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array497;
	Ry->arr[1] = array498;
	Ry->arr[2] = array499;;
	array_number_t array500 = (array_number_t)malloc(sizeof(int) * 2);
	array500->length=3;
	array500->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array500->arr[0] = cos(tz);
	array500->arr[1] = -(sin(tz));
	array500->arr[2] = 0;;
	array_number_t array501 = (array_number_t)malloc(sizeof(int) * 2);
	array501->length=3;
	array501->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array501->arr[0] = sin(tz);
	array501->arr[1] = cos(tz);
	array501->arr[2] = 0;;
	array_number_t array502 = (array_number_t)malloc(sizeof(int) * 2);
	array502->length=3;
	array502->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array502->arr[0] = 0;
	array502->arr[1] = 0;
	array502->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array500;
	Rz->arr[1] = array501;
	Rz->arr[2] = array502;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array507 = (array_number_t)malloc(sizeof(int) * 2);
	array507->length=1;
	array507->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array507->arr[0] = 0;;
	array_number_t array508 = (array_number_t)malloc(sizeof(int) * 2);
	array508->length=1;
	array508->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array508->arr[0] = 0;;
	array_number_t array509 = (array_number_t)malloc(sizeof(int) * 2);
	array509->length=1;
	array509->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array509->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array507;
	r1->arr[1] = array508;
	r1->arr[2] = array509;;
	array_number_t array510 = (array_number_t)malloc(sizeof(int) * 2);
	array510->length=4;
	array510->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array510->arr[0] = 0;
	array510->arr[1] = 0;
	array510->arr[2] = 0;
	array510->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array510;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_526 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_526;
env_t_526 make_env_t_526(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_526 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda526(env_t_526* env520, number_t i_bone) {
	array_array_number_t pose_params519 = env520->pose_params;
	index_t offset518 = env520->offset;
	array_array_array_number_t base_relatives517 = env520->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params519->arr[((int)(i_bone)) + (offset518)], base_relatives517->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_526 env_t_526_value = make_env_t_526(pose_params,offset,base_relatives); closure_t closure522 = make_closure(lambda526, &env_t_526_value);
	return linalg_vectorMapToMatrix3D(closure522, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite583 = 0;
	if((n) < (0.0001)) {
		array_number_t array585 = (array_number_t)malloc(sizeof(int) * 2);
	array585->length=3;
	array585->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array585->arr[0] = 1;
	array585->arr[1] = 0;
	array585->arr[2] = 0;;
		array_number_t array586 = (array_number_t)malloc(sizeof(int) * 2);
	array586->length=3;
	array586->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array586->arr[0] = 0;
	array586->arr[1] = 1;
	array586->arr[2] = 0;;
		array_number_t array587 = (array_number_t)malloc(sizeof(int) * 2);
	array587->length=3;
	array587->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array587->arr[0] = 0;
	array587->arr[1] = 0;
	array587->arr[2] = 1;;
		array_array_number_t array584 = (array_array_number_t)malloc(sizeof(int) * 2);
	array584->length=3;
	array584->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array584->arr[0] = array585;
	array584->arr[1] = array586;
	array584->arr[2] = array587;;
		ite583 = array584;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array589 = (array_number_t)malloc(sizeof(int) * 2);
	array589->length=3;
	array589->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array589->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array589->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array589->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array590 = (array_number_t)malloc(sizeof(int) * 2);
	array590->length=3;
	array590->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array590->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array590->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array590->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array591 = (array_number_t)malloc(sizeof(int) * 2);
	array591->length=3;
	array591->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array591->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array591->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array591->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array588 = (array_array_number_t)malloc(sizeof(int) * 2);
	array588->length=3;
	array588->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array588->arr[0] = array589;
	array588->arr[1] = array590;
	array588->arr[2] = array591;;
		ite583 = array588;
	}
	return ite583;
}
typedef struct env_t_612 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_612;
env_t_612 make_env_t_612(array_array_array_number_t relatives,array_number_t parents) {
	env_t_612 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda612(env_t_612* env604, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives603 = env604->relatives;
	array_number_t parents602 = env604->parents;
	array_array_array_number_t ite611 = 0;
	if((parents602->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives603->arr[i];;
		ite611 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents602->arr[i])], relatives603->arr[i]);;
		ite611 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite611;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array610 = (array_number_t)malloc(sizeof(int) * 2);
	array610->length=0;
	array610->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array609 = (array_array_number_t)malloc(sizeof(int) * 2);
	array609->length=1;
	array609->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array609->arr[0] = array610;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array609;;
	env_t_612 env_t_612_value = make_env_t_612(relatives,parents); closure_t closure606 = make_closure(lambda612, &env_t_612_value);
	return linalg_iterateMatrix3D(closure606, init, 0, (relatives->length) - (1));
}
typedef struct env_t_635 {
	array_number_t scale;
} env_t_635;
env_t_635 make_env_t_635(array_number_t scale) {
	env_t_635 env;
	env.scale = scale;
	return env;
}

value_t lambda635(env_t_635* env618, array_number_t row) {
	array_number_t scale617 = env618->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale617);
	return res;
}
typedef empty_env_t env_t_636;


value_t lambda636(env_t_636* env625, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_635 env_t_635_value = make_env_t_635(scale); closure_t closure620 = make_closure(lambda635, &env_t_635_value);
	array_array_number_t R1 = linalg_matrixMap(closure620, R);
	array_array_number_t array633 = (array_array_number_t)malloc(sizeof(int) * 2);
	array633->length=1;
	array633->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array633->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array633));
	env_t_636 env_t_636_value = make_empty_env(); closure_t closure627 = make_closure(lambda636, &env_t_636_value);
	array_number_t ones = linalg_vectorMap(closure627, linalg_vectorRange(1, positions->arr[0]->length));
	array_array_number_t array634 = (array_array_number_t)malloc(sizeof(int) * 2);
	array634->length=1;
	array634->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array634->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array634);
	return matrix_mult(T, positions_homog);
}
typedef empty_env_t env_t_667;


value_t lambda667(env_t_667* env640, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_668 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_668;
env_t_668 make_env_t_668(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_668 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda668(env_t_668* env656, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights655 = env656->weights;
	array_array_array_number_t transforms654 = env656->transforms;
	array_array_number_t base_positions653 = env656->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms654->arr[i_transform], 0, 2), base_positions653);
	array_array_number_t w = linalg_matrixFillFromVector(base_positions653->length, weights655->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	env_t_667 env_t_667_value = make_empty_env(); closure_t closure642 = make_closure(lambda667, &env_t_667_value);
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure642, absolutes, inverse_base_absolutes);
	index_t n_verts = base_positions->arr[0]->length;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	env_t_668 env_t_668_value = make_env_t_668(weights,transforms,base_positions); closure_t closure658 = make_closure(lambda668, &env_t_668_value);
	array_array_number_t positions = linalg_iterateMatrix(closure658, init_positions, 0, (transforms->length) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array664 = (array_number_t)malloc(sizeof(int) * 2);
	array664->length=3;
	array664->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array664->arr[0] = -1;
	array664->arr[1] = 0;
	array664->arr[2] = 0;;
		array_number_t array665 = (array_number_t)malloc(sizeof(int) * 2);
	array665->length=3;
	array665->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array665->arr[0] = 0;
	array665->arr[1] = 1;
	array665->arr[2] = 0;;
		array_number_t array666 = (array_number_t)malloc(sizeof(int) * 2);
	array666->length=3;
	array666->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array666->arr[0] = 0;
	array666->arr[1] = 0;
	array666->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array664;
	mirror_matrix->arr[1] = array665;
	mirror_matrix->arr[2] = array666;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_692 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_692;
env_t_692 make_env_t_692(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_692 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda692(env_t_692* env685, number_t i) {
	array_array_number_t vertex_positions684 = env685->vertex_positions;
	array_array_number_t points683 = env685->points;
	index_t n_corr682 = env685->n_corr;
	array_number_t correspondences681 = env685->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr682);
	index_t c = (ind) % (n_corr682);
	value_t res;
	res.number_t_value = (points683->arr[r]->arr[c]) - (vertex_positions684->arr[r]->arr[(int)(correspondences681->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, index_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_692 env_t_692_value = make_env_t_692(vertex_positions,points,n_corr,correspondences); closure_t closure687 = make_closure(lambda692, &env_t_692_value);
	array_number_t err = linalg_vectorMap(closure687, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_768;


value_t lambda768(env_t_768* env729, number_t r) {
	
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
	array_number_t array757 = (array_number_t)malloc(sizeof(int) * 2);
	array757->length=3;
	array757->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array757->arr[0] = 1;
	array757->arr[1] = 2;
	array757->arr[2] = 3;;
	array_number_t array758 = (array_number_t)malloc(sizeof(int) * 2);
	array758->length=3;
	array758->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array758->arr[0] = 4;
	array758->arr[1] = 5;
	array758->arr[2] = 6;;
	array_number_t array759 = (array_number_t)malloc(sizeof(int) * 2);
	array759->length=3;
	array759->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array759->arr[0] = 7;
	array759->arr[1] = 8;
	array759->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array757;
	mat1->arr[1] = array758;
	mat1->arr[2] = array759;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	env_t_768 env_t_768_value = make_empty_env(); closure_t closure731 = make_closure(lambda768, &env_t_768_value);
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure731, linalg_vectorRange(1, 4));
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
