#include <iostream>
using namespace std;

int printFibonacciSeries(int n, int prev, int cur) {
	if ( n == 0 ) {
		return 0;
	}

	cout << cur << " ";	
	int temp = prev;
	prev = cur;
	cur = temp + prev;
	
	printFibonacciSeries(--n, prev, cur);	
	return 0;
}

int main() {
	int n;
	cin >> n;
 	printFibonacciSeries(n, 1, 0);
}
