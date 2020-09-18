#include <stdlib.h>

typedef struct array{
    int size;
    double* data;
}array;

void allocate_mem_size_n(array *arr, int n);

void remove_index(array *arr, int index);

int in_array(array* arr, double i);

void array_delete(array* arr);
