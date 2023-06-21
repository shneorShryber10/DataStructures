/**************************************************************************************
    Author: Dudi Kahana
    Creation date :  6/7/22
    Last modified date: --
    Description : ADT General definitions.
***************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "ADTDefs.h"
#include "Vector.h"

#define REALLOC_FACTOR 2

struct Vector
{
    int* items;
    size_t  originalSize;
    size_t  blockSize;
    size_t  currSize;
    size_t  nItems;
};


Vector_t* VectorCreate(size_t size, size_t blockSize)
{
    Vector_t* vector;

    if ((size == 0) && (blockSize == 0))
    {
        return NULL;
    }

    vector = (Vector_t*)malloc(sizeof(Vector_t));
    if (!vector)
    {
        return NULL;
    }

    vector->items = (int*)malloc(sizeof(int) * size);
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

void     VectorDestroy(Vector_t* vector)
{
    if (vector)
    {
        free(vector->items);
        free(vector);
    }
}

ADTErr VectorAdd(Vector_t* vector, int item)
{
    int* tmp;

    if (!vector)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (vector->nItems == vector->currSize)
    {
        if (vector->blockSize == 0)
        {
            return ERR_OVERFLOW;
        }
        tmp = (int*)realloc(vector->items,
            sizeof(int) * (vector->currSize + vector->blockSize));

        if (NULL == tmp)
        {
            return ERR_REALLOCATION_FAILED;
        }
        vector->items = tmp;
        vector->currSize += vector->blockSize;
    }

    *(vector->items + vector->nItems) = item;
    ++vector->nItems;

    return ERR_OK;
}

ADTErr VectorDelete(Vector_t* vector, int* item)
{
    int* tmp;

    if (!vector || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (vector->nItems == 0)
    {
        return ERR_UNDERFLOW;
    }

    if ((vector->currSize > vector->originalSize) &&
        (vector->nItems <= vector->currSize - (vector->blockSize * REALLOC_FACTOR)))
    {
        tmp = (int*)realloc(vector->items,
            sizeof(int) * (vector->currSize - vector->blockSize));
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
ADTErr VectorGet(Vector_t* vector, size_t index, int* item)
{

    if (!vector || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (index > vector->nItems || index < 1)
    {
        return (ERR_WRONG_INDEX);
    }

    *item = *(vector->items + index - 1);

    return ERR_OK;
}

ADTErr   VectorSet(Vector_t* vector, size_t index, int  item)
{
    if (!vector)
    {
        return ERR_NOT_INITIALIZED;
    }
    if (index > vector->nItems || index < 1)
    {
        return (ERR_WRONG_INDEX);
    }

    *(vector->items + (index - 1)) = item;
    return ERR_OK;
}

ADTErr VectorItemsNum(Vector_t* vector, size_t* numOfItems)
{
    if (!vector || !numOfItems)
    {
        return ERR_NOT_INITIALIZED;
    }

    *numOfItems = vector->nItems;

    return ERR_OK;
}


/*  Unit-Test functions  */
void VectorPrint(Vector_t* vector)
{
    if (!vector)
    {
        return;
    }
    printf("----------------------------------------\n");

    printf("<vector details> | blockSize=%zu | nItems=%zu | currSize=%zu | originalSize=%zu | \n <vector item> ",
        vector->blockSize, vector->nItems, vector->currSize, vector->originalSize);

    for (int i = 0; i < vector->nItems; ++i)
    {
        printf("%d ", *(vector->items + i));

    }

    printf("\n----------------------------------------\n");


}