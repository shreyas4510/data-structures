#include <iostream>
#include "dynamicQueue.h"
using namespace std;

int main()
{
	DynamicQueue<int> dq(5);

	cout << dq.getSize() << endl;
	cout << dq.isEmpty() << endl;

	dq.enqueue(1);	
	dq.enqueue(2);	
	dq.enqueue(3);	
	dq.enqueue(4);
	dq.enqueue(5);
	dq.enqueue(6);		
	dq.enqueue(7);	
	dq.enqueue(8);	
	dq.enqueue(9);	
	dq.enqueue(10);	
	dq.enqueue(11);	

	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();		
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();		
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();		
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();		
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();		
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();
	cout << dq.front() << "\t" << dq.getSize() << "\t" << dq.isEmpty() << endl;
	dq.dequeue();
	return 0;
}