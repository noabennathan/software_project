#include <stdlib.h>
#include "my_array.h"

void allocate_mem_size_n(array *arr, int n){
	double *new_data = (double*)malloc(sizeof(double)*n);
	arr->data = new_data;
}

void remove_index(array *arr, int index){
	int original_size = arr->size;
	int new_size = original_size-1;
	int i, j = 0;
	double* new_data = (double*)malloc(sizeof(double)*new_size);
	for (i = 0; i < new_size; i++){
		if (arr->data[i] != index){
			new_data[j] = i;
			j++;
		}
	}
	arr->data = new_data;
}

int in_array(array* arr, double i){
	double *p;
	int ret = 0;
	for (p = arr->data; p < (arr->data + arr->size); p++){
		if(*p == i){
			ret = 1;
		}
	}
	return ret;
}

void array_delete(array* arr){
	free(arr->data);
	free(arr);
}
