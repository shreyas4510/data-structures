#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	bool flag = true;

	stack<char> stack;
	for (int i = 0; i < s.length(); ++i) {
		if ((int)s[i] == 41) {
			int count = 0;
			while( (int)stack.top() != 40 ) {
				count++;
				stack.pop();
			}
			stack.pop();
			if (count <= 1) {
				flag = false;
				break;
			}
		}
		else if ((int)s[i] == 125) {
			int count = 0;
			while( (int)stack.top() != 123 ) {
				count++;
				stack.pop();
			}
			stack.pop();
			if (count <= 1) {
				flag = false;
				break;
			}
		}
		else {
			stack.push( s[i] );
		}
	}

	cout << ( flag ? "false" : "true" );
}