#ifndef _QUEUE_H_
#define _QUEUE_H_

	#ifdef _QUEUE_C_
		typedef struct _queue_{
			int maxElms;
			//int front;
			int rear;
			//int nElms;
			void* *elms;//vetor de void* de tamanho max
		}Queue;
		
		Queue* qCreate(int n);
		int qDestroy(Queue *q);
		int qEnqueue(Queue *q, void *elm);
		void* qDequeue(Queue *q);
		int qIsEmpty(Queue *q);


	#else
		
		typedef struct _queue_ Queue;
		extern Queue* qCreate(int n);
		extern int qDestroy(Queue *q);
		extern int qEnqueue(Queue *q, void *elm);
		extern void* qDequeue(Queue *q);
		extern int qIsEmpty(Queue *q);

	#endif // _QUEUE_C_

#endif