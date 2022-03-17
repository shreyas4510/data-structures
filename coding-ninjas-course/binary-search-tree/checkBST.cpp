#include<iostream>
#include "binarySearchTree.h"
using namespace std;

bool checkBST( TreeNode<int> *root ) {
	if (!root) 
		return true;
	
	if ( root -> leftNode && root -> data < root -> leftNode -> data )
		return false;

	if ( root -> rightNode && root -> data > root -> rightNode -> data )
		return false;

	bool flag = true;
	if (root -> leftNode && flag)
		flag = checkBST(root -> leftNode);
	if (root -> rightNode && flag)
		flag = checkBST(root -> rightNode);

	return flag;
}

int main() {
	operations<int> op;
	TreeNode<int> *root = op.takeInput();
	bool ans = checkBST(root);
	cout << endl;
	cout << ( ans ? "true" : "false" );
}