#include <iostream>
using namespace std;

class Node {
	public :
		int data;
		Node *next;

		Node( int data ){
			this -> data = data;
			this -> next = NULL;
		}
};

Node* takeInput() {
	int input;
	Node *head = NULL, *tail = NULL;

	cin >> input;
	while( input != -1 ) {
		Node *n = new Node(input);

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
	cout << endl;
}

Node* deleteNode( Node *head, Node *tail, int pos, int count ) {
	if (pos == 0) {
		Node *temp = head -> next;
		delete head;
		return temp;
	}

	if (tail -> next == NULL) {
		return head;
	}

	if (count == pos - 1) {
		Node *a = tail -> next;
		tail -> next = a -> next;
		delete a;
		return head;
	}

	return deleteNode( head, tail -> next, pos, count+1 );
}

int main() {
	Node *head = takeInput();

	int pos;
	cin >> pos;

	print( deleteNode(head, head, pos, 0) );
}