#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "singelyLinkList.h"
#include <assert.h>


Person_t* MultLink2(Person_t* head)
{
	int count = 1;
	Person_t* orgHead = head;
	Person_t* orgHead2 = head;

	while (head->next)
	{

		count++;
		head = head->next;
	}
	while (count--)
	{

		Person_t* temp = malloc(1 * sizeof(Person_t));
		temp->age = orgHead->age;
		temp->id = orgHead->id;
		strcpy(temp->name, orgHead->name);

		orgHead = orgHead->next;

		head->next = temp;
		head = head->next;
	}
	head->next = NULL;
	return orgHead2;
}

Person_t* MultLink(Person_t* head1)
{
	Person_t* OrgHead1=head1;

	while (head1)
	{

		Person_t* temp = malloc( 1 * sizeof(Person_t));
		Person_t* temp2 = malloc( 1 * sizeof(Person_t));

		temp->age = head1->age;
		temp->id = head1->id;
		strcpy(temp->name, head1->name);
		

		temp2= head1->next;
		head1->next = temp;
		temp->next = temp2;
		head1 = temp2;
	}
	
	return OrgHead1;
}

Person_t* foundEqelNode(Person_t* head1, Person_t* head2)
{
	int count1 = 0;
	int count2 = 0;
	Person_t* temp1 = head1;
	Person_t* temp2 = head2;

	int res, start = 0;;

	while (temp1)
	{
		temp1 = temp1->next;
		count1++;
	}
	while (temp2)
	{
		temp2 = temp2->next;
		count2++;
	}
	if (count1 > count2)
	{
		res = (count1 - count2);
		while (res--)
		{
			head1 = head1->next;
			
		}
	}
	else if (count2 > count1)
	{
		res = (count2 - count1);

		while (res--)
		{
			head2 = head2->next;
		}
	}
	

	while (head1)
	{
		if (head1 == head2)
		{
			return head1;
		}
	 
		head1 = head1->next;
		head2 = head2->next;
	}

	return NULL;

}

Person_t* ListInsertHead(Person_t* head, Person_t* item)
{
	assert(item);
	
	item->next = head;

	return item;
}
Person_t* ListRemoveHead(Person_t* head, Person_t** item)
{
	assert(head || item);

	*item = head;
	Person_t* temp = head->next;
	head->next = NULL;

	return temp;
}
void PrintList(Person_t* head)
{
	if (!head)
	{
		printf("empty list!");
		return;
	}

	printf("\n\tlinked List is:\n------------------------------\n ");

	while (head)
	{
		printf("%d, ", head->age);
		printf("%d, ", head->id);
		printf("%s\n", head->name);

		head = head->next;
	}
	printf("\n\n");

}
Person_t* ListInsertByKey(Person_t* head, int key, Person_t* item)
{
	assert(item);

	Person_t* temp = head;

	if (!head || key > head->age)
	{
		item->next = head;
		return item;
	}
	while (temp->next != NULL &&  key < temp->next->age)
	{
		temp = temp->next;
	}
	item->next = temp->next;
	temp ->next = item;
	
	return head;
}
Person_t* ListInsertByKeyRec(Person_t* head, int key, Person_t* item)
{
	if (!head || key > head->age)
	{
	item->next = head;
		return item; 
	}

		 head->next = ListInsertByKeyRec(head->next, key, item);

		return head;
}

Person_t* ListRemovByKey(Person_t* head, int key, Person_t** item)
{
	assert(head && item);

	Person_t* temp = head;
	Person_t* temp2 = head;

	if (key == head->age)
	{
		*item = head;
		temp = NULL;
		return head->next ;
	}

	while (temp->next != NULL && key != temp->next->age)
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
Person_t* ListRemovByKeyRec(Person_t* head, int key, Person_t** item)
{
	assert(head || item);

	if (head == NULL)
	{
		return head;
	}
	if (key == head->age)
	{
		Person_t* orginalhead = head->next ;

		*item = head;

		head->next=NULL;
	 
		return orginalhead;
	}

	head->next = ListRemovByKeyRec(head->next, key, item);

	return head;
}
Person_t* ListFlip(Person_t* head) {

	assert(head);
	Person_t* prev = head;
	Person_t* next;
	Person_t* cur = head->next;

	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head->next = NULL;
	return prev;
}

Person_t* ListFlipDudi(Person_t* head) {

	Person_t* prev = NULL, * cur = head, * next;
	if (!head) {
		return head;
	}
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	head->next = NULL;
	return prev;
}

Person_t* ListFlipRec(Person_t* head)
{
    Person_t* temp;

    if (!head->next)
    {
        return head;
    }

    temp = ListFlipRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}
int CountUnit(Person_t* node)
{
	if (!node)
	{
		return 0;
	}

	return CountUnit(node->next) + 1;
	
}
int SumOFUnit(Person_t* node)
{
	int sum = 0;

	while (node)
	{
		sum += node->age;
		node = node->next;
	}

	return sum;
}
int ItSort(Person_t* node)
{

	while (node->next)
	{
		if (node->age > node->next->age)
		{
			return 0;
		}

		node = node->next;
	}
	return 1;
}
int SumOfAppir(Person_t* node,int key)
{

	int count = 0;

	while (node)
	{
		if (node->age == key)
		{
			count++;
		}
		node = node->next;
	}
	return count;
}
void PrintfFromEnd(Person_t* node)
{
	if (!node)
	{
		return 0;
	}
	PrintfFromEnd(node->next);

	printf("%d ,", node->age);
}
void ListSort(Person_t** pHead) {

	Person_t* curHead = *pHead;
	Person_t* nextItem = curHead->next;
	Person_t* tempPer;
	int temp;
	char curName[10];

	while (curHead->next != NULL)
	{
		while (nextItem != NULL)
		{
			if (curHead->age > nextItem->age) {

				temp = curHead->age;
				curHead->age = nextItem->age;
				nextItem->age = temp;

				temp = curHead->id;
				curHead->id = nextItem->id;
				nextItem->id = temp;

				strcpy(curName, curHead->name);
				strcpy(curHead->name, nextItem->name);
				strcpy(nextItem->name, curName);
			}

			nextItem = nextItem->next;
		}


		curHead = curHead->next;
		nextItem = curHead->next;
	}
}
Person_t* DelitEven(Person_t* node)
{

	Person_t* temp = node;

	while (node->next->next)
	{
		if (node->next-> age % 2 == 0)
		{
			node->next = node->next->next;
		}
		else
		{
			node = node->next;
		}
		
	}
	return temp;
}
int* DinamyArr(Person_t* node,int *size)
{

	Person_t* temp = node;
	Person_t* temp2 = node;

	int sizeofList = CountUnit(node);

	int min = 2000000,j=0,min2=0;

	int* res = calloc(sizeofList, sizeof(int));

	while (node)
	{
		while (temp)
		{
			if (temp->age < min && temp-> age > min2)
			{
				min = temp->age;
			}
			temp = temp->next;
		}

		res[j++] = min;
		min2 = min;
		min = 100000;
		node = node->next;
		temp = temp2;

	}
	 *size = j;

	return res;
}
Person_t* ListCreateByArr(Person_t* head, int* arr,int size)
{

	assert(arr);
	int i = 1;
	Person_t* temp = head;

	head->age = arr[0];
	while (i < size)
	{
		head->next = calloc(11, sizeof(Person_t));
		head->next->age = arr[i];
		head = head->next;
		i++;
	}
	
	return temp;
}
Person_t* DelitTheODddPlaces(Person_t* node)
{

	Person_t* temp = node;
	Person_t* temp2 = node;
	node = node->next;

	while (1)
	{
		node->next = node->next->next;
		node = node->next;
		if (node->next == NULL)
		{
			break;
		}
		if (node->next->next == NULL)
		{
			node->next = NULL;
			break;
		}
	}
	temp2 = NULL;
	return temp->next;
	
}
Person_t* DelitTheEvenPlaces(Person_t* node)
{
	Person_t* temp = node;
	Person_t* temp2 = node;


	while (1)
	{
		node->next = node->next->next;
		node = node->next;
		if (node->next == NULL)
		{
			break;
		}
		if (node->next->next == NULL)
		{
			node->next = NULL;
		}
	}

	return temp;
}
int DivAtThree(Person_t* node)
{

	Person_t* temp = node;
	int count = 0;

	while (node)
	{
		if (node->age % 3 == 0)
		{
			count++;
		}
		node = node->next;
	}
	return count;
}
Person_t* AddTen(Person_t* node)
{
	Person_t* temp = node;

	while (node)
	{
		node->age += 10;
		node = node->next;
	}

	return temp;
}
int ItDonuSort(Person_t* node)
{
	while (node->next)
	{
		if (node->next->age >= node->age)
		{
			return 0;
		}
		node = node->next;

	}
	return 1;

}
int NumOfShows(Person_t* node,int key)
{
	int count = 0;
	while (node->next)
	{
		if (node->age == key)
		{
			count++;

		}
			node = node->next;
	}
	return count;
}

Person_t* MaikingNewListAndSort(Person_t* node)
{
	/*Person_t* temp = node;
	Person_t* temp2 = node;
	Person_t* res = calloc(1, sizeof(Person_t));

	while (node->next)
	{
		temp2 = node;

		if (node->age >= node->next->age)
		{
			res->next = node->next;
			temp2 = node->next;
			
			node->next = node->next->next;
			temp2->next = NULL;
		}
		node = node->next;
		
	}
	PrintList(temp);

	return res->next;*/


	Person_t* temp = node;
	Person_t* res = calloc(1, sizeof(Person_t));
	Person_t* tempRes = res;
	

	while (temp->next)
	{
		while (temp->age >= temp->next->age)
		{
			res->next = temp->next;
			res = res->next;
			Person_t* temp2 = temp->next;
			temp->next = temp->next->next;
			temp2 = NULL;
		}
		res->next = NULL;
		temp = temp->next;
	}
	PrintList(node);

	return tempRes->next;
}
int SumOfEvenDigit(Person_t* node)
{
	if (!node)
	{
		return 0;
	}

	if (node->age % 2 == 0)
	{
	return SumOfEvenDigit(node->next)+node->age;
	}
	else
	{
		return SumOfEvenDigit(node->next);
	}
}

Person_t* DeliteOlTheKey(Person_t* node,int key)
{
	int countDel = 0, countStay = 0, flag = 1;
	Person_t* temp = node;
	Person_t* temp2 = node;

	if (node->age == key)
	{
			node = node->next;
			countDel++;
		   flag = 0;
	}
		   countStay++;

	while (node->next)
	{

		if (node->next->age == key)
		{
			temp=node;
			while (node->next && node->next->age == key)
			{
				node = node->next;
				countDel++;
			}
			temp->next = node->next;
			
		}
		else
		{
			countStay++;
			node = node->next;
		}
	}
	printf("we deleted %d digit ,\n", countDel);
	printf("we staying white %d digit ,\n", countStay);

	if(flag)
	return temp2;
	else
	{
		return temp2->next;
	}

}

void BigFromKey(Person_t* node, int key)
{

	int sum = 0;

	while (node->next)
	{
		if (node->age > key)
		{
			printf("%d ,", node->age);
			sum += node->age;
		}
		node = node->next;
	}
	printf("\nthe sum of oll biger num from key is is: %d ,",sum);

}

Person_t* FlipRec(Person_t* node)
{

	if (!node || !node->next)
	{
		return node;

	}
	Person_t* temp = FlipRec(node->next);

	node->next->next = node;
	node->next = NULL;

	return temp;
}
 
Person_t* AddToTheEnd(Person_t* node,int valiue)
{
	
	Person_t* temp = node;

	while (node->next)
	{
		node = node->next;
	}
	node->next = calloc(1, sizeof(Person_t));
	node->next->age = valiue;
	node->next->next = NULL;

	return temp;

}

Person_t* MackingLinkList()
{
	Person_t* head = calloc(1,sizeof(Person_t));
	Person_t* temp = head;

	int flag = 0, num = 0;
	
		printf("if you whnt to add more digit yo the list enter 1\n else enter 0\n");
		scanf("%d", &flag);

	while (flag)
	{
		printf("enter the number do you want to add:\n");
		scanf("%d", &num);

		head->next = calloc(1, sizeof(Person_t));
		head->next->age = num;
		head = head->next;

		printf("if you whnt to add more digit yo the list enter 1\n else enter 0\n");
		scanf("%d", &flag);
	}

	return temp->next;

}

Person_t* ItrFlip(Person_t* node)
{
	Person_t* prv = NULL;
	Person_t* cur = node->next;
	
	while (node->next)
	{
		node->next = prv;
		prv = node;
		node = cur;
		cur = cur->next;
	
	}
	node->next = prv;
	
	return node;
}

