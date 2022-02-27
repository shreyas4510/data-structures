#include<iostream>
using namespace std;

int getLength( int* arr ) {
	int i=0, count=0;
	while ( arr[i] != INT_MIN ) {
		i++;
		count++;
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	
	int **array = new int*[n];
	for( int i=0; i<n; i++ ) {
		int k;
		cin >> k;
		array[i] = new int[k];
		
		int j=0;
		for ( ; j<k; j++ ) {
			cin >> array[i][j];
		}
		array[i][j] = INT_MIN;
	}
	
	for ( int i=0; i<n; i++ ) {
		for ( int j=0; j<getLength(array[i]); j++ ) {
			cout << array[i][j] << "  ";
		}
		cout << endl;
	}
}
