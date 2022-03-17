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

heightOfTree( binaryTreeNode<int>* root ) {
	if (!root)
		return 0;

	int height = 1;
	int tempHeightLeft, tempHeightRight;
	tempHeightLeft = heightOfTree( root -> leftNode );
	tempHeightRight = heightOfTree( root -> rightNode );

	if ( tempHeightRight < tempHeightLeft ) 
		height += tempHeightLeft;
	else 
		height += tempHeightRight;

	return height;
}

int main() {
	binaryTreeNode<int>* root = takeInput();
	cout << heightOfTree( root );
	delete root;
}