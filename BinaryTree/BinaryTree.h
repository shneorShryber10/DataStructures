#ifndef __BINARYTREE2_H__
#define __BINARYTREE2_H__

typedef struct BinaryTree binaryTree_t;

enum Print
{
	INORDER
	, PREORDER
	, POSTORDER
};
enum SearchMode
{
	LEAF,
	NODE
};

binaryTree_t* BinTreeCreate();
ADTErr BinTreeInsert(binaryTree_t* root, int data);
void PrintTree(binaryTree_t* root, enum Print Mood);
int BinTreeDataIsFound(binaryTree_t* bintree, int data);
void DestroidBinaryTree(binaryTree_t* bintree);

void PrintfTheLeaf(binaryTree_t* bintree);
void PrintMax(binaryTree_t* bintree);
int SumOfNodes(binaryTree_t* bintree);
int SumOfLeftLifeAtBinarreTree(binaryTree_t* bintree);
int SumOfRightLifeAtBinarreTree(binaryTree_t* bintree);
void DeleteNodeFromBinarrTree(binaryTree_t* bintree, int valiue);
int AreSimelarTree(binaryTree_t* bintree1, binaryTree_t* bintree2);
int IsFullTree(binaryTree_t* bintree);
void ChackTree(binaryTree_t* bintree, int* IsPerfect, int* Treeheight);



#endif // __BINARYTREE2_H__
