#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "spmat.c"

typedef struct graph {
	/* n = |V| number of vertices */
	int n;

	/*adjacency matrix*/
	int* A;

	/*adjacency matrix in spmat*/
	spmat* A_spmat;

	/*2 * number of edges*/
	int M;
	/*expectation edges matrix*/
	double* K;

	int* f;

	/*list of dagrees*/
	int* neighbors_dag;

	int* ver_list;

} graph;



/* creates the source graph from the input file *
 * create A *
 * calculates M *
 * build K */
graph* initialize_graph_from_input(FILE* input_file);

/*creates the reduction graph g from the original graph and A*/
graph* reduction_graph(int* g, int original_A);

graph* array_to_graph(int* list_nodes);

/*creates the reduction A from the original A*/
int* reduction_A(int n, int* g, int M);

double* reduction_K(int n, int* reduction_A, int reduction_M);


