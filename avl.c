#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

avl_t* touchAVL(){
    avl_t* avl = malloc(sizeof(avl_t));
    if(!avl)
        return NULL;

    avl->root = NULL;

    return avl;
}

int liberaAVL(avl_t* avl){
    liberaNodo(avl->root);
    free(avl);
    return 1;
}

void emOrdemPrint(nodo_t* nodo){
    if(!nodo){
        return;
    }
    emOrdemPrint(nodo->esq);
    printf("%d %d\n", nodo->val, nodo->height);
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

int balanInsert(nodo_t* nodo, nodo_t* raiz){
    nodo_t* nodoAux = nodo->mom;
    while(1){
        if(!nodoAux->esq){
            printf("nao existe esquerda\n");
            if(nodoAux->dir->height > 0)
                printf("balancear aqui em %d\n", nodoAux->val);
        }
        else if(!nodoAux->dir){
            printf("nao existe direita\n");
            if(nodoAux->esq->height > 0)
                printf("balancear aqui em %d\n", nodoAux->val);
        }
        // else if(abs(nodo->esq->height - nodo->dir->height) > 1){
        //     printf("balancear aqui em %d\n", nodo->val);
        // }
        if(nodoAux->mom){
            nodoAux = nodoAux->mom;
        }
        else
            break;
    }
    return 1;
}

int insertNodo(avl_t* avl, int value){
    nodo_t* currNodo = malloc(sizeof(nodo_t));
    if(!currNodo)
        return 0;
    currNodo->height = 0;
    currNodo->val = value;
    currNodo->mom = NULL;
    currNodo->esq = NULL;
    currNodo->dir = NULL;
    if(!avl->root){
        avl->root = currNodo;
        return 1;
    }

    nodo_t* auxNodo;
    auxNodo = avl->root;
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
    nodo_t* hNodo = currNodo;
    int h = 0;
    while(hNodo!=avl->root){
        hNodo->height = h;
        hNodo = hNodo->mom;
        h++;
    }
    hNodo->height = h;
    hNodo = hNodo->mom;

    balanInsert(currNodo, avl->root);
    return 1;
}