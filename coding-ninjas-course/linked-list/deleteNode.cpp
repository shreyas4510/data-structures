#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;

		Node( int data ) {
			this -> data = data;
			this -> next = NULL;
		}
};

Node* takeInput() {
	int input;
	Node *head = NULL, *tail = NULL;
	cin >> input;

	while( input != -1 ) {
		Node *n = new Node( input );

		if (head == NULL)
			head = n;

		if (tail != NULL)
			tail -> next = n;

		tail = n;
		cin >> input;
	}
	return head;
}

print( Node *head ) {
	Node *temp = head;
	while( temp != NULL ) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

Node* deleteNode( Node *head, int pos ) {

	if (pos == 0) {
		Node *a = head;
		head = head -> next;
		delete a;
		return head;
	}

	int count = 0;
	Node *tail = head;
	while( count < pos && tail -> next != NULL ) {
		if ( count == pos - 1 ) {
			Node *temp = tail -> next;
			tail -> next = temp -> next;
			delete temp;
		}
		tail = tail -> next;
		count++;
	}
	return head;
}

int main () {
	Node *head = takeInput();

	int pos;
	cin >> pos;

	print(deleteNode( head, pos ));
}