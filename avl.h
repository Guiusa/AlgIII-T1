#ifndef __AVL__
#define __AVL__

struct nodo {
    int valor;
    int altura;
    struct nodo* esq;
    struct nodo* dir;
}; typedef struct nodo nodo_t;

nodo_t* criarNodo(int valor);

int fatorBalanceamento(nodo_t* nodo);

int maior(int a, int b);

int alturaNodo(nodo_t *nodo);

nodo_t* rotacaoEsquerda(nodo_t* nodo);

nodo_t* rotacaoDireita(nodo_t* nodo);

nodo_t* rotacaoEsquerdaDireita(nodo_t *nodo);

nodo_t* rotacaoDireitaEsquerda(nodo_t* nodo);

nodo_t* balancear(nodo_t *raiz);

nodo_t* inserir(nodo_t* raiz, int valor);

nodo_t* remover(nodo_t* raiz, int chave);

void imprimir(nodo_t *raiz, int nivel);

#endif