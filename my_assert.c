#include <stdlib.h>

void assert_int(int source, int dest);

void assert_int(int source, int dest){
	if (source != dest){
		exit(0);
	}
}

void assert_biiger_zero(int source){
    if (source>= 0){
        exit(0);
    }
}
