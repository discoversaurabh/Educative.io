// BINARY TREE BOUNDRY TRAVERSAL (PERIMETER)

#if 1
#include "AllHeader.h"

struct node {
	int val;
	struct node *left, *right;
};

// Iterative Way
//void printLeftSide(node *root)
//{
//	node *crawl = root, *prev;
//	while (crawl)
//	{
//		while (crawl)
//		{
//			cout << crawl->val << " ";
//			prev = crawl;
//			crawl = crawl->left;
//		}
//		crawl = prev->right;
//	}
//}

Node *_root;

void printLeftSide(node *root)
{
	if (!root) return;

	if (root->left)
	{
		cout << root->val << " ";
		printLeftSide(root->left);
	}
	else if(root->right)
	{
		cout << root->val << " ";
		printLeftSide(root->right);
	}
		
	//do nothing in case of leaf node to avoid duplicates in result
}

void printLeafNodes(node *root)
{
	if (!root) return;
	
	if (!root->left && !root->right && root != _root)
	{
		cout << root->val << " ";
	}

	if (root->left)
		printLeafNodes(root->left);
	if(root->right)
		printLeafNodes(root->right);
}

void printRightSide(node *root)
{
	if (!root) return;

	if (root->right)
	{
		cout << root->val << " ";
		printRightSide(root->right);
	}
	else if (root->left)
	{
		cout << root->val << " ";
		printLeftSide(root->left);
	}
}

void printBoundary(node *root)
{
	if (!root)
	{
		cout << "";
		return;
	}

	_root = root;
	cout << root->val << " ";

	//left view
	printLeftSide(root->left);

	//leaf nodes
	printLeafNodes(root);

	//right view
	printRightSide(root->right);
}

struct node* newNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->val = data;
	temp->left = temp->right = NULL;

	return temp;
}

int main()
{
	struct node* root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);

	printBoundary(root);

	return 0;
}
#endif
