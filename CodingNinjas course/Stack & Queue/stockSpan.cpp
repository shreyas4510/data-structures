#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	// n^2 complexity

	// int size;
	// stack<int> s;

	// cin >> size;
	// for (int i = 0; i < size; ++i) {
	// 	int input;
	// 	cin >> input;
	// 	s.push(input);
	// }

	// stack<int> result;
	// while( !s.empty() ) {
	// 	stack<int> temp = s;
	// 	int top = temp.top();
	// 	temp.pop();
	// 	int count = 1;
	// 	while( !temp.empty() && temp.top() < top ) {
	// 		count++;
	// 		temp.pop();
	// 	}
	// 	result.push(count);
	// 	s.pop();
	// }

	// while( !result.empty() ) {
	// 	cout << result.top() << " ";
	// 	result.pop();
	// }


	int len;
	vector<int> v, result;
	cin >> len;
	for (int i = 0; i < len; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	stack<int> maxIndexStack;
	for( int i=0; i<v.size(); i++ ) {
		int count = 1;
		while( !maxIndexStack.empty() && v.at(i) > v.at(maxIndexStack.top())) {
			maxIndexStack.pop();
			count++;
			if (maxIndexStack.empty()) {
				count = i+1;
			}
		}
		maxIndexStack.push(i);
		result.push_back(count);
	}

	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
	}
}