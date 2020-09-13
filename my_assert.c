#include <stdio.h>
#include <stdlib.h>

void assert_int(int source, int dest);

void assert_int(int source, int dest){
	if (source != dest){
		exit(0);
	}
}
