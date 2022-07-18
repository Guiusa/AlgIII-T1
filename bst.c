#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

bst_t* touchBST(){
    bst_t*bst = malloc(sizeof(bst_t));
    if(!bst)
        return NULL;

    bst->root = NULL;

    return bst;
}

int liberaBST(bst_t* bst){
    liberaNodo(bst->root);
    free(bst);
    return 1;
}

void emOrdemPrint(nodo_t* nodo){
    if(!nodo){
        return;
    }
    emOrdemPrint(nodo->esq);
    printf("%d\n", nodo->val);
    emOrdemPrint(nodo->dir);
}

int liberaNodo(nodo_t* nodo){
    if(!nodo){
        return 0;
    }
    liberaNodo(nodo->esq);
    liberaNodo(nodo->dir);
    free(nodo);
    return 1;
}
nodo_t* sucessor(bst_t* bst, nodo_t* nodo){
    if(!nodo->dir){
        
    }
    nodo = nodo->dir;
    while(nodo->esq)
        nodo = nodo->esq;
    return nodo;
}

int rmNodo(bst_t* bst, int value){
    nodo_t* aux = bst->root;
    while(aux){
        if(aux->val == value){
            break;
        }
        if(aux->val > value){
            aux = aux->esq;
        }
        else if(aux->val <= value){
            aux = aux->dir;
        }
    }
    if(!aux){
        return 0;
    }
    nodo_t* auxSuc = sucessor(bst, aux);
    
    aux->dir->mom = auxSuc;
    aux->esq->mom = auxSuc;
    auxSuc->mom = aux->mom;
    auxSuc->esq = aux->esq;
    auxSuc->dir = aux->dir;
    aux = auxSuc;

    return 1;
}

int insertNodo(bst_t* bst, int value){
    nodo_t* currNodo = malloc(sizeof(nodo_t));
    if(!currNodo)
        return 0;
    currNodo->val = value;
    currNodo->mom = NULL;
    currNodo->esq = NULL;
    currNodo->dir = NULL;
    if(!bst->root){
        bst->root = currNodo;
        return 1;
    }

    nodo_t* auxNodo;
    auxNodo = bst->root;
    while(1){
        if(currNodo->val <= auxNodo->val){
            if(auxNodo->esq){
                auxNodo = auxNodo->esq;
            }
            else{
                auxNodo->esq = currNodo;
                currNodo->mom = auxNodo;
                break;
            }
        }
        else{
             if(auxNodo->dir){
                auxNodo = auxNodo->dir;
            }
            else{
                auxNodo->dir = currNodo;
                currNodo->mom = auxNodo;
                break;
            }
        }
    }

    return 1;
}