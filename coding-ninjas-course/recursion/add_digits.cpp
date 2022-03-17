#include <iostream>
using namespace std;

int addDigits(int n) {
	int sum = 0;
	if ( n / 10 == 0 ) {
		sum += n;
		return sum;
	}
	
	sum = addDigits(n / 10);
	return sum + (n%10);
}

int main() {
	int n;
	cin >> n;
	cout << addDigits(n);
}
