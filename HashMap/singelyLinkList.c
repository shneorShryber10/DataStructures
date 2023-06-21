#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <malloc.h>
#include "singelyLinkList.h"
#include <assert.h>


Pair_t* ListInsertHead(Pair_t* head, Pair_t* item)
{
	assert(item);

	item->next = head;

	return item;
}
Pair_t* ListRemoveHead(Pair_t* head, Pair_t** item)
{
	assert(head || item);

	*item = head;

	Pair_t* temp = head->next;

	head->next = NULL;

	return temp;
}
void PrintList(Pair_t* head)
{

	if (!head)
	{
		printf("empty list!");
		return;
	}

	while (head)
	{
		printf("the data is: %d,\n ", head->data);
		printf("the key is: %d,\n ", head->key);


		head = head->next;
	}
	printf("\n\n");

}
Pair_t* ListInsertByKey(Pair_t* head, int key, Pair_t* item)
{
	assert(item);

	Pair_t* temp = head;

	if (!head || key > head->data)
	{
		item->next = head;
		return item;
	}
	while (temp->next != NULL && key < temp->next->data)
	{
		temp = temp->next;
	}
	item->next = temp->next;
	temp->next = item;

	return head;
}
Pair_t* ListRemovByKey(Pair_t* head, int key, Pair_t** item)
{
	assert(item);

	Pair_t* temp = head;
	Pair_t* temp2 = head;

	if (!head)
	{
		*item = head;
		return head;
	}
	if (key == head->key)
	{
		*item = head;
		temp = NULL;
		return head->next;
	}

	while (temp->next != NULL && key != temp->next->data)
	{
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		return head;
	}

	temp2 = temp;

	*item = temp->next;
	/*(*item)->next = NULL;*/
	temp = temp->next;
	temp2->next = temp->next;
	temp->next = NULL;

	return head;
}
