#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

void deleteDuplicates( SinglyLinkedListNode *head ) {
	SinglyLinkedListNode *temp = head; 
	while ( temp ) {
		if ( temp -> next && (temp -> data == temp -> next -> data)) {
			SinglyLinkedListNode *nextNode = temp -> next;
			temp -> next = nextNode -> next; 
			delete nextNode;
		}
		else {
			temp = temp -> next;
		}
	}
}

int main() {

	SinglyLinkedList obj;
	int size;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		int input;
		cin >> input;
		obj.insert_node(input);
	}
	deleteDuplicates( obj.head );
	print_list( obj.head );
	free_linked_list( obj.head );
}