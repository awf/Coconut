#ifndef __USECASES_BA_0_H__ 
#define __USECASES_BA_0_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"
typedef struct env_t_302 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_302;
env_t_302 make_env_t_302(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_302 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda302(env_t_302* env299, number_t i) {
	array_array_number_t x298 = env299->x;
	array_number_t w297 = env299->w;
	array_array_number_t obs296 = env299->obs;
	array_array_number_t feat295 = env299->feat;
	array_array_number_t cams294 = env299->cams;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err(cams294->arr[(int)(obs296->arr[(int)(i)]->arr[0])], x298->arr[(int)(obs296->arr[(int)(i)]->arr[1])], w297->arr[(int)(i)], feat295->arr[(int)(i)]);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_0(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef292 = cams->length;
	card_t n = macroDef292;
	card_t macroDef293 = w->length;
	card_t p = macroDef293;
	array_number_t range = TOP_LEVEL_linalg_vectorRange(0, (p) - (1));
	env_t_302 env_t_302_value = make_env_t_302(x,w,obs,feat,cams); closure_t closure301 = make_closure(lambda302, &env_t_302_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure301, range);
}
#endif
