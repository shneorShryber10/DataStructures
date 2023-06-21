#pragma once
#ifndef _BINARYHEAP_h__
#define _BINARYHEAP_h__

#include "Vector.h"
typedef struct Heap Heap_t;

Heap_t* BinHeapBuild(Vector_t* vector);

void PrintfBinartHeap(Heap_t* heap);

ADTErr BinHeapMax(Heap_t* heap, int* item);

ADTErr BinHeapInsert(Heap_t* heap, int item);

ADTErr BinHeapDelete(Heap_t* heap, int* item);

int IsHeap(Heap_t* heap);

void heapSort(Heap_t* heap);

void BinDestroy(Heap_t* heap);

#endif // ! _BINARYHEAP_h__