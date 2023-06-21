
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#include "ADTDefs.h"
#include "GenVector.h"
#include "Sorting.h"

typedef struct Person
{
    char name[20];
    int age;

}Person_t;
void PrintfInt(void* num);
void PrintStr(const void* item);
void PrintfPerson(void* person);

int cmpIntUp(void* num1, void* num2);
int cmpIntDonw(void* num1, void* num2);
int CmpStr(void* num1, void* num2);
int cmpPerson(void* num1, void* num2);

int ReturnIntToInt(void* num);
int ReturnPersonToInt(void* num);

int main()
{
    GenVector_t* vec = NULL;
    GenVector_t* vec2 = NULL;
    GenVector_t* vec3 = NULL;
    GenVector_t* vec4 = NULL;
    GenVector_t* vec5 = NULL;
    GenVector_t* tmpVec = NULL;
    ADTErr  eErr;

    int num1 = 40;
    int num2 = 20;
    int num3 = 50;
    int num4 = 80;
    int num5 = 10;
    int num6 = 20;
    vec = GenVectorCreate(10, 2);

    eErr = GenVectorAdd(vec, &num1);
    eErr = GenVectorAdd(vec, &num2);
    eErr = GenVectorAdd(vec, &num3);
    eErr = GenVectorAdd(vec, &num4);
    eErr = GenVectorAdd(vec, &num5);
    eErr = GenVectorAdd(vec, &num6); 

    //strung :
    char* str1 = "abc";
    char* str2 = "bac";
    char* str3 = "cab";
    char* str4 = "abc";
    char* str5 = "aaa";
    char* str6 = "bbb";

    vec2 = GenVectorCreate(10, 2);

    eErr = GenVectorAdd(vec2, str1);
    eErr = GenVectorAdd(vec2, str2);
    eErr = GenVectorAdd(vec2, str3);
    eErr = GenVectorAdd(vec2, str4);
    eErr = GenVectorAdd(vec2, str5);
    eErr = GenVectorAdd(vec2, str6);

    //Person:

    Person_t p1 = { "shneor",20 };
    Person_t p2 = { "dan",90 };
    Person_t p3 = { "jon",70 };
    Person_t p4 = { "shy",10 };
    Person_t p5 = { "rr",50 };
    Person_t p6 = { "or",40 };
   

    vec3 = GenVectorCreate(10, 2);

    eErr = GenVectorAdd(vec3, &p1);
    eErr = GenVectorAdd(vec3, &p2);
    eErr = GenVectorAdd(vec3, &p3);
    eErr = GenVectorAdd(vec3, &p4);
    eErr = GenVectorAdd(vec3, &p5);
    eErr = GenVectorAdd(vec3, &p6);

    //shke............................

    int num11 = 40;
    int num12 = 20;
    int num13 = 50;
    int num14 = 80;
    int num15 = 10;
    int num16 = 20;
    vec4 = GenVectorCreate(10, 2);

    eErr = GenVectorAdd(vec4, &num11);
    eErr = GenVectorAdd(vec4, &num12);
    eErr = GenVectorAdd(vec4, &num13);
    eErr = GenVectorAdd(vec4, &num14);
    eErr = GenVectorAdd(vec4, &num15);
    eErr = GenVectorAdd(vec4, &num16);


    int num21 = 329;
    int num22 = 457;
    int num23 = 657;
    int num24 = 839;
    int num25 = 436;
    int num26 = 720;
    int num27 = 355;
    int num28 = 4;
    int num29 = 755;
   
    

    
    
    vec5 = GenVectorCreate(12, 2);

    eErr = GenVectorAdd(vec5, &num21);
    eErr = GenVectorAdd(vec5, &num22);
    eErr = GenVectorAdd(vec5, &num23);
    eErr = GenVectorAdd(vec5, &num24);
    eErr = GenVectorAdd(vec5, &num25);
    eErr = GenVectorAdd(vec5, &num26);
    eErr = GenVectorAdd(vec5, &num27);
    eErr = GenVectorAdd(vec5, &num28);
   /* eErr = GenVectorAdd(vec5, &num29);*/
   
   
    
    


    // WORK.......................

    printf("\n BUBBLE SORT By int :\n\n..............................BUBBLE SORT...........................");

  /*  BubbleSort(vec, cmpIntUp);
    printf("\nsort after UpSort:\n ");
    GenVectorPrint(vec, PrintfInt);
   
    BubbleSort(vec,cmpIntDonw);
    printf("\nsort after DonwSort: \n");

    GenVectorPrint(vec, PrintfInt);*/



  /*  BubbleSort(vec2, CmpStr);
    printf("\n\n the string after Sort\n\n");

    GenVectorPrint(vec2,PrintStr);*/


    /*BubbleSort(vec3,cmpPerson);
    printf("\n\n the Person after Sort\n\n");

    GenVectorPrint(vec3, PrintfPerson);*/

    printf("\n SHKE Sort :\n\n..............................SHKE SORT...........................");

   /* ShkeBabeleSort(vec4, cmpIntDonw);
    printf("\nsort after UpSort ShkeBabeleSort :\n ");
    GenVectorPrint(vec4, PrintfInt);*/

    printf("\n INSERSION Sort :\n\n..............................INSERSION SORT...........................");
   /* ShkeBabeleSort(vec3, cmpPerson);
    printf("\nsort after UpSort:\n ");
    GenVectorPrint(vec3, PrintfPerson);*/

   /* InsertionSort(vec3, cmpPerson);
    printf("\n the Person after  Insertion Sort:\n ");
    GenVectorPrint(vec3, PrintfPerson);*/

    printf("\nSELECTIO Sort :\n\n..............................SELECTION SORT...........................");


  /*  SelectionSort(vec5, cmpIntUp);
    printf("\nsort after UpSort Selectio Sort :\n ");
    GenVectorPrint(vec5, PrintfInt);*/

    printf("\nQUICK Sort :\n\n..............................QUICK SORT...........................");

    //QuickSort(vec5, cmpIntUp);
    //printf("\n the arr after  Insertion Sort UP:\n ");

    //GenVectorPrint(vec5, PrintfInt);

    //QuickSort(vec5,cmpIntDonw);
    //printf("\n the arr after  Insertion Sort DONE:\n ");

    //GenVectorPrint(vec5, PrintfInt);

    printf("\n MARGE Sort :\n\n..............................MARGE SORT...........................");

   /* eErr=MargeSort(vec5, cmpIntUp);
    printf("\n the arr after  Insertion Sort UP:\n ");

    GenVectorPrint(vec5, PrintfInt);


    MargeSort(vec5, cmpIntDonw);
    printf("\n the arr after  Insertion Sort UP:\n ");

    GenVectorPrint(vec5, PrintfInt);*/


    printf("\nCOUNTING Sort :\n\n..............................COUNTING SORT...........................");

   /* eErr = CountingSort(vec3, ReturnPersonToInt);
    printf("the arr after  COUNTING Sort by person");
    GenVectorPrint(vec3, PrintfPerson);

   
    eErr = CountingSort(vec5, ReturnIntToInt);
    printf("the arr after  COUNTING Sort by int");
    GenVectorPrint(vec5, PrintfInt);*/


    printf("\RADIX Sort :\n\n..............................RADIX SORT...........................");

    eErr = RodixSort(vec3, ReturnPersonToInt);
    printf("the arr after  RADIX Sort by person");
    GenVectorPrint(vec3, PrintfPerson);


   eErr = RodixSort(vec5, ReturnIntToInt);
    printf("the arr after  RADIX Sort by Int");
    GenVectorPrint(vec5, PrintfInt);

    int item = 839;

    printf("\n\n item %d is found in index <---> %d \n",item, BinSearchRec(vec5, &item, cmpIntUp));

}
int cmpPerson(void* num1,void* num2)
{
    Person_t* p1 = (Person_t*)num1;
    Person_t* p2 = (Person_t*)num2;

    if (p1->age < p2->age)
    {
        return -1;
    }
    if (p1->age > p2->age)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int CmpStr(void* num1, void* num2)
{
        return strcmp(num1, num2);
}
int cmpIntUp(void* num1, void* num2)
{
    if ((*(int*)num1 < *(int*)num2))
    {
    return -1 ;
    }
    if ((*(int*)num1 > *(int*)num2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int cmpIntDonw(void* num1, void* num2)
{

    if ((*(int*)num1 > *(int*)num2))
    {
        return -1;
    }
    if ((*(int*)num1 < *(int*)num2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void cmpChar(void* num)
{
    printf("the charter is: %c", *(char*)num);
}
void cmpFloat(void* num)
{
    printf("the num is: %f", *(float*)num);
}

// /Print.....................................

void PrintfPerson(const void* person)
{

    Person_t* p = (Person_t*)person;

    printf("\n %d , %s \n", p->age, p->name);
}
void PrintfInt(void* num)
{
    printf("\n the num is: %d", *(int*)num);
}
void PrintChar(void* num)
{
    printf("the charter is: %c", *(char*)num);
}
void PrintFloat(void* num)
{
    printf("the num is: %f", *(float*)num);
}
void PrintStr(const void* item)
{

    char* str = (char*)item;
    printf("%s ", str);
}

// Casting to int............................
int ReturnIntToInt(void* num)
{
    return *(int*)num;
}
int ReturnPersonToInt(void* num)
{
    Person_t* p = (Person_t*)num;

    return p->age;
}
int ReturnCharToInt(void* num)
{

    return *(char*)num;
    
}
