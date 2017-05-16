#ifdef DPS
#ifdef FUSED
#include "../../outputs/C/usecases_ba_opt_storaged.h"
#else
#include "../../outputs/C/usecases_ba_storaged.h"
#endif
#else
#ifdef FUSED
#include "../../outputs/C/usecases_ba_opt.h"
#else
#include "../../outputs/C/usecases_ba.h"
#endif
#endif

int main(int argc, char** argv)
{
	// if(argc != 2) {
	// 	printf("You should use the following format for running this program: %s <folder containing the input data>\n", argv[0]);
	// 	exit(1);
	// }
	// char* file = argv[1];
	// array_number_t nmp = TOP_LEVEL_linalg_vectorRead(file, 0, 3);
	// card_t n = (int)(nmp->arr[0]);
	// card_t m = (int)(nmp->arr[1]);
	// card_t p = (int)(nmp->arr[2]);
	// TOP_LEVEL_usecases_ba_run_ba_from_file(file, n, m, p);
	// float milliseconds = (float)(benchmarked_time) * 1000.0 / CLOCKS_PER_SEC;
	// printf("Profiled Time: %d ms\n", (int)milliseconds);
	// printf("memory of closure: %d\n", closure_mem);
	array_number_t cam = (array_number_t)storage_alloc(sizeof(int) * 2);
	cam->length=11;
	cam->arr = (number_t*)storage_alloc(sizeof(number_t) * 11);
	// 		 0.1, 0.1, 0.1,     // ROT_IDX = 0;    
	cam->arr[0] = 0.1;
	cam->arr[1] = 0.1;
	cam->arr[2] = 0.1;
	//       0.2,0.1,0.3,       // CENTER_IDX = 3;
	cam->arr[3] = 0.2;
	cam->arr[4] = 0.1;
	cam->arr[5] = 0.3;
	//       1.2,               // FOCAL_IDX = 6;
	cam->arr[6] = 1.2;
	//       0.01, 0.03,        // X0_IDX = 7;
	cam->arr[7] = 0.01;
	cam->arr[8] = 0.03;
	//       0.009, 1.2e-4      // RAD_IDX = 9;
	cam->arr[9] = 0.009;
	cam->arr[10] = 1.2e-4;
	array_number_t X = (array_number_t)storage_alloc(sizeof(int) * 2);
	X->length=3;
	X->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	//auto X = vec(0.03, 0.11, -0.7);
	X->arr[0] = 0.03;
	X->arr[1] = 0.11;
	X->arr[2] = -0.7;
    timer_t t = tic();

#ifdef HOIST
  storage_t s = storage_alloc(256);
#endif

    // Debug 150s 
    // Release 1s
    double total = 0;
    int N = 10000000;
#ifdef _DEBUG
    N = N / 100;  // Debug is roughly this much slower than release -- multiply timings.
#endif
    for (int count = 0; count < N; ++count) {
        X->arr[0] = 1.0 / (2.0 + count);
        cam->arr[5] = 1.0 + count * 1e-6;
#ifdef DPS
#ifndef HOIST
    storage_t s = storage_alloc(256);
#endif
        total += TOP_LEVEL_linalg_sqnorm_dps(empty_storage, TOP_LEVEL_usecases_ba_project_dps(s, cam, X, 11, 3), 2);
#ifndef HOIST
    storage_free(s, 256);
#endif
#else
        total += TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_ba_project(cam, X));
#endif
    }
    float elapsed = toc2(t);
    printf("total =%f, time per call = %f ms\n", total, elapsed / (double)(N));
	return 0;
}
