#ifndef _SLLIST_H_
#define _SLLIST_H_

	#ifdef _SLLIST_C_
		typedef struct _sllelm_{
			struct _sllelm_ *next;
			void* data;
		}SLNode;

		typedef struct _sllist_{
			SLNode* first;
			void* data;
		}SLList;
		
		SLList* sllCreate();


	#else		
		typedef struct _sllelm_ SLNode;
		typedef struct _sllist_ SLList;

		SLList* sllCreate();


	#endif // _SLLIST_C_

#endif