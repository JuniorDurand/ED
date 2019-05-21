#define _DLLIST_C_
#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"
#define TRUE 1
#define FALSE 0

DLList* dllCreate(){
	DLList* list;
	list = (DLList*)malloc(sizeof(DLList));
	if(list != NULL){
		list->first = NULL;
		list->cur = NULL;
		return list;
	}
	return NULL;
}

int dllDestroy(DLList* list){
	if(list != NULL){
		if(list->first == NULL){
			free(list);
			return TRUE;
		}
	}
	return FALSE;
}

DLNode* dllGetNode(DLList* l, void *key, int(*cmp)(void*,void*)){
	DLNode *spec;
	if(l!=NULL){
		if(l->first != NULL){
			spec = l->first;
			stat = cmp(key, spec->data);
			whlie(stat != TRUE && spec->next != NULL){
				spec = spec->next;
				stat = cmp(key, spec->data);
			}
			if(stat){
				return spec;
			}
		}
	}
	return NULL;
}

int dllInsertFirst(DLList *list, void *data){
	DLNode* newNode;
	if(list != NULL){
		newNode = (DLNode*)malloc(sizeof(DLNode));
		if(newNode != TRUE){
			newNode->data = data;
			newNode->prev = NULL;
			if(list -> first != NULL){
				list->first->prev = newNode;
				newNode -> next = list->first;
			}else{
				newNode->next = NULL;
			}
			list->first = newNode;
			return TRUE;
		}
	}
	return FALSE;
}
