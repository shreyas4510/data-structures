#include <bits/stdc++.h>
#include "./priority-queue.h"
using namespace std;

int main() {

	priorityQueue obj;
	
	// check if empty
	// cout << obj.isEmpty() << endl;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		obj.insert(input);
	}

	cout << endl;
	obj.print();
	cout << endl;

	cout << "Minimum Element : " << obj.getMin() << endl;
	cout << "Size : " << obj.getSize() << endl;

	for (int i = 0; i < 2; ++i) {
		obj.removeMin();
		cout << endl;
		obj.print();
		cout << endl;

		cout << "Minimum Element : " << obj.getMin() << endl;
		cout << "Size : " << obj.getSize() << endl;
	}

	return 0;
}