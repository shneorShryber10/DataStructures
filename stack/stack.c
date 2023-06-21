/**************************************************************************************
    Author: shneor shryber.
    Creation date:  13/7/22
    Last modified date: --
    Description:LIFO, Sequence of elements, Grows on demand.
***************************************************************************************/


#include <stdlib.h>
#include <stdio.h>

#include "ADTDefs.h"
#include "vector.h"
#include "stack.h"


struct Stack
{
    Vector_t* vec;

};

stack_t* stackCreaite(size_t size, size_t blockSize)
{
    stack_t* stack=NULL;
    stack = (stack_t*)malloc(sizeof(stack_t));
    if (!stack)
    {
        return ERR_NOT_INITIALIZED;
    }

    stack->vec= VectorCreate(size, blockSize);
    if (!stack->vec)
    {
        free(stack);

        return ERR_NOT_INITIALIZED;
    }

    return stack;
}
ADTErr StackPush(stack_t* stack, int item)
{
    if (!stack)
    {
        return ERR_NOT_INITIALIZED;
    }
    return VectorAdd(stack->vec,item);
}
void StackPrint(stack_t* stack)
{
    if (!stack)
    {
        printf("\n\n!!!!cant print this is not initialized!!\n\n");
    }
    else
    {
    VectorPrint(stack->vec);
    }
}
ADTErr StackPop(stack_t* stack, int* item)
{
    if (!stack)
    {
        return ERR_NOT_INITIALIZED;
    }
    return VectorDelete(stack->vec,item);
}
ADTErr StackTop(stack_t* stack, int* item)
{
    size_t numOfItems;

    if (!stack|| VectorItemsNum(stack->vec, &numOfItems))
    {
        return ERR_NOT_INITIALIZED;
    }

   return VectorGet(stack->vec,numOfItems,item);
}
int StackIsEmpty(stack_t* stack)
{
    rsize_t nItem =0;
    if (!stack || VectorItemsNum(stack->vec, &nItem))
    {
        return 1;
    }
    return !(nItem);
}
void StackDestroy(stack_t* stack)
{
    if (stack)
    {
        VectorDestroy(stack->vec);
        free(stack);
    }
    
}
stack_t* StackReverse(stack_t* stack)
{
    ADTErr  eErr;
    stack_t* newStk = NULL;
    int num;
    size_t size;

    VectorItemsNum(stack->vec, &size);

    if (!stack || !size)
    {
        return NULL;
    }
    newStk = stackCreaite(size, 2);

    while (!StackIsEmpty(stack))
    {
        eErr = StackPop(stack, &num);

        if (eErr)
        {
            HandleErr(eErr, "try to get index");
        }
        eErr = StackPush(newStk, num);

        if (eErr)
        {
            HandleErr(eErr, "try to get index");
        }
    }
    StackPrint(newStk);

    return newStk;
}
 