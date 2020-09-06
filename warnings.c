#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "spmat.c"
#include "graph.c"

void assert_int(int,int);

void assert_int(int source,int dest){
	if(source != dest){
		exit(0);
	}
}
