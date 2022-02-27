#include <iostream>
#include "nodeClass.cpp"
using namespace std;

Node* reverseLinkedList( Node *head, Node *fhead ) {
	if ( head == NULL ) {
		return fhead;
	}

	Node *n = new Node(head -> data);
	n -> next = fhead;
	fhead = n;

	return reverseLinkedList( head -> next, fhead );
}

int main(){
	operations *op = new operations();
	Node* head = op -> takeInput();
	Node *fhead = NULL;
	op -> print( reverseLinkedList( head, fhead ) );	

	delete op;
	delete head;
}