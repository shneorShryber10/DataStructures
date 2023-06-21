/**************************************************************************************
    Author: shneor shryber.
    Creation date:  13/7/22
    Last modified date: --
    Description:LIFO, Sequence of elements, Grows on demand.
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "vector.h"
#include "stack.h"

stack_t* StackMaxToTop(stack_t* stack);
float CalcPostfixExpression(char* str);

int main()
{
    ADTErr  eErr;
  /*  Vector_t* stk = NULL;
   
    Vector_t* tmpstk = NULL;*/

    /* Test-case 1: Create Vector */
  /*  printf("Vector Unit-Test: \n-----------------\n");*/
  /*  stk = stackCreaite(10, 2);
    eErr = StackPush(stk, 7);*/
//    StackPrint(stk);
//    /*End-case: Add element to null vector */
//    HandleErr(eErr, "Adding value: 7");
//
////    /* Test-case 2: Add element */
//    eErr = StackPush(stk, 7);
//    StackPrint(stk);
//     HandleErr(eErr, "Adding value: 7");
//    eErr = StackPush(stk, 8);
//    HandleErr(eErr, "Adding value: 8");
//    eErr = StackPush(stk, 70);
//    HandleErr(eErr, "Adding value: 70");
//    eErr = StackPush(stk, 3);
//    StackPrint(stk);
  /*  StackPush(stk, 3);
    StackPush(stk, 3);
    StackPush(stk, 3);
    StackPush(stk, 3);
    StackPush(stk, 3);
    StackPush(stk, 3);*/
//   
//   
//    StackPush(stk, 10);
//    HandleErr(eErr, "Adding value: 10");
//    eErr = StackPush(stk, 11);
//    StackPrint(stk);/*Feature: Grows on demand. */
//      HandleErr(eErr, "Adding value: 11");
     /* */
//      ///////////////////////////////////////////////////////////////////////////////////3
//      /* Test-case 3: Delete element */
//      /*....*/
//
   /* int curNum = NULL;*/

  /*  eErr = StackPop(stk,curNum);
     HandleErr(eErr, "try to delite with null");
     printf("\n%d\n",curNum);
     StackPrint(stk);*/

   /*    int num ;
        eErr = StackPop(stk,&num);
        HandleErr(eErr, "\n try to delite with null");
        printf("\n%d\n",num);
        StackPrint(stk);

        eErr = StackPop(stk,&num);
        HandleErr(eErr, "\ntry to delite with null");
        printf("\n%d\n",num);

        while(!eErr)
        {
            eErr = StackPop(stk, &num);
            HandleErr(eErr, "\ntry to delite from empty vec");
            StackPrint(stk);
        }*/
//        /////////////////////////////////////////////////////////////////////////////////////////3

    
   
  /*  StackPrint(stk);*/

//   /* Test-case 5: Get element    */
//   /*....*/
//    ////////////////////////////////////////////////////////////////////////////5
//
  /*  int item;
  
    eErr = StackTop(stk,&item);
     HandleErr(eErr, "try to get index");
     StackPrint(stk);
     printf("\n the item is- %d",item);

     printf("\n%d", StackIsEmpty(stk));

     StackDestroy(stk);
    return 0;*/
    /////////////////////////////////////////exe 2:

    //char* str = "{}(2+C)[v]";
    //char* str1 = "{(2+C";
    //char* str2 = "{(2+C)[v]}}}}}";

    //printf("%d\n",CheckParentheses(str));

    //printf("%d\n",CheckParentheses(str1));
    //printf("%d\n",CheckParentheses(str2));
    ///////////////////////////////////////////exe3:

   
    stack_t* stk = NULL;
    stack_t* newStk = NULL;
    stack_t* tempStk = NULL;
    int num;
    stk = stackCreaite(8, 2);
    eErr = StackPush(stk, 2);
     HandleErr(eErr, "Adding value: 2"); 
     eErr = StackPush(stk, 4);
     HandleErr(eErr, "Adding value: 4");
     eErr = StackPush(stk, 9);
     HandleErr(eErr, "Adding value: 9"); 
     eErr = StackPush(stk, 6);
     HandleErr(eErr, "Adding value: 6"); 
     eErr = StackPush(stk, 9);
     HandleErr(eErr, "Adding value: 9"); 
     eErr = StackPush(stk, 5);
     HandleErr(eErr, "Adding value: 9"); 

    /* StackPrint(stk);*/
     printf("\n");
  
    /* printf("\t the stack after the 'maxToTop' func is: )\n");*/
    newStk= StackMaxToTop(stk);

   /*  StackPrint(newStk);*/

     /////////test 2
     newStk = StackMaxToTop(tempStk);

     StackDestroy(newStk);

   /* StackPrint(newStk);*/
     ///////////////////////////////////////////////////////////////////exe 6
    char* str1 = "123*+";

    char* str2 = "2345";

    char* str3 = "121*+++++++++";


    float res = CalcPostfixExpression(str1);
    printf("the res is: %f\n", res);
    
     res = CalcPostfixExpression(str2);
    printf("the res is: %f\n", res);

    res = CalcPostfixExpression(str3);
    printf("the res is: %f\n", res);


   /*  newStk = StackReverse(stk);*/



}
float CalcPostfixExpression(char* str)
{
 
    ADTErr  eErr;
    stack_t* stk;
    int num1 = 0,num2=0 ;
    float res = 0;

    stk = stackCreaite(8, 2);
    if (!stk)
    {
        printf("the stk not inilized!");
        exit(1);
    }

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
        {
            
            eErr= StackPop(stk, &num1);
            HandleErr(eErr, "Adding value: 9");
            if (eErr)
            {
                HandleErr(eErr, " pup to empty stack");
                exit(1);
            }

            eErr = StackPop(stk, &num2);
            if (eErr)
            {
            HandleErr(eErr, "pup to empty stack");
             exit(1);
            }



            if (str[i] == '*')
                res = num1*num2 ;

                if(str[i] == '/')
                    res = num1/num2;

                    if(str[i] == '+')
                        res = num1+num2 ;

                        if(str[i] == '-')
                            res = num1-num2;


                        StackPush(stk, res);
        }
        else
        {
          StackPush(stk, str[i]-'0');
        }
    }

    StackDestroy(stk);

    return res;
}

stack_t* StackMaxToTop(stack_t* stack)
{
    if (!stack)
    {
        return NULL;
    }
    int max = 0;
    int num, count = 0;
    ADTErr  eErr;
    stack_t* tempMax;
    stack_t* maxStk;
    tempMax= stackCreaite(8, 2);
    maxStk = stackCreaite(8, 2);

    while (!StackIsEmpty(stack))
    {
        eErr = StackPop(stack, &num);
        if (eErr)
        {
            HandleErr(eErr, "try to get index");
        }
        if (num > max)
        {
            max = num;
        }
                eErr = StackPush(tempMax,num);
                if (eErr)
                {
                    HandleErr(eErr, "try to get index");
                }
    }
    while (!StackIsEmpty(tempMax))
    {
        eErr = StackPop(tempMax, &num);

        if (eErr)
        {
            HandleErr(eErr, "try to get index");
        }
        if (num == max)
        {
            count++;
            continue;
        }
        eErr = StackPush(maxStk, num);
        if (eErr)
        {
            HandleErr(eErr, "try to get index");
        }
    }
    while (count--)
    {
        eErr = StackPush(maxStk, max);
        if (eErr)
        {
            HandleErr(eErr, "try to get index");
        }
    }

    StackDestroy(tempMax);
    return maxStk;
}
int CheckParentheses(char* str)
{
    
    ADTErr  eErr;
    stack_t* stk = NULL;
    int num;
    stk = stackCreaite(8,2);

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            eErr = StackPush(stk,str[i]);
            if (eErr)
            {
                HandleErr(eErr, "try to get index");
            }
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
                eErr = StackPop(stk, &num);
                if (eErr)
                {
                    HandleErr(eErr, "try to get index");
                    return 0;
                }
                if ( str[i] != num+2 && str[i] != ')' )
                {
                    return 0;
                }
                else if(str[i] != num+1 && str[i]==')')
                {
                    return 0;
                }
        }

    }
    if (!StackIsEmpty(stk))
    {
        return 0;
    }


        return 1;
}