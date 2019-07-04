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
        return 1;
    }else if (x<y){
        return -1;
    }else{
        return 0;
    }
}

int main(){
    TNode *tree = NULL;
    int num1;
    num1 = 15; 
    tree = abpInsert( tree, (void*)&num1, cmp);

    int num2;
    num2 = 19; 
    tree = abpInsert( tree, (void*)&num2, cmp);

    int num3;
    num3 = 7; 
    tree = abpInsert( tree, (void*)&num3, cmp);


    Simetrica(tree, visit);

    return 0;
}
