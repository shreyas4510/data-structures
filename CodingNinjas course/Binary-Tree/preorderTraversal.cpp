#include <iostream>
#include "binaryTree.h"
using namespace std;

printPreOrderTraversal( binaryTreeNode<int> *root ) {
	if (!root)
		return 0;

	cout << root -> data << " ";
	printPreOrderTraversal( root -> leftNode );
	printPreOrderTraversal( root -> rightNode );
}

int main() {
	operations<int> op;
	binaryTreeNode<int>* root = op.takeInput();
	printPreOrderTraversal(root);
	delete root;
}