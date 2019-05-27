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
		void* dllRemoveFirst(DLList *list);
		int dllInsertLast(DLList *list, void *data);
		void* dllRemoveLast(DLList *list);
		void* dllGetFirst(DLList *list);
		void* dllGetNext(DLList* list);
		void* dllQuery(DLList *list, void* key, int(*cmp)(void*,void*));
		void* dllRemoveSpec(DLList *list, void* key, int(*cmp)(void*,void*));
		


	#else		
		typedef struct _dllelm_ DLNode;
		typedef struct _dllist_ DLList;

		DLList* sllCreate();
		int sllDestroy(DLList* list);
		int dllInsertFirst(DLList *list, void *data);
		void* dllRemoveFirst(DLList *list);
		int dllInsertLast(DLList *list, void *data);
		void* dllRemoveLast(DLList *list);
		void* dllGetFirst(DLList *list);
		void* dllGetNext(DLList* list);
		void* dllQuery(DLList *list, void* key, int(*cmp)(void*,void*));
		void* dllRemoveSpec(DLList *list, void* key, int(*cmp)(void*,void*));

	#endif // _DLLIST_C_

#endif