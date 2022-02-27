#include <iostream>
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

int findLength( Node *head ) {
	if ( head == NULL )
		return 0;

	int length = findLength( head -> next );
	return ++length;
}

int main() {
	Node *head = takeInput();
	cout << findLength( head );
}