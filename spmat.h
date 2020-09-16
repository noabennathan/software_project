#ifndef _SPMAT_H
#define _SPMAT_H

typedef struct _spmat {
    /* Matrix size (n*n) */
    int		n;
    /* Private field for inner implementation.
     * Should not be read or modified externally */
    void	*private;
} spmat;

/* Adds row i the matrix. Called before any other call,
 * exactly n times in order (i = 0 to n-1) */
void	add_row (struct _spmat *A, int *row, int i);

/* Frees all resources used by A */
void	free_sm(struct _spmat *A);

/* Multiplies matrix A by vector v, into result (result is pre-allocated) */
void	mult(struct _spmat *A, const double *v, double *result);


/* Allocates a new linked-lists sparse matrix of size n */
spmat* spmat_allocate(int n);

void printSpmat(spmat *spm);
#endif
