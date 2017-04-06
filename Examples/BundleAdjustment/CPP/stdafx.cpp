// stdafx.cpp : source file that includes just the standard includes
// benchmark_ba.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
timer_t tic() {
	timer_t res;
	res.start = clock();
	return res;
}

float toc(timer_t t) {
	clock_t end = clock();
	float milliseconds = (float)(end - t.start) * 1000.0 / CLOCKS_PER_SEC;
	// printf("%s -- %d (ms)\n", s, (int)milliseconds);
	return milliseconds;
}

