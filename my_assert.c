#include <stdlib.h>
#include "my_assert.h"

void assert_int(int source, int dest){
	if (source != dest){
		exit(0);
	}
}

void assert_bigger_zero(int source){
    if (source>= 0){
        exit(0);
    }
}
