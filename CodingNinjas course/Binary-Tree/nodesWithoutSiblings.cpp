#include <iostream>
#include "binaryTree.h"
using namespace std;

printNodesWithoutSiblings( binaryTreeNode<int> *root ) {
	if (!root)
		return 0;

	if ( root -> leftNode != NULL && root -> rightNode == NULL )
		cout << root -> leftNode -> data << " ";

	if ( root -> rightNode != NULL && root -> leftNode == NULL )
		cout << root -> rightNode -> data << " ";

	printNodesWithoutSiblings( root -> leftNode );
	printNodesWithoutSiblings( root -> rightNode );
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	printNodesWithoutSiblings(root);
}