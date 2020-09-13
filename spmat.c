#include <stdio.h>
#include <stdlib.h>
#include "spmat.h"
#include "graph.h"


struct sp_Linked_list{
    double val;
    int col;
    struct sp_Linked_list *next;
} sp_Linked_list;
typedef struct sp_Linked_list spnode;



/* Allocates a new linked-lists sparse matrix of size n */
spmat* spmat_allocate(int n)
{
    spmat *sm = malloc(sizeof(spmat));
    spnode** row_lists = (spnode**)malloc(n * sizeof(spnode));
    sm -> private = row_lists;
    return sm;
}




/* Adds row i the matrix. Called before any other call,
	 * exactly n times in order (i = 0 to n-1) */
void	add_row (struct _spmat *A, const double *row, int i)
{
    int n = A -> n;
    spnode* head = NULL;
    spnode* tail = NULL;
    spnode** row_lists = (spnode**) A -> private;
    int j;
    int nnz = 0;
    for (j = 0; j < n; j++)
    {
        if (row[j] != 0)
        {
            if (head == NULL)
            {
                head = tail = malloc(sizeof(spnode));
            }
            else
            {
                tail->next = malloc(sizeof(spnode));
                tail = tail->next;
                tail->val = row[j];
                tail->col = j;
            }
        }
    }
    row_lists[i] = head;
}


void empty_list(spnode* list_head){
    if(list_head != NULL){
        empty_list(list_head->next);
        free(list_head);
    }
}



/* Frees all resources used by A */
void	free_sm(struct _spmat *A)
{
    spnode** row_lists;
    int i;
    row_lists = (spnode**) A -> private;
    for (i = 0; i < A -> n; i++)
    {
        empty_list(row_lists[i]);
    }
        free(row_lists);
        free(A);
}


/* Multiplies matrix A by vector v, into result (result is pre-allocated) */
void	mult(const struct _spmat *A, const double *v, double *result)
{
    int i;
    double sum;
    spnode* temp;
    spnode** row_lists = (spnode**) A->private;
    for (i = 0; i < A->n; i++)
    {
        temp = row_lists[i];
        sum = 0;
        while(temp != NULL)
        {
            sum = sum + (temp->val * v[temp->col]);
            temp = temp->next;
        }
        result[i] = sum;
    }
}

void create_spmat (graph* graph, int n){
	int* p;
	int i = 0;
	spmat* A = spmat_allocate(n);
	int* src_A = graph->A;
	for (p = src_A; p < (src_A + n) ; p++){
		add_row(A, (double*)p, i);
		i++;
	}
}


