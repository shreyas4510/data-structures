#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int* arr = new int[n];
	for ( int i=0; i<n; i++ ) {
		cin >> arr[i];
	}
	
	int max = INT_MIN;
	for ( int i=0; i<n; i++ ) {
		if ( max < arr[i] )
			max = arr[i];
	}
	cout << max << endl;
	delete [] arr;
}
