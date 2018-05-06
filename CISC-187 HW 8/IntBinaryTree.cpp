#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

void IntBinaryTree::insertNode(int num)
{
	TreeNode* newNode = nullptr;

	// Create new node and store num
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	//Insert Node 
	insert(root, newNode);
}

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr) {
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value) {
		insert(nodePtr->left, newNode);
	}
	else {
		insert(nodePtr->right, newNode);
	}
}