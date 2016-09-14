#ifdef BA_0
#include "usecases_ba_0.h"
#elif BA_1
#include "usecases_ba_1.h"
#elif BA_2
#include "usecases_ba_2.h"
#elif BA_3
#include "usecases_ba_3.h"
#elif BA_4
#include "usecases_ba_4.h"
#elif BA_5
#include "usecases_ba_5.h"
#elif BA_6
#include "usecases_ba_6.h"
#elif BA_7
#include "usecases_ba_7.h"
#elif BA_8
#include "usecases_ba_8.h"
#elif BA_9
#include "usecases_ba_9.h"
#elif BA_10
#include "usecases_ba_10.h"
#endif

typedef struct env_t_114__ {
	number_t one_w;
} env_t_114__;
env_t_114__ make_env_t_114__(number_t one_w) {
	env_t_114__ env;
	env.one_w = one_w;
	return env;
}

value_t lambda114__(env_t_114__* env104, number_t x) {
	number_t one_w103 = env104->one_w;
	value_t res;
	res.number_t_value = one_w103;
	return res;
}
typedef struct env_t_115__ {
	array_number_t one_feat;
} env_t_115__;
env_t_115__ make_env_t_115__(array_number_t one_feat) {
	env_t_115__ env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda115__(env_t_115__* env108, number_t x) {
	array_number_t one_feat107 = env108->one_feat;
	value_t res;
	res.array_number_t_value = one_feat107;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file_bench(string_t fn, card_t n, card_t m, card_t p) {
	card_t oneCard = 1;
	array_number_t one_cam = TOP_LEVEL_linalg_vectorRead(fn, 1);
	array_array_number_t macroDef101 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef101->length=n;
	macroDef101->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * n);
		for(int x = 0; x < macroDef101->length; x++){
			
			macroDef101->arr[x] = one_cam;;
		}
	array_array_number_t cam = macroDef101;
	array_number_t one_x = TOP_LEVEL_linalg_vectorRead(fn, 2);
	array_array_number_t macroDef102 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef102->length=m;
	macroDef102->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * m);
		for(int x = 0; x < macroDef102->length; x++){
			
			macroDef102->arr[x] = one_x;;
		}
	array_array_number_t x = macroDef102;
	number_t one_w = TOP_LEVEL_linalg_numberRead(fn, 3);
	env_t_114__ env_t_114_value = make_env_t_114__(one_w); closure_t closure106 = make_closure(lambda114__, &env_t_114_value);
	array_number_t w = TOP_LEVEL_linalg_vectorMap(closure106, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_number_t one_feat = TOP_LEVEL_linalg_vectorRead(fn, 4);
	env_t_115__ env_t_115_value = make_env_t_115__(one_feat); closure_t closure110 = make_closure(lambda115__, &env_t_115_value);
	array_array_number_t feat = TOP_LEVEL_linalg_vectorMapToMatrix(closure110, TOP_LEVEL_linalg_vectorRange(oneCard, p));
	array_array_number_t macroDef111 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef111->length=p;
	macroDef111->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * p);
		for(int x = 0; x < macroDef111->length; x++){
			array_number_t array112 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array112->length=2;
	array112->arr = (number_t*)storage_alloc(sizeof(number_t) * 2);
	array112->arr[0] = (double)(((int)(x)) % ((n)));
	array112->arr[1] = (double)(((int)(x)) % ((m)));;
			macroDef111->arr[x] = array112;;
		}
	array_array_number_t obs = macroDef111;
	timer_t t = tic();
	array_array_number_t res = METHOD(cam, x, w, obs, feat);
	toc(t);
	return res;
}

int main(int argc, char** argv)
{
	if(argc != 2) {
		printf("You should use the following format for running this program: %s <folder containing the input data>\n", argv[0]);
		exit(1);
	}
	char* file = argv[1];
	array_number_t nmp = TOP_LEVEL_linalg_vectorRead(file, 0);
	card_t n = (int)(nmp->arr[0]);
	card_t m = (int)(nmp->arr[1]);
	card_t p = (int)(nmp->arr[2]);
	TOP_LEVEL_usecases_ba_run_ba_from_file_bench(file, n, m, p);
	// float milliseconds = (float)(benchmarked_time) * 1000.0 / CLOCKS_PER_SEC;
	// printf("Profiled Time: %d ms\n", (int)milliseconds);
	// printf("memory of closure: %d\n", closure_mem);
	return 0;
}