#include<iostream>
using namespace std;

double getGeometricSum( int n, int divider = 2 ) {
	if ( n == 0 ) {
		return 1;
	}
	
	double sum = 0.0;
	return (getGeometricSum( --n, divider*2 ) + ( 1.0 / divider ));
}

int main() {
	int n;
	cin >> n;
	cout << getGeometricSum(n);
}
