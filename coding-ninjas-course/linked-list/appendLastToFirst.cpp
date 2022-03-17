#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;

		Node ( int data ) {
			this -> data = data;
			this -> next = NULL;
		}
};

Node* takeInput() {
	int input;
	Node *head = NULL , *tail = NULL;

	cin >> input;
	while( input != -1 ) {
		Node *n = new Node(input);
		if( head == NULL )
			head = n;
		if( tail != NULL )
			tail -> next = n;
		tail = n;
		cin >> input;
	}
	tail -> next = head;
	return head;
}

print( Node* head ) {
	Node *temp = head -> next;
	cout << head -> data << " ";
	while ( temp != head ) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

Node* updateHead( Node *head, int pos, int index ) {
	if ( index == pos - 1 ) {
		return head;
	}

	return updateHead( head -> next, pos, index+1 );
}

int main() {
	Node *head = takeInput();
	int pos;
	cin >> pos;

	head = updateHead( head, pos, 0 );
	print(head);
}