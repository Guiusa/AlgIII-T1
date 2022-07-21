#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

nodo_t* criarNodo(int valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if(!nodo){
        printf("Nao foi possível alocar memoria");
        return NULL;
    }

    nodo->valor = valor;
    nodo->esq = NULL;
    nodo->dir = NULL;
    nodo->altura = 0;

    return nodo;
}



int maior(int a, int b){
    if(a > b)
        return a;
    return b;
}

int alturaNodo(nodo_t *nodo){
    if(nodo == NULL)
        return -1;
    else
        return nodo->altura;
}

int fatorBalanceamento(nodo_t* nodo){
    if(!nodo)
        return 0;
    return (alturaNodo(nodo->esq) - alturaNodo(nodo->dir));
}

/*
    função para a rotação à esquerda
*/
nodo_t* rotacaoEsquerda(nodo_t* nodo){
    nodo_t *nodoAux, *nodoAuxRot;

    nodoAux = nodo->dir; // nodoAux aponta para a subárvore direita da raiz nodo
    nodoAuxRot = nodoAux->esq; // nodoAuxRot aponta para o filho esquerdo de nodoAux

    nodoAux->esq = nodo; // o filho esquerdo de nodoAux passa a ser a raiz nodo
    nodo->dir = nodoAuxRot; // o filho direito de nodo passa a ser nodoAuxRot

    // recalcula a altura dos nós que foram movimentados
    nodo->altura = maior(alturaNodo(nodo->esq), alturaNodo(nodo->dir)) + 1;
    nodoAux->altura = maior(alturaNodo(nodoAux->esq), alturaNodo(nodoAux->dir)) + 1;

    return nodoAux;
}

nodo_t* rotacaoDireita(nodo_t* nodo){
    nodo_t *nodoAux, *nodoAuxRot;

    nodoAux = nodo->esq; 
    nodoAuxRot = nodoAux->dir;

    nodoAux->dir = nodo;
    nodo->esq = nodoAuxRot; 

    // recalcula a altura dos nós que foram movimentados
    nodo->altura = maior(alturaNodo(nodo->esq), alturaNodo(nodo->dir)) + 1;
    nodoAux->altura = maior(alturaNodo(nodoAux->esq), alturaNodo(nodoAux->dir)) + 1;

    return nodoAux;
}

nodo_t* rotacaoEsquerdaDireita(nodo_t *nodo){
    nodo->esq = rotacaoEsquerda(nodo->esq);
    return rotacaoDireita(nodo);
}

nodo_t* rotacaoDireitaEsquerda(nodo_t* nodo){
    nodo->dir = rotacaoDireita(nodo->dir);
    return rotacaoEsquerda(nodo);
}



nodo_t* balancear(nodo_t *raiz){
    int fator = fatorBalanceamento(raiz);

    // Rotação à esquerda
    if(fator < -1 && fatorBalanceamento(raiz->dir) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // Rotação à direita
    else if(fator > 1 && fatorBalanceamento(raiz->esq) >= 0)
        raiz = rotacaoDireita(raiz);

    // Rotação dupla à esquerda
    else if(fator > 1 && fatorBalanceamento(raiz->esq) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    // Rotação dupla à direita
    else if(fator < -1 && fatorBalanceamento(raiz->dir) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

nodo_t* inserir(nodo_t* raiz, int x){
    if(raiz == NULL) // árvore vazia
        return criarNodo(x);
    else{ // inserção será à esquerda ou à direita
        if(x < raiz->valor)
            raiz->esq = inserir(raiz->esq, x);
        else
            raiz->dir = inserir(raiz->dir, x);
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaNodo(raiz->esq), alturaNodo(raiz->dir)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

nodo_t* remover(nodo_t* raiz, int chave) {
    if(raiz == NULL){
        return NULL;
    } else { // procura o nó a remover
        if(raiz->valor == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                return NULL;
            }
            else{
                nodo_t *nodoAux = raiz->esq;
                // remover nós que possuem 2 filhos
                if(!(raiz->esq) && !(raiz->dir)){
                    while(nodoAux->dir != NULL)
                        nodoAux = nodoAux->dir;
                    raiz->valor = nodoAux->valor;
                    nodoAux->valor = chave;
                    raiz->esq = remover(raiz->esq, chave);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    if(raiz->esq != NULL)
                        nodoAux = raiz->esq;
                    else
                        nodoAux = raiz->dir;
                    free(raiz);
                    return nodoAux;
                }
            }
        } else {
            if(chave < raiz->valor)
                raiz->esq = remover(raiz->esq, chave);
            else
                raiz->dir = remover(raiz->dir, chave);
        }

        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        raiz->altura = maior(alturaNodo(raiz->esq), alturaNodo(raiz->dir)) + 1;

        // verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
}

void imprimir(nodo_t *raiz, int nivel){
    if(raiz){
        imprimir(raiz->esq, nivel + 1);
        printf("%d, %d\n", raiz->valor, raiz->altura);
        imprimir(raiz->dir, nivel + 1);
    }
}