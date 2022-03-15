#include <iostream>
#include <queue>
#include <climits>
#include "binaryTree.h"
using namespace std;

void printLeveWise( binaryTreeNode<int> *root ) {
	queue<binaryTreeNode<int>*> q;
	q.push(root);
	q.push(new binaryTreeNode<int>(INT_MIN));

	while( q.size() > 1 ) {
		binaryTreeNode<int> *front = q.front();
		q.pop();

		if (front -> data == INT_MIN) {
			cout << endl;
			q.push(new binaryTreeNode<int>(INT_MIN));
			continue;
		}

		cout << front -> data << " ";
		if( front -> leftNode )
			q.push( front -> leftNode );
		
		if( front -> rightNode )
			q.push( front -> rightNode );
	}
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	printLeveWise( root );
	delete root;
}