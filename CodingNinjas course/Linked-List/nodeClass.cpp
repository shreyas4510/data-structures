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

class operations {
	public :
		Node* takeInput() {
			int input;
			Node *head = NULL, *tail = NULL;

			cin >> input;
			while( input != -1 ) {
				Node *n = new Node( input );
				
				if (head == NULL)
					head = n;
				
				if (tail != NULL)
					tail -> next = n;

				tail = n;
				cin >> input;
			}
			return head;
		}

		void print( Node *head ) {
			Node *temp = head;
			while ( temp != NULL ) {
				cout << temp -> data << " ";
				temp = temp -> next;
			}
			cout << endl;
		}
};