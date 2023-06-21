#pragma once
/**************************************************************************************
    Author: Dudi Kahana.
    Creation date:  6/7/22
    Last modified date: --
    Description: Sequence of elements, Direct access, Grows on demand.
***************************************************************************************/
#ifndef __GENVECTOR_H__
#define __GHNVECTOR_H__

typedef struct GenVector GenVector_t;



typedef void (*PrintFunc)(const void*);


/* size      - The initial allocation size.
   blockSize - The extention block size.    */
GenVector_t* GenVectorCreate(size_t _size, size_t blockSize);

void     GenVectorDestroy(GenVector_t* vector);

/* Add item to end. */
ADTErr   GenVectorAdd(GenVector_t* vector, void* item);

/* Delete item from the end. */
ADTErr   GenVectorDelete(GenVector_t* vector, void** item);

/* The Index range in the following functions is : 1..numOfItems */
ADTErr   GenVectorGet(GenVector_t* _vector, size_t index, void** item);

ADTErr   GenVectorSet(GenVector_t* vector, size_t index, void* item);

ADTErr   GenVectorItemsNum(GenVector_t* vector, size_t* numOfItems);


/*  Unit-Test functions  */
void GenVectorPrint(GenVector_t* vector, PrintFunc print);

void PrintfPerson(void* person);

void PrintfInt(void* num);

void PrintChar(void* num);

void PrintFloat(void* num);

#endif /*__GENVECTOR_H__*/