#ifndef __BST__
#define __BST__
#include <stdio.h>
#include <stdlib.h>


struct nodo {
    int val;
    
    struct nodo* esq;
    struct nodo* dir;
    struct nodo* mom;
};
typedef struct nodo nodo_t;

struct BST {
    nodo_t* root;
};
typedef struct BST bst_t;

bst_t* touchBST();
int liberaBST(bst_t* bst);

nodo_t* sucessor(bst_t* bst, nodo_t* nodo);
int rmNodo(bst_t* bst, int value);
int insertNodo(bst_t* bst, int value);
int liberaNodo(nodo_t* nodo);
void emOrdemPrint(nodo_t* nodo);

#endif