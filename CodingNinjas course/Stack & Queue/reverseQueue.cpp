#include <iostream>
#include <queue>
using namespace std;

void reverseQueue( queue<int> *q ) {

	if (q -> empty()) {
		return;
	}

	int temp = q -> front();
	q -> pop();
	reverseQueue(q);
	q -> push(temp);
}

int main()
{
	queue<int> *q = new queue<int>();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		q -> push(temp);
	}

	reverseQueue(q);
	while( !q -> empty() ) {
		cout << q -> front() << " ";
		q -> pop();
	}

	delete q;
	return 0;
}