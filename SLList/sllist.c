#define _SLLIST_C_
#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"
#define TRUE 1
#define FALSE 0

SLList* sllCreate(){
	SLList* list;
	list = (SLList*)malloc(sizeof(SLList));
	if(list != NULL){
		list->first = NULL;
		return list;
	}
	return NULL;
}

int sllDestroy(sllist* list){
	if(list != NULL){
		if(list->first == NULL){
			free(list);
			return TRUE;
		}
	}
	return FALSE;
}

int sllInsertFirst(SLList *list, void* data){
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

void* sllRemoveFirst(SLList* list){
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