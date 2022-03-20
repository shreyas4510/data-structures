#include<iostream>
#include "binarySearchTree.h"
#include<climits>
using namespace std;

int leftMaximum( TreeNode<int> *root ) {
	if ( !root )
		return INT_MIN;

	int leftData = leftMaximum( root -> leftNode );
	int rightData = leftMaximum( root -> rightNode );

	if ( leftData > rightData && leftData > root -> data ) 
		return leftData;

	else if ( rightData > leftData && rightData > root -> data )
		return rightData;

	return root -> data;
}

int rightMinimum( TreeNode<int> *root ) {
	if ( !root )
		return INT_MAX;

	int leftData = rightMinimum( root -> leftNode );
	int rightData = rightMinimum( root -> rightNode );

	if ( leftData < rightData && leftData < root -> data ) 
		return leftData;

	else if ( rightData < leftData && rightData < root -> data )
		return rightData;

	return root -> data;
}

bool checkBST( TreeNode<int> *root ) {
	if (!root) 
		return true;


	int leftMax = leftMaximum( root -> leftNode );
	if ( root -> leftNode && ( root -> data < root -> leftNode -> data || root -> data < leftMax ))
		return false;

	int rightMin = rightMinimum( root -> rightNode );
	if ( root -> rightNode && ( root -> data > root -> rightNode -> data || root -> data > rightMin ))
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
	cout << ( ans ? "true" : "false" ) << endl;
	return 0;	
}