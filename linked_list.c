#include "linked_list.h"

void initialize_list(linked_list* P){
	P->head = NULL;
	P->tail =NULL;
}

/*adds the graph that receives to be the first graph, the head*/
void add_node(linked_list* P, graph* graph){
	Node* new_node = (Node*)malloc(sizeof(Node*));
	new_node->data = graph;
	new_node->next = NULL;
	if(P->head == NULL){
        P->head = new_node;
        P->tail = new_node;
	}
	else{
	    P->tail->next = new_node;
	    P->tail = P->tail->next;
	}
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
