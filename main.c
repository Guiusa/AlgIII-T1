#include "avl.h"
#include <unistd.h>
#include <stdio.h>

int main(){
    avl_t* avl = touchAVL();

    insertNodo(avl, 10);
    insertNodo(avl, 8);
    insertNodo(avl, 9);
    insertNodo(avl, 7);
    printf("%d\n", avl->root->val);
    printf("%d\n", avl->root->esq->val);
    printf("%d\n", avl->root->esq->dir->val);
    printf("%d\n", avl->root->esq->esq->val);

    liberaAVL(avl);
    return 0;
}