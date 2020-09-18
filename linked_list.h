#include "graph.h"

typedef struct Node{
    graph *data;
    struct Node* next;
}Node;

typedef struct linked_list{
    Node* head;
    Node* tail;
}linked_list;

void initialize_list(linked_list* P);

/*adds the graph that receives to be the first graph, the head*/
void add_node(linked_list* P, graph* graph);

void delete_first_node(linked_list* P);

void delete_list_rec(Node* node);

void delete_list(linked_list* P);


int* list_count(linked_list* P);
