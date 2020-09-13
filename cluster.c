#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "spmat.c"
#include "graph.c"
#include "algorithm2.c"
#include "algorithm4.c"
#include "linked_list.c"
#include "my_assert.c"


void from_S_to_2_groups(int* S, Node *g1, Node* g2, graph* group);
void write_to_output(FILE* output_file, linked_list O);


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
		delete_first_node(P);
		/*algorithm 4*/
		maximization_delta_Q(S, group);
		from_S_to_2_groups(S, g1, g2, group);
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

void from_S_to_2_groups(int* S, Node *g1, Node* g2, graph* group){
	int *g1_ver, *g2_ver, i, count = 0, j = 0, k = 0;
	for (i = 0; i < group->n; i++)
	{
		if (S[i] == 1){
			count++;
		}
	}
	g1_ver = (int*)malloc(sizeof(int) * count);
	g2_ver = (int*)malloc(sizeof(int) * (group->n - count));
	for (i = 0; i < group->n; i++)
	{
		if (S[i] == 1){
			g1_ver[j] = group -> ver_list[i];
			j++;
		}
		else
		{
			g2_ver[k] = group -> ver_list[i];
			k++;
		}
	}
	g1 -> data = array_to_graph(g1_ver, count);
	g2 -> data = array_to_graph(g2_ver, (group->n - count));
}

void write_to_output(FILE* output_file, linked_list O){
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


