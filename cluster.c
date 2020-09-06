#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "spmat.c"
#include "graph.c"
#include "algorithm2.c"
#include "algorithm4.c"
#include "linked_list.c"
#include "warnings.c"


int main(int argc, char* argv[]){
	FILE* input_file = fopen(argv[1], "r");
	FILE* output_file = fopen(argv[2], "w");
	//assert(argc > 0);
	linked_list* P, O;
	Node *g1, *g2, *group;
	graph* src_graph, g;
	double* K;
	int i = 0, *p, first_group, *S;

    g1 = (Node*)malloc(sizeof(Node));
    g2 = (Node*)malloc(sizeof(Node));
    group = (Node*)malloc(sizeof(Node));
    src_graph = (graph*)malloc(sizeof(graph));
    P = (linked_list*)malloc(sizeof(linked_list));
    O = (linked_list*)malloc(sizeof(linked_list));


	/*read input file to struct graph*/
	src_graph = initialize_graph_from_input(input_file);

	/*crates A as spmat*/
	crate_spmat(src_graph, src_graph->n);

	/*compute f*/

	initialize_list(P);
	initialize_list(O);

	add_node(P, src_graph);

	/*algorithm 2 iteration*/
	P->head = group;
	while (group != NULL){
//		g1 = divide_a_group_into_two(group);
//		g2 = g1->next;
//		g1->next = NULL;
//		delete_first_node(P);
		/*algorithm 4*/
		maximization_delta_Q(S, group);
		if (g1->data->n == 0){
			add_node(O, g2);
		}
		if (g2->data->n == 0){
			add_node(O, g1);
        }
		else{
			if(g1->data->n == 1){
				add_node(O, g1);
            }
			if(g2->data->n == 1){
				add_node(O, g2);
            }
			else{
				add_node(P, g1);
				add_node(P, g2);
			}
		}
	group = P->head;
	}
	write_to_output(output_file, O);
	delete_list(P);
	delete_list(O);
	delete_graph(src_graph);

	fclose(input_file);
	fclose(output_file);
	return 0;
}

write_to_output(FILE* output_file, linked_list O){
	int n, *p, *q, *len;
	int *num_of_groups = list_count(O);
	n = fwrite(num_of_groups, sizeof(int), 1, output_file);
	//assert(n==1);
	assert_int(n,1);
	Node* node = O->head;
	while (node != NULL){
		*(len) = node->data->n;
		n = fwrite(len, sizeof(int), 1, output_file);
		//assert(n==1);
		assert_int(n,1);
		int* ver_list = node->data->ver_list;
		n = fwrite(q, sizeof(int), 1, output_file);
		for(p = ver_list; p < (ver_list + *len); p++){
			*q = *p;
			n = fwrite(q, sizeof(int), 1, output_file);
			//assert(n==1);
			assert_int(n,1);
		}

	}
}


