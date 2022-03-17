#include <iostream>
#include <climits>
using namespace std;

class stack {
	int *data;
	int capacity, nextIndex;

	public :
		stack() {
			this -> data = new int[10];
			this -> capacity = 10;
			this -> nextIndex = 0;
		}

		bool isEmpty() {
			return nextIndex == 0;
		}

		int size() {
			return nextIndex;
		}

		int top() {
			if (isEmpty()) {
				cout << "Empty Stack !!" << endl;
				return INT_MIN;
			}
			return data[ nextIndex - 1 ];
		}

		void push( int element ) {
			if (nextIndex == capacity) {
				int *temp = new int[2 * capacity];
				for( int i=0; i<capacity; i++ ) {
					temp[i] = data[i];
				}
				delete [] data;
				data = temp;
				capacity = 2*capacity;
			}
			data[ nextIndex ] = element;
			nextIndex++;
		}

		int pop() {
			if (isEmpty()) {
				cout << "Empty Stack !!" << endl;
				return INT_MIN;
			}
			nextIndex--;
			return data[nextIndex];
		}
};

int main() {
	stack s;
	cout << s.size() << endl;
	cout << s.isEmpty() << endl;
	s.pop();
	s.top();

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << s.size() << endl;

	s.push(60);
	s.push(70);
	s.push(80);
	s.push(90);
	s.push(100);
	s.push(110);
	s.push(120);
	s.push(130);
	s.push(140);
	s.push(150);

	cout << s.size() << endl;
	cout << s.isEmpty() << endl;

	cout << s.pop() << endl;
	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
}