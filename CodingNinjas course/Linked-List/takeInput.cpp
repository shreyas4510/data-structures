#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;

		Node (int data) {
			this -> data = data;
			this -> next = NULL;
		}
};

Node* takeInput() {
	int input;
	Node *head = new Node(0);
	Node *prev = head;

	while ( input != 0 ) {
		cin >> input;

		Node *n1 = new Node(input);
		prev -> next = n1;
		prev = n1;

		if ( head -> data == 0 ) {
			head = n1;			
		}
	}
	return head;
}

void print( Node *head ) {
	Node *temp = head;
	while( temp != NULL ){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

int main() {
	Node *head = takeInput();
	print( head );
}