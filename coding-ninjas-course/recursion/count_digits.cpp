#include<iostream>
using namespace std;

int countNumber(int n) {
	
	int count = 0;
	if ( n / 10 == 0) {
		return 1;
	}	
	count = countNumber(n/10);
	return ++count;
}

int main() {
	int n;
	cin >> n;
	cout << countNumber(n);
}
