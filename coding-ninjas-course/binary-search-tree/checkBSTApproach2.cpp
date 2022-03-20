#include <iostream>
#include <climits>
#include "binarySearchTree.h"
using namespace std;

class checkBSTReturn {
	public:
		bool isBST;
		int minimum;
		int maximum;
};

checkBSTReturn checkBST( TreeNode<int> *root ) {
	if (root == NULL) {
		checkBSTReturn object;
		object.isBST = true;
		object.minimum = INT_MAX;
		object.maximum = INT_MIN;
		return object;
	}

	checkBSTReturn leftObject = checkBST( root -> leftNode );
	checkBSTReturn rightObject = checkBST( root -> rightNode );

	checkBSTReturn finalObject;
	finalObject.isBST = leftObject.isBST && rightObject.isBST && ( leftObject.maximum < root -> data ) && ( rightObject.minimum > root -> data ) ;
	finalObject.minimum = ( root -> data < leftObject.minimum ) && ( root -> data < rightObject.minimum ) ? root -> data : 
						  ( leftObject.minimum < root -> data ) && ( leftObject.minimum < rightObject.minimum ) ? leftObject.minimum : rightObject.minimum;	
	finalObject.maximum = ( root -> data > leftObject.maximum ) && ( root -> data > rightObject.maximum ) ? root -> data : 
						  ( leftObject.maximum > root -> data ) && ( leftObject.maximum > rightObject.maximum ) ? leftObject.maximum : rightObject.maximum;;
	return finalObject;
}

int main() {

	operations<int> op;
	TreeNode<int> *root = op.takeInput();
	checkBSTReturn obj = checkBST(root);
	cout << ( obj.isBST ? "true" : "false" ) << endl;
	return 0;
}