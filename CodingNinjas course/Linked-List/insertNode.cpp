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
	int input = 0;
	Node *head = NULL;
	Node *tail = NULL;

	cin >> input;
	while( input != -1 ) {
		Node *n = new Node(input);

		if ( head == NULL )
			head = n;

		if ( tail != NULL )
			tail -> next = n;

		tail = n;
		cin >> input;
	}
	return head;
}

print( Node *head ) {
	Node *temp = head;
	while ( temp != NULL ) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

Node* insertNode( Node *head, int data, int pos ) {
	int count = 0;
	Node *n = new Node( data );
	
	if ( pos == 0 ) {
		n -> next = head;
		return n;
	}

	Node *temp = head; 
	while ( count < pos && temp != NULL) {
		if ( count == pos - 1 ) {
			n -> next = temp -> next;
			temp -> next = n;
		}
		temp = temp -> next;
		count++;
	}
	return head;
}

int main()
{
	Node *head = takeInput(); 

	int data, position;
	cout << "Enter the position : ";
	cin >> position;

	cout << "Enter the data : ";
	cin >> data;

	print(insertNode( head, data, position ));
	return 0;
}