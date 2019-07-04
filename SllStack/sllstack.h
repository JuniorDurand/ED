#ifndef _SLLSTACK_H_
#define _SLLSTACK_H_

	#ifdef _SLLSTACK_C_
		typedef struct _sllelm_{
			struct _sllelm_ *next;
			void* data;
		}SLNode;

		typedef struct _sllstack_{
			SLNode* first;
			SLNode* cur;
			void* data;
		}SLLStack;
		SLList* sllStkCreate();
		int sllStkDestroy(sllist* list);
		int sllStkPush(SLList *list, void* data);
		void* sllStkPop(SLList* list);
		void* sllStkGetFirst(SLList *list);
		void* sllStkGetNext(SLList* list);


	#else		
		typedef struct _sllelm_ SLNode;
		typedef struct _sllist_ SLList;
		SLList* sllStkCreate();
		int sllStkDestroy(sllist* list);
		int sllStkPush(SLList *list, void* data);
		void* sllStkPop(SLList* list);
		void* sllStkGetFirst(SLList *list);
		void* sllStkGetNext(SLList* list);


	#endif // _SLLSTACK_C_

#endif