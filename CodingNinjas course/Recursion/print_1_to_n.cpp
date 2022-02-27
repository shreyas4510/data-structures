#include <iostream>
using namespace std;

int printN(int n) {
	if ( n == 0 ) {
		return 1;
	}
	printN(--n); 
	cout << n+1 << " ";
	return n;
}

int main(){ 
	int n;
	cin >> n;
	
	printN(n);
}
