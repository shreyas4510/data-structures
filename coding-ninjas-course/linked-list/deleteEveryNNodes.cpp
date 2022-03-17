#include <iostream>
#include "nodeClass.cpp"
using namespace std;

int main() {
	
	operations *op = new operations();
	Node *head = op -> takeInput();
	int m, n;
	cin >> m >> n;

	Node *temp = head;
	int index = 1;
	while ( temp != NULL ) {
		if (m == 0) {
			head = NULL;
			break;
		}

		if (index % m == 0) {
			int count = 0;
			Node *tempHead = temp -> next, *tempTail = temp;
			while( tempTail -> next != NULL && count < n ) {
				tempTail = tempTail -> next;
				count ++;
			}
			temp -> next = tempTail -> next;			
			delete tempHead;
		}
		index++;
		temp = temp -> next;
	}

	op -> print(head);
}