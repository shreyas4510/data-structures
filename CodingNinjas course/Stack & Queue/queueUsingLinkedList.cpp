#include <iostream>
#include "queueLLTemplate.h"
using namespace std;

int main() {
	Queue<int> q;
	cout << q.getSize() << endl;
	cout << (q.isEmpty() ? "true" : "false") << endl;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);

	cout << q.getSize() << endl;
	cout << (q.isEmpty() ? "true" : "false")<< endl;

	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();


}