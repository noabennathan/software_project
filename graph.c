#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "spmat.c"

int* reduction_A(int n, int* g, int* src_A);
double* reduction_K(int n, int* g, int* src_A);

graph* initialize_graph_from_input(FILE* input_file){
	int k, i, n, j, *q, *p, M = 0, row_sum;
	double  *K;
	graph* graph;
	int* curr_vertex_neighbors;
	int* A = graph->A;
	k = fread(&n, sizeof(int), 1, input_file);
	graph->n = n;
	//assert(k == 1);

	graph->A_row_sum = (int*)malloc(sizeof(int)*n);

	/* create A and calculate M */
	A = (int*)malloc(sizeof(int)*n*n);
	for (i = 0; i < n; i++){
		k = fread(&j, sizeof(int), 1, input_file);
		*(graph->A_row_sum + i) = j; //now A_row_sum[i] = ki the number of neighbors i has
		//assert(k == 1);
		curr_vertex_neighbors = (int*) (malloc(j*sizeof(int)));
		k = fread(curr_vertex_neighbors, sizeof(int), j, input_file);
		//assert(k == j);
		for (q = curr_vertex_neighbors; q<(curr_vertex_neighbors + j); q++){
			*(A + (i*n) + k) = 1;
			M += 1;
		}
		graph->M=M;
	}

	/*builds K*/
	i = 0;
	j = 0;
	for(p = graph->A_row_sum; p<(graph->A_row_sum + n); p++){
		for(q = graph->A_row_sum; q<(graph->A_row_sum + n); q++){
			*(K + (i*n) +j) = ((*q)*(*p))/M;
			j++;
		}
		i++;
	}
	return graph;

}
graph* array_to_graph(int* list_nodes, graph* original_graph, int len){
	graph* new_graph = malloc(sizeof(graph));
	reduction_A(new_graph, len, list_nodes, original_graph);
	reduction_K(new_graph, len, list_nodes, original_graph);
	create_spmat (new_graph, len);

	return new_graph;
}
void reduction_A(graph new_graph, int len, int* g, graph* src_graph){
	int i, *row, j, row_sum, *p, *q, *h, k, M;
	int* src_A = src_graph->A;
	int n = src_graph->n;
	int* reduction_A = (int*)malloc(sizeof(int)*len);
	q = reduction_A;
	p = g;
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

void reduction_K(graph new_graph, int len, int* g, graph* src_graph){
	double* K = malloc(sizeof(double)*len);
	int M = new_graph->M;
	int i, j, k, count;
	for (i = 0; i < len; i++){
		for (j = 0; j < len; j++){
			if ()
		}
	}

	new_graph->K = K;

}
