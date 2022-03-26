#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

	SinglyLinkedListNode *head = NULL;
	SinglyLinkedListNode *tail = NULL;

	while ( head1 || head2 ) {
		if ( !head1 ) {
			if( head )
				tail -> next = head2;
			else {
				head = head2;
				head2 = NULL;
			}
			break;
		}
		else if ( !head2 ) {
			if( head )
				tail -> next = head1;
			else {
				head = head1;
				head1 = NULL;
			}
			break;
		}
		else {
			SinglyLinkedListNode *node;
			if ( head1 -> data < head2 -> data ) {
				node = new SinglyLinkedListNode( head1 -> data );
				head1 = head1 -> next;
			}
			else {
				node = new SinglyLinkedListNode( head2 -> data );
				head2 = head2 -> next;	
			}

			if( head ) {
				tail -> next = node;
				tail = tail -> next;
			}
			else {
				head = node;
				tail = node;
			}
		}
	}
	return head;
}

int main() {
	SinglyLinkedList list1;
	list1.insert_node(1);
	list1.insert_node(2);
	list1.insert_node(3);
	
	SinglyLinkedList list2;
	list2.insert_node(3);
	list2.insert_node(4);
	
	SinglyLinkedListNode *node = mergeLists( list1.head, list2.head );
	print_list( node );

	free_linked_list(node);
}