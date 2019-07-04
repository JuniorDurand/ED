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
        Simetrica(tNode->l, visit);
        visit(tNode->data);
        Simetrica(tNode->r, visit);
    }
}


void PosOrdem(TNode *tNode, void (*visit)(void *)){
    if (tNode != NULL){
        PosOrdem(tNode->l, visit);
        visit(tNode->data);
        PosOrdem(tNode->r, visit);
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


TNode* removeMaiorArvore(TNode* t, void** data){
    if(t!= NULL){
        if(t->r != NULL){
            t->r = removeMaiorArvore(t->r, data);
            return t;
        }else{
            *data = t->data;
            return t->l;
        }
    }
    return NULL;
}


TNode* abpRemove(TNode *t, void* key, void** data, int(*cmp)(void*, void*)){
    TNode* curt;
    void* dataMaiorSubArvoreEsq;
    int stat;
    if(t != NULL){

        stat = cmp(key, t->data);
        if(stat < 0){
            t->l = abpRemove(t->l, key, data, cmp);
            return t;
        }else if(stat > 0){
            t->r = abpRemove(t->r, key, data, cmp);
            return t;
        }else if(stat == 0){
            *data = t->data;
            if(t->l == NULL && t->r == NULL){
                free(t);
                return NULL;
            }else if(t->l == NULL && t->r != NULL){
                curt = t->r;
                free(t);
                return curt;
            }else if(t->l != NULL && t->r == NULL){
                curt = t->l;
                free(t);
                return curt;
            }else{
                t->l = removeMaiorArvore(t->l, &dataMaiorSubArvoreEsq);
                t->data = dataMaiorSubArvoreEsq;
                return t;
            }
        }
    }
    return NULL;
}