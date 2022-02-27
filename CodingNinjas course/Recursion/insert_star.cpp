#include<iostream>
#include<string>
using namespace std;

string insertStar( string s ) {
	if ( s.length() == 0 || s.length() == 1 ) {
		return s;
	}
	
	if( s[0] == s[1] ) {
		string temp = s.substr(1);
		string m(1, s[0]);
		s = m + "*" + temp;
	}
	
	string x( 1, s[0] );
	string resultString = x + insertStar(s.substr(1));
	return resultString;
	
}

int main() {
	string str = "aaaa";
	cout << insertStar(str);
}
