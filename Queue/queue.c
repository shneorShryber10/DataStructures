#include <stdlib.h>
#include <stdio.h>

#include "ADTDefs.h"
#include "Queue.h"

struct  Queue
{
	int* vec;
	size_t size;
	size_t numOfItems;
	size_t head;
	size_t tail;
	
};


Queue_t* QueueCreate(size_t size)
{
	Queue_t* queue;

	if (size == 0)
	{
		return NULL;
	}
	queue = (Queue_t*)malloc(sizeof(Queue_t));

	if (!queue)
	{
		return NULL;
	}

	queue->vec = (int*)malloc(sizeof(int)* size);

	if (!queue->vec)
	{
		free(queue);
		return NULL;
	}

	queue->size = size;
	queue->numOfItems=0;
	queue->head = 0 ;
	queue->tail = 0 ;

	return queue;
}

ADTErr QueueInsert(Queue_t* queue, int item)
{
	if (!queue) {
		return ERR_NOT_INITIALIZED;
	}
	if (queue->numOfItems == queue->size) {

		return ERR_OVERFLOW;
	}
	if (queue->tail == (queue->size) )
	{
		queue->tail = 0;
	}
	
	*(queue->vec + queue->tail) = item;
	++queue->tail;
	++queue->numOfItems;

	return ERR_OK;

}

ADTErr QueueDelete(Queue_t* queue, int* item)
{
	if (!queue || !queue->vec || !item) //assert(queue && queue->vec && item)
	{
		return ERR_NOT_INITIALIZED;
	}
	
	if (queue->numOfItems==0)
	{
		return ERR_UNDERFLOW;
	}

		*item = *(queue->vec + queue->head);
		++queue->head;
		--queue->numOfItems;
	
		if (queue->head == (queue->size))
		{
			queue->head = 0;
		}

	return ERR_OK;
}

int QueueIsEmpty(Queue_t* queue)
{
	if (!queue)
	{
		return 1;
	}
	 return !queue->numOfItems ;

}


void QueueDestroy(Queue_t* queue)
{
	if (queue)
	{
		if (queue->vec)
		{
			free(queue->vec);
		}
		free(queue);
	}

}


void QueuePrint(Queue_t* queue)
{
	if (!(queue && queue->vec && queue->numOfItems))
	{
		return ;
	}
		printf("\n\n--------------------------------------------------------------\nthe queue right now is:\n\n");

		for (int i = 0 , index = queue->head ; i < queue->numOfItems; ++i,++index)
		{
			if (index >= queue->size)
			{
				index = 0;
			}
			printf("%d ,",queue->vec[index % queue->size]);
		}
		printf("\n\nthere is : %d placec at the queue ! ", queue->size);
		printf("\n\nthere is : %d elements right now-", queue->numOfItems);


		printf(" \n --------------------------------------------------------------\n\n");
}






