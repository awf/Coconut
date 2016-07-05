#include "runtime/fsharp.h"
#include <stdio.h>

number_t* ba_cross(number_t* a, number_t* b) {
	number_t res[] = { a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0] };
	return res;
}

int main()
{
	number_t a[3] = { 1.0, 2.0, 3.0 };
	ba_cross(a, a);
  printf("hello!\n");
  return 0;
}