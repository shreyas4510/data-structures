#include <iostream>
using namespace std;

class queue {
	int *data, nextIndex, firsIndex, size, capacity;
	
	public :
		queue( int size ) {
			data = new int[size];
			nextIndex = 0;
			firsIndex = 0;
			capacity = size;
			this -> size = 0;
		}

		int getSize() {
			return size;
		}

		bool isEmpty() {
			return size == 0;
		}

		int front() {
			if (size == 0) {
				cout << "Queue Empty front" << endl;
				return 0;
			}
			return data[firsIndex];
		}

		void enqueue( int data ) {
			if (capacity == size) {
				cout << "Queue full" << endl;
				return;
			}

			if( nextIndex == capacity && size != capacity ) {
				nextIndex = 0;
			}

			this -> data[nextIndex] = data;
			nextIndex++;
			size++; 
		}

		dequeue() {
			if (size == 0) {
				cout << "Queue Empty dequeue" << endl;
				return 0;
			}
			cout << "dequeued successfully" << endl;
			firsIndex++;
			if (firsIndex == capacity && size != 0) {
				firsIndex = 0;
			}
			size--;
		}
};

int main()
{
	queue q(5);
	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	q.dequeue();
	q.enqueue(6);
	q.enqueue(7);

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.front();

	return 0;
}

// enqueue
// front
// size
// dequeue
// isEmpty