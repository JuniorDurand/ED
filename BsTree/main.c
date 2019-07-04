#include "bstree.h"
#include <stdio.h>
#include <malloc.h>

void visit(void *item){
    if (item != NULL){
        int i = *(int*)item;
        printf("%d ", i);
    }
    else { printf("NULL "); }
}

int cmp(void* a,void* b){
    int x, y;
    x = *(int*)a;
    y = *(int*)b;
    if (x>y){
        printf("1 ");
        return 1;
    }else if (x<y){
        printf("-1 ");
        return -1;
    }else{
        printf("0 ");
        return 0;
    }
}

int main(){
    TNode *tree = NULL;
    int *dado;
    int *num;
    int opc = 0;
    do{
        printf("1 - Adicionar num\n");
        printf("2 - Printar arvore\n");
        printf("3 - Remover\n");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                num = (int*)malloc(sizeof(int));
                printf("Dado a ser inserido :");
                scanf("%d", num);
                tree = abpInsert( tree, (void*)num, cmp);
                break;
            case 2:
                Simetrica(tree, visit);
                printf("\n");
                break;
            case 3:
                num = (int*)malloc(sizeof(int));
                printf("Dado a ser removido :");
                scanf("%d", num);
                tree = abpRemove(tree, num, (void*)&dado, cmp);
                printf("Dado removido %d \n", *dado);
                if(tree == NULL){
                    printf("arvore nula\n");
                }

                break;
        }

    }while( opc != 0);

    Simetrica(tree, visit);

    return 0;
}
