#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "spmat.h"
#include "graph.h"

void create_spmat (spmat*, graph*, int);

int main(int argc, char* argv[]){
	FILE* input_file = fopen(argv[1], "r");
	FILE* output_file = fopen(argv[2], "w");
	//assert(argc > 0);
	graph* src_graph;


	/*read input file to struct graph*/
	src_graph = initialize_graph_from_input(input_file);

	/*crates A as spmat*/
	crate_spmat(src_graph, src_graph->n);

}

void create_spmat (graph* graph, int n){
	int* p;
	int i = 0;
	spmat* A = spmat_allocate_list(n);
	int** src_A = graph->A;
	for (p = &src_A[0]; p < src_A[n] ; p++){
		A->add_row(A, p, i);
		i++;
	}
}

