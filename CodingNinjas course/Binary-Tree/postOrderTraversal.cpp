#include <iostream>
#include "binaryTree.h"
using namespace std;

printPostOrderTraversal( binaryTreeNode<int>* root ) {
	if (!root)
		return 0;

	printPostOrderTraversal(root -> leftNode);
	printPostOrderTraversal(root -> rightNode);
	cout << root -> data << " ";
}

int main() {
	operations<int> op;
	binaryTreeNode<int>* root = op.takeInput();
	printPostOrderTraversal(root);
	delete root;
}