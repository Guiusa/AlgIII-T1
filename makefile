parametrosCompilacao=-std=c99 -Wall
nomePrograma=myavl

all: $(nomePrograma)

$(nomePrograma): myavl.o avl.o
	gcc -o $(nomePrograma) myavl.o avl.o $(parametrosCompilacao)

myavl.o: myavl.c
	gcc -c myavl.c $(parametrosCompilacao)

avl.o: avl.h avl.c
	gcc -c avl.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
cleanr:
	rm -f *.o *.gch $(nomePrograma)
	clear