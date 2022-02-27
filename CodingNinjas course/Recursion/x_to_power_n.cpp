#include <iostream>
using namespace std;

int square(int n, int *r) {
	if ( (*r) == 0 ) {
		return 1;		
	}
	
	int k;
	(*r)--;
	k = square(n, r);
	return k*n; 
}

int main() {
	int n, r;
	cin >> n >> r;
	
	cout << square(n, &r);
}
