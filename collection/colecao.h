#IFNDEF _COLECAO_H_
#DEFINE _COLECAO_H_
	typedef struct _colecao_ Col;
#IFDEF _COLECAO_C_
	Col* colCreate(int n);
	int colInsert(Col*c, void* elm);
	Col* colQuery(Col *c, int n);
	//Col* colRemove(Col *c, void* elm);
	int colDestroy(Col *c, void* elm);
	void* colRemoveLast(Col *c)

#ELSE
	EXTERN Col* colCreate(int n);
	EXTERN int colInsert(Col*c, void* elm);
	EXTERN Col* colQuery(Col *c, int n);
	//EXTERN Col* colRemove(Col *c, void* elm);
	EXTERN int colDestroy(Col *c, void* elm);
	EXTERN void* colRemoveLast(Col *c)

#ENDIF