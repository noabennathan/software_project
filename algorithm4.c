#include "linked_list.c"
#include <math.h>
#include "my_array.c"
#include "spmat.h"


void maximization_delta_Q(int* S, graph* g);
void unmoved_initialization(array* unmoved);
int find_max_index(array* unmoved, array* score);
double* multi(graph *group,int *S);

void maximization_delta_Q(int* S, graph* g){
	int max_index, i, j, k, m, *r, *q, l;
	double *x, delta_Q, Q_0, *p, *h, max_score, max_improve;
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
		l = find_max_index(unmoved, improve);
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

}


double* multi(graph *group,int *S){
    int n = group -> n, i;
    double sum_sk = 0;
    spmat* A = group->A_spmat;
    double *a_tmp = calloc(n, sizeof(double ));
    double *result = calloc(n, sizeof(double));

    mult(A, (double*)S, a_tmp);
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

int is_not_empty(array* unmoved){
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

void unmoved_initialization(array* unmoved){
	int i;
	for (i = 0; i < unmoved->size; i++){
		unmoved->data[i] = i;
	}
}

