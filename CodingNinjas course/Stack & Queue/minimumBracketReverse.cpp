#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string inputStr;
	cin >> inputStr;

	// First Approach ( Drawback : Didnt handle edge cases )
	// stack<char> result; 
	// for (int i = 0; i < inputStr.length(); i++) {
	// 	if ((int) inputStr[i] == 125) {
	// 		result.pop();
	// 	}
	// 	else {
	// 		result.push(inputStr[i]);
	// 	}
	// }

	// if (result.size() % 2 == 0)	
	// 	cout << result.size() / 2;
	// else 
	// 	cout << -1;

	// Second Approach
	stack<char> result;
	if (inputStr.length() % 2 != 0) {
	  	cout << -1;
	  	return 0;
	}

	for (int i = 0; i < inputStr.length(); ++i) {
		if ((int) inputStr[i] == 125) {
			if (result.empty() || (int) result.top() == 125)
				result.push(inputStr[i]);
			else
				result.pop();
		}
		else 
			result.push(inputStr[i]);
	}

	if (result.size() % 2 != 0) {
		cout << -1;
	  	return 0;	
	}

	int count = 0;
	while(!result.empty()) {
		int c1 = (int) result.top();
		result.pop();
		int c2 = (int) result.top();
		result.pop();

		if (c1 == c2) {
			count ++;
		}
		else {
			count+=2;
		}
	}

	cout << count;
	return 0;
}