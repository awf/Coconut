#ifndef __USECASES_BA_1_H__ 
#define __USECASES_BA_1_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"
typedef struct env_t_420 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_420;
env_t_420 make_env_t_420(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_420 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}
typedef empty_env_t env_t_421;


value_t lambda421(env_t_421* env308, number_t x3, number_t y0) {
	
	value_t res;
	res.number_t_value = (x3) - (y0);
	return res;
}
typedef empty_env_t env_t_422;


value_t lambda422(env_t_422* env313, number_t x10) {
	
	value_t res;
	res.number_t_value = (x10) * (x10);
	return res;
}
typedef struct env_t_423 {
	number_t y;
} env_t_423;
env_t_423 make_env_t_423(number_t y) {
	env_t_423 env;
	env.y = y;
	return env;
}

value_t lambda423(env_t_423* env320, number_t a) {
	number_t y319 = env320->y;
	value_t res;
	res.number_t_value = (a) * (y319);
	return res;
}
typedef empty_env_t env_t_424;


value_t lambda424(env_t_424* env325, number_t x4, number_t y00) {
	
	value_t res;
	res.number_t_value = (x4) * (y00);
	return res;
}
typedef struct env_t_425 {
	number_t y;
} env_t_425;
env_t_425 make_env_t_425(number_t y) {
	env_t_425 env;
	env.y = y;
	return env;
}

value_t lambda425(env_t_425* env332, number_t a0) {
	number_t y331 = env332->y;
	value_t res;
	res.number_t_value = (a0) * (y331);
	return res;
}
typedef struct env_t_426 {
	number_t y;
} env_t_426;
env_t_426 make_env_t_426(number_t y) {
	env_t_426 env;
	env.y = y;
	return env;
}

value_t lambda426(env_t_426* env338, number_t a0) {
	number_t y337 = env338->y;
	value_t res;
	res.number_t_value = (a0) * (y337);
	return res;
}
typedef empty_env_t env_t_427;


value_t lambda427(env_t_427* env343, number_t x4, number_t y00) {
	
	value_t res;
	res.number_t_value = (x4) + (y00);
	return res;
}
typedef struct env_t_428 {
	number_t y;
} env_t_428;
env_t_428 make_env_t_428(number_t y) {
	env_t_428 env;
	env.y = y;
	return env;
}

value_t lambda428(env_t_428* env349, number_t a0) {
	number_t y348 = env349->y;
	value_t res;
	res.number_t_value = (a0) * (y348);
	return res;
}
typedef empty_env_t env_t_429;


value_t lambda429(env_t_429* env354, number_t x40, number_t y00) {
	
	value_t res;
	res.number_t_value = (x40) + (y00);
	return res;
}
typedef empty_env_t env_t_430;


value_t lambda430(env_t_430* env359, number_t x4, number_t y00) {
	
	value_t res;
	res.number_t_value = (x4) + (y00);
	return res;
}
typedef struct env_t_431 {
	number_t y;
} env_t_431;
env_t_431 make_env_t_431(number_t y) {
	env_t_431 env;
	env.y = y;
	return env;
}

value_t lambda431(env_t_431* env367, number_t a) {
	number_t y366 = env367->y;
	value_t res;
	res.number_t_value = (a) * (y366);
	return res;
}
typedef empty_env_t env_t_432;


value_t lambda432(env_t_432* env372, number_t x10) {
	
	value_t res;
	res.number_t_value = (x10) * (x10);
	return res;
}
typedef struct env_t_433 {
	number_t y;
} env_t_433;
env_t_433 make_env_t_433(number_t y) {
	env_t_433 env;
	env.y = y;
	return env;
}

value_t lambda433(env_t_433* env379, number_t a) {
	number_t y378 = env379->y;
	value_t res;
	res.number_t_value = (a) * (y378);
	return res;
}
typedef struct env_t_434 {
	number_t y;
} env_t_434;
env_t_434 make_env_t_434(number_t y) {
	env_t_434 env;
	env.y = y;
	return env;
}

value_t lambda434(env_t_434* env386, number_t a) {
	number_t y385 = env386->y;
	value_t res;
	res.number_t_value = (a) * (y385);
	return res;
}
typedef empty_env_t env_t_435;


value_t lambda435(env_t_435* env391, number_t x31, number_t y00) {
	
	value_t res;
	res.number_t_value = (x31) + (y00);
	return res;
}
typedef empty_env_t env_t_436;


value_t lambda436(env_t_436* env396, number_t x25, number_t y00) {
	
	value_t res;
	res.number_t_value = (x25) - (y00);
	return res;
}
typedef struct env_t_437 {
	number_t y;
} env_t_437;
env_t_437 make_env_t_437(number_t y) {
	env_t_437 env;
	env.y = y;
	return env;
}

value_t lambda437(env_t_437* env402, number_t a) {
	number_t y401 = env402->y;
	value_t res;
	res.number_t_value = (a) * (y401);
	return res;
}
value_t lambda420(env_t_420* env412, number_t i) {
	array_array_number_t x411 = env412->x;
	array_number_t w410 = env412->w;
	array_array_number_t obs409 = env412->obs;
	array_array_number_t feat408 = env412->feat;
	array_array_number_t cams407 = env412->cams;
	array_number_t cam = cams407->arr[(int)(obs409->arr[(int)(i)]->arr[0])];
	array_number_t x0 = x411->arr[(int)(obs409->arr[(int)(i)]->arr[1])];
	number_t w0 = w410->arr[(int)(i)];
	array_number_t feat0 = feat408->arr[(int)(i)];
	array_number_t cam0 = cam;
	array_number_t x1 = x0;
	index_t N_CAM_PARAMS = 11;
	index_t ROT_IDX = 0;
	index_t CENTER_IDX = 3;
	index_t FOCAL_IDX = 6;
	index_t X0_IDX = 7;
	index_t RAD_IDX = 9;
	array_number_t macroDef306 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef306->length=(((ROT_IDX) + (2)) - (ROT_IDX)) + (1);
	macroDef306->arr = (number_t*)storage_alloc(sizeof(number_t) * (((ROT_IDX) + (2)) - (ROT_IDX)) + (1));
		for(int i0 = 0; i0 < macroDef306->length; i0++){
			
			macroDef306->arr[i0] = cam0->arr[(i0) + (ROT_IDX)];;
		}
	array_number_t rot = macroDef306;
	array_number_t x2 = x1;
	array_number_t macroDef307 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef307->length=(((CENTER_IDX) + (2)) - (CENTER_IDX)) + (1);
	macroDef307->arr = (number_t*)storage_alloc(sizeof(number_t) * (((CENTER_IDX) + (2)) - (CENTER_IDX)) + (1));
		for(int i0 = 0; i0 < macroDef307->length; i0++){
			
			macroDef307->arr[i0] = cam0->arr[(i0) + (CENTER_IDX)];;
		}
	array_number_t y = macroDef307;
	env_t_421 env_t_421_value = make_empty_env(); closure_t closure310 = make_closure(lambda421, &env_t_421_value);
	closure_t f = closure310;
	array_number_t v1 = x2;
	array_number_t v2 = y;
	card_t macroDef311 = v1->length;
	array_number_t macroDef312 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef312->length=macroDef311;
	macroDef312->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef311);
		for(int i0 = 0; i0 < macroDef312->length; i0++){
			
			macroDef312->arr[i0] = f.lam(f.env, v1->arr[i0], v2->arr[i0]).number_t_value;;
		}
	array_number_t x20 = macroDef312;
	array_number_t x3 = rot;
	env_t_422 env_t_422_value = make_empty_env(); closure_t closure315 = make_closure(lambda422, &env_t_422_value);
	closure_t f0 = closure315;
	array_number_t v = x3;
	card_t macroDef316 = v->length;
	array_number_t macroDef317 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef317->length=macroDef316;
	macroDef317->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef316);
		for(int i0 = 0; i0 < macroDef317->length; i0++){
			
			macroDef317->arr[i0] = f0.lam(f0.env, v->arr[i0]).number_t_value;;
		}
	array_number_t v0 = macroDef317;
	number_t macroDef318 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef318 = (macroDef318) + (cur);;
	}
	number_t sqtheta = macroDef318;
	array_number_t ite417 = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		array_number_t x30 = rot;
		number_t y0 = theta_inv;
		env_t_423 env_t_423_value = make_env_t_423(y0); closure_t closure322 = make_closure(lambda423, &env_t_423_value);
		closure_t f1 = closure322;
		array_number_t v3 = x30;
		card_t macroDef323 = v3->length;
		array_number_t macroDef324 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef324->length=macroDef323;
	macroDef324->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef323);
		for(int i0 = 0; i0 < macroDef324->length; i0++){
			
			macroDef324->arr[i0] = f1.lam(f1.env, v3->arr[i0]).number_t_value;;
		}
		array_number_t w1 = macroDef324;
		array_number_t a = w1;
		array_number_t b = x20;
		array_number_t array418 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array418->length=3;
	array418->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array418->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array418->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array418->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
		array_number_t w_cross_X = array418;
		array_number_t x31 = w1;
		array_number_t y1 = x20;
		env_t_424 env_t_424_value = make_empty_env(); closure_t closure327 = make_closure(lambda424, &env_t_424_value);
		closure_t f2 = closure327;
		array_number_t v10 = x31;
		array_number_t v20 = y1;
		card_t macroDef328 = v10->length;
		array_number_t macroDef329 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef329->length=macroDef328;
	macroDef329->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef328);
		for(int i0 = 0; i0 < macroDef329->length; i0++){
			
			macroDef329->arr[i0] = f2.lam(f2.env, v10->arr[i0], v20->arr[i0]).number_t_value;;
		}
		array_number_t v4 = macroDef329;
		number_t macroDef330 = 0;
	for(int cur_idx = 0; cur_idx < v4->length; cur_idx++){
		number_t cur = v4->arr[cur_idx];
		
		macroDef330 = (macroDef330) + (cur);;
	}
		number_t tmp = (macroDef330) * ((1) - (costheta));
		array_number_t x32 = x20;
		number_t y2 = costheta;
		env_t_425 env_t_425_value = make_env_t_425(y2); closure_t closure334 = make_closure(lambda425, &env_t_425_value);
		closure_t f3 = closure334;
		array_number_t v5 = x32;
		card_t macroDef335 = v5->length;
		array_number_t macroDef336 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef336->length=macroDef335;
	macroDef336->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef335);
		for(int i0 = 0; i0 < macroDef336->length; i0++){
			
			macroDef336->arr[i0] = f3.lam(f3.env, v5->arr[i0]).number_t_value;;
		}
		array_number_t v11 = macroDef336;
		array_number_t x33 = w_cross_X;
		number_t y3 = sintheta;
		env_t_426 env_t_426_value = make_env_t_426(y3); closure_t closure340 = make_closure(lambda426, &env_t_426_value);
		closure_t f4 = closure340;
		array_number_t v6 = x33;
		card_t macroDef341 = v6->length;
		array_number_t macroDef342 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef342->length=macroDef341;
	macroDef342->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef341);
		for(int i0 = 0; i0 < macroDef342->length; i0++){
			
			macroDef342->arr[i0] = f4.lam(f4.env, v6->arr[i0]).number_t_value;;
		}
		array_number_t v21 = macroDef342;
		array_number_t x34 = v11;
		array_number_t y4 = v21;
		env_t_427 env_t_427_value = make_empty_env(); closure_t closure345 = make_closure(lambda427, &env_t_427_value);
		closure_t f5 = closure345;
		array_number_t v100 = x34;
		array_number_t v200 = y4;
		card_t macroDef346 = v100->length;
		array_number_t macroDef347 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef347->length=macroDef346;
	macroDef347->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef346);
		for(int i0 = 0; i0 < macroDef347->length; i0++){
			
			macroDef347->arr[i0] = f5.lam(f5.env, v100->arr[i0], v200->arr[i0]).number_t_value;;
		}
		array_number_t x35 = macroDef347;
		array_number_t x4 = w1;
		number_t y5 = tmp;
		env_t_428 env_t_428_value = make_env_t_428(y5); closure_t closure351 = make_closure(lambda428, &env_t_428_value);
		closure_t f6 = closure351;
		array_number_t v7 = x4;
		card_t macroDef352 = v7->length;
		array_number_t macroDef353 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef353->length=macroDef352;
	macroDef353->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef352);
		for(int i0 = 0; i0 < macroDef353->length; i0++){
			
			macroDef353->arr[i0] = f6.lam(f6.env, v7->arr[i0]).number_t_value;;
		}
		array_number_t y6 = macroDef353;
		env_t_429 env_t_429_value = make_empty_env(); closure_t closure356 = make_closure(lambda429, &env_t_429_value);
		closure_t f7 = closure356;
		array_number_t v101 = x35;
		array_number_t v201 = y6;
		card_t macroDef357 = v101->length;
		array_number_t macroDef358 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef358->length=macroDef357;
	macroDef358->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef357);
		for(int i0 = 0; i0 < macroDef358->length; i0++){
			
			macroDef358->arr[i0] = f7.lam(f7.env, v101->arr[i0], v201->arr[i0]).number_t_value;;
		}
		ite417 = macroDef358;;
	} else {
		array_number_t x30 = x20;
		array_number_t a = rot;
		array_number_t b = x20;
		array_number_t array419 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array419->length=3;
	array419->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array419->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array419->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array419->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
		array_number_t y0 = array419;
		env_t_430 env_t_430_value = make_empty_env(); closure_t closure361 = make_closure(lambda430, &env_t_430_value);
		closure_t f1 = closure361;
		array_number_t v10 = x30;
		array_number_t v20 = y0;
		card_t macroDef362 = v10->length;
		array_number_t macroDef363 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef363->length=macroDef362;
	macroDef363->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef362);
		for(int i0 = 0; i0 < macroDef363->length; i0++){
			
			macroDef363->arr[i0] = f1.lam(f1.env, v10->arr[i0], v20->arr[i0]).number_t_value;;
		}
		ite417 = macroDef363;;
	}
	array_number_t Xcam = ite417;
	array_number_t macroDef364 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef364->length=(((RAD_IDX) + (1)) - (RAD_IDX)) + (1);
	macroDef364->arr = (number_t*)storage_alloc(sizeof(number_t) * (((RAD_IDX) + (1)) - (RAD_IDX)) + (1));
		for(int i0 = 0; i0 < macroDef364->length; i0++){
			
			macroDef364->arr[i0] = cam0->arr[(i0) + (RAD_IDX)];;
		}
	array_number_t rad_params = macroDef364;
	array_number_t macroDef365 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef365->length=((1) - (0)) + (1);
	macroDef365->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i0 = 0; i0 < macroDef365->length; i0++){
			
			macroDef365->arr[i0] = Xcam->arr[(i0) + (0)];;
		}
	array_number_t x21 = macroDef365;
	number_t y0 = (1) / (Xcam->arr[2]);
	env_t_431 env_t_431_value = make_env_t_431(y0); closure_t closure369 = make_closure(lambda431, &env_t_431_value);
	closure_t f1 = closure369;
	array_number_t v3 = x21;
	card_t macroDef370 = v3->length;
	array_number_t macroDef371 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef371->length=macroDef370;
	macroDef371->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef370);
		for(int i0 = 0; i0 < macroDef371->length; i0++){
			
			macroDef371->arr[i0] = f1.lam(f1.env, v3->arr[i0]).number_t_value;;
		}
	array_number_t proj = macroDef371;
	array_number_t x22 = proj;
	env_t_432 env_t_432_value = make_empty_env(); closure_t closure374 = make_closure(lambda432, &env_t_432_value);
	closure_t f2 = closure374;
	array_number_t v4 = x22;
	card_t macroDef375 = v4->length;
	array_number_t macroDef376 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef376->length=macroDef375;
	macroDef376->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef375);
		for(int i0 = 0; i0 < macroDef376->length; i0++){
			
			macroDef376->arr[i0] = f2.lam(f2.env, v4->arr[i0]).number_t_value;;
		}
	array_number_t v5 = macroDef376;
	number_t macroDef377 = 0;
	for(int cur_idx = 0; cur_idx < v5->length; cur_idx++){
		number_t cur = v5->arr[cur_idx];
		
		macroDef377 = (macroDef377) + (cur);;
	}
	number_t rsq = macroDef377;
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	array_number_t x23 = proj;
	number_t y1 = L;
	env_t_433 env_t_433_value = make_env_t_433(y1); closure_t closure381 = make_closure(lambda433, &env_t_433_value);
	closure_t f3 = closure381;
	array_number_t v6 = x23;
	card_t macroDef382 = v6->length;
	array_number_t macroDef383 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef383->length=macroDef382;
	macroDef383->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef382);
		for(int i0 = 0; i0 < macroDef383->length; i0++){
			
			macroDef383->arr[i0] = f3.lam(f3.env, v6->arr[i0]).number_t_value;;
		}
	array_number_t distorted = macroDef383;
	array_number_t macroDef384 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef384->length=(((X0_IDX) + (1)) - (X0_IDX)) + (1);
	macroDef384->arr = (number_t*)storage_alloc(sizeof(number_t) * (((X0_IDX) + (1)) - (X0_IDX)) + (1));
		for(int i0 = 0; i0 < macroDef384->length; i0++){
			
			macroDef384->arr[i0] = cam0->arr[(i0) + (X0_IDX)];;
		}
	array_number_t x24 = macroDef384;
	array_number_t x30 = distorted;
	number_t y2 = cam0->arr[FOCAL_IDX];
	env_t_434 env_t_434_value = make_env_t_434(y2); closure_t closure388 = make_closure(lambda434, &env_t_434_value);
	closure_t f4 = closure388;
	array_number_t v7 = x30;
	card_t macroDef389 = v7->length;
	array_number_t macroDef390 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef390->length=macroDef389;
	macroDef390->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef389);
		for(int i0 = 0; i0 < macroDef390->length; i0++){
			
			macroDef390->arr[i0] = f4.lam(f4.env, v7->arr[i0]).number_t_value;;
		}
	array_number_t y3 = macroDef390;
	env_t_435 env_t_435_value = make_empty_env(); closure_t closure393 = make_closure(lambda435, &env_t_435_value);
	closure_t f5 = closure393;
	array_number_t v10 = x24;
	array_number_t v20 = y3;
	card_t macroDef394 = v10->length;
	array_number_t macroDef395 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef395->length=macroDef394;
	macroDef395->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef394);
		for(int i0 = 0; i0 < macroDef395->length; i0++){
			
			macroDef395->arr[i0] = f5.lam(f5.env, v10->arr[i0], v20->arr[i0]).number_t_value;;
		}
	array_number_t x10 = macroDef395;
	array_number_t y4 = feat0;
	env_t_436 env_t_436_value = make_empty_env(); closure_t closure398 = make_closure(lambda436, &env_t_436_value);
	closure_t f6 = closure398;
	array_number_t v11 = x10;
	array_number_t v21 = y4;
	card_t macroDef399 = v11->length;
	array_number_t macroDef400 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef400->length=macroDef399;
	macroDef400->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef399);
		for(int i0 = 0; i0 < macroDef400->length; i0++){
			
			macroDef400->arr[i0] = f6.lam(f6.env, v11->arr[i0], v21->arr[i0]).number_t_value;;
		}
	array_number_t x11 = macroDef400;
	number_t y5 = w0;
	env_t_437 env_t_437_value = make_env_t_437(y5); closure_t closure404 = make_closure(lambda437, &env_t_437_value);
	closure_t f7 = closure404;
	array_number_t v8 = x11;
	card_t macroDef405 = v8->length;
	array_number_t macroDef406 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef406->length=macroDef405;
	macroDef406->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef405);
		for(int i0 = 0; i0 < macroDef406->length; i0++){
			
			macroDef406->arr[i0] = f7.lam(f7.env, v8->arr[i0]).number_t_value;;
		}
	value_t res;
	res.array_number_t_value = macroDef406;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_1(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef303 = cams->length;
	card_t n = macroDef303;
	card_t macroDef304 = w->length;
	card_t p = macroDef304;
	card_t s = 0;
	card_t e = (p) - (1);
	array_number_t macroDef305 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef305->length=((e) - (s)) + (1);
	macroDef305->arr = (number_t*)storage_alloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef305->length; i++){
			
			macroDef305->arr[i] = (double)(((s)) + (i));;
		}
	array_number_t range = macroDef305;
	env_t_420 env_t_420_value = make_env_t_420(x,w,obs,feat,cams); closure_t closure414 = make_closure(lambda420, &env_t_420_value);
	closure_t f = closure414;
	array_number_t arr = range;
	card_t macroDef415 = arr->length;
	array_array_number_t macroDef416 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef416->length=macroDef415;
	macroDef416->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef415);
		for(int i = 0; i < macroDef416->length; i++){
			
			macroDef416->arr[i] = f.lam(f.env, arr->arr[i]).array_number_t_value;;
		}
	return macroDef416;
}
#endif
