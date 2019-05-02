#ifndef _STACK_H_
#define _STACK_H_

	#ifdef _STACK_C_
		typedef struct _stack_{
			int max;
			int top;
			int cur;
			void* *elms;//vetor de void* de tamanho max
		}Stack;

		Stack* stkCreate(int max);
		int stkDestroy(Stack *s);
		int stkPush(Stack* s, void* elm);
		void* stkPop(Stack* s);
		int stkIsEmpty(Stack *s);
		void* stkQuery(Stack* s);

	#else
		
		typedef struct _stack_ Stack;
		extern Stack* stkCreate(int max);
		extern int stkDestroy(Stack *s);
		extern int stkPush(Stack* s, void* elm);
		extern void* stkPop(Stack* s);
		extern int stkIsEmpty(Stack *s);
		extern void* stkQuery(Stack* s)



	#endif // _STACK_C_

#endif