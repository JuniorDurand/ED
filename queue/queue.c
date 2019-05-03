#define _QUEUE_C_
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define TRUE 1
#define FALSE 0

Queue* qCreate(int n){
	Queue *q;
	if(n>0){
		q=(Queue*)malloc(sizeof(Queue));
		if(q != NULL){
			q->elms=(void**)malloc(sizeof(void*)*n);
			if(q->elms != NULL){
				q->maxElms = n;
				//q->nElms = 0;
				//q->front =0;
				q->rear = -1;
				return q;
			}
		}
	}
	return NULL;
}

int qDestroy(Queue *q){
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

int qEnqueue(Queue *q, void *elm){
	if(q != NULL){
		if(q->rear < q->maxElms-1){
			q->rear++;
			q->elms[q->rear]=elm;
			return TRUE;
		}
	}
	return FALSE;
}

void* qDequeue(Queue *q){
	if(q != NULL){
		if(q->rear >= 0){
			void* aux;
			aux = q->elms[0];
			for(int i=0; i<q->rear; i++){
				q->elms[i]=q->elms[i+1];
			}
			q->rear--;
			return aux;
		}
	}
	return NULL;
}

int qIsEmpty(Queue *q){
	if(s != NULL){
		if (q->rear < 0){
			return TRUE;
		}
	}
	return FALSE;
}
