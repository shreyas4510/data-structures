#include <iostream>
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

Node* takeInput() {
	int input;
	Node *head = NULL, *tail = NULL;

	cin >> input;
	while( input != -1 ) {
		Node *n = new Node( input );
		if ( head == NULL )
			head = n;
		if (tail != NULL)
			tail -> next = n;
		tail = n;
		cin >> input;
	}
	return head;
}

int findIndex( Node *head, int target, int index ) {

	if ( head == NULL )
		return -1;

	if (head -> data == target)
		return index;

	return findIndex( head -> next, target, index+1 );
}

int main() {
	Node *head = takeInput();
	int target;
	cin >> target;

	cout << findIndex( head, target, 0 ); 
}