#IFNDEF _COLECAO_H_
#DEFINE _COLECAO_H_
	typedef struct _colecao_ Col;
#IFDEF _COLECAO_C_
	Col* colCreate(int n);
	int colInsert(Col*c, void* elm);
	int colQuery(Col *c, void* elm);
	int colRemove(Col *c, void* elm);
	int colDestroy(Col *c, void* elm);

#ELSE
	EXTERN Col* colCreate(int n);
	EXTERN int colInsert(Col*c, void* elm);
	EXTERN int colQuery(Col *c, void* elm);
	EXTERN Col* colRemove(Col *c, void* elm);
	EXTERN int colDestroy(Col *c, void* elm);

#ENDIF