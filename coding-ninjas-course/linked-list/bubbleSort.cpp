#include<iostream>
#include"nodeClass.cpp"
#include <climits>
using namespace std;

int main()
{
	operations *op = new operations();
	Node *head = op -> takeInput();
	Node *temp = head;

	int len=0, j=0;

	while ( temp != NULL ) {
		len++;
		temp = temp -> next;
	} 
	temp = head;
	while(len > 1) {
		j=0;
		temp = head;
		while( temp -> next -> next != NULL && j < len-1) {
			if (j == 0) {
				if ( temp -> data > temp -> next -> data ) {
					Node *n = new Node( temp -> data );
					Node *n1 = new Node( temp -> next -> data );

					Node *delNode = temp;
					Node *delNode1 = temp -> next;

					n -> next = temp -> next -> next;
					n1 -> next = n;
					temp = n1;
					head = n1;

					delete delNode;
					delete delNode1;
				}
				j++;
			}

			if ( j > 0 ) {
				if ( temp -> next -> data > temp -> next -> next -> data )
				{
					Node *n = new Node( temp -> next -> data );
					Node *n1 = new Node( temp -> next -> next -> data );

					Node *delNode = temp -> next;
					Node *delNode1 = temp -> next -> next;

					n -> next = temp -> next -> next -> next;
					n1 -> next = n;
					temp -> next = n1;

					delete delNode;
					delete delNode1;
				}
			}
			j++;
			temp = temp -> next;
		}
		len--;
	}

	// cout << j << endl;
	op -> print(head);
	return 0;
}