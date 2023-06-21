#pragma once
/**************************************************************************************
    Author: shneor shryber.
    Creation date:  13/7/22
    Last modified date: --
    Description:LIFO, Sequence of elements, Grows on demand.
***************************************************************************************/

#ifndef __STACK_H__
#define __STACK_H__

typedef struct Stack stack_t;

stack_t* stackCreaite(size_t size, size_t blockSize);

ADTErr StackPush(stack_t* stack, int item);

void StackPrint(stack_t* stack);

ADTErr StackPop(stack_t* stack, int* item);

ADTErr StackTop(stack_t* stack, int* item);

int StackIsEmpty(stack_t* stack);

void StackDestroy(stack_t* stack);

stack_t* StackReverse(stack_t* stk);


#endif // __STACK_H__
