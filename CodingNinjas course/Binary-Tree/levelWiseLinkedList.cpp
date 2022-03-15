#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "binaryTree.h"
using namespace std;

class Node {
	public :
		int data;
		Node* next;

		Node( int data ) {
			this -> data = data;
			this -> next = NULL;
		}	
};

vector<Node*> levelWiseLinkedList( binaryTreeNode<int> *root ) {

	queue<binaryTreeNode<int>*> q;
	vector<Node*> v ;
		
	q.push( root );
	q.push( new binaryTreeNode<int>(INT_MIN) );
	
	Node *head = NULL;
	Node *temp = NULL;

	while( q.size() > 0 ) {
		binaryTreeNode<int> *front = q.front();
		q.pop();

		if ( front -> data == INT_MIN ) {
			v.push_back( head );
			head = NULL;
			temp = NULL;
			if (!q.empty()) {
				q.push( new binaryTreeNode<int>(INT_MIN) );
			}
			continue;
		}

		if (head == NULL) {
			head = new Node( front -> data );
			temp = head; 
		}
		else {
			temp -> next = new Node( front -> data );
			temp = temp -> next;
		}

		if( front -> leftNode )
			q.push( front -> leftNode );

		if( front -> rightNode )
			q.push( front -> rightNode );
	}

	return v;
}


int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	vector<Node*> v = levelWiseLinkedList(root);
	for (Node *node : v) {
		Node *temp = node;
		while( temp ) {
			cout << temp -> data << "  ";
			temp = temp -> next;
		}
		cout << endl;
		delete node;
	}
	delete root;
}