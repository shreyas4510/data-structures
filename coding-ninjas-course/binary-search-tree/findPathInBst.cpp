#include <iostream>
#include "binarySearchTree.h"
using namespace std;

void findPathOfNode( TreeNode<int> *root, int target ) {
	if (!root) {
		cout << -1;
		return;
	}
	if ( root -> data == target ) {
		cout << root -> data << " ";
		return;
	}

	if ( target < root -> data )
		findPathOfNode( root -> leftNode, target );

	if ( target >= root -> data )
		findPathOfNode( root -> rightNode, target );

	cout << root -> data << " ";
}

int main() {
	operations<int> op;
	TreeNode<int> *root = op.takeInput();

	int target;
	cin >> target;

	findPathOfNode(root, target);
	cout << endl;
	delete root;
	return 0;
}