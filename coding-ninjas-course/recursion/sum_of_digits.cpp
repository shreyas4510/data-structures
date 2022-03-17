#include <iostream>
using namespace std;

int addDigits( int n ) {
	if ( n / 10 == 0 ) { 
		return n;
	}
	
	int sum = 0;
	sum = (n%10) + addDigits(n/10);
	return sum;
}

int main() {
	int n;
	cin >> n;
	cout << addDigits(n);
}
