#pragma once

#include <stdlib.h>
#include <time.h>

/** Timing */

typedef struct timer_t {
	clock_t start;
} timer_t;

// timer_t tic();

// void toc(timer_t t, char* s);

timer_t tic() {
	timer_t res;
	res.start = clock();
	return res;
}

void toc(timer_t t, char* s) {
	clock_t end = clock();
	float milliseconds = (float)(end - t.start) * 1000.0 / CLOCKS_PER_SEC;
	printf("%s -- %d (ms)\n", s, (int)milliseconds);
}

float toc2(timer_t t) {
	clock_t end = clock();
	float milliseconds = (float)(end - t.start) * 1000.0 / CLOCKS_PER_SEC;
	// printf("%s -- %d (ms)\n", s, (int)milliseconds);
	return milliseconds;
}

