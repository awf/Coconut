#ifndef __FSHARP_CLIB_H__ 
#define __FSHARP_CLIB_H__ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
#include "mem_mng.h"

#define VECTOR_HEADER_BYTES (sizeof(int) * 2)
#define VECTOR_ALL_BYTES(rows) ((rows) * sizeof(number_t) + VECTOR_HEADER_BYTES)
#define MATRIX_HEADER_BYTES(rows) (sizeof(int) * (2 + (rows)))
#define MATRIX_ROWS_OFFSET(rows, cols, row) (MATRIX_HEADER_BYTES(rows) + (VECTOR_ALL_BYTES(cols)) * (row))
#define STG_OFFSET(stg, offset) (storage_t)(((char*)(stg)) + (offset))

// extern int closure_mem = 0;

storage_t empty_storage = (void*)0;

empty_env_t make_empty_env() {
	return 0;
}

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
	printf("%d (ms)\n", (int)milliseconds);
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
	storage_t area = storage_alloc(VECTOR_ALL_BYTES(size));
	array_number_t boxed_vector = (array_number_t)area;
	boxed_vector->length = size;
	boxed_vector->arr = (number_t*)(((int*)area) + 2);
	// pause_timing();
	return area;
}

storage_t matrix_alloc(index_t size) {
	// start_timing();
	storage_t area = storage_alloc(VECTOR_HEADER_BYTES + sizeof(array_number_t) * size);
	array_array_number_t boxed_vector = (array_array_number_t)area;
	boxed_vector->length = size;
	boxed_vector->arr = (array_number_t*)(((int*)area) + 2);
	// pause_timing();
	return area;
}

storage_t matrix3d_alloc(index_t size) {
	// start_timing();
	storage_t area = storage_alloc(VECTOR_HEADER_BYTES + sizeof(array_array_number_t) * size);
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
	// printf("reading from file `%s` starting line %d, %d rows\n", name, start_line, rows);
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
	res->length = rows;
	res->arr = (array_number_t*)STG_OFFSET(storage, VECTOR_HEADER_BYTES);
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
		// TODO make its memory usage better
		array_number_t one_row = malloc(VECTOR_ALL_BYTES(elems));
		one_row->length = elems;
		one_row->arr = (number_t*)(((int*)one_row) + 2);
		for(int i=0; i<elems; i++) {
			fscanf(fp, "%lf", &one_row->arr[i]);
		}
		res->arr[row_index] = one_row;
	}
	// printf("finished reading!\n");
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

matrix_shape_t nested_shape_card_t(card_t elem, card_t card) {
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

card_t width_card_t(card_t shape) {
  return VECTOR_ALL_BYTES(shape);
}

card_t width_matrix_shape_t(matrix_shape_t shape) {
  card_t rows = shape.card;
  card_t cols = shape.elem;
  return width_card_t(cols) * rows + MATRIX_HEADER_BYTES(rows);
}

#endif