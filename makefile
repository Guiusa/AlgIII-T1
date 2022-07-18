OBJ = main.o bst.o
gps: ${OBJ}
	gcc -o bst ${FLAGS} ${OBJ} bst.h 

gps.o: main.c bst.h
	gcc -c main.c ${FLAGS}

utils.o: bst.c bst.h
	gcc -c bst.c ${FLAGS} 

clean:
	rm *.o

purge:
	rm *.o bst