#include <iostream>
#include "binaryTree.h"
using namespace std;

int findPathToNode( binaryTreeNode<int> *root, int target ) {
	if( !root )
		return 0;

	if ( root -> data == target ) {
		cout << root -> data << " ";
		return 1;
	}

	int leftNode = findPathToNode( root -> leftNode, target );
	if (leftNode) {
		cout << root -> data << " ";
		return 1;
	}

	int rightNode = findPathToNode( root -> rightNode, target );
	if (rightNode) {
		cout << root -> data << " ";
		return 1;
	}
	return 0;
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();

	int target;
	cin >> target;
	findPathToNode( root, target );
	cout << endl;
	delete root;
	return 0;
}