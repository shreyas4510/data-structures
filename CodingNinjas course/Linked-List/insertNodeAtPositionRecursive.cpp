#include <iostream>
using namespace std;

class Node {
	public :
		int data;
		Node *next;

		Node( int data ) {
			this -> data = data;
			this -> next = NULL;
		}
};

Node* takeInput() {
	int input;
	Node *head = NULL, *tail = NULL;

	cin >> input;
	while( input != -1 ) {
		Node *n = new Node(input);

		if (head == NULL)
			head = n;

		if (tail != NULL)
			tail -> next = n;

		tail = n;
		cin >> input;
	}
	return head; 
}

print( Node *head ) {
	Node *temp = head;
	while( temp != NULL ) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

Node* insertNode( Node *head, Node *tail, int pos, int data, int count ) {
	if (tail == NULL)
		return head;

	if ( pos == 0 )	{
		Node *n = new Node( data );
		n -> next = tail;
		return n;
	}

	if ( count == pos - 1 ) {
		Node *n = new Node( data );
		n -> next = tail -> next;
		tail -> next = n;
		return head;
	}

	return insertNode( head, tail -> next, pos, data, count+1 );
}

int main()
{
	Node *head = takeInput();

	int pos, data;
	cin >> pos >> data;

	print(insertNode( head, head, pos, data, 0 ));
	return 0;
}