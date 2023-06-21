#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#include "ADTDefs.h"
#include "Genvector.h"
#include "Sorting.h"


void BubbleSort(GenVector_t* vec, CmpFunc cmpfunc)
{
	assert(vec && cmpfunc);

	size_t size;

	GenVectorItemsNum(vec, &size);

	void* index1;
	void* index2;
	int flag = 1;
	size_t k=0;

	for (size_t i = 1; i <= size - 1; i++)
	{
		for (size_t j = 1; j <= size - i; j++)
		{

			GenVectorGet(vec, j, &index1);
			GenVectorGet(vec, j + 1, &index2);

			if (cmpfunc(index1, index2) == 1)
			{
				GenVectorSet(vec, j, index2);
				GenVectorSet(vec, j + 1, index1);
				flag = 1;
			}

		}
		if (!flag)
		{
			return;
		}
		flag = 0;
	}
}
void ShkeBabeleSort(GenVector_t* vec, CmpFunc cmpfunc)
{
	assert(vec && cmpfunc);
	size_t size;

	GenVectorItemsNum(vec, &size);
	void* index1;
	void* index2;
	int flag = 1;


	for (size_t i = 1; i <= size / 2; ++i)
	{

		for (size_t j = i; j < size - (i - 1); ++j)
		{

			GenVectorGet(vec, j, &index1);
			GenVectorGet(vec, j + 1, &index2);

			if (cmpfunc(index1, index2) == 1)
			{
				GenVectorSet(vec, j, index2);
				GenVectorSet(vec, j + 1, index1);
				flag = 1;
			}
		}
		if (!flag)
		{
			return;
		}

		for (size_t k = size - (i - 1); k > i; --k)
		{
			GenVectorGet(vec, k, &index1);
			GenVectorGet(vec, k - 1, &index2);

			if (cmpfunc(index1, index2) == -1)
			{
				GenVectorSet(vec, k, index2);
				GenVectorSet(vec, k - 1, index1);
				flag = 1;
			}

		}
		if (!flag)
		{
			return;
		}
		flag = 0;
	}
}
void InsertionSort(GenVector_t* vec, CmpFunc cmpfunc)
{
	assert(vec && cmpfunc);

	size_t size;

	GenVectorItemsNum(vec, &size);

	void* index1;
	void* index2;


	for (size_t i = 1; i <= size - 1; i++)
	{
		GenVectorGet(vec, i + 1, &index1);

		for (size_t j = i + 1; j > 1; --j)
		{

			GenVectorGet(vec, j - 1, &index2);


			if (cmpfunc(index1, index2) == -1)
			{
				GenVectorSet(vec, j, index2);
				GenVectorSet(vec, j - 1, index1);
			}
			else
			{
				break;
			}
		}

	}
}
void SelectionSort(GenVector_t* vec, CmpFunc cmpfunc)
{
	assert(vec && cmpfunc);

	size_t size;
	size_t currIndex;

	GenVectorItemsNum(vec, &size);
	void* min;
	void* index1;
	void* index2;

	for (size_t i = 1; i <= size; ++i)
	{
		GenVectorGet(vec, i, &index1);
		min = index1;

		for (size_t j = i + 1; j <= size; ++j)
		{
			GenVectorGet(vec, j, &index2);

			if (cmpfunc(min, index2) == -1)
			{
				min = index2;
				currIndex = j;
			}
		}
		if (i != currIndex)
		{
			GenVectorSet(vec, i, min);
			GenVectorSet(vec, currIndex, index1);
		}
	}
}

size_t Partition(GenVector_t* vec, size_t p, size_t r, CmpFunc cmpfunc)
{
	void* pivot;
	void* CurrFirst;
	void* CurrSecend;

	GenVectorGet(vec, p, &pivot);
	GenVectorGet(vec, p, &CurrFirst);
	GenVectorGet(vec, r, &CurrSecend);

	while (p <= r)
	{

		while (cmpfunc(CurrFirst, pivot) < 0) // currFirs (is) < pivot !
		{
			++p;
			GenVectorGet(vec, p, &CurrFirst);
		}
		while (cmpfunc(CurrSecend, pivot) > 0)// currSecend (is) > pivot !
		{
			--r;
			/*if (p > r)
			{
				return r;
			}*/
			GenVectorGet(vec, r, &CurrSecend);
		}
		if (p < r)
		{
			GenVectorSet(vec, p, CurrSecend);
			GenVectorSet(vec, r, CurrFirst);
			++p;
			--r;
			GenVectorGet(vec, p, &CurrFirst);
			GenVectorGet(vec, r, &CurrSecend);
		}
		else
		{
			break;
		}
	}
	return r;
}
void QuickSortImp(GenVector_t* vec, size_t p, size_t r, CmpFunc cmpfunc)
{

	size_t pivotIndex;

	if (p < r)
	{

		pivotIndex = Partition(vec, p, r, cmpfunc);

		QuickSortImp(vec, p, pivotIndex, cmpfunc);

		QuickSortImp(vec, pivotIndex + 1, r, cmpfunc);

	}


}
void QuickSort(GenVector_t* vec, CmpFunc cmpfunc)
{
	assert(vec && cmpfunc);

	size_t  p = 1;
	size_t r;
	GenVectorItemsNum(vec, &r);

	QuickSortImp(vec, p, r, cmpfunc);
}

void Merge(GenVector_t* vec, void** tempArr, size_t begin, size_t pivotIndex, size_t end, CmpFunc cmpfunc)
{

	int indexI = begin - 1;
	int indexJ = pivotIndex;
	int indexMerge = begin;

	for (int i = begin; i <= end; i++)
	{
		GenVectorGet(vec, i, &tempArr[i - 1]);
	}
	while (indexI < pivotIndex && indexJ < end)
	{
		if (cmpfunc(tempArr[indexI], tempArr[indexJ]) < 0)
		{
			GenVectorSet(vec, indexMerge++, tempArr[indexI++]);
		}
		else
		{
			GenVectorSet(vec, indexMerge++, tempArr[indexJ++]);
		}
	}
	if (indexI >= pivotIndex)
	{
		while (indexMerge <= end)
		{
			GenVectorSet(vec, indexMerge++, tempArr[indexJ++]);
		}
	}
	else if (indexJ >= end)
	{
		while (indexMerge <= end)
		{
			GenVectorSet(vec, indexMerge++, tempArr[indexI++]);
		}
	}
}
void MargeSortImp(GenVector_t* vec, void** tempArr, size_t begin, size_t end, CmpFunc cmpfunc)
{


	if (begin < end)
	{
		size_t pivotIndex = (begin + end) / 2;

		MargeSortImp(vec, tempArr, begin, pivotIndex, cmpfunc);

		MargeSortImp(vec, tempArr, pivotIndex + 1, end, cmpfunc);

		Merge(vec, tempArr, begin, pivotIndex, end, cmpfunc);

	}
}
ADTErr MargeSort(GenVector_t* vec, CmpFunc cmpfunc)
{
	assert(vec && cmpfunc);

	size_t  begin = 1;
	size_t end;

	GenVectorItemsNum(vec, &end);

	void** tempArr = (void**)calloc(end + 1, sizeof(void*));

	if (!tempArr)
	{
		return ERR_REALLOCATION_FAILED;
	}

	MargeSortImp(vec, tempArr, begin, end, cmpfunc);

	free(tempArr);

	return ERR_OK;

}
ADTErr CountingSort(GenVector_t* vec, ExtractKeyFunc KeyFunc)
{
	assert(vec && KeyFunc);

	size_t sizeOfVec;
	void* max;
	void* item;

	GenVectorItemsNum(vec, &sizeOfVec);

	void** sortedVec = (void**)calloc(sizeOfVec + 1, sizeof(void*));
	if (!sortedVec)
	{
		return ERR_REALLOCATION_FAILED;
	}

	GenVectorGet(vec, 1, &max);

	for (int i = 2; i <= sizeOfVec; i++)
	{
		GenVectorGet(vec, i, &item);
	
		if (KeyFunc(item) > KeyFunc(max))
		{
			max = item;
		}
	}
	size_t maxIndex = KeyFunc(max);

	int* indexOfVec = calloc(maxIndex+1,sizeof(int));
	if (!indexOfVec)
	{
		free(sortedVec);
		return ERR_REALLOCATION_FAILED;
	}
	for (int i = 1; i <= sizeOfVec; i++)
	{
		GenVectorGet(vec, i, &item);

		indexOfVec[KeyFunc(item)]++;
	}

	for (int i = 2; i <= maxIndex; i++)
	{
		indexOfVec[i] += indexOfVec[i - 1];
	}

	for (size_t i = sizeOfVec; i > 0; i--)
	{
		GenVectorGet(vec, i, &item);

		sortedVec[indexOfVec[KeyFunc(item)]--] = item;
	}

	for (int i = 1; i <= sizeOfVec; i++)
	{
		GenVectorSet(vec, i, sortedVec[i]);
	}


	free(indexOfVec);
	free(sortedVec);

	return ERR_OK;

}
void** CountingToRodix(void** arr, size_t size, ExtractKeyFunc intCasting, int mod, int div,void** rearrange)
{
	int counting[10] = { 0 };
	

	for (size_t i = 1; i <= size; ++i)
	{
		++counting[(intCasting(arr[i]) % mod) / div];
	}
	for (size_t i = 1; i < 10; ++i)
	{
		counting[i] += counting[i - 1];
	}

	for (size_t i = size; i > 0; --i)
	{
		rearrange[counting[(intCasting(arr[i]) % mod) / div]--] = arr[i];
	}
	for (size_t i = 1; i <= size; ++i)
	{
		arr[i] = rearrange[i];
	}

	return arr;
}
ADTErr RodixSort(GenVector_t* vec, ExtractKeyFunc intCasting)
{
	assert(vec && intCasting);

	int mod = 10, div = 1;
	size_t nIttem;
	int maxDigit = INT_MIN;
	size_t numOfDigit=0;

	GenVectorItemsNum(vec, &nIttem);

	void** rearrange = (void**)calloc(nIttem + 1, sizeof(void*));
	if (!rearrange)
	{
		return ERR_BLABLABLA;
	}

	void** aux = (void**)calloc(nIttem + 1, sizeof(void*));
	if (!aux)
	{
		return ERR_ALLOCATION_FAILED;
	}

	for (size_t i = 1; i <= nIttem; i++)
	{
		GenVectorGet(vec, i, &aux[i]);
		
		if (intCasting(aux[i]) > maxDigit)
		{
			maxDigit= intCasting(aux[i]);
		}
	}
	while (maxDigit)
	{
		numOfDigit++;
		maxDigit /= 10;
	}

	for (size_t i = 0; i < numOfDigit; i++)
	{
		aux = CountingToRodix(aux, nIttem, intCasting, mod, div, rearrange);

		mod *= 10;
		div *= 10;
	}


	for (size_t i = 1; i <= nIttem; i++)
	{
		GenVectorSet(vec, i, aux[i]);
	}
	free(rearrange);
	free(aux);
	return ERR_OK;
}
size_t BinSearchItr(GenVector_t* vec, void* item, CmpFunc CmpFunc)
{
	assert(vec && item && CmpFunc);
	
	 size_t end, start=1;
	 
	 GenVectorItemsNum(vec, &end);
	 
	 void* currItem;
	 size_t mid = end / 2;
	 
	 
	 while (start <= end)
	 {

		 GenVectorGet(vec, mid,&currItem);

		 int cmpResult = CmpFunc(currItem, item);

		 if (cmpResult == 0)
		 {
			 return mid;
		 }
		 else if(cmpResult == 1)
		 {
			 end = mid-1;
			 mid = (((mid - start) + 1) / 2);
		 }
		 else
		 {
			 start = mid+1;
			 mid += (((end - mid)+1) / 2);
		 }
	 }
	 return 0;
 }
size_t BinSearchRecImp(GenVector_t* vec, void* item, size_t start,size_t mid, size_t end, CmpFunc CmpFunc)
{
	void* currItem;

	if (start > end)
	{
		return 0;
	}

	GenVectorGet(vec, mid, &currItem);


	int cmpResult = CmpFunc(currItem, item);
		if (cmpResult == 0)
		{
			return mid;
		}
		else if (cmpResult == 1)
		{
			 return BinSearchRecImp(vec, item,start,(((mid-start)+1))/2 ,mid, CmpFunc);
		}
		else
		{
			 return BinSearchRecImp(vec, item, mid , mid + (((end - mid) + 1) / 2), end , CmpFunc);
		}
}
size_t BinSearchRec(GenVector_t* vec, void* item, CmpFunc CmpFunc)
{
	assert(vec && item && CmpFunc);

	size_t sizeOfOregVec;

	GenVectorItemsNum(vec,&sizeOfOregVec);

	 return BinSearchRecImp(vec,item,1,sizeOfOregVec/2 ,sizeOfOregVec,CmpFunc);

}


