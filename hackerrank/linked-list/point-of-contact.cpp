#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	int len1 = 0, len2 = 0;
	SinglyLinkedListNode *temp = head1, *temp1 = head2;
	while( temp || temp1 ) {
		if (temp) {
			len1++;
			temp = temp -> next;
		}
		if (temp1) {
			len2++;
			temp1 = temp1 -> next;
		}
	}

	temp = head1;
	temp1 = head2;

	if (len1 > len2) {
		int diff = len1 - len2;
		for (int i = 0; i < diff; ++i) {
			temp = temp -> next;
		}
	}
	else {
		int diff = len2 - len1;
		for (int i = 0; i < diff; ++i) {
			temp1 = temp1 -> next;
		}
	}

	while ( temp1 && temp ) {
		if ( temp == temp1 )
			return temp -> data;
		temp1 = temp1 -> next;
		temp = temp -> next;
	}

	return -1;
}

int main() {
	SinglyLinkedListNode *head1 = new SinglyLinkedListNode(1);
	SinglyLinkedListNode *n10 = new SinglyLinkedListNode(2);
	SinglyLinkedListNode *n11 = new SinglyLinkedListNode(3);
	head1 -> next = n10;
	n10 -> next = n11;

	SinglyLinkedListNode *head2 = new SinglyLinkedListNode(1);
	head2 -> next = n11;

	cout << findMergeNode( head1, head2 );

	free_linked_list( head1 );
	// free_linked_list( head2 );
	return 0;
}