#include <stdio.h>
#include "ADTDefs.h"
#include "BinaryHeap.h"
#include "Vector.h"

int main()
{
    Vector_t* vec = NULL;
    Vector_t* tmpVec = NULL;
    ADTErr  eErr;
    Heap_t* heap;
    int TheDeleteNum;
    int TheDeleteNum2;
    int TheDeleteNum3;

         
  
    vec = VectorCreate(10, 2);

    /* Test-case 2: Add element */
    eErr = VectorAdd(vec, 7);
    eErr = VectorAdd(vec, 8);
    eErr = VectorAdd(vec, 70);
    eErr = VectorAdd(vec, 3);
    eErr = VectorAdd(vec, 6);
    eErr = VectorAdd(vec, 3);
    eErr = VectorAdd(vec, 6);
    eErr = VectorAdd(vec, 10);
    eErr = VectorAdd(vec, 100);
    eErr = VectorAdd(vec, 190);
    eErr = VectorAdd(vec, 150);


    /*HandleErr(eErr, "Adding value: 3");
    VectorPrint(vec);*/
    

    VectorPrint(vec);

    printf("\nafter Heap Order:\n");

    heap = BinHeapBuild(vec);

    PrintfBinartHeap(heap);
    /*int item;
    BinHeapDelete(heap, &item);*/

    heapSort(heap);
    printf("\nheap after Sorted:\n");
    PrintfBinartHeap(heap);
    printf("\nheap after Remove:\n");


    BinHeapDelete(heap, &TheDeleteNum);
    PrintfBinartHeap(heap);
    printf("\n you remove thit num: %d\n", TheDeleteNum);
    eErr = BinHeapDelete(heap, &TheDeleteNum2);
    printf("\nheap after Remove:\n");
    PrintfBinartHeap(heap);
    printf("\n you remove thit num: %d\n", TheDeleteNum2);
    /*BinDestroy(heap);*/
    /*int max=0;

    eErr = BinHeapMax(heap, &max);

   printf("\nthe max is: %d\n", max);

   
   eErr = BinHeapInsert(heap, 20);


    PrintfBinartHeap(heap);
    printf("\n heap after delete: \n");

    int TheDeleteNum;
   BinHeapDelete(heap,&TheDeleteNum);

   printf("\n you remove thit num: %d\n",TheDeleteNum);

    PrintfBinartHeap(heap);*/

    //printf(" \nthis is heap Order? %d\n", IsHeap(vec));

  

    

    HandleErr(eErr, "\n empty vec");
    eErr = BinHeapDelete(heap, &TheDeleteNum3);
    HandleErr(eErr, "\n empty vec");

    PrintfBinartHeap(heap);

  

}
