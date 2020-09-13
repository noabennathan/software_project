#include "graph.h"


typedef struct Node{
	graph* data;
	struct Node* next;
}Node;

typedef struct linked_list{
	Node* head;
}linked_list;

void initialize_list(linked_list* P){
	P = (linked_list*)malloc(sizeof(linked_list));
	P->head = NULL;
}

/*adds the graph that receives to be the first graph, the head*/
void add_node(linked_list* P, graph* graph){
	Node* save = P->head;
	Node* new_node = (Node*)malloc(sizeof(Node*));
	new_node->data = graph;
	P->head = new_node;
	P->head->next = save;
}

void delete_first_node(linked_list* P){
	Node* save = P->head->next;
	free(P->head);
	P->head = save;
}
void delete_list_rec(Node* node){
	if (node != NULL){
		delete_list_rec(node->next);
		free(node);
	}
}
void delete_list(linked_list* P){
    delete_list_rec(P->head);
}

int* list_count(linked_list* P){
	int *count = NULL;
    Node *node;
	*count = 0;
	node = P->head;
	while (node != NULL){
		*count += 1;
		node = node->next;
	}
	return count;
}
