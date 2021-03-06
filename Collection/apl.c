//#IFNDEF _PROG_C_
//#define _APL_C_


#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"

typedef struct _time_{
	char nome[20];
	int numCampeao;
	int numVice;
}Time;

int main(void){
	Col* c; Time* t; Time ta;
	c = colCreate(10);
	if(c != NULL){
		for(int i=0; i<4; i++){
			t=(Time*)malloc(sizeof(Time));
			if(t != NULL){
				scanf("%s %d %d",(t->nome) , &(t->numCampeao), &t->numVice);
				colInsert(c, (void*)t);
			}
		}
		t = (Time*)colRemoveLast(c);
		while(t != NULL){
			printf("%s %d %d\n",t->nome , t->numCampeao, t->numVice);
			t = (Time*)colRemoveLast(c);
		}
	}
	return 0; 
}