#include<iostream>
using namespace std;

int staircase( int n ) {
	if ( n == 0 ) 
		return 1;
	
	if ( n < 0 )
		return 0;
		
	int count = 0;
	
	for ( int i=1; i<4; i++ ) {
		count = count + staircase(n - i);
	}
	return count;
}

int main() {
	int n = 5;
	cout << staircase(n);
}
