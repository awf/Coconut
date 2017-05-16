#ifndef __USECASES_BA_2_H__ 
#define __USECASES_BA_2_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"
typedef struct env_t_552 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_552;
env_t_552 make_env_t_552(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_552 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}
typedef empty_env_t env_t_553;


value_t lambda553(env_t_553* env445, number_t x1, number_t y0) {
	
	value_t res;
	res.number_t_value = (x1) - (y0);
	return res;
}
typedef empty_env_t env_t_554;


value_t lambda554(env_t_554* env450, number_t x10) {
	
	value_t res;
	res.number_t_value = (x10) * (x10);
	return res;
}
typedef struct env_t_555 {
	number_t theta_inv;
} env_t_555;
env_t_555 make_env_t_555(number_t theta_inv) {
	env_t_555 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda555(env_t_555* env457, number_t a) {
	number_t theta_inv456 = env457->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv456);
	return res;
}
typedef empty_env_t env_t_556;


value_t lambda556(env_t_556* env462, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) * (y0);
	return res;
}
typedef struct env_t_557 {
	number_t costheta;
} env_t_557;
env_t_557 make_env_t_557(number_t costheta) {
	env_t_557 env;
	env.costheta = costheta;
	return env;
}

value_t lambda557(env_t_557* env469, number_t a) {
	number_t costheta468 = env469->costheta;
	value_t res;
	res.number_t_value = (a) * (costheta468);
	return res;
}
typedef struct env_t_558 {
	number_t sintheta;
} env_t_558;
env_t_558 make_env_t_558(number_t sintheta) {
	env_t_558 env;
	env.sintheta = sintheta;
	return env;
}

value_t lambda558(env_t_558* env475, number_t a) {
	number_t sintheta474 = env475->sintheta;
	value_t res;
	res.number_t_value = (a) * (sintheta474);
	return res;
}
typedef empty_env_t env_t_559;


value_t lambda559(env_t_559* env480, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) + (y0);
	return res;
}
typedef struct env_t_560 {
	number_t tmp;
} env_t_560;
env_t_560 make_env_t_560(number_t tmp) {
	env_t_560 env;
	env.tmp = tmp;
	return env;
}

value_t lambda560(env_t_560* env486, number_t a) {
	number_t tmp485 = env486->tmp;
	value_t res;
	res.number_t_value = (a) * (tmp485);
	return res;
}
typedef empty_env_t env_t_561;


value_t lambda561(env_t_561* env491, number_t x3, number_t y1) {
	
	value_t res;
	res.number_t_value = (x3) + (y1);
	return res;
}
typedef empty_env_t env_t_562;


value_t lambda562(env_t_562* env496, number_t x2, number_t y1) {
	
	value_t res;
	res.number_t_value = (x2) + (y1);
	return res;
}
typedef struct env_t_563 {
	number_t y0;
} env_t_563;
env_t_563 make_env_t_563(number_t y0) {
	env_t_563 env;
	env.y0 = y0;
	return env;
}

value_t lambda563(env_t_563* env504, number_t a) {
	number_t y0503 = env504->y0;
	value_t res;
	res.number_t_value = (a) * (y0503);
	return res;
}
typedef empty_env_t env_t_564;


value_t lambda564(env_t_564* env509, number_t x10) {
	
	value_t res;
	res.number_t_value = (x10) * (x10);
	return res;
}
typedef struct env_t_565 {
	number_t L;
} env_t_565;
env_t_565 make_env_t_565(number_t L) {
	env_t_565 env;
	env.L = L;
	return env;
}

value_t lambda565(env_t_565* env516, number_t a) {
	number_t L515 = env516->L;
	value_t res;
	res.number_t_value = (a) * (L515);
	return res;
}
typedef struct env_t_566 {
	number_t y1;
} env_t_566;
env_t_566 make_env_t_566(number_t y1) {
	env_t_566 env;
	env.y1 = y1;
	return env;
}

value_t lambda566(env_t_566* env523, number_t a) {
	number_t y1522 = env523->y1;
	value_t res;
	res.number_t_value = (a) * (y1522);
	return res;
}
typedef empty_env_t env_t_567;


value_t lambda567(env_t_567* env528, number_t x4, number_t y3) {
	
	value_t res;
	res.number_t_value = (x4) + (y3);
	return res;
}
typedef empty_env_t env_t_568;


value_t lambda568(env_t_568* env533, number_t x5, number_t y3) {
	
	value_t res;
	res.number_t_value = (x5) - (y3);
	return res;
}
typedef struct env_t_569 {
	number_t w0;
} env_t_569;
env_t_569 make_env_t_569(number_t w0) {
	env_t_569 env;
	env.w0 = w0;
	return env;
}

value_t lambda569(env_t_569* env539, number_t a) {
	number_t w0538 = env539->w0;
	value_t res;
	res.number_t_value = (a) * (w0538);
	return res;
}
value_t lambda552(env_t_552* env548, number_t i0) {
	array_array_number_t x547 = env548->x;
	array_number_t w546 = env548->w;
	array_array_number_t obs545 = env548->obs;
	array_array_number_t feat544 = env548->feat;
	array_array_number_t cams543 = env548->cams;
	array_number_t cam = cams543->arr[(int)(obs545->arr[(int)(i0)]->arr[0])];
	array_number_t x0 = x547->arr[(int)(obs545->arr[(int)(i0)]->arr[1])];
	number_t w0 = w546->arr[(int)(i0)];
	array_number_t feat0 = feat544->arr[(int)(i0)];
	array_number_t macroDef442 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef442->length=(((0) + (2)) - (0)) + (1);
	macroDef442->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef442->length; i1++){
			
			macroDef442->arr[i1] = cam->arr[(i1) + (0)];;
		}
	array_number_t rot = macroDef442;
	array_number_t macroDef443 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef443->length=(((3) + (2)) - (3)) + (1);
	macroDef443->arr = (number_t*)storage_alloc(sizeof(number_t) * (((3) + (2)) - (3)) + (1));
		for(int i1 = 0; i1 < macroDef443->length; i1++){
			
			macroDef443->arr[i1] = cam->arr[(i1) + (3)];;
		}
	array_number_t y = macroDef443;
	card_t macroDef444 = x0->length;
	array_number_t macroDef448 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef448->length=macroDef444;
	macroDef448->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef444);
		for(int i1 = 0; i1 < macroDef448->length; i1++){
			env_t_553 env_t_553_value = make_empty_env(); closure_t closure447 = make_closure(lambda553, &env_t_553_value);
			macroDef448->arr[i1] = closure447.lam(closure447.env, x0->arr[i1], y->arr[i1]).number_t_value;;
		}
	array_number_t x1 = macroDef448;
	card_t macroDef449 = rot->length;
	array_number_t macroDef453 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef453->length=macroDef449;
	macroDef453->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef449);
		for(int i1 = 0; i1 < macroDef453->length; i1++){
			env_t_554 env_t_554_value = make_empty_env(); closure_t closure452 = make_closure(lambda554, &env_t_554_value);
			macroDef453->arr[i1] = closure452.lam(closure452.env, rot->arr[i1]).number_t_value;;
		}
	array_number_t v = macroDef453;
	number_t macroDef454 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef454 = (macroDef454) + (cur);;
	}
	number_t sqtheta = macroDef454;
	array_number_t Xcam = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		card_t macroDef455 = rot->length;
		array_number_t macroDef460 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef460->length=macroDef455;
	macroDef460->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef455);
		for(int i1 = 0; i1 < macroDef460->length; i1++){
			env_t_555 env_t_555_value = make_env_t_555(theta_inv); closure_t closure459 = make_closure(lambda555, &env_t_555_value);
			macroDef460->arr[i1] = closure459.lam(closure459.env, rot->arr[i1]).number_t_value;;
		}
		array_number_t w1 = macroDef460;
		array_number_t w_cross_X = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X->length=3;
	w_cross_X->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X->arr[0] = ((w1->arr[1]) * (x1->arr[2])) - ((w1->arr[2]) * (x1->arr[1]));
	w_cross_X->arr[1] = ((w1->arr[2]) * (x1->arr[0])) - ((w1->arr[0]) * (x1->arr[2]));
	w_cross_X->arr[2] = ((w1->arr[0]) * (x1->arr[1])) - ((w1->arr[1]) * (x1->arr[0]));;
		card_t macroDef461 = w1->length;
		array_number_t macroDef465 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef465->length=macroDef461;
	macroDef465->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef461);
		for(int i1 = 0; i1 < macroDef465->length; i1++){
			env_t_556 env_t_556_value = make_empty_env(); closure_t closure464 = make_closure(lambda556, &env_t_556_value);
			macroDef465->arr[i1] = closure464.lam(closure464.env, w1->arr[i1], x1->arr[i1]).number_t_value;;
		}
		array_number_t v0 = macroDef465;
		number_t macroDef466 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef466 = (macroDef466) + (cur);;
	}
		number_t tmp = (macroDef466) * ((1) - (costheta));
		card_t macroDef467 = x1->length;
		array_number_t macroDef472 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef472->length=macroDef467;
	macroDef472->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef467);
		for(int i1 = 0; i1 < macroDef472->length; i1++){
			env_t_557 env_t_557_value = make_env_t_557(costheta); closure_t closure471 = make_closure(lambda557, &env_t_557_value);
			macroDef472->arr[i1] = closure471.lam(closure471.env, x1->arr[i1]).number_t_value;;
		}
		array_number_t v1 = macroDef472;
		card_t macroDef473 = w_cross_X->length;
		array_number_t macroDef478 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef478->length=macroDef473;
	macroDef478->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef473);
		for(int i1 = 0; i1 < macroDef478->length; i1++){
			env_t_558 env_t_558_value = make_env_t_558(sintheta); closure_t closure477 = make_closure(lambda558, &env_t_558_value);
			macroDef478->arr[i1] = closure477.lam(closure477.env, w_cross_X->arr[i1]).number_t_value;;
		}
		array_number_t v2 = macroDef478;
		card_t macroDef479 = v1->length;
		array_number_t macroDef483 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef483->length=macroDef479;
	macroDef483->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef479);
		for(int i1 = 0; i1 < macroDef483->length; i1++){
			env_t_559 env_t_559_value = make_empty_env(); closure_t closure482 = make_closure(lambda559, &env_t_559_value);
			macroDef483->arr[i1] = closure482.lam(closure482.env, v1->arr[i1], v2->arr[i1]).number_t_value;;
		}
		array_number_t x2 = macroDef483;
		card_t macroDef484 = w1->length;
		array_number_t macroDef489 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef489->length=macroDef484;
	macroDef489->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef484);
		for(int i1 = 0; i1 < macroDef489->length; i1++){
			env_t_560 env_t_560_value = make_env_t_560(tmp); closure_t closure488 = make_closure(lambda560, &env_t_560_value);
			macroDef489->arr[i1] = closure488.lam(closure488.env, w1->arr[i1]).number_t_value;;
		}
		array_number_t y0 = macroDef489;
		card_t macroDef490 = x2->length;
		array_number_t macroDef494 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef494->length=macroDef490;
	macroDef494->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef490);
		for(int i1 = 0; i1 < macroDef494->length; i1++){
			env_t_561 env_t_561_value = make_empty_env(); closure_t closure493 = make_closure(lambda561, &env_t_561_value);
			macroDef494->arr[i1] = closure493.lam(closure493.env, x2->arr[i1], y0->arr[i1]).number_t_value;;
		}
		Xcam = macroDef494;;
	} else {
		array_number_t y0 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y0->length=3;
	y0->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y0->arr[0] = ((rot->arr[1]) * (x1->arr[2])) - ((rot->arr[2]) * (x1->arr[1]));
	y0->arr[1] = ((rot->arr[2]) * (x1->arr[0])) - ((rot->arr[0]) * (x1->arr[2]));
	y0->arr[2] = ((rot->arr[0]) * (x1->arr[1])) - ((rot->arr[1]) * (x1->arr[0]));;
		card_t macroDef495 = x1->length;
		array_number_t macroDef499 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef499->length=macroDef495;
	macroDef499->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef495);
		for(int i1 = 0; i1 < macroDef499->length; i1++){
			env_t_562 env_t_562_value = make_empty_env(); closure_t closure498 = make_closure(lambda562, &env_t_562_value);
			macroDef499->arr[i1] = closure498.lam(closure498.env, x1->arr[i1], y0->arr[i1]).number_t_value;;
		}
		Xcam = macroDef499;;
	}
	array_number_t macroDef500 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef500->length=(((9) + (1)) - (9)) + (1);
	macroDef500->arr = (number_t*)storage_alloc(sizeof(number_t) * (((9) + (1)) - (9)) + (1));
		for(int i1 = 0; i1 < macroDef500->length; i1++){
			
			macroDef500->arr[i1] = cam->arr[(i1) + (9)];;
		}
	array_number_t rad_params = macroDef500;
	array_number_t macroDef501 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef501->length=((1) - (0)) + (1);
	macroDef501->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef501->length; i1++){
			
			macroDef501->arr[i1] = Xcam->arr[(i1) + (0)];;
		}
	array_number_t x2 = macroDef501;
	number_t y0 = (1) / (Xcam->arr[2]);
	card_t macroDef502 = x2->length;
	array_number_t macroDef507 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef507->length=macroDef502;
	macroDef507->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef502);
		for(int i1 = 0; i1 < macroDef507->length; i1++){
			env_t_563 env_t_563_value = make_env_t_563(y0); closure_t closure506 = make_closure(lambda563, &env_t_563_value);
			macroDef507->arr[i1] = closure506.lam(closure506.env, x2->arr[i1]).number_t_value;;
		}
	array_number_t proj = macroDef507;
	card_t macroDef508 = proj->length;
	array_number_t macroDef512 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef512->length=macroDef508;
	macroDef512->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef508);
		for(int i1 = 0; i1 < macroDef512->length; i1++){
			env_t_564 env_t_564_value = make_empty_env(); closure_t closure511 = make_closure(lambda564, &env_t_564_value);
			macroDef512->arr[i1] = closure511.lam(closure511.env, proj->arr[i1]).number_t_value;;
		}
	array_number_t v0 = macroDef512;
	number_t macroDef513 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef513 = (macroDef513) + (cur);;
	}
	number_t rsq = macroDef513;
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	card_t macroDef514 = proj->length;
	array_number_t macroDef519 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef519->length=macroDef514;
	macroDef519->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef514);
		for(int i1 = 0; i1 < macroDef519->length; i1++){
			env_t_565 env_t_565_value = make_env_t_565(L); closure_t closure518 = make_closure(lambda565, &env_t_565_value);
			macroDef519->arr[i1] = closure518.lam(closure518.env, proj->arr[i1]).number_t_value;;
		}
	array_number_t distorted = macroDef519;
	array_number_t macroDef520 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef520->length=(((7) + (1)) - (7)) + (1);
	macroDef520->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef520->length; i1++){
			
			macroDef520->arr[i1] = cam->arr[(i1) + (7)];;
		}
	array_number_t x3 = macroDef520;
	number_t y1 = cam->arr[6];
	card_t macroDef521 = distorted->length;
	array_number_t macroDef526 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef526->length=macroDef521;
	macroDef526->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef521);
		for(int i1 = 0; i1 < macroDef526->length; i1++){
			env_t_566 env_t_566_value = make_env_t_566(y1); closure_t closure525 = make_closure(lambda566, &env_t_566_value);
			macroDef526->arr[i1] = closure525.lam(closure525.env, distorted->arr[i1]).number_t_value;;
		}
	array_number_t y2 = macroDef526;
	card_t macroDef527 = x3->length;
	array_number_t macroDef531 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef531->length=macroDef527;
	macroDef531->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef527);
		for(int i1 = 0; i1 < macroDef531->length; i1++){
			env_t_567 env_t_567_value = make_empty_env(); closure_t closure530 = make_closure(lambda567, &env_t_567_value);
			macroDef531->arr[i1] = closure530.lam(closure530.env, x3->arr[i1], y2->arr[i1]).number_t_value;;
		}
	array_number_t x4 = macroDef531;
	card_t macroDef532 = x4->length;
	array_number_t macroDef536 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef536->length=macroDef532;
	macroDef536->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef532);
		for(int i1 = 0; i1 < macroDef536->length; i1++){
			env_t_568 env_t_568_value = make_empty_env(); closure_t closure535 = make_closure(lambda568, &env_t_568_value);
			macroDef536->arr[i1] = closure535.lam(closure535.env, x4->arr[i1], feat0->arr[i1]).number_t_value;;
		}
	array_number_t x5 = macroDef536;
	card_t macroDef537 = x5->length;
	array_number_t macroDef542 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef542->length=macroDef537;
	macroDef542->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef537);
		for(int i1 = 0; i1 < macroDef542->length; i1++){
			env_t_569 env_t_569_value = make_env_t_569(w0); closure_t closure541 = make_closure(lambda569, &env_t_569_value);
			macroDef542->arr[i1] = closure541.lam(closure541.env, x5->arr[i1]).number_t_value;;
		}
	value_t res;
	res.array_number_t_value = macroDef542;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_2(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef438 = cams->length;
	card_t n = macroDef438;
	card_t macroDef439 = w->length;
	card_t p = macroDef439;
	card_t s = 0;
	card_t e = (p) - (1);
	array_number_t macroDef440 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef440->length=((e) - (s)) + (1);
	macroDef440->arr = (number_t*)storage_alloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef440->length; i++){
			
			macroDef440->arr[i] = (double)(((s)) + (i));;
		}
	array_number_t range = macroDef440;
	card_t macroDef441 = range->length;
	array_array_number_t macroDef551 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef551->length=macroDef441;
	macroDef551->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef441);
		for(int i = 0; i < macroDef551->length; i++){
			env_t_552 env_t_552_value = make_env_t_552(x,w,obs,feat,cams); closure_t closure550 = make_closure(lambda552, &env_t_552_value);
			macroDef551->arr[i] = closure550.lam(closure550.env, range->arr[i]).array_number_t_value;;
		}
	return macroDef551;
}
#endif
