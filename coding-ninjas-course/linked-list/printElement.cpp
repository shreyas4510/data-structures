#include<iostream>
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

	Node *head = NULL;
	Node *tail = NULL;

	while( input != -1 ) {
		cin >> input;
		Node *n = new Node(input);

		if ( head == NULL )
			head = n;

		if ( tail != NULL )
			tail -> next = n;

		tail = n;
	}
	return head;
}

void print( Node *head, int element ) {
	int count = 0;
	Node *temp = head;
	while( temp -> data != -1 ) {
		if (count == element) {
			cout << temp -> data << endl;
			break;
		}
		temp = temp -> next;
		count++;
	} 
}

int main() {
	int testCases;
	cin >> testCases;

	for (int i = 0; i < testCases; ++i) {
		Node *head = takeInput();
		int element;
		cin >> element;
		print( head, element );
	}

}