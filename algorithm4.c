#include "algorithm4.h"
#include <math.h>

void maximization_delta_Q(int* S, graph* g){
	int i, j, k, *r, *q, l;
	double *x, delta_Q = 0, *p, *h;
	array *unmoved, *indices, *score, *improve;
	x = (double*)malloc(sizeof(double)*g->n);
	unmoved = (array*)malloc(sizeof(array));
	indices = (array*)malloc(sizeof(array));
	score = (array*)malloc(sizeof(array));
	improve = (array*)malloc(sizeof(array));
	allocate_mem_size_n(unmoved, g->n);
	allocate_mem_size_n(indices, g->n);
	allocate_mem_size_n(score, g->n);
	allocate_mem_size_n(improve, g->n);

	/*
	printf("S before = \n");
	for (m = 0; m < g->n; m++){
	    printf("%d  ", S[m]);
	}
	printf("\n");
*/
	while (delta_Q > 0){
		unmoved_initialization(unmoved);
		x = multi(g,S);
		/*computing delta_Q for each spnode - block 2*/
		q = S;
		h = x;
		r = g->A_row_sum;
		for (p = score->data; p < (score->data + g->n); p++){
			*p = -2*(*h*(*q)+(pow((*r),2))/g->M);
			h++;
			q++;
			r++;
		}
		for (i = 0; i < g->n; i++){
			k = find_max_index(unmoved, score);
			/*changing group for index k*/
			*(S + k) = -*(S + k);
			indices->data[i]= k;
			/*line 14-18*/
			if (i == 0){
				improve->data[i] = score->data[k];
			}
			else{
				improve->data[i] = score->data[i-1] + score->data[k];
			}
			remove_index(unmoved, k);
			/*block 3*/
			for (j = 0; j < g->n; j++){
				if (j == k){
					score->data[j] = -score->data[j];
				}
				else{
					score->data[j] = score->data[j] - 4*S[j]*S[k]*(g->B[(j*g->n)+k]);
				}
			}
		}
		/*lines 21-30*/
		l = find_max_index_in_improve(improve);
		for (i = g->n-1; i > l; i--){
			j = *(indices->data + i);
			*(S + j) = -*(S + j);
			}
		if (l == g->n-1){
			delta_Q = 0;
		}
		else{
			delta_Q = improve->data[l];
		}
	}

	array_delete(unmoved);
	array_delete(indices);
	array_delete(score);
	array_delete(improve);
	free(x);
	printf("finish algorithm 4\n");

}


double* multi(graph *group,int *S){
    int n = group -> n, i;
    double sum_sk = 0;
    spmat* A = group->A_spmat;
    double *a_tmp = calloc(n, sizeof(double ));
    double *result = calloc(n, sizeof(double));

    mult(A, (double *)S, a_tmp);
    for (i = 0; i < n; i++)
    {
        sum_sk = sum_sk + (S[i] * group ->A_row_sum[i]);
    }
    for (i = 0; i < n; i++)
    {
        result[i] = a_tmp[i] - (group->A_row_sum[i] * sum_sk / group->M);
    }
    return result;
}

int find_max_index(array* unmoved, array* score){
	int i;
	double *p, max_score = 0, max_k = 0;
	p = score->data;
	for (i = 0; i < unmoved->size; i++){
		if ((*p >= max_score) && in_array(unmoved, i)){
			max_k = i;
		}
		p++;
	}
	return max_k;
}

void unmoved_initialization(array* unmoved){
	int i;
	for (i = 0; i < unmoved->size; i++){
		unmoved->data[i] = i;
	}
}

int find_max_index_in_improve(array* improve){
    int i, max_i;
    double max_imp = 0;
    for (i = 0; i < improve->size; i++){
        if (improve->data[i] >= max_imp){
            max_i = i;
        }
    }
    return max_i;
}

