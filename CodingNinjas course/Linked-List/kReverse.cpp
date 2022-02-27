#include <iostream>
#include "nodeClass.cpp"
using namespace std;

int main() {
	operations *op = new operations();
	Node *head = op -> takeInput();

	int n, i=0;
	cin >> n;

	Node *temp = NULL;
	Node *newHead = NULL;
	while( i < n ) {
		Node *n = new Node( head -> data );
		if (temp == NULL) {
			temp = n;
			newHead = n;
		}
		else{
			n -> next = temp;
			temp = n;
			newHead -> next = head;
		}

		head = head -> next;
		i++;
	}

	newHead -> next = head;
	op -> print(temp);
}