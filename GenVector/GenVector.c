/**************************************************************************************
    Author: Dudi Kahana
    Creation date :  6/7/22
    Last modified date: --
    Description : ADT General definitions.
***************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ADTDefs.h"
#include "GenVector.h"

#define REALLOC_FACTOR 2

struct GenVector
{
    void** items;
    size_t  originalSize;
    size_t  blockSize;
    size_t  currSize;
    size_t  nItems;
};


GenVector_t*  GenVectorCreate(size_t size, size_t blockSize)
{
    GenVector_t* vector;

    if ((size == 0) && (blockSize == 0))
    {
        return NULL;
    }

    vector = (GenVector_t*)malloc(sizeof(GenVector_t));
    if (!vector)
    {
        return NULL;
    }

    vector->items = (void**)malloc(sizeof(void*) * size);

    if (!vector->items)
    {
        free(vector);
        return NULL;
    }

    vector->currSize = size;
    vector->originalSize = size;
    vector->blockSize = blockSize;
    vector->nItems = 0;

    return vector;
}

void  GenVectorDestroy(GenVector_t* vector)
{
    if (vector)
    {
        free(vector->items);
        free(vector);
    }
}

ADTErr   GenVectorAdd(GenVector_t* vector, void* item)
{
    void** tmp;

    assert(vector && item);

    if (vector->nItems == vector->currSize)
    {
        if (vector->blockSize == 0)
        {
            return ERR_OVERFLOW;
        }
        tmp = (void**)realloc(vector->items,
            sizeof(void*) * (vector->currSize + vector->blockSize));

        if (NULL == tmp)
        {
            return ERR_REALLOCATION_FAILED;
        }
        vector->items = tmp;
        vector->currSize += vector->blockSize;
    }

    *(vector->items + vector->nItems) = item; //*void 
    ++vector->nItems;

    return ERR_OK;
}

ADTErr   GenVectorDelete(GenVector_t* vector, void** item)
{
    void** tmp;

    assert(vector&&item);

    if (vector->nItems == 0)
    {
        return ERR_UNDERFLOW;
    }

    if ((vector->currSize > vector->originalSize) &&
        (vector->nItems <= vector->currSize - (vector->blockSize * REALLOC_FACTOR)))
    {
        tmp = (void**)realloc(vector->items,
            sizeof(void*) * (vector->currSize - vector->blockSize));
        if (!tmp)
        {
            return (ERR_REALLOCATION_FAILED);
        }

        vector->items = tmp;
        vector->currSize -= vector->blockSize;
    }

    *item = *(vector->items + vector->nItems - 1);
    --vector->nItems;

    return ERR_OK;
}

/* Index from 1 */
ADTErr   GenVectorGet(GenVector_t* vector, size_t index, void** item)
{
    assert(vector && item);

    if (index > vector->nItems || index < 1)
    {
        return (ERR_WRONG_INDEX);
    }

    *item = *(vector->items + index - 1);

    return ERR_OK;
}

ADTErr   GenVectorSet(GenVector_t* vector, size_t index, void* item)
{
    assert(vector && item);

    if (index > vector->nItems || index < 1)
    {
        return (ERR_WRONG_INDEX);
    }

    *(vector->items + (index - 1)) = item;
    return ERR_OK;
}

ADTErr   GenVectorItemsNum(GenVector_t* vector, size_t* numOfItems)
{
    assert(vector && numOfItems);

    *numOfItems = vector->nItems;

    return ERR_OK;
}


/*  Unit-Test functions  */

void GenVectorPrint(GenVector_t* vector,PrintFunc print)
{
    assert(vector);
    printf("----------------------------------------\n");

    printf("<vector details> | blockSize=%zu | nItems=%zu | currSize=%zu | originalSize=%zu | \n <vector item> ",
        vector->blockSize, vector->nItems, vector->currSize, vector->originalSize);

    for (int i = 0; i < vector->nItems; ++i)
    {
        print(*(vector->items + i));
    }

}

