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

void* dllRemoveFirst(DLList *list){
	DLNode *first;
	void *data;
	if(list != NULL){
		if(list->first != NULL){
			first = list->first;
			list->first = first->next;
			if(list->first != NULL){
				list->first->prev = NULL;
			}
			data = first->data;
			free(first);
			return data;
		}
	}
	return NULL;
}

int dllInsertLast(DLList *list, void *data){
	DLNode* newNode, *cur;
	if(list != NULL){
		newNode = (DLNode*)malloc(sizeof(DLNode));
		if(newNode != TRUE){
			newNode->data = data;
			if(list -> first != NULL){
				cur = list->first;
				while(cur->next!=NULL){
					cur= cur->next;
				}
				cur->next = newNode;
				newNode->prev = cur;
			}else{
				list->first = newNode;
				newNode->next = NULL;
				newNode->prev = NULL;
			}	

			return TRUE;
		}
	}
	return FALSE;
}

void* dllRemoveLast(DLList *list){
	DLNode *cur;
	void* data;
	if(list != NULL){
		if(list -> first != NULL){
			cur = list->first;
			while(cur->next!=NULL){
				cur= cur->next;
			}
			data = cur->data;
			if(cur->prev != NULL){
				cur->prev->next = NULL;
			}else{
				list->first=NULL;
			}
			free(cur);
			return data;
		}
	}
	return NULL;
}

void* dllGetFirst(DLList *list){
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

void* dllGetNext(DLList* list){
	void* data;
	if(list != NULL){
		if(list->cur != NULL){
			if(list->cur->next != NULL){	
				list->cur = list->cur->next;
				data = list->cur->data;
			}
			return data;
		}
	}
	return NULL;
}

void* dllQuery(DLList *list, void* key, int(*cmp)(void*,void*)){
	DLNode *spec;
	void *data;
	int stat;
	if(list != NULL){
		if(list->first != NULL){
			spec = dllGetNode(list, key, cmp);
			if(spec != NULL){
				data = spec->data;
				return data;
			}
		}
	}
	return NULL;
}

void* dllRemoveSpec(DLList *list, void* key, int(*cmp)(void*,void*)){
	DLNode *spec, *prev, *next;
	void* data;
	if(list != NULL){
		if(list->first != NULL){
			spec = dllGetNode(list, key, cmp);
			if(spec != NULL){
				data = spec->data;
				prev = spec->prev;
				next = spec->next;
				if(prev != NULL){
					prev->next = spec -> next;
				}else{
					list->first = spec->next;
				}
				if( next!= NULL){
					next->prev = prev;
				}
				free(spec);
				return data;
			}
		}
	}
	return NULL;
}