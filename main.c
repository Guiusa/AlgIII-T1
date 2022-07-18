#include "avl.h"
#include <time.h>

int main(){
    srand(time(0));
    avl_t* avl = touchAVL();

    for(int i = 0; i < 5; i++){
        int k = random()%10;
        printf("%d ", k);
        insertNodo(avl, k);
    }
    printf("\n");
    emOrdemPrint(avl->root);
    printf("\n");

    liberaAVL(avl);
    return 0;
}