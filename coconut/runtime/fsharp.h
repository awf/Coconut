#ifndef __FSHARP_CLIB_H__ 
#define __FSHARP_CLIB_H__ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

// extern int closure_mem = 0;

typedef int index_t;
typedef double number_t;
typedef struct array_number_t {
	number_t* arr;
	int length;
}* array_number_t;
typedef struct array_array_number_t {
	array_number_t* arr;
	int length;
}* array_array_number_t;
typedef struct array_array_array_number_t {
	array_array_number_t* arr;
	int length;
}* array_array_array_number_t;

typedef union value_t {
	number_t number_t_value;
	array_number_t array_number_t_value;
	array_array_number_t array_array_number_t_value;
	array_array_array_number_t array_array_array_number_t_value;
} value_t;

typedef void* storage_t;

typedef char* string_t;

typedef value_t (*lambda_t)();

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
	// closure_mem += sizeof(closure_t);
	return c;
}

void free_closure(closure_t* closure) {
	free(closure->env);
	free(closure);
}

void array_print(array_number_t arr) {
	printf("[");
	for (int i = 0; i < arr->length; i++) {
		printf("%f", arr->arr[i]);
		if (i != arr->length - 1)
			printf(", ");
	}
	printf("]\n");
}

array_number_t vector_build(index_t size, closure_t* closure) {
	array_number_t res = (array_number_t)malloc(sizeof(int) * 2);
	res->length = size;
	res->arr = (number_t*)malloc(sizeof(number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure->lam(closure->env, i).number_t_value;
	}
	free_closure(closure);
	return res;
}

array_array_number_t matrix_build(index_t size, closure_t* closure) {
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length = size;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure->lam(closure->env, i).array_number_t_value;
	}
	free_closure(closure);
	return res;
}

array_array_array_number_t matrix3d_build(index_t size, closure_t* closure) {
	array_array_array_number_t res = (array_array_array_number_t)malloc(sizeof(int) * 2);
	res->length = size;
	res->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure->lam(closure->env, i).array_array_number_t_value;
	}
	free_closure(closure);
	return res;
}

array_number_t array_slice(array_number_t arr, index_t start, index_t end) {
	index_t size = end - start + 1;
	array_number_t res = (array_number_t)malloc(sizeof(int) * 2);
	res->length = size;
	res->arr = (number_t*)malloc(sizeof(number_t) * size);
	for (int i = 0; i < size; i++) {
		res->arr[i] = arr->arr[start + i];
	}
	return res;
}

array_array_number_t matrix_slice(array_array_number_t arr, index_t start, index_t end) {
	index_t size = end - start + 1;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length = size;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * size);
	for (int i = 0; i < size; i++) {
		res->arr[i] = arr->arr[start + i];
	}
	return res;
}

array_number_t array_range(index_t start, index_t end) {
	index_t size = end - start + 1;
	array_number_t res = (array_number_t)malloc(sizeof(int) * 2);
	res->length = size;
	res->arr = (number_t*)malloc(sizeof(number_t) * size);
	for (int i = 0; i < size; i++) {
		res->arr[i] = start + i;
	}
	return res;
}

void number_print(number_t num) {
	printf("%f\n", num);
}

array_array_number_t matrix_concat(array_array_number_t mat1, array_array_number_t mat2) {
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length = mat1->length + mat2->length;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		if (i < mat1->length)
			res->arr[i] = mat1->arr[i];
		else 
			res->arr[i] = mat2->arr[i - mat1->length];
	}
	return res;
}

array_array_array_number_t matrix3d_concat(array_array_array_number_t mat1, array_array_array_number_t mat2) {
	array_array_array_number_t res = (array_array_array_number_t)malloc(sizeof(int) * 2);
	res->length = mat1->length + mat2->length;
	res->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		if (i < mat1->length)
			res->arr[i] = mat1->arr[i];
		else 
			res->arr[i] = mat2->arr[i - mat1->length];
	}
	return res;
}

number_t vector_fold_number(closure_t* closure, number_t zero, array_number_t range) {
	number_t acc = zero;
	for (int i = 0; i < range->length; i++) {
		acc = closure->lam(closure->env, acc, range->arr[i]).number_t_value;
	}
	free_closure(closure);
	return acc;
}

array_number_t vector_fold_vector(closure_t* closure, array_number_t zero, array_number_t range) {
	array_number_t acc = zero;
	for (int i = 0; i < range->length; i++) {
		acc = closure->lam(closure->env, acc, range->arr[i]).array_number_t_value;
	}
	free_closure(closure);
	return acc;
}

array_array_number_t vector_fold_matrix(closure_t* closure, array_array_number_t zero, array_number_t range) {
	array_array_number_t acc = zero;
	for (int i = 0; i < range->length; i++) {
		acc = closure->lam(closure->env, acc, range->arr[i]).array_array_number_t_value;
	}
	free_closure(closure);
	return acc;
}

array_array_array_number_t vector_fold_matrix3d(closure_t* closure, array_array_array_number_t zero, array_number_t range) {
	array_array_array_number_t acc = zero;
		for (int i = 0; i < range->length; i++) {
		acc = closure->lam(closure->env, acc, range->arr[i]).array_array_array_number_t_value;
	}
	free_closure(closure);
	return acc;
}

array_array_number_t matrix_transpose(array_array_number_t mat) {
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length = mat->arr[0]->length;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		array_number_t row = (array_number_t)malloc(sizeof(int) * 2);
		row->length = mat->length;
		row->arr = (number_t*)malloc(sizeof(number_t) * row->length);
		for (int j = 0; j < row->length; j++) {
			row->arr[j] = mat->arr[j]->arr[i];
		}
		res->arr[i] = row;
	}
	return res;
}

array_array_number_t matrix_mult(array_array_number_t mat1, array_array_number_t mat2) {
	int r1 = mat1->length;
	int c2 = mat2->arr[0]->length;
	int c1 = mat1->arr[0]->length;
	int r2 = mat2->length;
	if(c1 != r2) {
		printf("Matrcies have the inconsistent dimensions %dx%d and %dx%d for MMM", r1, c1, r2, c2);
		exit(1);
	}
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length = r1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * res->length);
	for (int i = 0; i < r1; i++) {
		array_number_t row = (array_number_t)malloc(sizeof(int) * 2);
		row->length = c2;
		row->arr = (number_t*)malloc(sizeof(number_t) * c2);
		for (int j = 0; j < c2; j++) {
			row->arr[j] = 0;
			for(int k = 0; k < c1; k++) {
				row->arr[j] += mat1->arr[i]->arr[k] * mat2->arr[k]->arr[j];
			}
		}
		res->arr[i] = row;
	}
	return res;
}



void matrix_print(array_array_number_t arr) {
	printf("[\n   ");
	for (int i = 0; i < arr->length; i++) {
		if (i != 0)
			printf(" , ");
		array_print(arr -> arr[i]);
	}
	printf("]\n");
}

array_array_number_t matrix_read(string_t name, int start_line, int rows) {
	FILE * fp;
    fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Couldn't read the file `%s`.", name);
        exit(1);
    }

    for(int i = 0; i < start_line; i++) {
    	while(getc(fp) != '\n') {}
    }
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length = rows;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * rows);
	for(int row_index=0; row_index<rows; row_index++) {
		char cur = 0;
		int length = 0;
		int elems = 1;
		while(1) {
			char prevCur = cur;
			cur = getc(fp);
			if(cur == '\n')
				break;
			else if(((cur >= '0' && cur <= '9') || cur == '-') && prevCur == ' ')
				elems++;
			length++;
		}
		fseek(fp, -length-2, SEEK_CUR);
		array_number_t one_row = array_range(0, elems - 1);
		for(int i=0; i<elems; i++) {
			fscanf(fp, "%lf", &one_row->arr[i]);
		}
		res->arr[row_index] = one_row;
	}
	fclose(fp);
	return res;
}

number_t gamma_ln(number_t x) {
	// TODO needs to be implemented.
	return x;
}

storage_t vector_alloc(index_t size) {
	array_number_t res = (array_number_t)malloc(sizeof(int) * 2);
	res->length = size;
	res->arr = (number_t*)malloc(sizeof(number_t) * res->length);
	return res;
}

void vector_alloc_cps(index_t size, closure_t* closure) {
	array_number_t res = (array_number_t)vector_alloc(size);
	closure->lam(closure->env, res);
	free(closure);
	free(res);
}


array_number_t vector_build_given_storage(storage_t storage, closure_t* closure) {
	array_number_t res = (array_number_t)storage;
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure->lam(closure->env, i).number_t_value;
	}
	free_closure(closure);
	return res;
}

/** Timing */

typedef struct timer_t {
	clock_t start;
} timer_t;

timer_t tic() {
	timer_t res;
	res.start = clock();
	return res;
}

void toc(timer_t t) {
	clock_t end = clock();
	float milliseconds = (float)(end - t.start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time: %d ms\n", (int)milliseconds);
}

#endif