#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[100];
	cin.getline(str, 100);
	
	int max = INT_MAX, count = 0;	
	for( int i=0; i<strlen(str); i++ ) {
		if( str[i] == ' ') {
			if ( max > count )
				max = count;
			count = 0;
			continue;
		}
		count++;
	}
	
	count=0;
	for( int i=0; i<strlen(str); i++ ) {
		if( str[i] == ' ') {
			if ( max == count ){
				for( int k = i-count; k < i; k++) {
					cout << str[k];
				}	
				break;
			}
			count = 0;
			continue;
		}
		count++;
	}
}
