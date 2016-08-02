#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_373;

typedef empty_env_t env_t_374;


value_t lambda374(env_t_374* env367, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda373(env_t_373* env370, index_t i) {
	env_t_374 env_t_374_value = make_empty_env(); closure_t closure369 = make_closure(lambda374, &env_t_374_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure369);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	env_t_373 env_t_373_value = make_empty_env(); closure_t closure372 = make_closure(lambda373, &env_t_373_value);
	return matrix_build(10, closure372);
}
typedef empty_env_t env_t_382;

typedef struct env_t_383 {
	index_t i;
} env_t_383;
env_t_383 make_env_t_383(index_t i) {
	env_t_383 env;
	env.i = i;
	return env;
}

value_t lambda383(env_t_383* env376, index_t j) {
	index_t i375 = env376->i;
	value_t res;
	res.number_t_value = (double)((i375) + (j));
	return res;
}
value_t lambda382(env_t_382* env379, index_t i) {
	env_t_383 env_t_383_value = make_env_t_383(i); closure_t closure378 = make_closure(lambda383, &env_t_383_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure378);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	env_t_382 env_t_382_value = make_empty_env(); closure_t closure381 = make_closure(lambda382, &env_t_382_value);
	return matrix_build(10, closure381);
}
typedef struct env_t_393 {
	number_t n;
} env_t_393;
env_t_393 make_env_t_393(number_t n) {
	env_t_393 env;
	env.n = n;
	return env;
}
typedef struct env_t_394 {
	number_t n;
	index_t i;
} env_t_394;
env_t_394 make_env_t_394(number_t n,index_t i) {
	env_t_394 env;
	env.n = n;
	env.i = i;
	return env;
}

value_t lambda394(env_t_394* env386, index_t j) {
	number_t n385 = env386->n;
	index_t i384 = env386->i;
	value_t res;
	res.number_t_value = ((double)((i384) + (j))) * (n385);
	return res;
}
value_t lambda393(env_t_393* env390, index_t i) {
	number_t n389 = env390->n;
	env_t_394 env_t_394_value = make_env_t_394(n389,i); closure_t closure388 = make_closure(lambda394, &env_t_394_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure388);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	env_t_393 env_t_393_value = make_env_t_393(n); closure_t closure392 = make_closure(lambda393, &env_t_393_value);
	return matrix_build(10, closure392);
}
#endif
