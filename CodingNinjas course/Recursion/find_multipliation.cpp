#include<iostream>
using namespace std;

int findMultiplication( int n1, int n2 ) {
	if ( n2 == 0 ) {
		return 0;
	}
	int sum = 0;
	sum = n1 + findMultiplication( n1, --n2 );
	return sum;
}

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	cout << findMultiplication(num1, num2);
}
