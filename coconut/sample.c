#include "runtime/fsharp.h"
#include <stdio.h>

/* Oringinal code:
Lambda (a,
Lambda (b,
NewArray (Double,
Call (None, op_Subtraction,
[Call (None, op_Multiply,
[Call (None, GetArray, [a, Value (1)]),
Call (None, GetArray, [b, Value (2)])]),
Call (None, op_Multiply,
[Call (None, GetArray, [a, Value (2)]),
Call (None, GetArray, [b, Value (1)])])]),
Call (None, op_Subtraction,
[Call (None, op_Multiply,
[Call (None, GetArray, [a, Value (2)]),
Call (None, GetArray, [b, Value (0)])]),
Call (None, op_Multiply,
[Call (None, GetArray, [a, Value (0)]),
Call (None, GetArray, [b, Value (2)])])]),
Call (None, op_Subtraction,
[Call (None, op_Multiply,
[Call (None, GetArray, [a, Value (0)]),
Call (None, GetArray, [b, Value (1)])]),
Call (None, op_Multiply,
[Call (None, GetArray, [a, Value (1)]),
Call (None, GetArray, [b, Value (0)])])]))))
*/

/* Preprocessed code:
Lambda (a,
Lambda (b,
Let (array1,
NewArray (Double,
Call (None, op_Subtraction,
[Call (None, op_Multiply,
[Call (None, GetArray,
[a, Value (1)]),
Call (None, GetArray,
[b, Value (2)])]),
Call (None, op_Multiply,
[Call (None, GetArray,
[a, Value (2)]),
Call (None, GetArray,
[b, Value (1)])])]),
Call (None, op_Subtraction,
[Call (None, op_Multiply,
[Call (None, GetArray,
[a, Value (2)]),
Call (None, GetArray,
[b, Value (0)])]),
Call (None, op_Multiply,
[Call (None, GetArray,
[a, Value (0)]),
Call (None, GetArray,
[b, Value (2)])])]),
Call (None, op_Subtraction,
[Call (None, op_Multiply,
[Call (None, GetArray,
[a, Value (0)]),
Call (None, GetArray,
[b, Value (1)])]),
Call (None, op_Multiply,
[Call (None, GetArray,
[a, Value (1)]),
Call (None, GetArray,
[b, Value (0)])])])), array1)))
*/

// Generated C code for linalg.cross:


array_number_t* linalg_cross(array_number_t* a, array_number_t* b) {
	array_number_t* array1 = (array_number_t*)malloc(sizeof(array_number_t));
	array1->length = 3;
	array1->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array1->arr[0] = a->arr[1] * b->arr[2] - a->arr[2] * b->arr[1];
	array1->arr[1] = a->arr[2] * b->arr[0] - a->arr[0] * b->arr[2];
	array1->arr[2] = a->arr[0] * b->arr[1] - a->arr[1] * b->arr[0];;
	return array1;
}
/* Oringinal code:
Lambda (x,
Lambda (y,
Call (None, Map,
[Lambda (a, Call (None, op_Multiply, [a, y])), x])))
*/

/* Preprocessed code:
Lambda (x,
Lambda (y,
Let (closure5,
Call (None, makeClosure,
[Lambda (env3,
Lambda (a,
Let (y2,
Call (None, envRef,
[env3, Value ("y")]),
Call (None, op_Multiply,
[a, y2])))),
Call (None, makeEnv,
[NewUnionCase (Cons,
NewTuple (Value ("y"),
Value (42.0)),
NewUnionCase (Empty))])]),
Call (None, Map,
[Lambda (arg4,
Call (None, applyClosure, [closure5, arg4])),
x]))))
*/

// Generated C code for linalg.mult_by_scalar:

typedef struct env_t_6 {
	number_t y;
} env_t_6;
env_t_6* make_env_t_6(number_t y) {
	env_t_6* env = (env_t_6*)malloc(sizeof(env_t_6));
	env->y = y;
	return env;
}

number_t lambda6(env_t_6* env3, number_t a) {
	number_t y2 = env3->y;
	return a * y2;
}
array_number_t* linalg_mult_by_scalar(array_number_t* x, number_t y) {
	closure_t* closure5 = make_closure(lambda6, make_env_t_6(y));
	return array_map(closure5, x);
}
/* Oringinal code:
Lambda (x,
Lambda (y,
Call (None, Map2,
[Lambda (x, Lambda (y, Call (None, op_Addition, [x, y]))),
x, y])))
*/

/* Preprocessed code:
Lambda (x,
Lambda (y,
Let (closure9,
Call (None, makeClosure,
[Lambda (env7,
Lambda (x,
Lambda (y,
Call (None, op_Addition,
[x, y])))),
Call (None, makeEnv, [NewUnionCase (Empty)])]),
Call (None, Map2,
[Lambda (arg8,
Call (None, applyClosure, [closure9, arg8])),
x, y]))))
*/

// Generated C code for linalg.add_vec:

typedef struct env_t_10 {
	number_t dummy_variable;
} env_t_10;
env_t_10* make_env_t_10() {
	env_t_10* env = (env_t_10*)malloc(sizeof(env_t_10));

	return env;
}

number_t lambda10(env_t_10* env7, number_t x, number_t y) {

	return x + y;
}
array_number_t* linalg_add_vec(array_number_t* x, array_number_t* y) {
	closure_t* closure9 = make_closure(lambda10, make_env_t_10());
	return array_map2(closure9, x, y);
}
/* Oringinal code:
Lambda (x,
Lambda (y,
Call (None, Map2,
[Lambda (x,
Lambda (y, Call (None, op_Subtraction, [x, y]))),
x, y])))
*/

/* Preprocessed code:
Lambda (x,
Lambda (y,
Let (closure13,
Call (None, makeClosure,
[Lambda (env11,
Lambda (x,
Lambda (y,
Call (None, op_Subtraction,
[x, y])))),
Call (None, makeEnv, [NewUnionCase (Empty)])]),
Call (None, Map2,
[Lambda (arg12,
Call (None, applyClosure, [closure13, arg12])),
x, y]))))
*/

// Generated C code for linalg.sub_vec:

typedef struct env_t_14 {
	number_t dummy_variable;
} env_t_14;
env_t_14* make_env_t_14() {
	env_t_14* env = (env_t_14*)malloc(sizeof(env_t_14));

	return env;
}

number_t lambda14(env_t_14* env11, number_t x, number_t y) {

	return x - y;
}
array_number_t* linalg_sub_vec(array_number_t* x, array_number_t* y) {
	closure_t* closure13 = make_closure(lambda14, make_env_t_14());
	return array_map2(closure13, x, y);
}
/* Oringinal code:
Lambda (x,
Lambda (y,
Lambda (z,
Call (None, add_vec, [Call (None, add_vec, [x, y]), z]))))
*/

/* Preprocessed code:
Lambda (x,
Lambda (y,
Lambda (z,
Call (None, add_vec, [Call (None, add_vec, [x, y]), z]))))
*/

// Generated C code for linalg.add_vec3:


array_number_t* linalg_add_vec3(array_number_t* x, array_number_t* y, array_number_t* z) {

	return linalg_add_vec(linalg_add_vec(x, y), z);
}

/* Oringinal code:
Lambda (x,
Call (None, Sum,
[Call (None, Map,
[Lambda (x, Call (None, op_Multiply, [x, x])), x])]))
*/

/* Preprocessed code:
Lambda (x,
Let (closure17,
Call (None, makeClosure,
[Lambda (env15, Lambda (x, Call (None, op_Multiply, [x, x]))),
Call (None, makeEnv, [NewUnionCase (Empty)])]),
Call (None, Sum,
[Call (None, Map,
[Lambda (arg16,
Call (None, applyClosure, [closure17, arg16])),
x])])))
*/

// Generated C code for linalg.sqnorm:

typedef struct env_t_18 {
	number_t dummy_variable;
} env_t_18;
env_t_18* make_env_t_18() {
	env_t_18* env = (env_t_18*)malloc(sizeof(env_t_18));

	return env;
}

number_t lambda18(env_t_18* env15, number_t x) {

	return x * x;
}
number_t linalg_sqnorm(array_number_t* x) {
	closure_t* closure17 = make_closure(lambda18, make_env_t_18());
	return array_sum(array_map(closure17, x));
}

/* Oringinal code:
Lambda (x,
Lambda (y,
Call (None, Sum,
[Call (None, Map2,
[Lambda (x,
Lambda (y,
Call (None, op_Multiply, [x, y]))),
x, y])])))
*/

/* Preprocessed code:
Lambda (x,
Lambda (y,
Let (closure21,
Call (None, makeClosure,
[Lambda (env19,
Lambda (x,
Lambda (y,
Call (None, op_Multiply,
[x, y])))),
Call (None, makeEnv, [NewUnionCase (Empty)])]),
Call (None, Sum,
[Call (None, Map2,
[Lambda (arg20,
Call (None, applyClosure,
[closure21, arg20])), x, y])]))))
*/

// Generated C code for linalg.dot_prod:

typedef struct env_t_22 {
	number_t dummy_variable;
} env_t_22;
env_t_22* make_env_t_22() {
	env_t_22* env = (env_t_22*)malloc(sizeof(env_t_22));

	return env;
}

number_t lambda22(env_t_22* env19, number_t x, number_t y) {

	return x * y;
}
number_t linalg_dot_prod(array_number_t* x, array_number_t* y) {
	closure_t* closure21 = make_closure(lambda22, make_env_t_22());
	return array_sum(array_map2(closure21, x, y));
}


int main()
{
	array_number_t* a = (array_number_t*)malloc(sizeof(number_t) * 3);
	a->length = 3;
	a->arr = (number_t*)malloc(sizeof(number_t) * 3);
	a->arr[0] = 1.0;
	a->arr[1] = 2.0;
	a->arr[2] = 3.0;
	array_number_t* b = (array_number_t*)malloc(sizeof(number_t) * 3);
	b->length = 3;
	b->arr = (number_t*)malloc(sizeof(number_t) * 3);
	b->arr[0] = 5.0;
	b->arr[1] = 6.0;
	b->arr[2] = 7.0;
	array_number_t* c = linalg_cross(a, b);
	array_print(c);
	array_number_t* d = linalg_mult_by_scalar(c, 15.0);
	array_print(d);
	array_number_t* e = linalg_add_vec(a, b);
	array_print(e);
	array_number_t* f = linalg_sub_vec(a, b);
	array_print(f);
	array_number_t* g = linalg_add_vec3(a, b, c);
	array_print(g);
	number_t h = linalg_sqnorm(a);
	printf("%f\n", h);
	number_t i = linalg_dot_prod(a, b);
	printf("%f\n", i);
	return 0;
}