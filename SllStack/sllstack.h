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
		SLLStack* sllStkCreate();
		int sllStkDestroy(SLLStack* list);
		int sllStkPush(SLLStack *list, void* data);
		void* sllStkPop(SLLStack* list);
		void* sllStkGetFirst(SLLStack *list);
		void* sllStkGetNext(SLLStack* list);


	#else		
		typedef struct _sllelm_ SLNode;
		typedef struct _sllstack_ SLLStack;
		SLLStack* sllStkCreate();
		int sllStkDestroy(SLLStack* list);
		int sllStkPush(SLLStack *list, void* data);
		void* sllStkPop(SLLStack* list);
		void* sllStkGetFirst(SLLStack *list);
		void* sllStkGetNext(SLLStack* list);


	#endif // _SLLSTACK_C_

#endif