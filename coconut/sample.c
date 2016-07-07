#include "runtime/fsharp.h"
#include <stdio.h>

/* Preprocessed code:
Lambda (a,
Lambda (b,
Let (array1,
NewArray (d,
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
/* Preprocessed code:
Lambda (x,
Lambda (y,
Let (closure,
Call (None, makeClosure,
[Lambda (env,
Lambda (x,
Call (None, op_Multiply,
[x,
Call (None, envRef,
[env, Value ("y")])]))),
Call (None, makeEnv,
[NewUnionCase (Cons,
NewTuple (Value ("y"),
Value (2.0)),
NewUnionCase (Empty))])]),
Call (None, Map,
[Lambda (lambdaArg,
Call (None, applyClosure,
[closure, lambdaArg])), x]))))
*/

// Generated C code for linalg.mult_by_scalar:

typedef struct env_t_1 {
	number_t y;
} env_t_1;
env_t_1* make_env_t_1(number_t y) {
	env_t_1* env = (env_t_1*)malloc(sizeof(env_t_1));
	env->y = y;
	return env;
}

number_t lambda1(env_t_1* env, number_t x) {

	return x * env->y;
}
array_number_t* linalg_mult_by_scalar(array_number_t* x, number_t y) {
	closure_t* closure = make_closure(lambda1, make_env_t_1(y));
	return array_map(closure, x);
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
	return 0;
}