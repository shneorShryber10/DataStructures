#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "GenVector.h"


typedef struct Person
{
    int age;
    char* name;

}Person_t;

int main()
{

    GenVector_t* vec = NULL;
    GenVector_t* tmpVec = NULL;
    ADTErr  eErr;

    Person_t p1 = { 23,"shneor"};
    Person_t p2 = { 35,"dan" };
    Person_t p3 = { 77,"ron" };
    Person_t p4 = { 97,"moshe" };
    Person_t p5 = { 43,"jon" };

    int num1=7;
    int num2=6;
    int num3=5;
    int num4=4;
    int num5=3;
    size_t sum;

    /* Test-case 1: Create Vector */
  /*  printf("Vector Unit-Test: \n-----------------\n");*/
   // HandleErr(eErr, "Adding value: 7");

    vec = GenVectorCreate(10,2);

    eErr = GenVectorAdd(vec, &p1);          /*End-case: Add element to null vector */
    /* Test-case 2: Add element */
    eErr = GenVectorAdd(vec, &p2);
    // HandleErr(eErr, "Adding value: 7");
    eErr = GenVectorAdd(vec, &p3);

    eErr = GenVectorAdd(vec, &p4);

    //eErr = GenVectorAdd(vec, &p5);

    //eErr = GenVectorAdd(vec, &num1);
    //eErr = GenVectorAdd(vec, &num2);
    //eErr = GenVectorAdd(vec, &num4);
    //HandleErr(eErr, "Adding value: 8");
    ////HandleErr(eErr, "Adding value: 70");
    //eErr = GenVectorAdd(vec, &num5); 

    //eErr= GenVectorAdd(vec, &num3);
    /*HandleErr(eErr, "Adding value: 3");
    VectorPrint(vec);*/

    int* del;
    
        int* found ;
        Person_t* delP;
        Person_t* foundP;


    GenVectorItemsNum(vec, &sum);
    printf("\n  the sum is: %d\n",sum);

    eErr = GenVectorDelete(vec, &delP);
    printf("\n del the num :%d\n",delP->age);
    GenVectorPrint(vec, PrintfPerson);

    GenVectorGet(vec, 2, &foundP);
    printf("\n found num is the num :%d\n", foundP->age);
 
    int num8 = 99;
    Person_t p9 = { 1000,"gogo" };
    
    /* GenVectorPrint(vec, PrintfInt);*/
     GenVectorPrint(vec, PrintfPerson);

    GenVectorSet(vec, 2, &p9);

    GenVectorItemsNum(vec, &sum);
    printf("\n  the sum is: %d\n", sum);

     /*GenVectorPrint(vec, PrintfInt);*/
    GenVectorPrint(vec, PrintfPerson);

}
void PrintfPerson(void* person)
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