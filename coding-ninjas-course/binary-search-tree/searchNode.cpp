#include <iostream>
#include "binarySearchTree.h"
using namespace std;

bool searchNode( TreeNode<int> *root, int target ) {
	if (!root)
		return false;
	
	if ( root -> data == target )
		return true;

	bool flag = false;
	if ( root -> leftNode && root -> data > target )
		flag = searchNode( root -> leftNode, target );

	if ( root -> rightNode && root -> data < target )
		flag = searchNode( root -> rightNode, target );

	return flag;
}

int main() {
	operations<int> op;
	TreeNode<int> *root = op.takeInput();

	int target;
	cin >> target;
	cout << ( searchNode(root, target) ? "true" : "false" );
}