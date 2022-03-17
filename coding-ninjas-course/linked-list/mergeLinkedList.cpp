#include <iostream>
#include "nodeClass.cpp"
using namespace std;

void mergeLists( Node *head1, Node *head2, Node *finalList ) {
	if( head1 == NULL && head2 == NULL ) 
		return;

	if ( head1 == NULL ) {
		Node *temp = head2; 
		finalList -> next = temp;
		return;
	}

	if ( head2 == NULL ) {
		Node *temp = head1; 
		finalList -> next = temp;
		return;
	}

	if ( head1 -> data < head2 -> data ) {
		Node *n = new Node(head1 -> data);
		finalList -> next = n;
		mergeLists( head1 -> next, head2, finalList -> next );
	}
	else {
		Node *n = new Node(head2 -> data);
		finalList -> next = n;	
		mergeLists( head1, head2 -> next, finalList -> next );
	}
	return;
}

int main() {
	operations *op = new operations();
	Node *head1 = op -> takeInput();
	Node *head2 = op -> takeInput();
	Node *finalList = NULL;

	if ( head1 -> data < head2 -> data ) {
		Node *n = new Node(head1 -> data);
		finalList = n;
		mergeLists( head1 -> next, head2, finalList );
	}
	else {
		Node *n = new Node(head2 -> data);
		finalList = n;
		mergeLists( head1, head2 -> next, finalList );
	}

	op -> print(finalList);
	delete finalList;
	delete head1;
	delete head2;
}