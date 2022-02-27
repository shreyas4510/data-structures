#include <iostream>
#include "nodeClass.cpp"
using namespace std;

class Pair {
	public:
		Node *head = NULL;
		Node *tail = NULL;
};

int main(int argc, char const *argv[])
{
	operations *op = new operations();
	Node *head = op -> takeInput();
	int m, n, index=0;
	cin >> m >> n;

	Node *temp = head;
	Pair *p = new Pair();
	while( temp != NULL ) {
		if (m > 0 && n > 0) {
			if ( index == m-1 ) {
				p -> head = temp;
			}
			if ( index == n-1 ) {
				p -> tail = temp;
				break;
			}
		}
		else {
			if ( m == 0 && index == 0 ) {
				p -> head = temp;
			}
			if ( n == 0 && index == 0) {
				p -> tail = temp;
				break;
			}
		}
		index ++;
		temp = temp-> next;
	}

	Node *newTemp = new Node( n == 0 ? p -> tail -> data : p -> tail -> next -> data);
	Node *newTemp1 = new Node( m == 0 ? p -> head -> data : p -> head -> next -> data );

	if (m == 0)
	{
		newTemp -> next = p -> head -> next;
		p -> head -> next = newTemp;
	}
	else {
		newTemp -> next = p -> head -> next -> next;
		p -> head -> next = newTemp;
	}

	if ( n ==0 ){
		newTemp1 -> next = p -> tail -> next;
		p -> tail -> next = newTemp1;	
	}
	else {	
		newTemp1 -> next = p -> tail -> next -> next;
		p -> tail -> next = newTemp1;			
	}

	op -> print(head);
	return 0;
}