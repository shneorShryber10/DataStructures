#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "doublyLinkedList.h"
#include <assert.h>

typedef struct ListItr {

	void* data;

	ListItr_t* next;
	ListItr_t* prev;
}ListItr_t;

typedef struct List
{
	ListItr_t* head;
	ListItr_t* tail;
}List_t;

List_t* ListCreate()
{
	List_t* list = malloc(sizeof(List_t));


	return list;
}
void ListPushHead(List_t* list, void* data)
{
	assert(list, data);

	ListItr_t* newNode = createNode(data,list->head,list->head->prev);

	list->head = newNode;



	

	
}
void ListPushTail(List_t* list, void* data)
{
	assert(list, data);

	ListItr_t* newNode = createNode(data, list->tail->next, list->tail->prev);

	list->head = newNode;

}

ListItr_t* createNode(void* item, ListItr_t* next, ListItr_t* prev)
{
	ListItr_t* newNode = malloc(sizeof(ListItr_t));

	newNode->data = item;
	newNode->next = next;
	
	
	 prev->next=newNode->prev;
	 newNode->prev;

	return newNode;


}