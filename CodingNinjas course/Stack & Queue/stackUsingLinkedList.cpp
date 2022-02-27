#include <iostream>
using namespace std;

template <typename type>
class Node {
	public :
		type data;
		Node *next;

		Node( type item ) {
			this -> data = item;
			this -> next = NULL;
		}
};

template <typename type>
class Stack {

	int size;
	Node<type> *head;

	public :
		Stack() {
			this -> size = 0;
			this -> head = NULL;
		}

		int getSize() {
			return size;
		}

		bool isEmpty() {
			return size == 0;
		}

		void push( type data ) {
			Node<type> *n = new Node<type>(data);
			n -> next = head;
			head = n;
			size++;
		}

		type pop() {
			if (head == NULL) {
				cout << "Empty Stack";
				return 0;
			}
			Node<type> *temp = head;
			head = head -> next;
			size--;
			type ans = temp -> data;
			delete temp;
			return ans;
		}

		type top() {
			if (head == NULL) {
				cout << "Empty Stack";
				return 0;
			}
			return head -> data;
		}
};

int main()
{
	Stack<int> s;
	cout << "Size : " << s.getSize() << endl;
	cout << "Is Empty : " << s.isEmpty() << endl;

	s.push(1);
	s.push(2);

	cout << "Size : " << s.getSize() << endl;
	cout << "Is Empty : " << s.isEmpty() << endl;
	
	cout << "Top Element : " << s.top() << endl;
	cout << "Top Element : " << s.top() << endl;
	
	cout << "Popped Element : " << s.pop() << endl;
	cout << "Popped Element : " << s.pop() << endl;
	cout << "Popped Element : " << s.pop() << endl;

	return 0;
}