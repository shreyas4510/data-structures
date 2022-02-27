#include <iostream>
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
	while ( temp != NULL ) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

void removeDuplicates( Node *head ) {
	if (head -> next == NULL)
		return;

	if ( head -> data == head -> next -> data ) {
		while( head -> data == head -> next -> data ) {
			Node *temp = head -> next;
			head -> next = temp -> next;
			delete temp;
			if (head -> next == NULL)
				return;
		}
	}
	
	return removeDuplicates( head -> next );
}

int main() {
	Node *head = takeInput();
	removeDuplicates(head);
	print(head);
}