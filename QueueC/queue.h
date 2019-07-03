#ifndef _QUEUE_H_
#define _QUEUE_H_

	#ifdef _QUEUE_C_
		typedef struct _queue_{
			int maxElms;
			int front;
			int rear;
			int nElms;
			void* *elms;//vetor de void* de tamanho max
		}Queue;
		
		Queue* qCreateC(int n);
		int qDestroyC(Queue *q);
		

	#else
		
		typedef struct _queue_ Queue;
		extern Queue* qCreateC(int n);
		extern int qDestroyC(Queue *q);
		
	#endif // _QUEUE_C_

#endif