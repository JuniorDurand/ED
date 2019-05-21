#ifndef _DLLIST_H_
#define _DLLIST_H_

	#ifdef _DLLIST_C_
		typedef struct _dllelm_{
			struct _dllelm_ *next, *prev;
			void* data;
		}DLNode;

		typedef struct _dllist_{
			DLNode* first;
			DLNode* cur;
		}DLList;
		
		DLList* sllCreate();
		int sllDestroy(DLList* list);
		int dllInsertFirst(DLList *list, void *data);
		


	#else		
		typedef struct _dllelm_ DLNode;
		typedef struct _dllist_ DLList;

		DLList* sllCreate();
		int sllDestroy(DLList* list);
		int dllInsertFirst(DLList *list, void *data);

	#endif // _DLLIST_C_

#endif