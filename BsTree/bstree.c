#define _BSTREE_C_
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#define TRUE 1
#define FALSE 0

void PreOrdem(TNode *tNode, void (*visit)(void *)){
    if (tNode != NULL){
        visit(tNode->data);
        PreOrdem(tNode->l, visit);
        PreOrdem(tNode->r, visit);
    }
}


void Simetrica(TNode *tNode, void (*visit)(void *)){
    if (tNode != NULL){
        PreOrdem(tNode->l, visit);
        visit(tNode->data);
        PreOrdem(tNode->r, visit);
    }
}


void PosOrdem(TNode *tNode, void (*visit)(void *)){
    if (tNode != NULL){
        PreOrdem(tNode->l, visit);
        visit(tNode->data);
        PreOrdem(tNode->r, visit);
    }
}

TNode* abpInsert(TNode* t, void*data, int (*cmp)(void*,void*)){
    int stat;
    TNode *newt;
    if(t!= NULL){
        stat = cmp(data, t->data);
        if(stat < 0){
            t->l = abpInsert(t->l,data, cmp);
        }else{
            t->r = abpInsert(t->r,data, cmp);
        }
        return t;
    }else{
        newt=(TNode*)malloc(sizeof(TNode));
        if (newt != NULL){
            newt->data = data;
            newt->l = NULL;
            newt->r = NULL;
            return newt;
        }
    }
    return NULL;
}