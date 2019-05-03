#define _QUEUE_C_
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define TRUE 1
#define FALSE 0

int incCirc( int var, int max){
	var++;
	if(var<max){
		return var;
	}else{
		return 0;
	}
}

Queue* qCreateC(int n){
	Queue *q;
	if(n>0){
		q=(Queue*)malloc(sizeof(Queue));
		if(q != NULL){
			q->elms=(void**)malloc(sizeof(void*)*n);
			if(q->elms != NULL){
				q->maxElms = n;
				q->nElms = 0;
				q->front =0;
				q->rear = -1;
				return q;
			}
		}
	}
	return NULL;
}

int qDestroyC(Queue *q){
	if(q != NULL){
		if(q->nElms == 0){
			free(q->elms);
			free(q);
			*q = NULL;
			return TRUE;
		}
	}
	return FALSE;
}

int qEnqueueC(Queue *q, void* elm){
	if(q != NULL){
		if(q->nElms < q->maxElms){
			q->rear=incCirc(q->rear, q->maxElms);
			q->elms[q->rear]=elm;
			q->nElms++;
			return TRUE;
		}
	}
	return FALSE;
}

void* qDequeueC(Queue *q, void* elm){
	if(q != NULL){
		if(q->nElms < 1){
			void *aux;
			aux = q->elms[q->front];
			q->front=incCirc(q->front, q->maxElms);
			q->nElms--;
			return aux;
		}
	}
	return NULL;
}

int qIsEmptyC(Queue *q){
	if(q != NULL){
		if (q->nElms == 0){
			return TRUE;
		}
	}
	return FALSE;
}