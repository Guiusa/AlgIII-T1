#include "bst.h"
#include <time.h>

int main(){
    srand(time(0));
    bst_t* bst = touchBST();

    for(int i = 0; i< 100; i++){
        insertNodo(bst, random()%100);
    }
    for(int i = 0; i<50; i++){
        if(!rmNodo(bst, random()%100)){
            printf("Valor não existe\n");
        }
    }
    
    printf("\n");
    emOrdemPrint(bst->root);
    printf("\n");

    liberaBST(bst);
    return 0;
}