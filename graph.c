#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "my_assert.h"

graph* initialize_graph_from_input(FILE* input_file){
	int k, i, n, j, *q, *p, M = 0, *A, *curr_vertex_neighbors, m;
	double  *K, k_sum, r;
	graph* s_graph;

	s_graph = malloc(sizeof(graph));
	k = fread(&n, sizeof(int), 1, input_file);
	assert_int(k,1);
	s_graph->n = n;
	A = (int*)malloc((n*n*sizeof(int)));
	for(i = 0; i < n; i++){
	    for (j = 0; j < n; j++){
	        A[n*i + j] = 0;
	    }
	}
	s_graph->ver_list = malloc((sizeof(int)*n));
	for (m = 0; m <n; m++){
	    s_graph->ver_list[m] = m;
	}
	s_graph->A_row_sum = (int*)malloc(n*sizeof(int));

	/* create A and calculate M */
	for (i = 0; i < n; i++){
		k = fread(&j, sizeof(int), 1, input_file);;
        assert_int(k,1);
		*(s_graph->A_row_sum + i) = j;
		curr_vertex_neighbors = (int*) (malloc((j)*sizeof(int)));
		k = fread(curr_vertex_neighbors, sizeof(int), j, input_file);
		assert_int(k,j);
		for (q = curr_vertex_neighbors; q<(curr_vertex_neighbors + j); q++){
			*(A + (i*n) + (*q)) = 1;
			M += 1;
		}
		s_graph->M=M;
	}
    s_graph->A = A;
	/*builds K*/
	K = (double*)malloc(n*n*sizeof(double));
	s_graph->K_row_sum = (double*)malloc(s_graph->n*sizeof(double));
	i = 0;
	for(p = s_graph->A_row_sum; p<(s_graph->A_row_sum + n); p++){
	    j = 0;
	    k_sum = 0;
		for(q = s_graph->A_row_sum; q<(s_graph->A_row_sum + n); q++){
		    r = (double)((*q)*(*p))/M;
			*(K + (i*n) +j) = r;
			k_sum += r;
			j++;
		}
		s_graph->K_row_sum[i] = k_sum;
		i++;
		j = 0;
	}
	s_graph->K = K;
	compute_B(s_graph);
	compute_f(s_graph);
	return s_graph;
}

graph* array_to_graph(int* list_nodes, graph* original_graph, int len){
	graph* new_graph = malloc(sizeof(graph*));
	new_graph->n = len;
	if (len == 0){
	    printf("len is 0\n");
	    return new_graph;
	}
	else{
        new_graph->ver_list = list_nodes;
        reduction_A(new_graph, len, list_nodes, original_graph);
        printf("finish reduction_A\n");
        reduction_K(new_graph, len);
        printf("finish reduction_K\n");
        compute_B(new_graph);
        printf("finish reduction_B\n");
        create_spmat (new_graph, len);
        printf("finish spmat\n");
        compute_f(new_graph);
        printf("finish array to graph\n");
        return new_graph;
	}
}

void reduction_A(graph* new_graph, int len, const int* g, graph* src_graph){
	int i, j, row_sum, M = 0;
	int* src_A = src_graph->A,  *reduction_A, *A_row_sum;
	int n = src_graph->n;
    A_row_sum = malloc(sizeof(int)*len);
    reduction_A = malloc(sizeof(int)*len*len);
	for (i = 0; i < len; i++){
		row_sum = 0;
		for (j = 0; j < len; j++){
			if (src_A[g[i]*n+g[j]] == 1){
				reduction_A[i*len + j] = 1;
				M +=1;
				row_sum +=1;
			}
			else{
				reduction_A[i*len + j] = 0;
			}
		}
		new_graph->A_row_sum[i] = row_sum;
	}
    new_graph->A_row_sum = A_row_sum;
	new_graph->A = reduction_A;
	new_graph->M = M;
}

void reduction_K(graph* new_graph, int len){
	double* K, row_sum;
	int M = new_graph->M;
	int i, j, k;
	int* degrees = new_graph->A_row_sum;
    printf("line 1\n");
	new_graph->K_row_sum = malloc((len*sizeof(double)));
    printf("line 2\n");
	K = malloc(len*len*sizeof(double));
    printf("line 3\n");
	for (i = 0; i < len; i++){
		row_sum = 0;
		for (j = 0; j < len; j++){
			k = (*(degrees+i))*(*(degrees+j))/M;
			*(K+(len*i)+j) = k;
			row_sum += k;
		}
		new_graph->K_row_sum[i] = row_sum;
	}
	new_graph->K = K;
}

void compute_B(graph* graph){
	double *q, *i, *B;
	int *p, n;
	n = graph->n;
	B = (double*)malloc(sizeof(double)*n*n);
	q = graph->K;
	i = B;
	for(p = graph->A; p < (graph->A+(n*n)); p++){
		*i = *p-*q;
		q++;
		i++;
	}
	graph->B = B;
}

void compute_f(graph* graph){
	int i, j, n = graph->n;
	double *f, sum = 0, x;
	f = (double*)malloc(sizeof(double)*n);
	for(i = 0;i < n; ++i){
	    for (j = 0; j < n; ++j){
	        x = graph->B[n*i + j];
            sum += x;
        }
	    f[i] = sum;
        sum = 0;
	}
	graph->f = f;

}

void delete_graph(graph* graph){
	free(graph->A);
	free(graph->A_row_sum);
	free_sm(graph->A_spmat);
	free(graph->K);
	free(graph->K_row_sum);
	free(graph->B);
	free(graph->f);
	free(graph->ver_list);
}

void create_spmat (graph* graph, int n){
    int* p;
    int i = 0;
    spmat* A = spmat_allocate(n);
    int* src_A = graph->A;
    for (p = src_A; p < (src_A + n*n) ; p +=n){
        add_row(A,p, i);
        i++;
    }
    graph->A_spmat = A;
    printf("-----------spmat-------------\n");
    printSpmat(A);
}
