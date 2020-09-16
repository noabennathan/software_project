#include <stdio.h>
#include <stdlib.h>
#include "spmat.h"


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
    spnode** row_lists = (spnode**)malloc(n * sizeof(spnode*));
    sm -> private = row_lists;
    sm ->n = n;
    return sm;
}




/* Adds row i the matrix. Called before any other call,
	 * exactly n times in order (i = 0 to n-1) */
void	add_row (struct _spmat *A, int *row, int i)
{
    int n = A -> n;
    spnode* head = NULL;
    spnode* tail = NULL;
    spnode* new_node;
    spnode** row_lists = (spnode**) A -> private;
    int j;
    for (j = 0; j < n; j++)
    {
        if (row[j] != 0)
        {
            if (head == NULL)
            {
                head = malloc(sizeof(spnode));
                head->val = 1;
                head->col = j;
                head->next = NULL;
                tail = head;

            }
            else
            {
                new_node = malloc(sizeof(spnode));
                new_node->col = j;
                new_node->val = 1;
                new_node->next = NULL;
                tail->next = new_node;
                tail = new_node;
            }
        }
    }
    tail->next = NULL;
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
void	mult(struct _spmat *A, const double *v, double *result)
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

void printSpmat(spmat *spm) {
    int i, j, col;
    spnode** rows = (spnode**) spm->private;
    for (i = 0; i < spm->n; i++) {
        spnode* node = rows[i];
        for (j = 0; j < spm->n; j++) {
            col = node != NULL ? node->col : spm->n;
            if (j < col) {
                printf("%d ", 0);
            } else {
                printf("%d ", (int) node->val);
                node = node->next;
            }
        }
        printf("\n");
    }
}

