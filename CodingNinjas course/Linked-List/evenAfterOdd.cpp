#include <iostream>
#include "nodeClass.cpp"
using namespace std;

class Pair {
	public :
		Node *head = NULL;
		Node *tail = NULL;
};

int main() {
	operations *op = new operations();
	Node *head = op -> takeInput();

	Pair *even = new Pair(), *odd = new Pair();
	while( head != NULL ) {
		if ( head -> data % 2 == 0 ) {
			if ( even -> head == NULL ) {
				even -> head = head;
				even -> tail = head;
			} else {
				even -> tail -> next = head;
				even -> tail = even -> tail -> next;
			}
		}
		else {
			if ( odd -> head == NULL ) {
				odd -> head = head;
				odd -> tail = head;
			} else {
				odd -> tail -> next = head;
				odd -> tail = odd -> tail -> next;
			}
		}
		if (head -> next == NULL) {
			if (odd -> tail != NULL)
				odd -> tail -> next = NULL;
			if (even -> tail != NULL)
				even -> tail -> next = NULL;
		}
		head = head -> next;
	}
	if (odd -> tail != NULL) {
		odd -> tail -> next = even -> head;
	}
	else {
		odd -> head = even -> head;
	}
	op -> print(odd -> head);
	return 0;
}