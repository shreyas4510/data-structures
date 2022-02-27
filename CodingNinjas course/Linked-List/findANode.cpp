#include <iostream>
#include "nodeClass.cpp"
using namespace std;

int main() {
	operations *op = new operations();
	Node *head = op -> takeInput();

	int input, index = 0;
	bool flag = true;
	cin >> input;

	while( head != NULL ) {
		if ( head -> data == input ) {
			cout << index;
			flag = false;
			break;
		}
		head = head -> next;
		index++;
	}

	if (flag) 
		cout << -1;
}