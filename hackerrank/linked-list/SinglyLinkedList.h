#include <iostream>
using namespace std;

class SinglyLinkedListNode {
	public :
		int data;
		SinglyLinkedListNode *next;

		SinglyLinkedListNode(int data) {
			this -> data = data;
			this -> next = NULL;
		}
};

class SinglyLinkedList {
	public : 
		SinglyLinkedListNode *head = NULL;
		SinglyLinkedListNode *tail = NULL;

		void insert_node( int data ) {
			SinglyLinkedListNode *node = new SinglyLinkedListNode( data );
			if ( this -> head ) {
				this -> tail -> next = node;
				this -> tail = tail -> next;
			}
			else {
				this -> head = node;
				this -> tail = node;
			}
		}
};

void print_list( SinglyLinkedListNode *head ) {
	SinglyLinkedListNode *tail = head;
	while( tail ) {
		cout << tail -> data << " ";
		tail = tail -> next;
	}
	cout << endl;
}

void free_linked_list( SinglyLinkedListNode *head ) {
	while( head ) {
		SinglyLinkedListNode *temp = head;
		head = head -> next;
		delete temp;
	}
}