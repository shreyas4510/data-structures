#include <iostream>
#include "nodeClass.cpp"
using namespace std;

class Pair {
	public :
		Node *head = NULL;
		Node *tail = NULL;

		Pair( Node* head, Node *tail ) {
			this -> head = head;
			this -> tail = tail;
		}
};

Pair* reverseLinkedList( Node *head ) {
	if ( head -> next == NULL ) {
		Pair *p = new Pair( head, head );
		return p;
	}

	Pair *temp = reverseLinkedList( head -> next );
	temp -> tail -> next = new Node(head -> data);
	temp -> tail = temp -> tail -> next;
	return temp;
}

int main(){
	operations *op = new operations();
	Node* head = op -> takeInput();
	
	op -> print( reverseLinkedList( head ) -> head );
	delete op;
	delete head;
}