#include<iostream>
#include "SinglyLinkedList.h"
using namespace std;

class Pair {
	public :
		int index;
		int value;
		bool status = false;
};

Pair helperGetNode( SinglyLinkedListNode *llist, int positionFromTail ) {
	
	if (!llist) {
		Pair obj;
		obj.index = 0;
		obj.value = 0;
		return obj;
	}

	Pair returnAns = helperGetNode( llist -> next, positionFromTail );
	if ( returnAns.index == positionFromTail && !returnAns.status ) {
		returnAns.value = llist -> data;
		returnAns.status = true;
		return returnAns;
	}

	returnAns.index++;
	return returnAns;
}

int getNode( SinglyLinkedListNode *llist, int positionFromTail ) {
	Pair obj = helperGetNode( llist, positionFromTail );
	return obj.value;
} 

int main() {
	int size, positionFromTail;
	cin >> size;
	SinglyLinkedList head;
	for (int i = 0; i < size; ++i) {
		int data;
		cin >> data;
		head.insert_node(data);
	}
	cin >> positionFromTail;
	cout << getNode( head.head, positionFromTail ) << endl;
	free_linked_list( head.head );
}
