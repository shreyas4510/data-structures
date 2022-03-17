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

mirrorTree( binaryTreeNode<int> *root ) {

	if (!root)
		return 0;

	binaryTreeNode<int>* tempLeftNode = root -> leftNode;
	root -> leftNode = root -> rightNode;
	root -> rightNode = tempLeftNode;

	mirrorTree( root -> leftNode );
	mirrorTree( root -> rightNode );
}

int main() {
	binaryTreeNode<int>* root = takeInput();
	mirrorTree(root);
	printBinaryTree(root);
	delete root;
}