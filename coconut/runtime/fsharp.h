#ifndef __FSHARP_CLIB_H__ 
#define __FSHARP_CLIB_H__ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef union value_t {
	number_t number_t_value;
	array_number_t array_number_t_value;
} value_t;

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
	return c;
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

array_number_t array_map(closure_t* closure, array_number_t arr) {
	array_number_t res = (array_number_t)malloc(sizeof(int) * 2);
	res->length = arr->length;
	res->arr = (number_t*)malloc(sizeof(number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure->lam(closure->env, arr->arr[i]).number_t_value;
	}
	return res;
}

array_number_t array_map2(closure_t* closure, array_number_t arr1, array_number_t arr2) {
	array_number_t res = (array_number_t)malloc(sizeof(int) * 2);
	res->length = arr1->length;
	res->arr = (number_t*)malloc(sizeof(number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure->lam(closure->env, arr1->arr[i], arr2->arr[i]).number_t_value;
	}
	return res;
}

number_t array_sum(array_number_t arr) {
	number_t sum = 0;
	for (int i = 0; i < arr->length; i++) {
		sum += arr->arr[i];
	}
	return sum;
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

array_number_t array_range(index_t start, index_t end) {
	index_t size = end - start + 1;
	array_number_t res = (array_number_t)malloc(sizeof(int) * 2);
	res->length = size;
	res->arr = (number_t*)malloc(sizeof(number_t) * size);
	for (int i = 0; i < size; i++) {
		res->arr[i] = i;
	}
	return res;
}

void number_print(number_t num) {
	printf("%f\n", num);
}

array_array_number_t array_map_to_matrix(closure_t* closure, array_number_t arr) {
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length = arr->length;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * res->length);
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure->lam(closure->env, arr->arr[i]).array_number_t_value;
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