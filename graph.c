#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "my_assert.h"

graph* initialize_graph_from_input(FILE* input_file){
	int k, i, n, j, *q, *p, M = 0, *A, *curr_vertex_neighbors;
	double  *K;
	graph* graph;

	graph = malloc(sizeof(*graph));
	k = fread(&n, sizeof(int), 1, input_file);
	printf("im here 3\n");
	assert_int(k,1);
    printf("im here 4\n");
	graph->n = n;
	A = (int*)malloc((n*n*sizeof(int)));

	graph->A_row_sum = (int*)malloc(n*sizeof(int));

	/* create A and calculate M */
	for (i = 0; i < n; i++){
		k = fread(&j, sizeof(int), 1, input_file);
        printf("im here 5\n");
        assert_int(k,1);
		*(graph->A_row_sum + i) = j;
		curr_vertex_neighbors = (int*) (malloc((j)*sizeof(int)));
		k = fread(curr_vertex_neighbors, sizeof(int), j, input_file);
		printf("before out\n");
		assert_int(k,j);
		printf("after out\n");
		for (q = curr_vertex_neighbors; q<(curr_vertex_neighbors + j); q++){
			*(A + (i*n) + (*q)) = 1;
			M += 1;
		}
		graph->M=M;
	}
    graph->A = A;
    printf("im here 6\n");
	/*builds K*/
	K = (double*)malloc(n*n*sizeof(double));
	i = 0;
	for(p = graph->A_row_sum; p<(graph->A_row_sum + n); p++){
	    j = 0;
		for(q = graph->A_row_sum; q<(graph->A_row_sum + n); q++){
			*(K + (i*n) +j) = (double)((*q)*(*p))/M;
			j++;
		}
		i++;
	}
	graph->K = K;
	compute_B(graph);
    printf("finish compute B\n");
	compute_f(graph);
	printf("finish initiliaze graph\n");
	return graph;
}

graph* array_to_graph(int* list_nodes, graph* original_graph, int len){
	graph* new_graph = malloc(sizeof(graph));
	new_graph->n = len;
	new_graph->ver_list = list_nodes;
	reduction_A(new_graph, len, list_nodes, original_graph);
	reduction_K(new_graph, len);
	create_spmat (new_graph, len);
	compute_f(new_graph);
	return new_graph;
}

void reduction_A(graph* new_graph, int len, const int* g, graph* src_graph){
	int i, j, row_sum, M = 0;
	int* src_A = src_graph->A;
	int n = src_graph->n;
	int* reduction_A = (int*)malloc(sizeof(int)*len);
	for (i = 0; i < len; i++){
		row_sum = 0;
		for (j = 0; j < len; j++){
			if (src_A[g[i]*n+g[j]] == 1){
				reduction_A[i*len + j] = 1;
				M +=1;
				row_sum +=1;
			}
			else{
				reduction_A[i*n + j] = 0;
			}
		}
		new_graph->A_row_sum[i] = row_sum;
	}
	new_graph->A = reduction_A;
	new_graph->M = M;
}

void reduction_K(graph* new_graph, int len){
	double* K = (double*)malloc(sizeof(double)*len);
	int M = new_graph->M;
	int i, j, k, row_sum;
	int* degrees = new_graph->A_row_sum;
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
    printf("in compute B 1\n");
	B = (double*)malloc(sizeof(double)*n*n);
    printf("in compute B 2\n");
	q = graph->K;
	i = B;
    printf("in compute B 3\n");
	for(p = graph->A; p < (graph->A+(n*n)); p++){
		*i = *p-*q;
		q++;
		i++;
	}
	graph->B = B;
}

void compute_f(graph* graph){
	int i, j, n = graph->n;
	double *f, sum;
	f = (double*)malloc(sizeof(double)*n);
	for(i = 0;i < n; i++){
	    sum = 0;
	    for (j = 0; j < n; j++){
	        sum += graph->B[n*i + j];
	    }
	    f[i] = sum;
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
    for (p = src_A; p < (src_A + n) ; p++){
        add_row(A, (double*)p, i);
        i++;
    }
}
