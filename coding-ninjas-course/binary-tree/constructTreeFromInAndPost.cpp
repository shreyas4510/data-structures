#include <iostream>
#include "binaryTree.h"
#include <vector>
using namespace std;

binaryTreeNode<int>* buildTree( vector<int> postOrder, vector<int> inOrder, int inStart, int inEnd, int *currentPointer ) {
	if (inEnd < inStart) 
		return NULL;

	(*currentPointer)--;
	binaryTreeNode<int> *root = new binaryTreeNode<int>(postOrder.at( *currentPointer ));
	if ( inStart == inEnd )
		return root;

	int i;
	for (i = inStart; i <= inEnd; i++) {
		if ( inOrder.at(i) == postOrder.at(*currentPointer) )
			break;
	}
	
	root -> rightNode = buildTree(  postOrder, inOrder, i+1, inEnd, currentPointer );
	root -> leftNode = buildTree(  postOrder, inOrder, inStart, i-1, currentPointer );
	return root;
}


int main() {
	vector<int> postOrder, inOrder;
	int size;
	cin >> size;

	for ( int i=0; i<size; i++ ) {
		int input;
		cin >> input;
		postOrder.push_back(input);
	}

	for ( int i=0; i<size; i++ ) {
		int input;
		cin >> input;
		inOrder.push_back(input);
	}

	int i = size;
	int *currentPointer = &i; 

	binaryTreeNode<int> *root = buildTree(postOrder, inOrder, 0, size-1, currentPointer);
	cout << endl;
	operations<int> op;
	op.printLeveWise(root);
}