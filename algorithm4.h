#include "algorithm2.h"
#include <math.h>
#include "my_array.h"

void maximization_delta_Q(int* S, graph* g);

void unmoved_initialization(array* unmoved);

int find_max_index(array* unmoved, array* score);

double* multi(graph *group,int *S);

int find_max_index_in_improve(array* improve);
