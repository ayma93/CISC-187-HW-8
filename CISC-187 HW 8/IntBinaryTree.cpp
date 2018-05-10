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

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
	if (num < nodePtr->value) {
		deleteNode(num, nodePtr->left);
	}
	else if (num > nodePtr->value) {
		deleteNode(num, nodePtr->right);
	}
	else {
		makeDeletion(nodePtr);
	}
}

void IntBinaryTree::makeDeletion(TreeNode *& nodePtr)
{
	// Temporary pointer to reattach left subtree
	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr) {
		cout << "Cannot delete empty node." << endl;
	}
	else if (nodePtr->right == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; // Reattach left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	// If node has two children
	else {
		// Move one node to right
		tempNodePtr = nodePtr->right;
		// Go to end left node
		while (tempNodePtr->left) {
			tempNodePtr = tempNodePtr->left;
		}
		//Reattach Left Subtree
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach right subtree
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

void IntBinaryTree::remove(int num)
{
	deleteNode(num, root);
}

// Recursively delete all nodes in given subtree
void IntBinaryTree::destroySubTree(TreeNode* nodePtr)
{
	if (nodePtr) {
		if (nodePtr->left) {
			destroySubTree(nodePtr->left);
		}
		if (nodePtr->right) {
			destroySubTree(nodePtr->right);
		}
		delete nodePtr;
	}
}

void IntBinaryTree::displayInOrder(TreeNode* nodePtr) const
{
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << "Tree element is " << nodePtr->value << endl;
		//leafCounter++;
		displayInOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayInOrder() const
{
	displayInOrder(root);
}

bool IntBinaryTree::searchNode(int num)
{
	TreeNode* nodePtr = root;

	if (!nodePtr) {
		cout << "Tree is empty." << endl;
		return false;
	}
	while (nodePtr) {
		if (nodePtr->value == num) {
			return true;
		}
		else if (num < nodePtr->value) {
			nodePtr = nodePtr->left;
		}
		else {
			nodePtr = nodePtr->right;
		}
	}
	return false;
}

// Private function for returning leaf count
// If Node is NULL, return 0
// else recursively calculate leaf node;
// leaf count = left subtree count + right subtree count
// return 1 if leaf node (left and right are null) found
int IntBinaryTree::leafCount(TreeNode* nodePtr)
{
	if (!nodePtr) {
		return 0;
	}
	if (nodePtr->left == NULL && nodePtr->right == NULL) {
		return 1;
	}
	else {
		return leafCount(nodePtr->left) + leafCount(nodePtr->right);
	}
}

// Getter for private method leafCount
int IntBinaryTree::leafCount()
{
	return leafCount(root);
}

//returns height of tree (number of levels)
int IntBinaryTree::treeHeight(TreeNode* nodePtr)
{
	int tHeightLeft;
	int tHeightRight;

	if (!nodePtr) {
		return 0;
	}

	tHeightLeft = treeHeight(nodePtr->left);
	tHeightRight = treeHeight(nodePtr->right);
	if (tHeightLeft > tHeightRight) {
		return tHeightLeft + 1;
	}
	else {
		return tHeightRight + 1;
	}
}

// Getter for private treeHeight method
int IntBinaryTree::treeHeight()
{
	return treeHeight(root);
}


//returns width of tree (largest number of nodes in same level)
int IntBinaryTree::treeWidth(TreeNode* nodePtr)
{
	
	if (!nodePtr) {
		return 0;
	}


	cout << nodePtr->value << endl;
	treeWidth(nodePtr->left);
	treeWidth(nodePtr->right);

}

// Getter for private treeWidth method
int IntBinaryTree::treeWidth()
{
	return treeWidth(root);
}