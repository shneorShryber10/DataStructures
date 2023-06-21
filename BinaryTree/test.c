#include <stdio.h>
#include "ADTDefs.h"
#include "BinaryTree.h"


int main()
{
	binaryTree_t* bintree1;
	binaryTree_t* bintree2;
	ADTErr eErr;


    bintree1 = BinTreeCreate();
    bintree2 = BinTreeCreate();

  
    BinTreeInsert(bintree1, 15);
    BinTreeInsert(bintree1, 10);
    BinTreeInsert(bintree1, 20);
    BinTreeInsert(bintree1, 8);
    BinTreeInsert(bintree1, 12);
    BinTreeInsert(bintree1, 6);
    BinTreeInsert(bintree1, 9);
    BinTreeInsert(bintree1, 11);
    BinTreeInsert(bintree1, 13);
    BinTreeInsert(bintree1, 18);
    BinTreeInsert(bintree1, 25);
    BinTreeInsert(bintree1, 16);
    BinTreeInsert(bintree1, 19);
    BinTreeInsert(bintree1, 23);
    BinTreeInsert(bintree1, 28);
 
    PrintTree(bintree1, INORDER);
    printf("\n");
    PrintTree(bintree1, PREORDER);
    printf("\n");
    PrintTree(bintree1, POSTORDER);
    printf("\n");

    printf("%d", SumOfLeftLifeAtBinarreTree(bintree1));
  
    BinTreeInsert(bintree2, 10);
    BinTreeInsert(bintree2, 6);
    BinTreeInsert(bintree2, 17);
    BinTreeInsert(bintree2, 15);
    BinTreeInsert(bintree2, 14);
    BinTreeInsert(bintree2, 4);
    BinTreeInsert(bintree2, 7);
    BinTreeInsert(bintree2, 20);


    //BinTreeInsert(bintree, 7);
    //BinTreeInsert(bintree, 11);
    //BinTreeInsert(bintree, 19);
    //BinTreeInsert(bintree, 20);
    //BinTreeInsert(bintree, 17);
    //BinTreeInsert(bintree, 18);
    //BinTreeInsert(bintree, 14);
    //BinTreeInsert(bintree, 16);
    //BinTreeInsert(bintree, 15);
   

   

	////PrintTree(bintree,PREORDER);

   /*printf("\n%d", BinTreeDataIsFound(bintree, 196));*/

    /*printf("\n\n");*/
    //PrintfTheLeaf(bintree);


   /* printf("%d ", PrintMax(bintree));*/

   /* printf("%d ,", TheLevel(bintree));*/
    /*printf("\nthe sum of oll nodews is %d: ,\n", SumOfNodes(bintree));

    printf("\n the sum of left leaf is: %d ,\n", SumOfLeftLifeAtBinarreTree(bintree));
    printf("\n the sum of right leaf is: %d ,\n", SumOfRightLifeAtBinarreTree(bintree));
*/



 //   DeleteNodeFromBinarrTree(bintree, 12);
 //   PrintTree(bintree, PREORDER);
 //   PrintMax(bintree);

 //   DeleteNodeFromBinarrTree(bintree, 20);
	//PrintTree(bintree,PREORDER);
 //   PrintMax(bintree);

    /*printf("this is sumullar: %d", AreSimelarTree(bintree, bintree2));*/

   /* PrintTree(bintree, PREORDER);
    printf("\n");
    PrintfTheLeaf(bintree);
    printf("\n");
   PrintMax(bintree);

   DeleteNodeFromBinarrTree(bintree, 3);
   printf("bin tree after remove :\n ");
   PrintTree(bintree, PREORDER);
   printf("\n");
   PrintfTheLeaf(bintree);
   printf("\n");
   PrintMax(bintree);

   printf("this is full Tree: %d", IsFullTree(bintree));

   printf("\n");
   printf("this leaf is:");
  PrintfTheLeaf(bintree);*/



    /*int IsPerfect=0, TreeHeight=0;*/
  /*  printf("this is full Tree: %d", IsFullTree(bintree));*/
  //printf("\n%d\n",BinTreeDataIsFound(NULL, 15));

  /*  ChackTree(bintree,&IsPerfect,&TreeHeight);

    printf(" is perfect?-> %d \n", IsPerfect);

    printf("haight = %d \n", TreeHeight);*/


   /*DestroidBinaryTree(bintree);*/

}
