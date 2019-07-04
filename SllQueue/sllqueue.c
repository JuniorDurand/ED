#define _SLLQUEUE_C_
#include <stdio.h>
#include <stdlib.h>
#include "sllstack.h"
#define TRUE 1
#define FALSE 0

SLLQueue* sllqCreate(){
	SLLQueue* list;
	list = (SLLQueue*)malloc(sizeof(SLLQueue));
	if(list != NULL){
		list->first = NULL;
		list->last = NULL;
		list->cur = NULL;
		return list;
	}
	return NULL;
}

int sllqDestroy(SLLQueue* list){
	if(list != NULL){
		if(list->first == NULL){
			free(list);
			return TRUE;
		}
	}
	return FALSE;
}

int sllqEnqueue(SLLQueue* list, void* data){
	SLNode* newNode;
	if(list != NULL){
		newNode = (SLNode*)malloc(sizeof(SLNode));
		if(newNode != NULL){
			newNode->data = data;
			newNode->next = NULL;
			if(list -> last == NULL){
				list -> first = newNode;
				list -> last = newNode;
			}else{
				SLNode* cur = list->last;
				cur->next=newNode;
				list->last = newNode;
			}
			return TRUE;
		}
	}
	return FALSE;
}

void* sllqDequeue(SLLQueue* list){
	SLNode* aux;
	void* data;
	if(list != NULL){
		if(list -> first != NULL){
			data = list->first->data;
			aux= list->first;
			if(list->first == list->last){
				list->first = NULL;
				list->last = NULL;
			}else{
				list->first = aux->next;
			}
			free(aux);
			return data;
		}
	}
	return NULL;
}

void* sllqGetFirst(SLLQueue *list){
	void* data;
	if(list != NULL){
		if(list->first != NULL){
			list->cur = list->first;
			data = list->first->data;
			return data;
		}
	}
	return NULL;
}

void* sllqGetNext(SLLQueue* list){
	void* data;
	if(list != NULL){
		if(list->cur != NULL){
			list->cur = list->cur->next;
			data = list->cur->data;
			return data;
		}
	}
	return NULL;
}