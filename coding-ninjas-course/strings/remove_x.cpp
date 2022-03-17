#include<iostream>
#include<string>
using namespace std;

void removeX( string s ) {
	if ( s.length() == 0 ) {
		return;
	} 
	
	if ( s[0] != 'x' ) {
		cout << s[0];
	}
	removeX(s.substr(1));
}

int main() {
	string str = "abc";
	removeX(str);
}
