#include <iostream>
using namespace std;

int printFibonacci(int n) {
	
	if ( n == 0 ) {
		return 0;
	}
	
	if ( n == 1 ) {
		return 1;
	}
		
	int out1 = printFibonacci(n-1);
	int out2 = printFibonacci(n-2);
	return out1 + out2;
	
} 

int main() {
	int n;
	cin >> n;
	cout << printFibonacci(n);
}
