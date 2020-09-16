#include <stdio.h>
#include <stdlib.h>
#include "algorithm4.h"
#include "my_assert.h"

void from_S_to_2_groups(int* S, Node *g1, Node* g2, graph* group);
void write_to_output(FILE* output_file, linked_list *O);

int main(int argc, char* argv[]){
    /*delete after debug*/
    int i,j;
    linked_list *P;
    linked_list *O;
    Node *g1, *g2, *group;
    graph* src_graph;
    int *S;
    FILE* input_file = fopen(argv[1], "rb");

	FILE* output_file = fopen(argv[2], "w");
    printf("im here 1\n");
	assert_bigger_zero(argc);
    printf("im here 2\n");

    g1 = (Node*)malloc(sizeof(Node*));
    g2 = (Node*)malloc(sizeof(Node*));
    group = (Node*)malloc(sizeof(Node*));
    P = (linked_list*)malloc(sizeof(linked_list*));
    O = (linked_list*)malloc(sizeof(linked_list*));


	/*read input file to struct graph*/
	src_graph = initialize_graph_from_input(input_file);
	printf("----print A-----");
	for (i = 0; i < src_graph->n; i++){
	    for (j = 0; j<src_graph->n; j++){
	        printf("%d ", src_graph->A[i*src_graph->n + j]);
	    }
	    printf("\n");
	}

    printf("im here again\n");
	/*crates A as spmat*/
	create_spmat(src_graph, src_graph->n);

	initialize_list(P);
	initialize_list(O);

	add_node(P, src_graph);
	/*algorithm 2 iteration*/
    group = P->head;
	printf("checkin the add node\n");
	printf("%d\n",group->data->n);
	while (group != NULL){
        printf("im in algorithm 2\n");
        S = divide_a_group_into_two(group);
        printf("finish algorithm 2");
		delete_first_node(P);
		/*algorithm 4*/
		maximization_delta_Q(S, group->data);
		from_S_to_2_groups(S, g1, g2, group->data);
		if (g1->data->n == 0){
			add_node(O, g2->data);
		}
		if (g2->data->n == 0){
			add_node(O, g1->data);
        }
		else{
			if(g1->data->n == 1){
				add_node(O, g1->data);
            }
			if(g2->data->n == 1){
				add_node(O, g2->data);
            }
			else{
				add_node(P, g1->data);
				add_node(P, g2->data);
			}
		}
	group = P->head;
	}
	printf("write to output\n");
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
			count+= 1;
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
	g1 -> data = array_to_graph(g1_ver, group,count);
	g2 -> data = array_to_graph(g2_ver, group,(group->n - count));
}

void write_to_output(FILE* output_file, linked_list *O){
	int n, *p, *q = NULL, *len = NULL;
    int* ver_list;
	int *num_of_groups = list_count(O);
    Node* node;
    printf("write to output");
	n = fwrite(num_of_groups, sizeof(int), 1, output_file);
	assert_int(n,1);
	node = O->head;
	while (node != NULL){
		*(len) = node->data->n;
		printf("%d",*len);
		n = fwrite(len, sizeof(int), 1, output_file);
		assert_int(n,1);
		ver_list = node->data->ver_list;
		n = fwrite(q, sizeof(int), 1, output_file);
        assert_int(n,1);
		for(p = ver_list; p < (ver_list + *len); p++){
			*q = *p;
			n = fwrite(q, sizeof(int), 1, output_file);
            printf("%d",*q);
			assert_int(n,1);
		}
		node = node->next;

	}
}


