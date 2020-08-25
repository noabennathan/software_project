#include "graph.c"
#include "graph.h"


typedef struct Node{
	graph* data;
	struct Node* next;
}Node;

typedef struct linked_list{
	Node* head;
	Node* tail;
}linked_list;
