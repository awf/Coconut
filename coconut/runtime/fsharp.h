#ifndef __FSHARP_CLIB_H__ 
#define __FSHARP_CLIB_H__ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#define VECTOR_HEADER_BYTES (sizeof(int) * 2)
#define VECTOR_ALL_BYTES(rows) ((rows) * sizeof(number_t) + VECTOR_HEADER_BYTES)
#define MATRIX_HEADER_BYTES(rows) (sizeof(int) * (2 + (rows)))
#define MATRIX_ROWS_OFFSET(rows, cols, row) (MATRIX_HEADER_BYTES(rows) + (VECTOR_ALL_BYTES(cols)) * (row))

// extern int closure_mem = 0;

typedef int index_t;
typedef double number_t;
typedef struct array_number_t_struct {
	number_t* arr;
	int length;
} array_number_t_struct;
typedef array_number_t_struct* array_number_t;
typedef struct array_array_number_t {
	array_number_t* arr;
	int length;
}* array_array_number_t;
typedef struct array_array_array_number_t {
	array_array_number_t* arr;
	int length;
}* array_array_array_number_t;

typedef int card_t;
typedef struct vector_shape_t {
  card_t elem;
  card_t card;
} vector_shape_t;
typedef struct matrix_shape_t {
  vector_shape_t elem;
  card_t card;
} matrix_shape_t;
typedef struct matrix3d_shape_t {
  matrix_shape_t elem;
  card_t card;
} matrix3d_shape_t;

typedef union value_t {
	card_t card_t_value;
	vector_shape_t vector_shape_t_value;
	matrix_shape_t matrix_shape_t_value;
	matrix3d_shape_t matrix3d_shape_t_value;
	number_t number_t_value;
	array_number_t array_number_t_value;
	array_array_number_t array_array_number_t_value;
	array_array_array_number_t array_array_array_number_t_value;
} value_t;


typedef void* storage_t;

typedef char* string_t;

typedef value_t (*lambda_t)();

typedef void* env_t;

typedef int empty_env_t;

storage_t empty_storage = (void*)0;

empty_env_t make_empty_env() {
	return 0;
}

typedef struct closure_t {
	enum Tag t;
	lambda_t lam;
	env_t env;
} closure_t;

closure_t make_closure(lambda_t lam, env_t env) {
	closure_t c;
	c.lam = lam;
	c.env = env;
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

clock_t benchmarked_time = 0;
clock_t start_time = 0;

void start_timing() {
	start_time = clock();
}

void pause_timing() {
	benchmarked_time += clock() - start_time;
}

/* Memory allocation constructs */

storage_t vector_alloc(index_t size) {
	// start_timing();
	storage_t area = malloc(VECTOR_HEADER_BYTES + sizeof(number_t) * size);
	array_number_t boxed_vector = (array_number_t)area;
	boxed_vector->length = size;
	boxed_vector->arr = (number_t*)(((int*)area) + 2);
	// pause_timing();
	return area;
}

storage_t matrix_alloc(index_t size) {
	// start_timing();
	storage_t area = malloc(VECTOR_HEADER_BYTES + sizeof(array_number_t) * size);
	array_array_number_t boxed_vector = (array_array_number_t)area;
	boxed_vector->length = size;
	boxed_vector->arr = (array_number_t*)(((int*)area) + 2);
	// pause_timing();
	return area;
}

storage_t matrix3d_alloc(index_t size) {
	// start_timing();
	storage_t area = malloc(VECTOR_HEADER_BYTES + sizeof(array_array_number_t) * size);
	array_array_array_number_t boxed_vector = (array_array_array_number_t)area;
	boxed_vector->length = size;
	boxed_vector->arr = (array_array_number_t*)(((int*)area) + 2);
	// pause_timing();
	return area;
}

array_number_t array_slice(array_number_t arr, index_t start, index_t end) {
	index_t size = end - start + 1;
	array_number_t res = (array_number_t)vector_alloc(size);
	for (int i = 0; i < size; i++) {
		res->arr[i] = arr->arr[start + i];
	}
	return res;
}

array_array_number_t matrix_slice(array_array_number_t arr, index_t start, index_t end) {
	index_t size = end - start + 1;
	array_array_number_t res = (array_array_number_t) matrix_alloc(size);
	for (int i = 0; i < size; i++) {
		res->arr[i] = arr->arr[start + i];
	}
	return res;
}

void number_print(number_t num) {
	printf("%f\n", num);
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

array_array_number_t matrix_read_s(storage_t storage, string_t name, int start_line, int rows) {
	FILE * fp;
    fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Couldn't read the file `%s`.", name);
        exit(1);
    }

    for(int i = 0; i < start_line; i++) {
    	while(getc(fp) != '\n') {}
    }
	array_array_number_t res = (array_array_number_t)storage;
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
		array_number_t one_row = (array_number_t)vector_alloc(elems);
		for(int i=0; i<elems; i++) {
			fscanf(fp, "%lf", &one_row->arr[i]);
		}
		res->arr[row_index] = one_row;
	}
	fclose(fp);
	return res;
}

array_array_number_t matrix_read(string_t name, int start_line, int rows) {
	return matrix_read_s(matrix_alloc(rows), name, start_line, rows);
}

number_t gamma_ln(number_t x) {
	// TODO needs to be implemented.
	return x;
}

void vector_alloc_cps(index_t size, closure_t closure) {
	array_number_t res = (array_number_t)vector_alloc(size);
	closure.lam(closure.env, res);
	free(res);
}


array_number_t vector_build_given_storage(storage_t storage, closure_t closure) {
	array_number_t res = (array_number_t)storage;
	for (int i = 0; i < res->length; i++) {
		res->arr[i] = closure.lam(closure.env, i).number_t_value;
	}
	return res;
}

// cardinality related methods

vector_shape_t nested_shape_card_t(card_t elem, card_t card) {
	vector_shape_t res;
	res.elem = elem;
	res.card = card;
	return res;
}


matrix_shape_t nested_shape_vector_shape_t(vector_shape_t elem, card_t card) {
	matrix_shape_t res;
	res.elem = elem;
	res.card = card;
	return res;
}

matrix3d_shape_t nested_shape_matrix_shape_t(matrix_shape_t elem, card_t card) {
	matrix3d_shape_t res;
	res.elem = elem;
	res.card = card;
	return res;
}

card_t width_vector_shape_t(vector_shape_t shape) {
  return VECTOR_ALL_BYTES(shape.card);
}

card_t width_matrix_shape_t(matrix_shape_t shape) {
  card_t rows = shape.card;
  card_t cols = shape.elem.card;
  return width_vector_shape_t(shape.elem) * rows + MATRIX_HEADER_BYTES(rows);
}

#endif