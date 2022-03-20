#include <iostream>
#include <climits>
#include "binarySearchTree.h"
using namespace std;

bool checkBST( TreeNode<int> *root, int start, int end ) {
	if( !root )
		return true;

	if( root -> data < start || root -> data > end )
		return false;

	bool flag = true;
	if (root -> leftNode && flag)
		flag = checkBST( root -> leftNode, start, root -> data);

	if (root -> rightNode && flag)
		flag = checkBST( root -> rightNode, root -> data, end);

	return flag;
}


int main() {
	operations<int> op;
	TreeNode<int> *root = op.takeInput();
	cout << ( checkBST( root, INT_MIN, INT_MAX ) ? "true" : "false" ) << endl;
	delete root;
}