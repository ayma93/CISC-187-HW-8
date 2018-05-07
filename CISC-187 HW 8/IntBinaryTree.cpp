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
	int leafCounter = 0;

	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << "Tree element " << leafCounter << " is " << nodePtr->value << endl;
		leafCounter++;
		displayInOrder(nodePtr->right);
	}
	else {
		cout << "Tree is empty." << endl;
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

//returns leaf count
int IntBinaryTree::leafCount(TreeNode* nodePtr)
{
	int leafCount = 0;
	nodePtr = root;

	if (!nodePtr) {
		cout << "Tree is empty." << endl;
		return leafCount;
	}

	while (nodePtr) {
		if (nodePtr->left) {
			nodePtr = nodePtr->left;
		}
		else if (nodePtr->right) {
			nodePtr = nodePtr->right;
		}
		leafCount++;
	}
	return leafCount;
}

//returns height of tree (number of levels)
int IntBinaryTree::treeHeight(TreeNode* nodePtr)
{
	int tHeightLeft = 0;
	int tHeightRight = 0;
	int tHeight = 0;
	nodePtr = root;

	if (!nodePtr) {
		cout << "Tree is empty." << endl;
		return 0;
	}

	while (nodePtr) {
		// Go as far down the left as possible
		if (nodePtr->left) {
			nodePtr = nodePtr->left;
			tHeightLeft++;
		}
		// Reset nodePtr to root for right hand side
		nodePtr = root;

		if (nodePtr->right) {
			nodePtr = nodePtr->right;
			tHeightRight++;
		}
		// Compare right height and left height
		if (tHeightLeft >= tHeightRight) {
			tHeight = tHeightLeft;
			// return tHeightLeft;
		}
		else {
			tHeight = tHeightRight;
			//return tHeightRight;
		}
	}
	return tHeight;
}

//returns width of tree (largest number of nodes in same level)
int IntBinaryTree::treeWidth(TreeNode* nodePtr)
{
	int tWidth = 0;
	nodePtr = root;

	if (!nodePtr) {
		cout << "Tree is empty." << endl;
		return 0;
	}

	while (nodePtr) {
		// Go as far left as possible
		if (nodePtr->left) {
			nodePtr = nodePtr->left;
		}



	}
}

