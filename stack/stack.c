#define _STACK_C_
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define TRUE 1
#define FALSE 0

Stack* stkCreate(int max){
	Stack* s;
	if(max>0){
		s = (Stack*)malloc(sizeof(Stack));
		if(s!=NULL){
			s->elms = (void**)malloc(sizeof(void*)*max);
			if (s->elms !=NULL){
				s->max = max;
				s->top = -1;

				return s;
			}else{
				free(s);
			}
		}
	}
	return NULL;
}

int stkDestroy(Stack *s){
	if(s != NULL){
		if(s->top < 0){
			free(s->elms);
			free(s);
			return TRUE;
		}
	}
	return FALSE;
}

int stkPush(Stack* s, void* elm){
	if(s != NULL){
		if(s->top < s->max-1){
			s->top++;
			s->elms[s->top] = elm;
			return TRUE;
		}
	}
	return FALSE
}

void* stkPop(Stack* s){
	if(s != NULL){
		if(s->top >= 0){
			void* elm = s->elms[s->top];
			s->top--;
			return elm;
		}
	}
	return NULL;
}

int stkIsEmpty(Stack *s){
	if(s != NULL){
		if (s->top < 0){
			return TRUE;
		}
	}
	return FALSE;
}

void* stkQuery(Stack* s){
	if(s != NULL){
		if(s->top >= 0){
			return s->elms[s->top];
		}
	}
	return NULL;
}