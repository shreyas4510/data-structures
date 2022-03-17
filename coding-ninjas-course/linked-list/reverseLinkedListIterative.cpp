#include <iostream>
#include "nodeClass.cpp"
using namespace std;

int main() { 
	operations *op = new operations();
	Node* head = op -> takeInput();

	Node *temp = NULL;
	while( head != NULL ) {
		Node *n = new Node( head -> data );
		n -> next = temp;
		temp = n;
		head = head -> next;
	}

	op -> print(temp);
}