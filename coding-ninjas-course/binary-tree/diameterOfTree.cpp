#include <iostream>
#include "binaryTree.h"
using namespace std;

int diameter = 0;

int heightOfTree( binaryTreeNode<int> *root ) {
	if (!root)
		return 0;

	int count = 1;
	int leftHeight = heightOfTree( root -> leftNode );
	int rightHeight = heightOfTree( root -> rightNode );

	if (leftHeight > rightHeight)
		count += leftHeight;
	else
		count += rightHeight;

	if ( (leftHeight + rightHeight) > diameter ) {
		diameter = (leftHeight + rightHeight);
	}

	return count;
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	// op.printLeveWise(root);
	heightOfTree( root );
	cout << diameter << endl;
	return 0;
}