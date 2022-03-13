#include <iostream>
#include "binaryTree.h"
using namespace std;

printInorderTraversal( binaryTreeNode<int> *root ) {

	if (!root)
		return 0;

	printInorderTraversal( root -> leftNode );
	cout << root -> data << " ";
	printInorderTraversal( root -> rightNode );

}

int main() {
	operations<int> op;
	binaryTreeNode<int>* root = op.takeInput();
	printInorderTraversal(root);
	delete root;
}