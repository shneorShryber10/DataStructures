
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ADTDefs.h"
#include "BinaryHeap.h"
#include "Vector.h"

struct Heap
{
	Vector_t * vec;
	size_t heapSize;

};

// Foward Declartion
void BringUpToPlace(Heap_t* heap, size_t index);

void Heapify(Heap_t* heap,int i)
{
	int largest, leftSon, rightSon,index,leftIndex,rightIndex,largIndex,found;

	ADTErr errLeft, errRight;

	 VectorGet(heap->vec , i , &index);
	 leftIndex = i * 2;
	 rightIndex = (i * 2) +1;


	 errLeft = VectorGet(heap->vec,leftIndex, &leftSon);
	 errRight= VectorGet(heap->vec,rightIndex,&rightSon);


	 if (errLeft == ERR_OK && leftSon > index)
	 {
		 largest = leftSon;
		 found = leftSon;
		 largIndex = leftIndex;
	 }
	 else
	 {
		 largest = index;
		 largIndex = i;
	 }
	 if (errRight == ERR_OK && rightSon > largest)
	 {
		 largest = rightSon;
		 largIndex = rightIndex;
	 }
	 if (largIndex != i)
	 {

		 VectorSet(heap->vec, i , largest);

		 VectorSet(heap->vec,largIndex , index);
		  
		 Heapify(heap,largIndex);
	 }
}

Heap_t* BinHeapBuild(Vector_t* vector)
{
	
	Heap_t* heap = calloc(1,sizeof(Heap_t));
	ADTErr Err ;
	if (!heap)
	{
		return NULL;
	}

	heap->vec = vector;
	size_t numOfVec;

	Err = VectorItemsNum(heap->vec,&numOfVec);
	heap->heapSize = numOfVec;

	for (int i = (int)numOfVec / 2; i > 0; i--)
	{
		Heapify(heap, i);
	}	

	return heap;
}
void PrintfBinartHeap(Heap_t* heap)
{
	VectorPrint(heap->vec);
}
ADTErr BinHeapMax(Heap_t* heap, int* item)
{

	assert(heap);
	if (!item)
	{
		return ERR_NOT_INITIALIZED;
	}

	int max=0;

	
	VectorGet(heap->vec,1,&max);

	*item = max;

	return ERR_OK;
}

void HeapifyForInser(Heap_t* heap, size_t i)
{

	if ((i / 2) == 0)
	{
		return;
	}
	size_t value, father, fatherIndex;

	fatherIndex = (i / 2);

	 VectorGet(heap->vec, i, &value);
	 VectorGet(heap->vec, fatherIndex, &father);

	heap->heapSize++;

	if (father < value)
	{
		VectorSet(heap->vec, i, father);

		VectorSet(heap->vec, fatherIndex, value);

		HeapifyForInser(heap, fatherIndex);
	}
	else
	{
		return;
	}

}

ADTErr BinHeapInsert(Heap_t* heap, int item)
{
	assert(heap);
	ADTErr  eErr;

	size_t num = 0;

	eErr = VectorAdd(heap->vec, item);

	eErr = VectorItemsNum(heap->vec, &num);
		
	HeapifyForInser(heap,num);

	

	return ERR_OK;
}

ADTErr BinHeapDelete(Heap_t* heap,int* item)
{

	assert(heap);

	size_t numOfVec,index,numOfVecIndex;
	ADTErr Err;

	if (heap->heapSize <= 0)
	{
		return ERR_ALLOCATION_FAILED;
	}
	Err = VectorItemsNum(heap->vec, &numOfVec);

	VectorGet(heap->vec,1, &index);
	VectorGet(heap->vec, numOfVec, &numOfVecIndex);


	VectorSet(heap->vec, 1, numOfVecIndex);
	VectorSet(heap->vec,numOfVec, index);

	*item = index;

	VectorDelete(heap->vec, &index);

	--heap->heapSize;
  
	Heapify(heap, 1);

	return ERR_OK;

}

void heapSort(Heap_t* heap)
{
	assert(heap);
	int theIndex, oneIndex;
	
	for (int i = heap->heapSize; i >= 0; i--)
	{
	
		VectorGet(heap->vec, i, &theIndex);
		VectorGet(heap->vec, 1, &oneIndex);

		VectorSet(heap->vec, 1, theIndex);
		VectorSet(heap->vec, i, oneIndex);

		Heapify(heap, 1);
	}

}


int IsHeap(Heap_t* heap)
{
	int theIndex,leftSon,rightSon;
	
	for (int i = 1; i < heap->heapSize/2; i++)
	{
		VectorGet(heap->vec, i, &theIndex);
		VectorGet(heap->vec, (i * 2), &leftSon);
		VectorGet(heap->vec, ((i * 2) + 1), &rightSon);

		if (theIndex < leftSon || theIndex < rightSon)
		{
			return 0;
		}
				
	}
	return 1;


}

void BinDestroy(Heap_t* heap)
{
	assert(heap);
	free(heap);

}