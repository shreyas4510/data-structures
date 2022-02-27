#include<iostream>
using namespace std;

int getSubsequences( string s, string* subs ) {
	if ( s.empty() ) {
		subs[0] = "";
		return 1;
	}
	
	int n = getSubsequences(s.substr(1), subs);
	for( int i=n; i<2*n; i++ ) {
		subs[i] = s[0] + subs[i-n];
	}
	return 2*n;
}

int main() {
	string s="abc";
//	cin >> s;
	string* subs = new string[1000];
	int len = getSubsequences( s, subs );
	
	cout << "[ ";
	for ( int i=0; i<len; i++ ) {
		cout << subs[i] << ",  ";
	}
	cout << "]" << endl;
}
