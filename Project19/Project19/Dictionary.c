#include "Dictionary.h"
#include <string.h>

// add a new node to the BST with the new_data values, space must be allocated in the BST node
void insert(char *new_data, BSTObj **pBST)
{

	BSTObj *temp = *pBST;
	// This will check if the passed node is NULL
	if (temp == NULL)
	{
		// This will craete a new node
		*pBST = malloc(sizeof(BSTObj));
		// This statement will set the term of node
		(*pBST)->term = new_data;
		// This statement will set left to NULL
		(*pBST)->leftChild = NULL;
		// This statement will set right to NULL
		(*pBST)->rightChild = NULL;
	}
	// This will check if the data is less than current node
	else if (strcmp(new_data, (*pBST)->term) < 0)
		// This will insert node at left of current node by making a recursive call
		insert(new_data, &(*pBST)->leftChild);

	// This will check if the data is greater than current node
	else if (strcmp(new_data, (*pBST)->term) > 0)
		// This will insert node at right of current node by making a recursive call
		insert(new_data, &(*pBST)->rightChild);
}

// print to OUT the inorder traversal
void inorderTraverse(FILE *out, BSTObj *T)
{
	// This will check if the current node has some value
	if (T != NULL)
	{
		inorderTraverse(out, T->leftChild);
		fprintf(out, "%s ", T->term);
		inorderTraverse(out, T->rightChild);
	}
}

// print to OUT the preorder traversal
void preorderTraverse(FILE *out, BSTObj *T)
{
	// This will check if the current node has some value
	if (T != NULL)
	{
		// print the data
		fprintf(out, "%s ", T->term);
		// left and right recursive calls
		preorderTraverse(out, T->leftChild);
		preorderTraverse(out, T->rightChild);
	}
}

// print to OUT the postorder traversal
void postorderTraverse(FILE *out, BSTObj *T)
{
	// This will check if the current node has some value
	if (T != NULL)
	{
		// left and right recursive calls
		postorderTraverse(out, T->leftChild);
		postorderTraverse(out, T->rightChild);
		// display the data
		fprintf(out, "%s ", T->term);
	}
}

// print the leaves of the tree in inorder to OUT
void inorderLeaves(FILE *out, BSTObj *T)
{

	// This will check if the current node has some value
	if (T != NULL)
	{
		// left recursive call
		inorderLeaves(out, T->leftChild);
		// check if the current node is a leaf node
		if (T->rightChild == NULL && T->leftChild == NULL)
		{
			fprintf(out, "%s", T->term);
		}
		// right recursive call
		inorderLeaves(out, T->rightChild);
	}
}


// return TRUE if the item_to_find matches a string stored in the tree
int  find(char *term_to_find, BSTObj *T)
{
	// check if the current element approached NULL
	if (T == NULL)
		return 0;
	// If the term_to_find is found
	else if (strcmp(term_to_find, T->term) == 0)
		return 1;
	// If the term_to_find is less than current node
	else if (strcmp(term_to_find, T->term) < 0)
		return find(term_to_find, T->leftChild);
	// If the term_to_find is greater than current node
	else
		return find(term_to_find, T->rightChild);

}
// return the maximum of 2 numbers passed as parameter
int maxNum(int a, int b)
{
	// check if a is greater than b then return a
	if (a > b)
		return a;
	// otherwise return b
	else
		return b;
}

// compute the height of the tree
int treeHeight(BSTObj *T, int height)
{

	// This will check if the current node has some value
	if (T == NULL)
	{
		return 0;
	}
	else
		return 1 + maxNum(treeHeight(T->leftChild, height), treeHeight(T->rightChild, height));
}


// 
void printGivenLevel(struct BSTObj* root, int level, BSTObj** newTree)
{

	// This will check if the current node has some value
	if (root == NULL)
		return;
	if (level == 1)
		insert(strdup(root->term), newTree);
	else if (level > 1)
	{
		printGivenLevel(root->leftChild, level - 1, newTree);
		printGivenLevel(root->rightChild, level - 1, newTree);
	}
}

// create and return a complete memory independent copy of the tree 
BSTObj * copyTree(BSTObj *T)
{
	int h = treeHeight(T, 0);
	int i;
	BSTObj**root = NULL;
	*root = NULL;
	for (i = 1; i <= h; i++)
		printGivenLevel(T, i, root);
}

// remove all the nodes from the tree, deallocate space and reset Tree pointer
void makeEmpty(BSTObj **pT)
{
	if ((*pT) != NULL) {

		if (((*pT)->leftChild == NULL) && ((*pT)->rightChild == NULL)) {
			free(*pT);
			(*pT) = NULL;
		}
		else {
			makeEmpty((*pT)->leftChild);
			makeEmpty((*pT)->rightChild);
		}

	}
	return;
}
