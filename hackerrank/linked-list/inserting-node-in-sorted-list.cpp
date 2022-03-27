#include <iostream>
using namespace std;

class DoublyLinkedListNode {
	public :
 		int data;
 		DoublyLinkedListNode* next;
 		DoublyLinkedListNode* prev;

 		DoublyLinkedListNode( int data ) {
 			this -> data = data;
 			this -> next = NULL;
 			this -> prev = NULL;
 		}
};

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
	if (!llist)
		return NULL;

	if( !llist -> prev && data < llist -> data ) {
		DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
		llist -> prev = node;
		node -> next = llist;
		return node;
	} else if (!llist -> next && data > llist -> data) {
		DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
		llist -> next = node;
		node -> prev = llist;
		return llist;
	} else if ( llist -> next && data > llist -> data && data < llist -> next -> data ) {
		DoublyLinkedListNode *node = new DoublyLinkedListNode(data);

		node -> next = llist -> next;
		node -> prev = llist;

		llist -> next -> prev = node;
		llist -> next = node;

		return llist;
	} else if ( llist -> data == data ) {
		DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
		node -> next = llist -> next;
		llist -> next = node;
		node -> prev = llist;
		return llist;		
	}

	sortedInsert( llist -> next, data );
	return llist;
}

int main() {
	int size;
	cin >> size;

	DoublyLinkedListNode *head = NULL, *tail = NULL;

	for (int i = 0; i < size; ++i) {
		int input;
		cin >> input;
		DoublyLinkedListNode *node = new DoublyLinkedListNode( input );
		if (head) {
			node -> prev = tail;
			tail -> next = node;
			tail = tail -> next;
		}
		else {
			head = node;
			tail = node;
		}
	}
	int target;
	cin >> target;

	head = sortedInsert( head, target );
	while( head ) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}