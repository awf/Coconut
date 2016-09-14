#include "usecases_ba_storaged.h"

int main(int argc, char** argv)
{
	if(argc != 2) {
		printf("You should use the following format for running this program: %s <folder containing the input data>\n", argv[0]);
		exit(1);
	}
	char* file = argv[1];
	array_number_t nmp = TOP_LEVEL_linalg_vectorRead_s(empty_storage, file, 0, 0, 0);
	card_t n = (int)(nmp->arr[0]);
	card_t m = (int)(nmp->arr[1]);
	card_t p = (int)(nmp->arr[2]);
	TOP_LEVEL_usecases_ba_run_ba_from_file_s(empty_storage, file, n, m, p, 0, n, m, p);
	float milliseconds = (float)(benchmarked_time) * 1000.0 / CLOCKS_PER_SEC;
	printf("Profiled Time: %d ms\n", (int)milliseconds);
	// printf("memory of closure: %d\n", closure_mem);
	return 0;
}