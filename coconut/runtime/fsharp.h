#ifndef __FSHARP_CLIB_H__ 
#define __FSHARP_CLIB_H__ 

typedef int index_t;
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

void array_print(array_number_t* arr) {
	printf("[");
	for (int i = 0; i < arr->length; i++) {
		printf("%f", arr->arr[i]);
		if (i != arr->length - 1)
			printf(", ");
	}
	printf("]\n");
}

array_number_t* array_map(closure_t* closure, array_number_t* arr) {
	array_number_t* res = (array_number_t*)malloc(sizeof(array_number_t));
	res->length = arr->length;
	res->arr = (number_t*)malloc(sizeof(number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure->lam(closure->env, arr->arr[i]);
	}
	return res;
}

array_number_t* array_map2(closure_t* closure, array_number_t* arr1, array_number_t* arr2) {
	array_number_t* res = (array_number_t*)malloc(sizeof(array_number_t));
	res->length = arr1->length;
	res->arr = (number_t*)malloc(sizeof(number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure->lam(closure->env, arr1->arr[i], arr2->arr[i]); 
	}
	return res;
}

number_t array_sum(array_number_t* arr) {
	number_t sum = 0;
	for (int i = 0; i < arr->length; i++) {
		sum += arr->arr[i];
	}
	return sum;
}

array_number_t* array_slice(array_number_t* arr, index_t start, index_t end) {
	index_t size = end - start + 1;
	array_number_t* res = (array_number_t*)malloc(sizeof(array_number_t));
	res->length = size;
	res->arr = (number_t*)malloc(sizeof(number_t) * size);
	for (int i = 0; i < size; i++) {
		res->arr[i] = arr->arr[start + i];
	}
	return res;
}

void number_print(number_t num) {
	printf("%f\n", num);
}

#endif