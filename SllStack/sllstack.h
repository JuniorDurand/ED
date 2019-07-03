#ifndef _SLLSTACK_H_
#define _SLLSTACK_H_

	#ifdef _SLLSTACK_C_
		typedef struct _sllelm_{
			struct _sllelm_ *next;
			void* data;
		}SLNode;

		typedef struct _sllstack_{
			SLNode* first;
			void* data;
		}SLLStack;
		


	#else		
		typedef struct _sllelm_ SLNode;
		typedef struct _sllist_ SLList;


	#endif // _SLLSTACK_C_

#endif