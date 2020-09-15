#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "algorithm2.h"

#define IS_POSITIVE(X) ((X) > 0.00001)

/*Divides a group into two
 * @param group the group to split
 * all the comments below are according to the flow of algorithm 2 as presented in the instructions
 */

int* divide_a_group_into_two(Node* g){
    graph *group = g ->data;
    double *eigen_value, *eigen_vector, sBs;
    int *S, i, count = 0;
    S = (int*)malloc(sizeof(int) * group -> n);
    eigen_value = (double*)malloc(sizeof(int));
    eigen_vector = (double*)malloc(group->n * sizeof(int));
    printf("checkin the graph data\n");
    printf("%d\n", group->n);

    for (i = 0; i < group ->n; i++)
    {
        S[i] = 1;
    }


    mat_shift(group);
    printf("finish mat shift");
    /*line 1*/
    power_iteration(group, eigen_vector, eigen_value);

    /*line 2*/
    if (!IS_POSITIVE(*eigen_value))
    {
        return S;
    }

    /*line 3*/
    for (i = 0; i < group->n; i++)
    {
        if (IS_POSITIVE(eigen_vector[i]))
        {
            S[i] = 1;
            count++;
        }
        else
            S[i] = -1;
    }

    /*line 4*/
    sBs = calculate_sbs(group, S);
    if (!IS_POSITIVE(sBs))
    {
        return S;
    }

    return S;
}
void mat_shift(graph* group)
{
    int i;
    double C = 0;
    /*calculate the 1-norm*/
    printf("in mat shift");
    for (i = 0; i < group->n; i++)
    {
        if(group->A_row_sum[i] + group->K_row_sum[i] + group->f[i] > C)
            C = group->A_row_sum[i] + group->K_row_sum[i] + group->f[i];
    }
    for (i = 0; i < group->n; i++)
    {
        group->f[i] = group->f[i] + C;
    }
    printf("finish mat shift");

}



/* finds the eigenpair for B^[g]
* @param group the group of vertexes
* @param eigen_vector the result eigen vector
* @param eigen_value the result eigen value

*/
void power_iteration(graph* group, double* eigen_vector, double* eigen_value)
{
    /*initializion*/
    double *b, *nextb, *a_tmp, *k_tmp, *f_tmp, *tmp, sum_sk = 0, sum, norma, x, y;
    spmat* A = group->A_spmat;
    double* f = group->f;
    int* A_row_sum = group -> A_row_sum;
    int diff = 1, i, n = group->n;
    printf("power iteration\n");


    srand(time(NULL));

    b = eigen_vector;
    nextb = calloc(n, sizeof(double));
    a_tmp = calloc(n, sizeof(double));
    f_tmp = calloc(n, sizeof(double));
    k_tmp = calloc(n, sizeof(double));

    for (i = 0; i < n; ++i)
    {
        b[i] = rand();
    }

    /*in this loop we find the leading eigenvector */
    while (diff == 1)
    {
        diff =0;
        mult(A, b, a_tmp);
        for (i = 0; i < n; i++)
        {
            f_tmp[i] = b[i] * f[i];
            sum_sk = sum_sk + (b[i] * A_row_sum[i]);
        }
        for (i = 0; i < n; i++)
        {
            k_tmp[i] = sum_sk * A_row_sum[i] / group->M;
            nextb[i] = a_tmp[i] - k_tmp[i] - f_tmp[i];
            sum = sum + nextb[i] * nextb[i];
        }
        norma = sqrt(sum);
        sum = 0;

        for (i = 0; i < n; i++)
        {
            nextb[i] = nextb[i]/norma;
            if (fabs(nextb[i] - b[i]) > 0.00001)
                diff = 1;
        }

        tmp = b;
        b = nextb;
        nextb = tmp;
    }


    /*this section finds the eigenvalue matching the eigenvector we found*/
    mult(A, b, a_tmp);
    for (i = 0; i < n; i++)
    {
        f_tmp[i] = b[i] * f[i];
        sum_sk = sum_sk + (b[i] * A_row_sum[i]);
    }
    for (i = 0; i < n; i++)
    {
        k_tmp[i] = sum_sk * A_row_sum[i] / group->M;
        nextb[i] = a_tmp[i] - k_tmp[i] - f_tmp[i];
        x = nextb[i] * b[i];
        y = b[i] * b[i];
    }
    *eigen_value = x/y;
    free(nextb);
    free(a_tmp);
    free(k_tmp);
    free(f_tmp);
}

double calculate_sbs(graph* group, int* S)
{
    spmat* A = group->A_spmat;
    double* f = group->f;
    int* A_row_sum = group -> A_row_sum;
    double *a_tmp, *f_tmp, a_res = 0, f_res = 0, sum_sk = 0;
    int i, n = group->n;

    a_tmp = calloc(n, sizeof(double));
    f_tmp = calloc(n, sizeof(double));

    mult(A, (double*)S, a_tmp);
    for (i = 0; i < n; i++)
    {
        f_tmp[i] = S[i] * f[i];
        /*k_res = sum_sk^2*/
        sum_sk = sum_sk + (S[i] * A_row_sum[i]);
    }
    for (i = 0; i < n; i++)
    {
        a_res = a_res + a_tmp[i] * S[i];
        f_res = f_res + f_tmp[i] * S[i];
    }

    free(a_tmp);
    free(f_tmp);
    return (a_res + f_res + sum_sk * sum_sk);
}
