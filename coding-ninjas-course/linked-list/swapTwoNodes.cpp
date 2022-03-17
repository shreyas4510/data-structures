#include <iostream>
#include "nodeClass.cpp"
using namespace std;

class Pair {
	public:
		Node *head = NULL;
		Node *tail = NULL;
};

int main() {
	operations *op = new operations();
	Node *head = op -> takeInput();

	int m, n;
	cin >> m >> n;

	int index = 0;
	Node *n1 = NULL, *n2 = NULL;
	Node *temp = head;
	while( index <= n ) {
		if ( index == m )
			n1 = new Node( temp -> data );
		
		if ( index == n )
			n2 = new Node( temp -> data );

		temp = temp -> next;
		index++;
	}

	temp = head;
	index = 0;
	while( index < n ) {

		if (m == 0 && index == 0) {
			Node *delNode = temp;
			n2 -> next = temp -> next;
			temp = n2;
			head = n2;
			delete delNode;
		}
		else {
			if (index == m-1) {
				Node *delNode = temp -> next;
				n2 -> next = temp -> next -> next;
				temp -> next = n2;
				delete delNode;
			}
		}

		if ( index == n-1 ) {
			Node *delNode = temp -> next;
			n1 -> next = temp -> next -> next;
			temp -> next = n1;
			delete delNode;
		}

		temp = temp -> next;
		index++;
	}

	op -> print(head);

	return 0;
}