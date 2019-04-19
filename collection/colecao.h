#ifndef _COLECAO_H_
#define _COLECAO_H_

	#ifdef _COLECAO_C_
		typedef struct _colecao_{
			int max;
			int numElms;
			int cur;
			void* *elms;//vetor de void* de tamanho max
		}Col;

		Col* colCreate(int n);
		int colInsert(Col*c, void* elm);
		Col* colQuery(Col *c, int n);
		//Col* colRemove(Col *c, void* elm);
		int colDestroy(Col *c);
		void* colRemoveLast(Col *c);
		void* colQueryFirst(Col *c);
		void* colQueryNext(Col *c);

	#else
		typedef struct _colecao_ Col;
		extern Col* colCreate(int n);
		extern int colInsert(Col*c, void* elm);
		extern Col* colQuery(Col *c, int n);
		//extern Col* colRemove(Col *c, void* elm);
		extern int colDestroy(Col *c);
		extern void* colRemoveLast(Col *c);
		extern void* colQueryFirst(Col *c);
		extern void* colQueryNext(Col *c);

	#endif // _COLECAO_C_

#endif