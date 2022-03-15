#include <iostream>
#include "binaryTree.h"
using namespace std;

bool ans = true;
int checkIfBalanced( binaryTreeNode<int> *root ) {
	if( !root )
		return 0;

	int height = 1;

	int leftHeight = height + checkIfBalanced( root -> leftNode );
	int rightHeight = height + checkIfBalanced( root -> rightNode );

	if (leftHeight > rightHeight)
		height = leftHeight;
	else 
		height = rightHeight;

	if ( abs(leftHeight - rightHeight) > 1 && ans == true)
		ans = false;

	return height;
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	checkIfBalanced(root);
	cout << (ans ? "true" : "false");
}