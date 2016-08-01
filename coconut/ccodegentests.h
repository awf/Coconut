#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_371;

typedef empty_env_t env_t_372;


value_t lambda372(env_t_372* env365, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda371(env_t_371* env368, index_t i) {
	env_t_372 env_t_372_value = make_empty_env(); closure_t closure367 = make_closure(lambda372, &env_t_372_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure367);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	env_t_371 env_t_371_value = make_empty_env(); closure_t closure370 = make_closure(lambda371, &env_t_371_value);
	return matrix_build(10, closure370);
}
typedef empty_env_t env_t_380;

typedef struct env_t_381 {
	index_t i;
} env_t_381;
env_t_381 make_env_t_381(index_t i) {
	env_t_381 env;
	env.i = i;
	return env;
}

value_t lambda381(env_t_381* env374, index_t j) {
	index_t i373 = env374->i;
	value_t res;
	res.number_t_value = (double)((i373) + (j));
	return res;
}
value_t lambda380(env_t_380* env377, index_t i) {
	env_t_381 env_t_381_value = make_env_t_381(i); closure_t closure376 = make_closure(lambda381, &env_t_381_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure376);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	env_t_380 env_t_380_value = make_empty_env(); closure_t closure379 = make_closure(lambda380, &env_t_380_value);
	return matrix_build(10, closure379);
}
typedef struct env_t_391 {
	number_t n;
} env_t_391;
env_t_391 make_env_t_391(number_t n) {
	env_t_391 env;
	env.n = n;
	return env;
}
typedef struct env_t_392 {
	number_t n;
	index_t i;
} env_t_392;
env_t_392 make_env_t_392(number_t n,index_t i) {
	env_t_392 env;
	env.n = n;
	env.i = i;
	return env;
}

value_t lambda392(env_t_392* env384, index_t j) {
	number_t n383 = env384->n;
	index_t i382 = env384->i;
	value_t res;
	res.number_t_value = ((double)((i382) + (j))) * (n383);
	return res;
}
value_t lambda391(env_t_391* env388, index_t i) {
	number_t n387 = env388->n;
	env_t_392 env_t_392_value = make_env_t_392(n387,i); closure_t closure386 = make_closure(lambda392, &env_t_392_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure386);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	env_t_391 env_t_391_value = make_env_t_391(n); closure_t closure390 = make_closure(lambda391, &env_t_391_value);
	return matrix_build(10, closure390);
}
#endif
