#define _SLLSTACK_C_
#include <stdio.h>
#include <stdlib.h>
#include "sllstack.h"
#define TRUE 1
#define FALSE 0

SLList* sllStkCreate(){
	SLList* list;
	list = (SLList*)malloc(sizeof(SLList));
	if(list != NULL){
		list->first = NULL;
		list->cur = NULL;
		return list;
	}
	return NULL;
}

int sllStkDestroy(sllist* list){
	if(list != NULL){
		if(list->first == NULL){
			free(list);
			return TRUE;
		}
	}
	return FALSE;
}

int sllStkPush(SLList *list, void* data){
	SLNode* newNode;
	if(list!=NULL){
		newNode = (SLNode*)malloc(sizeof(SLNode));
		if(newNode != NULL){
			newNode->data = data;
			newNode->next = list->first;
			list->first = newNode;
			return TRUE;
		}
	}
	return FALSE;
}

void* sllStkPop(SLList* list){
	SLNode* aux;
	void* data;
	if(list != NULL){
		aux= list->first;
		list->first = aux->next;
		data = aux->data;
		free(aux);
		return data;
	}
	return NULL;
}


void* sllStkGetFirst(SLList *list){
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

void* sllStkGetNext(SLList* list){
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