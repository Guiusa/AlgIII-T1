#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){
    int valor;
    char opcao;
    nodo_t* raiz = NULL;

    do{
        printf("(S)AIR\n(I)NSERIR\n(R)EMOVER\nIM(P)RIMIR\n");
        scanf("%s", &opcao);

        switch(opcao){
        case 's':
            printf("Programa finalizado.\n");
            break;
        case 'i':
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 'r':
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        case 'p':
            imprimir(raiz, 1);
            break;
        default:
            printf("\nOpcao invalida\n");
        }

    }while(opcao != 's');
    imprimir(raiz, 1);
    return 0;
}