#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main() {
	stack<char> s;
	string brackets;
	bool flag = true;

	getline(cin, brackets);


	for( int i=0; i< brackets.length() ; i++ ) {
		char temp = brackets[i];
		int check = (int)temp;

		if ( check == 91 || check == 40 || check == 123  ) {
			s.push(temp);
		}
		
		if( check == 93 || check == 41 || check == 125 ){
			char top = s.top();
			if ( ((int)top == 91 && check == 93) || ((int)top == 40 && check == 41) || ((int)top == 123 && check == 125)) {
				s.pop();
			}
			else {
				flag = false;
				break;
			}
		}
	}
	cout << ( flag && s.empty() ? "true" : "false" );
}