#include <iostream>
#include <vector>
#include "binaryTree.h"
using namespace std;

// Incorrect Approach
// binaryTreeNode<int>* constructTree( vector<int> inOrder, vector<int> preOrder, int preStart, int preEnd, int inStart, int inEnd ) {
// 	binaryTreeNode<int>* root = new binaryTreeNode<int>(preOrder.at(preStart));
// 	if (preEnd <= preStart || inEnd <= inStart)
// 		return root;

// 	int tempPs = preStart+1;
// 	int index = 0;
// 	for (int i = inStart; i <= inEnd; ++i) {
// 		if (inOrder.at(i) == preOrder.at(preStart)) {
// 			if (index == 0)
// 				index = 1;
// 			break;
// 		}
// 		index++;
// 	}

// 	root -> leftNode = constructTree( inOrder, preOrder, tempPs, (tempPs + index - 1 ), inStart, inStart+index-1 );
// 	root -> rightNode = constructTree( inOrder, preOrder, (tempPs + index ), preEnd, inStart+index+1, inEnd );
// 	return root;
// } 


// Complexity n^2
binaryTreeNode<int>* constructTree( vector<int> inOrder, vector<int> preOrder, int inStart, int inEnd, int *preIndex ) {
	if ( inStart > inEnd )
		return NULL;

	binaryTreeNode<int> *root = new binaryTreeNode<int>(preOrder.at(*preIndex));
	if ( inStart == inEnd )
		return root;

	int i;
	for (i = inStart; i <= inEnd; i++) {
		if ( inOrder.at(i) == preOrder.at(*preIndex) ) 
			break;
	}
	(*preIndex)++;
	root -> leftNode = constructTree( inOrder, preOrder, inStart, i-1, preIndex );
	if (root -> leftNode)
		(*preIndex)++;
	root -> rightNode = constructTree( inOrder, preOrder, i+1, inEnd, preIndex );
	return root;
} 

int main() {
	int size;
	cin >> size;

	vector<int> preOrder, inOrder;
	for (int i = 0; i < size; ++i) {
		int input;
		cin >> input;
		preOrder.push_back(input);
	}

	for (int i = 0; i < size; ++i) {
		int input;
		cin >> input;
		inOrder.push_back(input);
	}

	int p = 0;
	int *preIndex = &p;

	binaryTreeNode<int>* root = constructTree( inOrder, preOrder, 0, size-1, preIndex );
	operations<int> op;
	op.printLeveWise(root);
}