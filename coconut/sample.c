#include "linalg.h"

int main()
{
	linalg_test1(NULL);
	array_array_number_t cam = (array_array_number_t)malloc(sizeof(int) * 2);
	cam->length = 2;
	cam->arr = (array_number_t*)malloc(sizeof(array_number_t) * 2);
	cam->arr[0] = (array_number_t)malloc(sizeof(int) * 2);
	cam->arr[0]->length = 11;
	cam->arr[0]->arr = (number_t*)malloc(sizeof(number_t) * 11);
	cam->arr[0]->arr[0] = 1.797201;
	cam->arr[0]->arr[1] = 0.590697;
	cam->arr[0]->arr[2] = -0.635786;
	cam->arr[0]->arr[3] = 90.85955;
	cam->arr[0]->arr[4] = 29.361415;
	cam->arr[0]->arr[5] = 28.777534;
	cam->arr[0]->arr[6] = 211.628116;
	cam->arr[0]->arr[7] = -0.284531;
	cam->arr[0]->arr[8] = -14.762924;
	cam->arr[0]->arr[9] = 0.058931;
	cam->arr[0]->arr[10] = 0.069976;
	cam->arr[1] = (array_number_t)malloc(sizeof(int) * 2);
	cam->arr[1]->length = 11;
	cam->arr[1]->arr = (number_t*)malloc(sizeof(number_t) * 11);
	cam->arr[1]->arr[0] = 1.797201;
	cam->arr[1]->arr[1] = 0.590697;
	cam->arr[1]->arr[2] = -0.635786;
	cam->arr[1]->arr[3] = 90.85955;
	cam->arr[1]->arr[4] = 29.361415;
	cam->arr[1]->arr[5] = 28.777534;
	cam->arr[1]->arr[6] = 211.628116;
	cam->arr[1]->arr[7] = -0.284531;
	cam->arr[1]->arr[8] = -14.762924;
	cam->arr[1]->arr[9] = 0.058931;
	cam->arr[1]->arr[10] = 0.069976;
	array_array_number_t X = (array_array_number_t)malloc(sizeof(int) * 2);
	X->length = 10;
	X->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
	for(int i=0; i<10; i++){
		X->arr[i] = (array_number_t)malloc(sizeof(int) * 2);
		X->arr[i]->length = 3;
		X->arr[i]->arr = (number_t*)malloc(sizeof(number_t) * 3);
		X->arr[i]->arr[0] = 4.173048;  
		X->arr[i]->arr[1] = 5.586898;
		X->arr[i]->arr[2] = 1.403869;
	}
	array_array_number_t obs = (array_array_number_t)malloc(sizeof(int) * 2);
	obs->length = 10;
	obs->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
	for(int i=0; i<10; i++){
		obs->arr[i] = (array_number_t)malloc(sizeof(int) * 2);
		obs->arr[i]->length = 2;
		obs->arr[i]->arr = (number_t*)malloc(sizeof(number_t) * 2);
		obs->arr[i]->arr[0] = i % 2;  
		obs->arr[i]->arr[1] = i;
	}
	array_array_number_t feat = (array_array_number_t)malloc(sizeof(int) * 2);
	feat->length = 10;
	feat->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
	for(int i=0; i<10; i++){
		feat->arr[i] = (array_number_t)malloc(sizeof(int) * 2);
		feat->arr[i]->length = 2;
		feat->arr[i]->arr = (number_t*)malloc(sizeof(number_t) * 2);
		feat->arr[i]->arr[0] = -525.672849; 
		feat->arr[i]->arr[1] = 161.811929;
	}
	array_number_t w = (array_number_t)malloc(sizeof(int) * 2);
	w->length = 10;
	w->arr = (number_t*)malloc(sizeof(number_t) * 10);
	for(int i=0; i<10; i++){
		w->arr[i] = 0.417022;
	}
	array_array_number_t err = linalg_reproj_err(cam, X, w, obs, feat);
	matrix_print(err);
	matrix_read("../ba.txt", 1, 3);
	return 0;
}