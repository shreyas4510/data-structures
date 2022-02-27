#include<iostream>
#include<string>
using namespace std;

void removeDuplicates( char s[100] ) {
	if ( s[0] == '\0' ) {
		return;
	}
	
	if ( s[0] == s[1] ) {
		for ( int i = 0; s[i]!='\0'; i++ ) {
			s[i] = s[i+1];
		}
		removeDuplicates(s);
	} 
	else {
		removeDuplicates(s+1);
	}
}

int main() {
	char str[100];
	cin >> str;
	removeDuplicates(str);
	cout << str;
}
