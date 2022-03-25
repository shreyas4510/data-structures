#include <iostream>
#include "binaryTree.h"
using namespace std;

void createInsertDuplicateNode( binaryTreeNode<int> *root ) {

	if ( !root )
		return;

	binaryTreeNode<int> *leftTree = root -> leftNode;
	root -> leftNode = NULL;
	binaryTreeNode<int> *duplicate = new binaryTreeNode<int>(root -> data);
	duplicate -> leftNode = leftTree;
	root -> leftNode = duplicate;

	createInsertDuplicateNode( root -> leftNode -> leftNode );
	createInsertDuplicateNode( root -> rightNode );
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	createInsertDuplicateNode(root);
	op.printLeveWise( root );
	delete root;
}