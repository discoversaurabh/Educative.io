//BINARY TREE TO CIRCULAR DOUBLY LINKED LIST
#include"AllHeader.h"

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};


class Solution {
public:
	Node *first = NULL, *last = NULL;

	void treeToDoublyListUtil(Node* root)
	{
		if (!root)
			return;

		treeToDoublyListUtil(root->left);

		if (!last)	//first node
			first = root;
		else
		{
			//link subsequent nodes
			root->left = last;
			last->right = root;
		}
		
		//update last node
		last = root;

		treeToDoublyListUtil(root->right);
	}

	Node* treeToDoublyList(Node* root) {
		treeToDoublyListUtil(root);
		first->left = last;
		last->right = first;
		return first;
	}
};
