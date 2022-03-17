#include<iostream>
using namespace std;

void removeX( char s[100] ) {
	if ( s[0] == '\0' ) { 
		return;
	}
	
	if ( s[0] == 'x' ) {
		int i=0;
		for(; s[i]!='\0'; i++ ) {
			s[i] = s[i+1];
		}
		removeX(s);
	}
	else {
		removeX(s+1);
	}
}

int getLength( char* str ) {
	if ( str[0] == '\0' ) {
		return 0;
	}
	return 1 + getLength( str+1 );
}

int main() {
	char str[100];
	cin >> str;	
	cout << getLength(str) << endl;
	removeX(str);
	cout << str << endl;
	
}
