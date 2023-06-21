#pragma once

#ifndef __SINGELYLINKLIST_H__
#define __SINGELYLINKLIST_H__

typedef struct Pair Pair_t;

struct Pair
{
	size_t key;
	int data;

	Pair_t* next;
};


Pair_t* ListInsertHead(Pair_t* head, Pair_t* item);
Pair_t* ListRemoveHead(Pair_t* head, Pair_t** item);
void PrintList(Pair_t* head);
Pair_t* ListInsertByKey(Pair_t* head, int key, Pair_t* item);
Pair_t* ListRemovByKey(Pair_t* head, int key, Pair_t** item);
Pair_t* ListInsertByKeyRec(Pair_t* head, int key, Pair_t* item);
Pair_t* ListRemovByKeyRec(Pair_t* head, int key, Pair_t** item);

Pair_t* ListFlipRec(Pair_t* head);
int CountUnit(Pair_t* node);
int SumOFUnit(Pair_t* node);
int SumOFUnit(Pair_t* node);
int ItSort(Pair_t* node);
int SumOfAppir(Pair_t* node, int key);

void PrintfFromEnd(Pair_t* node);

void ListSort(Pair_t** pHead);
Pair_t* DelitEven(Pair_t* node);
int* DinamyArr(Pair_t* node, int* size);
Pair_t* ListCreateByArr(Pair_t* head, int* arr, int size);
Pair_t* DelitTheODddPlaces(Pair_t* node);
Pair_t* DelitTheEvenPlaces(Pair_t* node);
int DivAtThree(Pair_t* node);
Pair_t* AddTen(Pair_t* node);
int ItDonuSort(Pair_t* node);
int NumOfShows(Pair_t* node, int key);
Pair_t* MaikingNewListAndSort(Pair_t* node);
int SumOfEvenDigit(Pair_t* node);
Pair_t* DeliteOlTheKey(Pair_t* node, int key);
void BigFromKey(Pair_t* node, int key);
Pair_t* FlipRec(Pair_t* node);
Pair_t* AddToTheEnd(Pair_t* node, int valiue);
Pair_t* MackingSortLinkList();
Pair_t* ItrFlip(Pair_t* node);

#endif /*__SINGELYLINKLISTE_H__*/