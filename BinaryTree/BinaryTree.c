#include <malloc.h>
#include <stdio.h>
#include <assert.h>

#include "ADTDefs.h"
#include "BinaryTree.h"

typedef struct Node node_t;

void PrintNodeInOrder(node_t* node);
void PrintNodePreOrder(node_t* node);
void PrintNodeOrderPost(node_t* node);


struct Node
{
	int data;

	node_t* father;
	node_t* left;
	node_t* right;
};
struct BinaryTree
{
	node_t* root;
};


binaryTree_t* BinTreeCreate()
{

	binaryTree_t* bin = (binaryTree_t*)calloc(1, sizeof(binaryTree_t));

	if (!bin)
	{
		printf("not initialize !");
	}
	return bin;
}
node_t* FundTheFather(binaryTree_t* bintree, int data,enum SearchMode Mode)
{
	node_t* dad = NULL;
	node_t* orgRoot = bintree->root;

	while (bintree->root)
	{
		dad = bintree->root;
		if (Mode && bintree->root->data == data) 
		{
			bintree->root = orgRoot;
			return dad;
		}

		if (bintree->root->data < data)
		{
			bintree->root = bintree->root->right;
		}
		else
		{
			bintree->root = bintree->root->left;
		}
	}
	if (Mode)
	{
		return NULL;
	}
	bintree->root = orgRoot;

	return dad;
}
int BinTreeDataIsFound(binaryTree_t* bintree, int data)
{	
	assert(bintree);

		node_t* res= FundTheFather(bintree, data, NODE);

		if (res)
		{
			return 1;
		}
		return 0;
	
}
ADTErr BinTreeInsert(binaryTree_t* bintree, int data)
{
	assert(bintree);

	node_t* node = (node_t*)calloc(1, sizeof(node_t));
	if (!node)
	{
		return ERR_ALLOCATION_FAILED;
	}

	if (!bintree->root)
	{
		node->data = data;
		bintree->root = node;

		return  ERR_OK;
	}

	node_t* Father = FundTheFather(bintree, data, LEAF);
	if (!Father)
	{
		free(node);
		return ERR_NOT_INITIALIZED;
	}


	node->data = data;
	node->father = Father;
	
	if (Father->data > data)
	{
		Father->left = node;
	}
	else
	{	
		Father->right = node;
	}

	return ERR_OK;
}
void PrintNodeInOrder(node_t* node)
{

	if (!node)
	{
		return;
	}

	PrintNodeInOrder(node->left);

	printf("%d, ", node->data);

	PrintNodeInOrder(node->right);
	

}
void PrintNodePreOrder(node_t* node)
{
	if (!node)
	{
		return;
	}
	printf("%d,", node->data);

	PrintNodePreOrder(node->left);

	PrintNodePreOrder(node->right);
	
	
}
void PrintNodeOrderPost(node_t* node)
{

	if (!node)
	{
		return;
	}

	PrintNodeOrderPost(node->left);

	PrintNodeOrderPost(node->right);

	printf("%d, ", node->data);
}
void PrintTree(binaryTree_t* bintree,enum Print Mood)
{
	if(Mood == INORDER)
	PrintNodeInOrder(bintree->root);

	else if (Mood == PREORDER)
		PrintNodePreOrder(bintree->root);

	else if (Mood == POSTORDER)
		PrintNodeOrderPost(bintree->root);

	
}

void DestroyTheTree(binaryTree_t* bintree)
{
	free(bintree); 
}
void DestroyTheTreeNodes(node_t* node)
{ 

	if (!node)
	{
		return;
	}

	DestroyTheTreeNodes(node->left);

	DestroyTheTreeNodes(node->right);
		
	free(node);

}

void DestroidBinaryTree(binaryTree_t* bintree)
{
	assert(bintree);

	DestroyTheTreeNodes(bintree->root);

	DestroyTheTree(bintree);
}


void PrintfTheLeafByNode(node_t* node)
{

	if (node == NULL)
	{
		return;
	}
	
	if (node->left == NULL && node->right==NULL)
	{
		printf("%d ,",node->data);
		return;
	}
	PrintfTheLeafByNode(node->right);

	PrintfTheLeafByNode(node->left);
	
}

void PrintfTheLeaf(binaryTree_t* bintree)
{
	PrintfTheLeafByNode(bintree->root);
}

void PrintMaxByNode(node_t* node)
{
	if (!node->right)
	{
		printf("\n\nthe max num is: %d \n\n ", node->data);
		return;
	}

	PrintMaxByNode(node->right);

}
void PrintMax(binaryTree_t* bintree)
{
	 PrintMaxByNode(bintree->root);
}

int TheSumOfNodes(node_t* node)
{
	if (!node)
	{
		return 0;
	}
	return node->data + TheSumOfNodes(node->left) + TheSumOfNodes(node->right);


}
int SumOfNodes(binaryTree_t* bintree)
{
	return TheSumOfNodes(bintree->root);
}
node_t* Successor(node_t* node)
{
	node_t* temp = node;
	
	while (temp->left)
		temp = temp->left;

	return temp->data;
}
node_t* PreDecessor(node_t* node,int value)
{
	node_t* temp = node;
	while (temp)
	{
		if (temp->left && temp->left->data == value)
		{
			return temp;
		}
		if (temp->right && temp->right->data == value)
		{
			return temp;
		}
		if (temp->data > value)
		{
			temp = temp->left;
		}
		else if (temp->data < value)
		{
			temp = temp->right;
		}
		/*else if (temp->data == value)
		{

		}*/

	}
}
void DeleteNode(node_t* node, int valiue)
{

	node_t* temp;
	 temp = node;
	 node_t* temp2;
	 temp2 = node;
	 
	 int successor;

	 while (temp)
	 {
		 if (temp->data == valiue)
		 {
			 if (temp->left && temp->right)
			 {

				 successor = Successor(temp->right);
				 temp->data = successor;
				 if (!temp->right->right && !temp->right->left)
				 {
					 temp->right = NULL; 
				 }
				 else
				 {
				 DeleteNode(temp->right, successor);
				 }
			 }
			 else if (temp->right)
			 {
				 node_t* preDecessor = PreDecessor(temp2, valiue);
				 if (preDecessor->left->data == valiue)
					 preDecessor->left = temp->right;
				 else
					 preDecessor->right = temp->right;
			 }
			 else if (temp->left)
			 {
				 node_t* preDecessor = PreDecessor(temp2, valiue);
				 if (preDecessor->left->data == valiue)
					 preDecessor->left = temp->left;
				 else
					 preDecessor->right = temp->left;
			 }
			 else
			 {

				 node_t* preDecessor = PreDecessor(temp2, valiue);
				
				  if (preDecessor->left && preDecessor->left->data == valiue)
					 preDecessor->left = NULL;
				 else if (preDecessor->right && preDecessor->right->data == valiue)
					 preDecessor->right = NULL;
			 }
			 break;
		 }
		 if (valiue > temp->data)
		 {
			 temp = temp->right;
		 }
		 else
		 {
			 temp = temp->left;
		 }
	 }
}
void DeleteNodeFromBinarrTree(binaryTree_t* bintree, int valiue)
{
	assert(bintree);
	DeleteNode(bintree->root,valiue);
}
int SumOfLeftLifeAtBinarreTreeNode(node_t* node,int flag, int* sum)
{
	if (!node)
	{
		return 0;
	}

	if (!node->right && !node->left && flag)
	{
		*sum += node->data;

	}
	SumOfLeftLifeAtBinarreTreeNode(node->left, 1, sum);
	SumOfLeftLifeAtBinarreTreeNode(node->right, 0, sum);

	
}
int SumOfLeftLifeAtBinarreTree(binaryTree_t* bintree)
{
	int sum = 0,flag = 1;

	 SumOfLeftLifeAtBinarreTreeNode(bintree->root,flag,&sum);

	 return sum;

	
}
int SumOfRightLifeAtBinarreTreeNode(node_t* node, int flag, int* sum)
{
	if (!node)
	{
		return 0;
	}

	if (!node->right && !node->left && flag)
	{
		*sum += node->data;

	}
	SumOfRightLifeAtBinarreTreeNode(node->left, 0, sum);
	SumOfRightLifeAtBinarreTreeNode(node->right, 1, sum);
													
}
int SumOfRightLifeAtBinarreTree(binaryTree_t* bintree)
{
	int sum = 0, flag = 1;

	SumOfRightLifeAtBinarreTreeNode(bintree->root, flag, &sum);

	return sum;


}
int AreSimelarTreeImpRec(node_t* node1, node_t* node2)
{

	if (!node1 && !node2)
	{
		return 1;
	}
	else if (!node1  || !node2)
	{
		return 0;
	}

	return AreSimelarTreeImpRec(node1->left, node2->left) && AreSimelarTreeImpRec(node1->right, node2->right) ;
	 
}
int AreSimelarTree(binaryTree_t* bintree1, binaryTree_t* bintree2)
{
	return AreSimelarTreeImpRec(bintree1->root, bintree2->root);
}
int IsFullTreeImp(node_t* node)
{
	if (!node->left && !node->right)
	{
		return 1;
	}
	if (!node->left || !node->right)
	{
		return 0;
	}

	return IsFullTreeImp(node->left) && IsFullTreeImp(node->right);
}
int IsFullTree(binaryTree_t* bintree)
{
	assert(bintree);
	if (!bintree->root)
	{
		return 1;
	}
	return IsFullTreeImp(bintree->root);
}
int levelByNode(node_t* node)
{

	if (!node)
	{
		return -1;
	}


	int left = levelByNode(node->left);

	int right = levelByNode(node->right);

	if (right < left)
	{
		return left + 1;
	}

	return right + 1;

}
int TheLevel(binaryTree_t* bintree)
{
	levelByNode(bintree->root);
}
void ChackTreeImp(node_t* node, int* IsPerfect, int* Treeheight)
{
	int LeftHaight = 0, RightHight = 0, IsRightPerfect = 0, IsLeftPerfect = 0;

		if (!node)
		{
			*IsPerfect = 1;
			*Treeheight = -1;
			return;
		}

	ChackTreeImp(node->left, &IsLeftPerfect, &LeftHaight);
	ChackTreeImp(node->right, &IsRightPerfect, &RightHight);

	*IsPerfect = (IsRightPerfect && IsLeftPerfect && LeftHaight == RightHight);
	*Treeheight = (LeftHaight > RightHight) ? LeftHaight : RightHight;
	++(*Treeheight) ;

}
void ChackTree(binaryTree_t* bintree, int* IsPerfect, int* Treeheight)
{
	assert(bintree);
	ChackTreeImp(bintree->root, IsPerfect, Treeheight);

}