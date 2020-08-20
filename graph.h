#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct graph {
	/* n = |V| number of vertices */
	int n;
	/*adjacency matrix*/
	int* A;
	/*2 * number of edges*/
	int M;
	/*expectation edges matrix*/
	double* K;

	int* f;

	/*modularity matrix*/
	double** B;

	/*list of dagrees*/
	int* neighbors;

} graph;

/* creates the source graph from the input file *
 * calculates M *
 * build K */
graph* initialize_graph_from_input(FILE* input_file);
/*creates the reduction graph g from the original graph and A*/
graph* reduction_graph(int* g, int original_A);
/*creates the reduction A from the original A*/
int* reduction_A(int n, int* g, int M);
double* reduction_K(int n, int* reduction_A, int reduction_M);

