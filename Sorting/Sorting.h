#pragma once

#ifndef __SORTING_H__
#define __SORTING_H_H__


typedef int (*CmpFunc)( void*,void*);
typedef int (*ExtractKeyFunc)(void*);

void ShkeBabeleSort(GenVector_t* vec, CmpFunc cmpfuncUp);
void BubbleSort(GenVector_t* vec, CmpFunc cmpfunc);
void InsertionSort(GenVector_t* vec, CmpFunc cmpfunc);
void SelectionSort(GenVector_t* vec, CmpFunc cmpfunc);
void QuickSort(GenVector_t* vec, CmpFunc cmpfunc);
ADTErr MargeSort(GenVector_t* vec, CmpFunc cmpfunc);
ADTErr CountingSort(GenVector_t* vec, ExtractKeyFunc KeyFunc);
ADTErr RodixSort(GenVector_t* vec, ExtractKeyFunc CmpFunc);
size_t BinSearchItr(GenVector_t* vec, void* item, CmpFunc CmpFunc);
size_t BinSearchRec(GenVector_t* vec, void* item, CmpFunc CmpFunc);




#endif /*__SORTING_H__*/