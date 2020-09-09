#include "linked_list.c"
#include "algorithm2.c"
#include "graph.c"
#include "graph.h"
#include <math.h>
#include "my_array.c"


maximization_delta_Q(int* S, graph* g);

maximization_delta_Q(int* S, graph* g){
	int max_index, i, j, k, max_improve, m;
	double *x, delta_Q, Q_0, *p, *q, *h, *r, max_score, max_improve, l;
	array *unmoved, *indices, *unmoved_copy, *score, *improve;
	x = (double*)malloc(sizeof(double)*g->n);
	unmoved = (array*)malloc(sizeof(array));
	indices = (array*)malloc(sizeof(array));
	score = (array*)malloc(sizeof(array));
	improve = (array*)malloc(sizeof(array));
	allocate_mem_size_n(unmoved, g->n);
	allocate_mem_size_n(indices, g->n);
	allocate_mem_size_n(score, g->n);
	allocate_mem_size_n(improve, g->n);

	while (delta_Q > 0){
		x = mult(g->B,S);
		for (i = 0; i<g->n; i++){
			/*computing delta_Q for each node - block 2*/
			q = S;
			h = x;
			r = g->A_row_sum;
			for (p = score; p < (score + g->n); p++){
				*p = -2*(*h*(*q)+(pow((*r),2))/g->M);
				h++;
				q++;
				r++;
			}
			while (is_not_emapty(unmoved)){
				k = find_max_index(unmoved, score);
				/*changing group for index k*/
				*(S + k) = -*(S + k);
				p = indices->data;
				q = improve->data;
				for (i = 0; i < g->n; i++){
					*p = k;
					/*line 14-18*/
					if (i == 0){
						*q = *(score->data + k);
					}
					else{
						*q = *(q-1) + *(score->data + k);
					}
					p++;
					q++;
					/*block 3*/
					for (j = 0; j < g->n; j++){
						if (j == k){
							score->data[j] = -score->data[j];
						}
						else{
							score[j] = score[j] - 4*S[j]*S[k]*(g->B[(j*g->n)+k]);
						}
					}
				}
				remove_index(unmoved, k);
				/*lines 21-30*/
				l = find_max_index(unmoved, improve);
				for (i = g->n-1; i > l; i--){
					j = *(indices->data + i);
					*(S + j) = -*(S + j); //S[j]
				}
				if (l == g->n-1){
					delta_Q = 0;
				}
				else{
					delta_Q = *(improve + l);
				}
			}
		}
	}
	array_delete(unmoved);
	array_delete(indices);
	array_delete(score);
	array_delete(improve);
	free(x);

}


double* mult(double *B,int *S){

}

int is_not_emapty(array* unmoved){
	if (unmoved->size == 0){
		return 0;
	}
	return 1;
}

int find_max_index(array* unmoved, array* score){
	int i;
	double *p, max_score = 0, max_k = 0;
	for (i = 0; i < unmoved->size; i++){
		if ((*p >= max_score) && in_array(unmoved, i)){
			max_k = i;
		}
	}
	return max_k;
}

