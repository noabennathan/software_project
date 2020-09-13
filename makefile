FLAGS=-ansi -Wall -Wextra -Werror -pedantic-errors -c
LIBS=-lm

all: cluster.o algorithm2.o algorithm4.o graph.o linked_list.o my_array.o my_assert.o spmat.o
	gcc cluster.o algorithm2.o algorithm4.o graph.o linked_list.o my_array.o my_assert.o spmat.o -o cluster ${LIBS}

cluster.o: cluster.c spmat.h graph.h linked_list.c algorithm2.c algorithm4.c my_assert.c
	gcc ${FLAGS} cluster.c

algorithm2.o: algorithm2.c spmat.h linked_list.c graph.c
    gcc ${FLAGS} algorithm2.c

algorithm4.o: algorithm4.c graph.c graph.h my_array.c spmat.h
	gcc ${FLAGS} algorithm4.c

graph.o: graph.c spmat.c my_assert.c
	gcc ${FLAGS} graph.c

linked_list.o: linked_list.c graph.c graph.h
	gcc ${FLAGS} linked_list.c

my_array.o: my_array.c
	gcc ${FLAGS} my_array.c

my_assert.o: my_array.c
	gcc ${FLAGS} my_assert.c

spmat.o: spmat.c
	gcc ${FLAGS} spmat.c

clean:
	rm -rf *.o cluster