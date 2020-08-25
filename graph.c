#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "spmat.c"

#define LENTH(x)  (sizeof(x) / sizeof((x)[0]))

int* reduction_A(int n, int* g, int* src_A);
graph* reduction_graph(int* g,int original_A);

graph* initialize_graph_from_input(FILE* input_file){
	int k, i, n, j, *q, *p, M = 0;
	double  *K;
	graph* graph;
	int* curr_vertex_neighbors;
	int* A = graph->A;
	k = fread(&n, sizeof(int), 1, input_file);
	graph->n = n;
	//assert(k == 1);

	graph->neighbors_dag = (int*)malloc(sizeof(int)*n);

	/* create A and calculate M */
	A = (int*)malloc(sizeof(int)*n*n);
	for (i = 0; i < n; i++){
		k = fread(&j, sizeof(int), 1, input_file);
		*(graph->neighbors_dag + i) = j; //now neighbors[i] = ki the number of neighbors i has
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
	for(p = graph->neighbors_dag; p<(graph->neighbors_dag + n); p++){
		for(q = graph->neighbors_dag; q<(graph->neighbors_dag + n); q++){
			*(K + (i*n) +j) = ((*q)*(*p))/M;
			j++;
		}
		i++;
	}
	return graph;

}
graph* array_to_graph(int* list_nodes, int* original_A){

}
int* reduction_A(int n, int* g, int* src_A){
	int i, *row;
	int* reduction_A = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++){

	}
	return reduction_A;
}
