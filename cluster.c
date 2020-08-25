#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "spmat.c"
#include "graph.c"
#include "algorithm2.c"
#include "algorithm4.c"
#include "linked_list.c"


int main(int argc, char* argv[]){
	FILE* input_file = fopen(argv[1], "r");
	FILE* output_file = fopen(argv[2], "w");
	//assert(argc > 0);
	linked_list* P, O;
	Node *g1, *g2, *group, *res_groups;
	graph* src_graph, g;
	double* K;
	int i = 0, *p, first_group;


	/*read input file to struct graph*/
	src_graph = initialize_graph_from_input(input_file);

	/*crates A as spmat*/
	crate_spmat(src_graph, src_graph->n);

	/*compute f*/

	/*initialize P,O as linked lists*/
	first_group = (int*)malloc(sizeof(int)*src_graph->n);
	for (p = first_group; p < (first_group + src_graph->n); p++){
		*p = i;
		i++;
	}
	P->head->data = first_group;

	/*algorithm 2 iteration*/
	P->head = group;
	while (group != NULL){
		res_groups = divide_a_group_into_two(group); //get g
		g1 = res_groups[0];
		g2 = res_groups[1];
		/*algorithm 4*/
		maximization_delta_Q(g1, g2);
		if (g1->data->n == 0){
			O->tail->next = g2;
			O->tail = g2;
		}
		if (g2->data->n == 0){
			O->tail->next = g1;
            O->tail = g1;
        }
		else{
			if(g1->data->n == 1){
				O->tail->next = g1;
                O->tail = g1;
            }
			if(g2->data->n == 1){
				O->tail->next = g2;
                O->tail = g2;
            }
			else{
			P->tail->next = g1;
			P->tail->next->next = g2;
			P->tail = g2;
			}
		}
	}
	//return O;
}

//general way after we have neighbors list

double* build_k (graph* graph){
	double* K;
	int i, j;

	//write code//
	return K;
}


