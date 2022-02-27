#include <iostream>
using namespace std;

int findFibonacci(int n) {
	
	if ( n == 0 ) {
		return 0;
	}

	if ( n == 1 ) {
		return 1;
	}
	
	int firstNum = findFibonacci(n-1);
	int secondNum = findFibonacci(n-2);
	
	return firstNum + secondNum;
}

int main() {
	int n;
	cin >> n;
	
	cout << findFibonacci(n);
}
