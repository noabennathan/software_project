#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "spmat.h"

typedef struct graph{
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

	/*modularity matrix*/
	double* B;

	double* f;

	/*list of vertex*/
	int* ver_list;

	/*list of row sum of K*/
	double* K_row_sum;

	/*list of row sum of A, A_row_sum[i] = ki*/
	int* A_row_sum;

}graph;



/* creates the source graph from the input file *
 * create A *
 * calculates M *
 * build K */
graph* initialize_graph_from_input(FILE* input_file);

/*creates the reduction graph g from the original graph*/
graph* array_to_graph(int* list_nodes, graph* original_graph, int len);

/*free all the mem that was allocate*/
void delete_graph(graph* graph);

void reduction_A(graph* new_graph, int len, const int* g, graph* src_graph);

void reduction_K(graph* new_graph, int len);

void compute_f(graph* new_graph);

void compute_B(graph* graph);

void create_spmat (graph* graph, int n);




