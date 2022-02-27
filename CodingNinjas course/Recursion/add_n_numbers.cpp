#include<iostream>
using namespace std;

int addNnumbers( int n ) {
	if ( n == 1 ) {
		return 0;
	}
	int x = addNnumbers(--n);
	return x + n;
}

int main() {
	int n;
	cin >> n;
	
	cout << addNnumbers(n+1);
}
