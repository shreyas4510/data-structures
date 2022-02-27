#include<iostream>
using namespace std;

void replaceWords( char s[100], char target, char dest ) {
	if (s[0] == '\0') {
		return;
	}
	
	if ( s[0] == target ) {
		s[0] = dest;
	}
	replaceWords(s+1, target, dest);
}

int main() {
	char str[100], target, dest;
	cin >> str;
	cin >> target >> dest;
	replaceWords( str, target, dest );
	cout << str;
	
}
