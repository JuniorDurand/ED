#define _SLCLIST_C_
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
		list->cur = NULL;
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

