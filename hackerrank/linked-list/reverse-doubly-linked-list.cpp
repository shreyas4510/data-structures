#include <iostream>
using namespace std;

class DoublyLinkedListNode {
	public:
	    int data;
	    DoublyLinkedListNode *next;
	    DoublyLinkedListNode *prev;

	    DoublyLinkedListNode( int data ) {
	    	this -> data = data;
	    	this -> next = NULL;
	    	this -> prev = NULL;
	    }
};

class Pair {
	public:
		DoublyLinkedListNode *head;
		DoublyLinkedListNode *tail; 

		Pair( DoublyLinkedListNode *head, DoublyLinkedListNode *tail ) {
			this -> head = head;
			this -> tail = tail;
		}
};

Pair* reverseHelper(DoublyLinkedListNode* llist, DoublyLinkedListNode* head, DoublyLinkedListNode* tail ) {
	if (!llist)
		return new Pair( NULL, NULL );

	Pair *obj = reverseHelper(llist -> next, head, tail);
	llist -> next = NULL;
	llist -> prev = NULL;
	if (!obj -> head) {
		obj -> head = llist;
		obj -> tail = llist;
	}
	else {
		DoublyLinkedListNode *prev = obj -> tail;
		obj -> tail -> next = llist;
		obj -> tail = obj -> tail -> next;
		obj -> tail -> prev = prev;
	}

	return obj;
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {

	// First Solution
	// if (!llist)
	// 	return NULL;

	// DoublyLinkedListNode *head = NULL, *tail = NULL;
	// Pair *obj = reverseHelper(llist, head, tail);
	// return obj -> head;


	DoublyLinkedListNode *head = NULL;
	while( llist) {
		DoublyLinkedListNode *temp = llist -> next;
		llist -> next = llist -> prev;
		llist -> prev = temp;
		if (!llist -> prev)
			head = llist;
		llist = llist -> prev;
	}
	return head;
}

int main() {
	DoublyLinkedListNode *first = new DoublyLinkedListNode(1);
	DoublyLinkedListNode *second = new DoublyLinkedListNode(2);
	DoublyLinkedListNode *third = new DoublyLinkedListNode(3);
	DoublyLinkedListNode *fourth = new DoublyLinkedListNode(4);

	first -> next = second;
	second -> next = third;
	third -> next = fourth;

	fourth -> prev = third;
	third -> prev = second;
	second -> prev = first;

	DoublyLinkedListNode *head = reverse(first);
	while( head ) {
		cout << head -> data << " ";
		head = head -> next;
	}
	return 0;
}