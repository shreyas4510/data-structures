#include <iostream>
#include <queue>
#include "binaryTree.h"
using namespace std;

binaryTreeNode<int>* takeInput() {
	int input;
	cin >> input;
	if (input == -1)
		return NULL;

	binaryTreeNode<int>* root = new binaryTreeNode<int>(input);
	queue<binaryTreeNode<int>*> q;
	q.push(root);

	while ( !q.empty() ) {
		binaryTreeNode<int>* front = q.front();
		q.pop();

		int leftData, rightData;
		cin >> leftData >> rightData;

		if (leftData != -1){
			binaryTreeNode<int>* leftNode = new binaryTreeNode<int>(leftData);
			q.push(leftNode);
			front -> leftNode = leftNode;
		}

		if (rightData != -1) {
			binaryTreeNode<int>* rightNode = new binaryTreeNode<int>(rightData);
			front -> rightNode = rightNode;
			q.push(rightNode);
		}
	}
	return root;
}

printBinaryTree( binaryTreeNode<int> *root ) {

	queue<binaryTreeNode<int>*> q;
	q.push(root);

	while( !q.empty() ) {

		binaryTreeNode<int>* front = q.front();
		q.pop();
	
		cout << front -> data << " : ";
		if( front -> leftNode ) {
			cout << " LN : " << front -> leftNode -> data << "  ";
			q.push( front -> leftNode );
		}

		if( front -> rightNode ) {
			cout << " RN : "<< front -> rightNode -> data << "  ";
			q.push( front -> rightNode );
		}
		cout << endl;
	}
}

bool isNodePresent( binaryTreeNode<int> *root, int target ) {
	if (!root)
		return false;

	if ( root -> data == target )
		return true;

	bool ans = false;
	ans = isNodePresent( root -> leftNode, target );
	if (!ans)
		ans = isNodePresent( root -> rightNode, target );

	return ans;
}

int main() {
	binaryTreeNode<int>* root = takeInput();
	int target;
	cin >> target;
	
	cout << ( isNodePresent( root, target ) ? "true" : "false" )<< endl; 
	delete root;
}

