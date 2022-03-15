#include <iostream>
#include "binaryTree.h"
using namespace std;

bool removeLeafNodes( binaryTreeNode<int> *root ) {
	if ( root -> leftNode == NULL && root -> rightNode == NULL )
		return false;
	
	if(root -> leftNode && !removeLeafNodes(root -> leftNode))
		root -> leftNode = NULL;

	if(root -> rightNode && !removeLeafNodes(root -> rightNode))
		root -> rightNode = NULL;

	return true;
}

int main(int argc, char const *argv[])
{
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	removeLeafNodes(root);
	op.printLeveWise(root);
	return 0;
}