#include <iostream>
#include<string>
#include "IntBinaryTree.h"

using namespace std;

int main()
{
	IntBinaryTree newTree;

	newTree.insertNode(5);
	newTree.insertNode(3);
	newTree.insertNode(7);
	newTree.insertNode(9);
	newTree.insertNode(11);

	cout << "Displaying list.... " << endl;
	newTree.displayInOrder();
	cout << endl;

	cout << "Checking leaf count.... " << endl;
	cout << "LeafCount is " << newTree.leafCount() << endl;

	cout << "Checking tree height...." << endl;
	cout << "Tree height is " << newTree.treeHeight() << endl;

	// Introduces pause to be able to read output
	cin.ignore(256, '\n');
	cin.get();

	return 0;
}