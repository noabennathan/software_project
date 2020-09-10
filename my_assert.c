#include <stdio.h>
#include <stdlib.h>

assert_int(int source, int dest);

assert_int(int source, int dest){
	if (source != dest){
		exit(0);
	}
}
