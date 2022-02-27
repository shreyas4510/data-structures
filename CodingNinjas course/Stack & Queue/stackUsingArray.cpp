#include <iostream>
#include <climits>
using namespace std;

class stack {
	int *data;
	int capacity, nextIndex;

	public : 
		stack( int size ) {
			this -> data = new int[size];
			this -> capacity = size;
			this -> nextIndex = 0;
		}

		int size() {
			return nextIndex;
		}

		bool isEmpty() {
			return nextIndex == 0;
		}

		int top() {
			if (isEmpty()) {
				cout << "Stack is empty";
				return INT_MIN;
			}
			return data[ nextIndex - 1 ];
		}

		void push( int element ) {
			if (nextIndex == capacity) {
				cout << "Stack Full" << endl;
				return;
			}
			data[nextIndex] = element;
			nextIndex++;
		}

		int pop(){
			if (isEmpty()) {
				cout << "Stack is empty";
				return INT_MIN;
			}
			nextIndex--;
			return data[ nextIndex ];
		}
};

int main() {
	stack s(5);
	cout << s.size() << endl;
	cout << ( s.isEmpty() ? "true" : "false" ) << endl;

	int top = s.top();
	cout << ( top != INT_MIN ? top + "" : "" ) << endl;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	// cout << s.top() << endl;
	cout << s.pop() << endl;
	// cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
}