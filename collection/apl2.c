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
		printf("\n---------------\n");
		t = (Time*)colQueryFirst(c);
		while(t != NULL){
			printf("%s %d %d\n",t->nome , t->numCampeao, t->numVice);
			t = (Time*)colQueryNext(c);
		}
		printf("\n---------------\n");
		t = (Time*)colQueryN(c, 2);
		printf("%s %d %d\n",t->nome , t->numCampeao, t->numVice);
	}
	return 0; 
}