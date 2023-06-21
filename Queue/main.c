#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "Queue.h"

Queue_t* NewCueue(Queue_t* vec, size_t size);
Queue_t* func2Cueue(Queue_t* vec, size_t x1, size_t x2, size_t size);
Queue_t* func3Cueue(Queue_t* vec, size_t size);

int main()
{
	//Queue_t* vec = NULL;
	//ADTErr  eErr;
	//int num;

	//vec = QueueCreate(4);

	//eErr = QueueInsert(vec, 1);
	//HandleErr(eErr, "try to add more item");
	//eErr = QueueDelete(vec, &num);
	//HandleErr(eErr, "try to delite");

	//eErr = QueueInsert(vec,2);
	//HandleErr(eErr, "try to add more item");
	//eErr = QueueDelete(vec, &num);
	//HandleErr(eErr, "try to delite");

	//eErr = QueueInsert(vec,3);
	//HandleErr(eErr, "try to add more item");
	//eErr = QueueDelete(vec, &num);
	//HandleErr(eErr, "try to delite");

	//eErr = QueueInsert(vec,4);
	//HandleErr(eErr, "try to add more item");
	//eErr = QueueDelete(vec, &num);
	//HandleErr(eErr, "try to delite");

	//	eErr = QueueInsert(vec,5);
	//HandleErr(eErr, "try to add more item");
	//eErr = QueueInsert(NULL,5);
	//HandleErr(eErr, "try to add null!");

	//
	//

	//QueuePrint(vec);


	//eErr = QueueDelete(vec,&num);
	//HandleErr(eErr, "try to delite");

	//QueuePrint(vec);

	//eErr = QueueInsert(vec, 8);
	//HandleErr(eErr, "try to add more item");


	//eErr = QueueInsert(vec, 9);
	//HandleErr(eErr, "try to add more item");

	//QueuePrint(vec);


	//
	//
	//////////////////////////////////////////test 2 empty 

	////printf("%d", QueueIsEmpty(vec));
	////printf("\n%d", QueueIsEmpty(NULL));


	//QueueDestroy(vec);
	
	Queue_t* vec = NULL;
	Queue_t* res = NULL;
	ADTErr  eErr;
	int num;

	vec = QueueCreate(7);

	eErr = QueueInsert(vec,-16);
	HandleErr(eErr, "try to add more item");

	eErr = QueueInsert(vec, -3);
	HandleErr(eErr, "try to add more item");

	HandleErr(eErr, "try to add more item");
	eErr = QueueInsert(vec, -5);

	eErr = QueueInsert(vec, 1);
	HandleErr(eErr, "try to add more item");

	eErr = QueueInsert(vec, -3);
	HandleErr(eErr, "try to add more item");

	eErr = QueueInsert(vec, 62);
	HandleErr(eErr, "try to add more item");
	eErr = QueueInsert(vec, 111);
	HandleErr(eErr, "try to add more item");


	QueuePrint(vec);

	res = func3Cueue(vec,7);

	QueuePrint(res);

}

Queue_t* func3Cueue(Queue_t* vec, size_t size)
{
	Queue_t* tVec = NULL;
	ADTErr  eErr;
	int num;
	tVec = QueueCreate(6);


	for (int i = 0; i < size; i++)
	{
		eErr = QueueDelete(vec, &num);
		HandleErr(eErr, "try to delite");
		if (num>0)
		{
			eErr = QueueInsert(vec, num);
			HandleErr(eErr, "try to add more item");
		}
		else
		{
			eErr = QueueInsert(tVec,num);
			HandleErr(eErr, "try to add more item"); 
		}
		
	}
	while ((QueueIsEmpty(tVec)))
	{
		eErr = QueueDelete(tVec,&num);
		HandleErr(eErr, "try to delite");

		eErr = QueueInsert(vec,num);
		HandleErr(eErr, "try to add more item");
	}
	return vec;

}
Queue_t* func2Cueue(Queue_t* vec, size_t x1, size_t x2, size_t size)
{
	Queue_t* newVec = NULL;
	ADTErr  eErr;
	newVec = QueueCreate(size);

	int num;

	for (int i = 0; i < size; i++)
	{
		eErr = QueueDelete(vec, &num);
		HandleErr(eErr, "try to delite");
		if (num == x1)
		{
			num = x2;
		}
		eErr = QueueInsert(newVec, num);
		HandleErr(eErr, "try to add more item");
	}

	return newVec;
}
Queue_t* NewCueue(Queue_t* vec, size_t size)
{
	
	Queue_t* newVec = NULL;
	ADTErr  eErr;
	int num1,num2;

	
	newVec = QueueCreate(4);
		eErr = QueueDelete(vec, &num1);
		HandleErr(eErr, "try to delite");
		eErr = QueueInsert(vec, num1);
		HandleErr(eErr, "try to add more item");

	for (int i = 0; i < size-1 ; i++)
	{
		
		eErr = QueueDelete(vec, &num2);
		HandleErr(eErr, "try to delite");

		
		eErr = QueueInsert(newVec, (num1-num2));
		HandleErr(eErr, "try to add more item");

		num1 = num2;

		eErr = QueueInsert(vec, num1);
		HandleErr(eErr, "try to add more item");

	
	}

	return newVec;
}

 //-4 -2 5 3 1