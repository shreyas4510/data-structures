#include<iostream>
#include<string>
using namespace std;

bool checkPalindrom( string str ) {
	if ( str.length() == 0 || str.length() == 1 ) {
		return true;
	}
	
	if ( str[0] != str[str.length() - 1] ) {
		return false;
	}
	
	bool ans = checkPalindrom(str.substr( 1, str.length() - 2 ));
	return ans;
}

int main() {
	string str;
	cin >> str;
	cout << ( checkPalindrom(str) ? "true" : "false" );
}
