#pragma once

#pragma once

#ifndef __SINGELYLINKLIST_H__
#define __SINGELYLINKLIST_H__

typedef struct Person Person_t;








struct Person {

	int id;
	char name[20];
	int age;

	Person_t* next;

};

Person_t* MultLink2(Person_t* head);
Person_t* MultLink(Person_t* head1);
Person_t* foundEqelNode(Person_t* head1, Person_t* head2);
Person_t* ListInsertHead(Person_t* head, Person_t* item);
Person_t* ListRemoveHead(Person_t* head, Person_t** item);
void PrintList(Person_t* head);
Person_t* ListInsertByKey(Person_t* head, int key, Person_t* item);
Person_t* ListRemovByKey(Person_t* head, int key, Person_t* item);
Person_t* ListInsertByKeyRec(Person_t* head, int key, Person_t* item);
Person_t* ListRemovByKeyRec(Person_t* head, int key, Person_t** item);

Person_t* ListFlipRec(Person_t* head);
int CountUnit(Person_t* node);
int SumOFUnit(Person_t* node);
int SumOFUnit(Person_t* node);
int ItSort(Person_t* node);
int SumOfAppir(Person_t* node, int key);

void PrintfFromEnd(Person_t* node);

void ListSort(Person_t** pHead);
Person_t* DelitEven(Person_t* node);
int* DinamyArr(Person_t* node,int* size);
Person_t* ListCreateByArr(Person_t* head, int* arr, int size);
Person_t* DelitTheODddPlaces(Person_t* node);
Person_t* DelitTheEvenPlaces(Person_t* node);
int DivAtThree(Person_t* node);
Person_t* AddTen(Person_t* node);
int ItDonuSort(Person_t* node);
int NumOfShows(Person_t* node, int key);
Person_t* MaikingNewListAndSort(Person_t* node);
int SumOfEvenDigit(Person_t* node);
Person_t* DeliteOlTheKey(Person_t* node, int key);
void BigFromKey(Person_t* node, int key);
Person_t* FlipRec(Person_t* node);
Person_t* AddToTheEnd(Person_t* node, int valiue);
Person_t* MackingSortLinkList();
Person_t* ItrFlip(Person_t* node);

#endif /*__SINGELYLINKLISTE_H__*/