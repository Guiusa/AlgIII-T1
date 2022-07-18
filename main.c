#include "bst.h"
#include <time.h>

int main(){
    srand(time(0));
    bst_t* bst = touchBST();

    for(int i = 0; i < 5; i++){
        insertNodo(bst, i);
    }
    if(!rmNodo(bst, 1)){
        printf("não encontrado\n");
    }
    printf("\n");
    emOrdemPrint(bst->root);
    printf("\n");

    liberaBST(bst);
    return 0;
}