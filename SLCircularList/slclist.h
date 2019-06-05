#ifndef _SLCLIST_H_
#define _SLCLIST_H_

	#ifdef _SLLIST_C_
		typedef struct _sllelm_{
			struct _sllelm_ *next;
			void* data;
		}SLNode;

		typedef struct _sllist_{
			SLNode* first;
			SLNode* cur;
		}SLList;
		
		SLList* sllCreate();
		int sllDestroy(sllist* list);
		int sllcInsertFisrt(sllist *list, void *data);
		void *sllcRemoveFisrt(sllist *list);


	#else		
		typedef struct _sllelm_ SLNode;
		typedef struct _sllist_ SLList;

		SLList* sllCreate();
		int sllDestroy(sllist* list);
		int sllcInsertFisrt(sllist *list, void *data);
		void *sllcRemoveFisrt(sllist *list);

	#endif // _SLCLIST_C_

#endif