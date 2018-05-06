#include <iostream>
using namespace std;

#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree
{
private:
	struct TreeNode
	{
		int value;       // Node value
		TreeNode* left;  // Pointer to left child node
		TreeNode* right; // Pointer to right child node
	};
	TreeNode* root; // Pointer to Root Node

	// Private Member functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode*);
	void deleteNode(int, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode*) const;

public:
	// Constructor
	IntBinaryTree()
	{
		root = nullptr;
	}

	// Destructor
	IntBinaryTree()
	{
		destroySubTree(root);
	}

	// Binary  Tree Operations
	void insertNode(int);
	bool searchNode(int);
	void remove(int);
	void displayInOrder() const
	{
		displayInOrder(root);
	}
};

#endif // !INTBINARYTREE_H

