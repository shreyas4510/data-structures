#include <iostream>
using namespace std;

template<typename type>

class Stack {
	type *data;
	int capacity, nextIndex;

	public:
		Stack() {
			this -> data = new type[5];
			this -> capacity = 5;
			this -> nextIndex = 0;
		}

		int size() {
			return nextIndex;
		}

		bool isEmpty() {
			return nextIndex == 0;
		}

		type top() {
			if (isEmpty()) {
				cout << "Stack Empty";
				return 0;
			}
			return data[nextIndex - 1];
		}

		type pop() {
			if (isEmpty()) {
				cout << "Stack Empty";
				return 0;
			}
			nextIndex--;
			return data[nextIndex];	
		}

		void push( type item ) {
			if( nextIndex == capacity ) {
				type *tempData = new type[2 * capacity];
				for (int i = 0; i < capacity; ++i) {
					tempData[i] = data[i];
				}
				delete [] data;
				data = tempData;
				capacity *= 2; 
			}
			data[nextIndex] = item;
			nextIndex++;
		}

};

int main()
{
	// Stack<int> s;

	// cout << s.size() << endl;
	// cout << s.isEmpty() << endl;

	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(4);
	// s.push(5);
	// s.push(6);

	// cout << s.top() << endl;

	// cout << s.pop() << endl;
	// cout << s.pop() << endl;
	// cout << s.pop() << endl;
	// cout << s.pop() << endl;
	// cout << s.pop() << endl;
	// cout << s.pop() << endl;
	// cout << s.pop() << endl;

	Stack<char> s;

	cout << "Size : " << s.size() << endl;
	cout << "Is Empty : " << s.isEmpty() << endl;

	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');
	s.push('E');
	s.push('F');

	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << "Size : " << s.size() << endl;
	cout << "Is Empty : " << s.isEmpty() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	return 0;
}