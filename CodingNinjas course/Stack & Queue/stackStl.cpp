#include<iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[]) {
	stack<int> s;
	cout << s.size() << endl;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);

	cout << "isEmpty : " << s.empty() << endl;

	s.pop();
	s.pop();
	s.pop();
	s.pop();

	cout << s.top() << endl;

	s.pop();
	cout << s.top() << endl;

	s.pop();
	s.pop();
	s.pop();

	return 0;
}