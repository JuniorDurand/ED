#ifndef _SLLQUEUE_H_
#define _SLLQUEUE_H_

	#ifdef _SLLQUEUE_C_
		typedef struct _sllelm_{
			struct _sllelm_ *next;
			void* data;
		}SLNode;

		typedef struct _sllqueue_{
			SLNode* first;
			SLNode* last;
			SLNode* cur;
			void* data;
		}SLLQueue;
		SLLQueue* sllqCreate();
		int sllqDestroy(SLLQueue* list);
		int sllqEnqueue(SLLQueue* list, void* data);
		void* sllqDequeue(SLLQueue* list);
		void* sllqGetFirst(SLLQueue *list);
		void* sllqGetNext(SLLQueue* list);
		


	#else		
		typedef struct _sllelm_ SLNode;
		typedef struct _sllQueue_ SLLQueue;
		SLLQueue* sllqCreate();
		int sllqDestroy(SLLQueue* list);
		int sllqEnqueue(SLLQueue* list, void* data);
		void* sllqDequeue(SLLQueue* list);
		void* sllqGetFirst(SLLQueue *list);
		void* sllqGetNext(SLLQueue* list);


	#endif // 

#endif