#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include "binaryTree.h"
using namespace std;

class Node {
	public :
		int data;
		Node *next;

		Node( int data ) {
			this -> data = data;
			this -> next = NULL;
		}
};

vector<Node*> printLevelWise( binaryTreeNode<int> *root ) {
	queue<binaryTreeNode<int>*> q;
	q.push(root);
	q.push(new binaryTreeNode<int>(INT_MIN));

	Node *head = NULL;
	Node *temp = NULL;

	vector<Node*> v;
	int count = 0;

	while( !q.empty() ) {
		binaryTreeNode<int> *front = q.front();
		q.pop();

		if (front -> data == INT_MIN) {
			v.push_back( head );
			head = NULL;
			temp = NULL;
			++count;
			if (!q.empty())
				q.push(new binaryTreeNode<int>(INT_MIN));
			continue;
		}

		if( !head ) {
			head = new Node(front -> data);
			temp = head;
		}
		else {
			Node *newNode = new Node(front -> data);
			if (count % 2) {
				newNode -> next = temp;
				head = newNode;
				temp = newNode;
			}
			else {
				temp -> next = newNode;
				temp = temp -> next;
			}
		}

		if (front -> leftNode)
			q.push( front -> leftNode );

		if (front -> rightNode)
			q.push( front -> rightNode );
	}

	return v;
}

int main() {
	operations<int> op;
	binaryTreeNode<int>* root = op.takeInput();
	vector<Node*> v= printLevelWise(root);
	for (Node* node : v) {
		Node *temp = node;
		while( temp ){
			cout << temp -> data << " ";
			temp = temp -> next;
		}
		cout << endl;
		delete node;
	}
	delete root;
}