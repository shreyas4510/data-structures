#include<iostream>
using namespace std;

class Node {
	public : 
		int data;
		Node *next;

		Node( int data ){ 
			this -> data = data;
			this -> next = NULL;
		}
};

Node* takeInput() {

	int input = 0;

	Node *head = NULL;
	Node *tail = NULL;

	cin >> input;
	while ( input != -1 ) {
		Node *n = new Node(input);
		if (tail != NULL)
			tail -> next = n;
		tail = n;
		if (head == NULL) {
			head = n;
		}
		cin >> input;
	}
	return head;
}
int print( Node *head ) {
	Node *temp = head;
	int count=0;
	while( temp != NULL ) {
		count++;
		temp = temp -> next;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << print(takeInput()) << endl;	
	}

	return 0;
}