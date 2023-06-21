#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include"singelyLinkList.h"


int main()
{


	Person_t* head = NULL;
	Person_t* head2 = NULL;



		Person_t item5 = { 1,"ket",50,NULL };

		head = ListInsertHead(head, &item5);


		Person_t item6 = { 2,"meny",60,NULL };

		head = ListInsertHead(head, &item6);
	
		Person_t item4 = { 3,"mom",40,NULL };

		head = ListInsertHead(head, &item4);

	Person_t item1= { 4,"shneor",10,NULL };

		head = ListInsertHead(head,&item1);

	Person_t item2= {5,"davib",20,NULL};
		
		head = ListInsertHead(head,&item2);

	Person_t item3= {6,"gay",30,NULL};

		head = ListInsertHead(head,&item3);



		//head2//

		//head2 = ListInsertHead(head2, &item6);

		//head2 = ListInsertHead(head2, &item5);

		//head2 = ListInsertHead(head2, &item4);

		//Person_t item9 = { 333,"shneor_b",10,NULL };

		//head2 = ListInsertHead(head2, &item9);

		PrintList(head);

		Person_t* res = MultLink2(head);
		
		PrintList(res);

		
		/*Person_t* res= foundEqelNode(head, head2);*/

				/*PrintList(head);
				PrintList(head2);*/

				//printf("\n %d \n", res->age);
				//printf("\n %s \n", res->name);


		
		 
			
				/*head = FlipRec(head);

				PrintList(head);*/

	/*Person_t item6;

		head = ListInsertHead(head,&item6);*/


		/*Person_t* item4 ;

		head = ListRemoveHead(head,&item4);

		printf("im go to remov:\n\n");
		printf("%d ", item4->age);
		printf("%d ", item4->id);
		printf("%s\n ", item4->name);
		
		PrintList(head);*/

	/*PrintList(head);

		head = ListInsertHead(head,&item5);*/

		
	/*Person_t item5= {888,"ron",2,NULL};

		head = ListInsertByKey(head,item5.age, &item5);

		PrintList(head);

		Person_t* empty = NULL;

	Person_t item7= {1010,"dandan",25,NULL};

		head = ListRemovByKey(head, 25, &empty);

		PrintList(head);

		if(empty->next)
		printf("\n%d\n", empty->next->id);

		if(empty)
		{
			printf("\n%d\n", empty->age);
		}*/

		/*Person_t item6 = { 333,"ron",10,NULL };

		head = ListInsertByKeyRec(head, item6.age, &item6);*/

	

	/*	Person_t item7 = { 999,"tom",90,NULL };

		head=ListInsertByKeyRec(head, item7.age, &item7);
		
		head = ListRemovByKeyRec(head, item7.age, &item7);

		head = ListFlipRec(head);

		PrintList(head);*/



		//printf("\n%d\n", CountUnit(head));
		//printf("\n%d\n",SumOFUnit(head));
		//printf("\n%d\n", ItSort(head));
	/*	PrintfFromEnd(head);*/
	/*	printf("\n%d\n", SumOfAppir(head,50));*/
		/*ListSort(&head);*/

		/*head = DelitEven(head);
			PrintList(head);*/
	
		/*	int size;

			int* res = DinamyArr(head,&size);

			for (int i = 0; i < size; i++)
			{
				printf("%d ,", res[i]);
			}*/

		/*int arr[10] = {3,5,7,9,11};

		Person_t* head2 = calloc(6, sizeof(Person_t));
		Person_t* head3 = NULL;

		

		head3 = ListCreateByArr(head2, arr, 5);

		PrintList(head3);*/

		//head = DelitTheODddPlaces(head);
	/*	head = DelitTheEvenPlaces(head);*/

	/*	printf("\n%d\n", DivAtThree(head));*/

		/*head = AddTen(head);

		PrintList(head);*/

		/*printf("\n%d\n",ItDonuSort(head));*/

	/*	printf("\n%d\n", NumOfShows(head,30));*/

	/*	Person_t* res;

		res = MaikingNewListAndSort(head);*/
	
		/*printf("\n%d\n", SumOfEvenDigit(head));
		*/
		/*BigFromKey(head,15);*/

  /*  head = AddToTheEnd(head,999);

	head = ListInsertHead(head, &item11);*/

//Person_t* newList = MackingSortLinkList();
//
//	PrintList(newList);

	
		
	/*head=ItrFlip(head);

	PrintList(head);

		*/







}