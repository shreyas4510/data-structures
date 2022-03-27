#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "SinglyLinkedList.h"
using namespace std;

bool helper_fun( SinglyLinkedListNode *head, vector< SinglyLinkedListNode* > *visited_nodes ) {
	if (!head) 
		return false;

	auto it = find( visited_nodes -> begin(), visited_nodes -> end(), head );
	if (it != visited_nodes -> end())
		return true;

	visited_nodes -> push_back( head );
	return helper_fun( head -> next, visited_nodes );
}

bool has_cycle( SinglyLinkedListNode *head ) {
	vector< SinglyLinkedListNode* > *visited_nodes = new vector< SinglyLinkedListNode* >();
	return helper_fun( head, visited_nodes );
}

int main() {

	SinglyLinkedListNode *head = new SinglyLinkedListNode(1);
	// SinglyLinkedListNode *node1 = new SinglyLinkedListNode(2);
	// SinglyLinkedListNode *node2 = new SinglyLinkedListNode(3);

	head -> next = NULL;
	// node1 -> next = node2;
	// node2 -> next = node1;

	cout << has_cycle(head);

}