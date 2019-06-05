#define _SLCLIST_C_
#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"
#define TRUE 1
#define FALSE 0

SLList* sllcCreate(){
	SLList* list;
	list = (SLList*)malloc(sizeof(SLList));
	if(list != NULL){
		list->first = NULL;
		list->cur = NULL;
		return list;
	}
	return NULL;
}

int sllcDestroy(sllist* list){
	if(list != NULL){
		if(list->first == NULL){
			free(list);
			return TRUE;
		}
	}
	return FALSE;
}

int sllcInsertFisrt(sllist *list, void *data){
	SLNode *newNode, *last;
	if(list != NULL){
		newNode = (SLNode*)malloc(sizeof(SLNode));
		if(newNode != NULL){
			newNode->data = data;
			if(list ->first != NULL){
				last = list -> first;
				while(last->next != list->first){
					last = last->next;
				}
				newNode->next = list->first;
				last->next = newNode;
			}else{
				list->first = newNode;
				newNode -> next = newNode;
			}
			return TRUE;
		}
	}
	return FALSE;
}

void *sllcRemoveFisrt(sllist *list){
	SLNode *last, *first;
	void *data;
	if(list != NULL){
		if(list-> first != NULL){
			last = list -> first;
			while(last->next != list->first){
				last = last->next;
			}
			first = list->first;
			if(last == first){
				list->first = NULL;
			}else{
				last->next = first->next;
				list->first = first->next;
			}
			data = first->data;
			return data;
		}
	}
	return NULL;
}