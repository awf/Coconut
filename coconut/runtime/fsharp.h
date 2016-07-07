#ifndef __FSHARP_CLIB_H__ 
#define __FSHARP_CLIB_H__ 

typedef double number_t;
typedef struct array_number_t {
	number_t* arr;
	int length;
} array_number_t;

typedef number_t (*lambda_t)();

typedef void* env_t;

typedef struct closure_t {
	enum Tag t;
	lambda_t lam;
	env_t env;
} closure_t;

closure_t* make_closure(lambda_t lam, env_t env) {
	closure_t* c = (closure_t*)malloc(sizeof(closure_t));
	c->lam = lam;
	c->env = env;
	return c;
}

#endif