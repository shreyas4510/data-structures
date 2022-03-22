#include <iostream>
#include "binarySearchTree.h"
using namespace std;

class Node {
	public :
		int data;
		Node *next;

		Node( int data ) {
			this -> data = data;
			this -> next = NULL;
		}

		~Node() {
			delete this -> next;
		}
};

class NodeHelper {
	public :
		Node *head = NULL;
		Node *temp = NULL;
};

void convertToLinkedList( TreeNode<int> *root, NodeHelper *nodeHelper ) {
	if ( !root ) 
		return;

	convertToLinkedList( root -> leftNode, nodeHelper );
	Node *obj = new Node( root -> data );
	if ( nodeHelper -> head == NULL ) {
		nodeHelper -> head = obj;
		nodeHelper -> temp = obj;
	}
	else {
		nodeHelper -> temp -> next = obj;
		nodeHelper -> temp = nodeHelper -> temp -> next;
	}

	convertToLinkedList( root -> rightNode, nodeHelper );
}

int main() {
	operations<int> op;
	TreeNode<int> *root = op.takeInput();

	NodeHelper *nodeHelper = new NodeHelper();
	convertToLinkedList( root, nodeHelper );

	nodeHelper -> temp = nodeHelper -> head;
	while( nodeHelper -> temp ) {
		cout << nodeHelper -> temp -> data << " ";
		nodeHelper -> temp = nodeHelper -> temp -> next;
	}
	cout << endl;
	delete nodeHelper -> head;
	delete root;
	return 0;
}