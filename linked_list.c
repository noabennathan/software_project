
typedef struct Node{
	int* data;
	int size;
	struct Node* next;
}Node;

typedef struct linked_list{
	Node* head;
	Node* tail;
}linked_list;
