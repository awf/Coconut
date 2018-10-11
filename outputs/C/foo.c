#include "usecases_gmm_storaged.h"

// The return array is never freed.  For that we would need to run
// 
//     storage_free(stgVar1416, size1443);
//
// But that's fine for our purposes because once we're done with the
// input data our program terminates.
array_number_t make_a_vector(card_t a_shp, const number_t *input) {
	card_t size1443 = width_card_t(a_shp);
	array_number_t stgVar1416 = storage_alloc(size1443);
	array_number_t macroDef1433 = (array_number_t)stgVar1416;

	macroDef1433->length=a_shp;
	macroDef1433->arr=(number_t*)(STG_OFFSET(stgVar1416, VECTOR_HEADER_BYTES));

        for (int j = 0; j < a_shp; j++) {
          macroDef1433->arr[j] = input[j];
        }
        
	array_number_t a_dps = macroDef1433;
        //	array_print(a_dps);

        return a_dps;
}

// The return array is never freed.  For that we would need to run
// 
//     storage_free(stgVar, size1442);
//
// But that's fine for our purposes because once we're done with the
// input data our program terminates.
array_array_number_t make_a_matrix(card_t irange, card_t jrange, const number_t *input) {
	matrix_shape_t mat1_shp = nested_shape_card_t(jrange, irange);
	card_t size1442 = width_matrix_shape_t(mat1_shp);

	array_number_t stgVar = storage_alloc(size1442);
	array_array_number_t macroDef = (array_array_number_t)stgVar;

	macroDef->length=irange;
	macroDef->arr=(array_number_t*)(STG_OFFSET(stgVar, VECTOR_HEADER_BYTES));

	int stgVar_offsetVar = 0;

        for (int i = 0; i < irange; i++) {
          // Skip over the irange elements pointing to the rows (or is it columns?!)
          storage_t stgVarInner = STG_OFFSET(stgVar, MATRIX_HEADER_BYTES(irange) + stgVar_offsetVar);
          array_number_t macroDef_arr_i = (array_number_t)stgVarInner;

          macroDef_arr_i->length=jrange;
          macroDef_arr_i->arr=(number_t*)(STG_OFFSET(stgVarInner, VECTOR_HEADER_BYTES));
	
          for (int j = 0; j < jrange; j++) {
            macroDef_arr_i->arr[j] = input[i * jrange + j];
          }

          macroDef->arr[i] = macroDef_arr_i;
          stgVar_offsetVar += VECTOR_ALL_BYTES(macroDef->arr[i]->length);
        }

	array_array_number_t mat1_dps = macroDef;
	// matrix_print(mat1_dps);

        return mat1_dps;
}

double extract_and_run_gmm(int n,
                           int k,
                           int d,
                           int l_sz,
                           const double *x,
                           const double *alphas,
                           const double *means,
                           const double *qs,
                           const double *ls,
                           double wishart_gamma_dps,
                           double wishart_m_dps,
                           double *err) {
  array_array_number_t x_dps = make_a_matrix(n, d, x);
  array_number_t alphas_dps = make_a_vector(k, alphas);
  array_array_number_t means_dps = make_a_matrix(k, d, means);
  array_array_number_t qs_dps = make_a_matrix(k, d, qs);
  array_array_number_t ls_dps = make_a_matrix(k, l_sz, ls);
  
  *err = TOP_LEVEL_usecases_gmm_gmm_objective_dps(
          (storage_t)0,
          x_dps,
          alphas_dps,
          means_dps,
          qs_dps,
          ls_dps,
          wishart_gamma_dps,
          wishart_m_dps,
          nested_shape_card_t(d, n),
          k,
          nested_shape_card_t(d, k),
          nested_shape_card_t(d, k),
          nested_shape_card_t(l_sz, k),
          1,
          1);
}

