#include <iostream>
#include "binaryTree.h"
using namespace std;

int getSumOfNodes( binaryTreeNode<int> *root ) {
	if (!root)
		return 0;
	return root -> data + getSumOfNodes( root -> leftNode ) + getSumOfNodes( root -> rightNode );
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	cout << getSumOfNodes(root);
}