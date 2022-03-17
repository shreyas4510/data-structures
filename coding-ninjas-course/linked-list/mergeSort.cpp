#include <iostream>
#include "nodeClass.cpp"
using namespace std;

mergeLists( Node *h1, Node *h2, Node *fL ) {
	while( h1 != NULL && h2 != NULL ) {
		if ( h1 -> data < h2 -> data ) {
			Node *n = new Node( h1 -> data );
			fL -> next = n;
			h1 = h1 -> next;
		}
		else {
			Node *n = new Node( h2 -> data );
			fL -> next = n;
			h2 = h2 -> next;
		}
		fL = fL -> next;
	}

	if ( h1 == NULL ) {
		fL -> next = h2;
	}

	if ( h2 == NULL ) {
		fL -> next = h1;
	}
}

Node* mergeSort( Node *head ) {
	if (head == NULL )
		return head;

	if (head -> next == NULL)
		return head;

	Node *slow = head, *fast = head -> next;
	while( fast -> next != NULL ) {
		if ( fast -> next -> next == NULL )
			break;
		fast = fast -> next -> next;
		slow = slow -> next;
	}

	Node *temp = slow -> next;
	slow -> next = NULL;

	Node *n1 = mergeSort( head );
	Node *n2 = mergeSort( temp );

	Node *finalList = NULL;
	if ( n1 -> data < n2 -> data ) {
		Node *n = new Node(n1 -> data);
		finalList = n;
		mergeLists( n1 -> next, n2, finalList );
	}
	else {
		Node *n = new Node(n2 -> data);
		finalList = n;
		mergeLists( n1, n2 -> next, finalList );	
	}
	return finalList;
}

int main() {
	operations *op = new operations();
	Node *head = op -> takeInput();
	op -> print( mergeSort(head) );
	delete op;
}
