#include <iostream>
#include "nodeClass.cpp"
using namespace std;

int main() {
	operations *op = new operations();
	Node *head = op -> takeInput();

	int x, i=1;
	cin >> x;

	Node *cursor = NULL, *tempHead = NULL, *tempTail = NULL, *tail = NULL;

	if( x > 0 ) {
		cursor = head;
		head = NULL;	
	}
	
	while( cursor != NULL ) {
		Node *n = new Node( cursor -> data );
		if (tempHead == NULL) {
			tempHead = n;
			tempTail = n;
		}
		else {
			n -> next = tempHead;
			tempHead = n;
		}

		if (i % x == 0 || cursor -> next == NULL) {
			if (head == NULL) {
				head = tempHead;
			}

			if (tail == NULL) {
				tail = tempTail;
			}
			else {
				tail -> next = tempHead;
				tail = tempTail;
			}

			tempHead = NULL;
			tempTail = NULL;
		}

		Node *delNode = cursor;
		cursor = cursor -> next;
		delete delNode;
		i++;
	}

	op -> print(head);

}