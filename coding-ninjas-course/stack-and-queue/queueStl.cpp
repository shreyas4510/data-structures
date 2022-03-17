#include<iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[]) {
	queue<int> q;
	cout << q.size() << endl;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	cout << "isEmpty : " << q.empty() << endl;

	q.pop();
	q.pop();
	q.pop();
	q.pop();

	cout << q.front() << endl;

	q.pop();
	cout << q.front() << endl;

	q.pop();
	q.pop();
	q.pop();
	cout << q.front() << endl; // garbage value when queue is empty

	return 0;
}