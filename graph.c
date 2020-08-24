#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENTH(x)  (sizeof(x) / sizeof((x)[0]))

graph* initialize_graph_from_input(FILE* input_file){
	int k, i, n, j, *q, *p, M = 0;
	double  *K;
	graph* graph;
	int* curr_vertex_neighbors;
	int* A = graph->A;
	k = fread(&n, sizeof(int), 1, input_file);
	graph->n = n;
	//assert(k == 1);

	graph->neighbors = (int*)malloc(sizeof(int)*n);
	/* create A and calculate M */
	A = (int*)malloc(sizeof(int)*n*n);
	for (i = 0; i < n; i++){
		k = fread(&j, sizeof(int), 1, input_file);
		*(graph->neighbors + i) = j; //now neighbors[i] = ki the number of neighbors i has
		//assert(k == 1);
		curr_vertex_neighbors = (int*) (malloc(j*sizeof(int)));
		k = fread(curr_vertex_neighbors, sizeof(int), j, input_file);
		//assert(k == j);
		for (q = curr_vertex_neighbors; q<(curr_vertex_neighbors + j); q++){
			*p = *q;
			*(A + (i*n) + p) = 1;
			M += 1;
		}
		graph->M=M;
	}

	/*builds K*/
	i = 0;
	j = 0;
	for(p = graph->neighbors[0]; p<graph->neighbors[n]; p++){
		for(q = graph->neighbors; q<graph->neighbors + n; q++){
			*(K + (i*n) +j) = ((*q)*(*p))/M;
			j++;
		}
		i++;
	}
	return graph;

}

graph* reduction_graph(int* g,int original_A){
	graph* reduction_graph = (graph*)malloc(sizeof(graph));
	reduction_graph->A = reduction_A(LENTH(g), g, original_A);

	return reduction_graph;
}

int* reduction_A(int n, int* g, int* src_A){
	int* reduction_A = (int*)malloc(sizeof(int)*n);

	return reduction_A;
}
