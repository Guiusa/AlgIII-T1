OBJ = main.o avl.o
gps: ${OBJ}
	gcc -o avl ${FLAGS} ${OBJ} avl.h 

gps.o: main.c avl.h
	gcc -c main.c ${FLAGS}

utils.o: avl.c avl.h
	gcc -c avl.c ${FLAGS} 

clean:
	rm *.o

purge:
	rm *.o avl