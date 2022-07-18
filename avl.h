#ifndef __AVL__
#define __AVL__
#include <stdio.h>
#include <stdlib.h>


struct nodo {
    int val;
    int height;
    
    struct nodo* esq;
    struct nodo* dir;
    struct nodo* mom;
};
typedef struct nodo nodo_t;

struct avl {
    nodo_t* root;
};
typedef struct avl avl_t;

avl_t* touchAVL();
int liberaAVL(avl_t* avl);


int balanInsert(nodo_t* nodo, nodo_t* raiz);


int insertNodo(avl_t* avl, int value);
int liberaNodo(nodo_t* nodo);
void emOrdemPrint(nodo_t* nodo);

#endif