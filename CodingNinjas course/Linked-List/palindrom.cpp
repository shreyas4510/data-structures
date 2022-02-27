#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;

		Node(int data) {
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

Node* reverseList( Node *tail ) {
	if (tail -> next == NULL) {
		return tail;
	}

	Node *head = reverseList( tail -> next );
	Node *temp = head;
	while( temp -> next != NULL ) {
		temp = temp -> next;
	}
	temp -> next = new Node(tail -> data);
	return head;
}

int main() {
	Node *head = takeInput();
	Node *temp = head;

	int length = 0; 
	while( temp != NULL ){
		length++;
		temp = temp -> next;
	}

	if (length == 0) {
		cout << "Palindrom" <<endl;
	}
	else {
		temp = head;
		int mid = length / 2, i=0; 
		Node *tail = NULL;
		while( i < mid ) {
			if ( i == mid - 1) {
				tail = temp -> next;
				temp -> next = NULL;
			}
			temp = temp -> next;
			i++;
		}

		Node *head2 = reverseList( tail );
		bool flag = true;
		while( head != NULL && head2 != NULL ) {
			if (head -> data != head2 -> data) {
			 	flag = false;
			 	break;
			} 
			head2 = head2 -> next;
			head = head -> next;
		}
		cout << (flag ? "Palindrom" : "Not Palindrom") <<endl;
	}
}