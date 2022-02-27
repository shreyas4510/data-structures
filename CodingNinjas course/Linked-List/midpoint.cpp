#include <iostream>
#include "nodeClass.cpp"
using namespace std;

int main() {
	operations *op = new operations();
	Node *head = op -> takeInput();

	// int length = 0;
	// Node *temp = head;
	// while( temp != NULL ) {
	// 	length++;
	// 	temp = temp -> next;
	// }

	// temp = head;
	// int index = 0, mid = length % 2 == 0 ? length / 2 : length / 2 + 1;
	// while( index < mid-1 ) {
	// 	temp = temp -> next;
	// 	index++;
	// }

	// if (temp != NULL)
	// 	cout << temp -> data;
	// delete temp;

	Node *slow = head, *fast = head -> next;
	while( fast != NULL && fast -> next != NULL ) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	cout << slow -> data;
}
