#include <iostream>
#include <conio.h>
using namespace std;
struct node{
	int data;
	node *ryt, *left;
	bool insert = false;
};

class tree
{
	node *root;
	bool indicator = true;
	node *newnode;
public:

	tree()
	{
		root = NULL;
		newnode = NULL;
	}


	bool search(int x)
	{
		bool found = true;
		newnode = new node;
		newnode->data = x;
		newnode->left = NULL;
		newnode->ryt = NULL;

		if (root == NULL)
		{
			return false;
		}
		else
		{
			while (found == true)
			{
				if (root->left != NULL && x < root->data)
				{
					root = root->left;
				}

				else if (root->ryt != NULL && x > root->data)
				{
					root = root->ryt;
				}

				else
				{
					return true;
				}
			}
		}
		return false;
	}
	void insert(int x)
	{
		bool found = true;
		newnode = new node;
		newnode->data = x;
		newnode->left = NULL;
		newnode->ryt = NULL;

		if (root == NULL)
		{
			root = root = newnode;
		}
		else
		{
			while (found == true)
			{
				if (root->left != NULL && x < root->data)
				{
					root = root->left;
				}

				else if (root->ryt != NULL && x > root->data)
				{
					root = root->ryt;
				}

				else
				{
					found = false;
				}
			}
		}

		if (x < root->data)
		{
			root->left = newnode;
		}

		else if (x > root->data)
		{
			root->ryt = newnode;
		}
	}



	void deleteSmall()
	{
		node *temp;
		temp = NULL;
		while (root->left->left != NULL)
		{
			root = root->left;
		}

		if (root->left->ryt != NULL)
		{
			temp = root->left;
			root->left = temp->ryt;
			delete temp;
			temp = NULL;
		}
		else
		{
			temp = root->left;
			root->left = NULL;
			delete temp;
			temp = NULL;
		}
	}
};