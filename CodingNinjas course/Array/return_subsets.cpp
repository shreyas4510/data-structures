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

int getSize ( int n ) {
	int ans = 2;
	while ( n > 0 ) {
		ans = ans*2;
		n--;
	}
	return ans;
}

int returnSubsets(int* arr, int len, int** output) {
	if ( len == 0 ) {
	    output[0] = new int[1];
		output[0][0] = INT_MIN;
		return 1;
	}
	int size = returnSubsets(arr+1, len-1, output);
	for ( int i=size; i < 2*size; i++ ) {
		int length = getLength(output[i-size]);
		output[i] = new int[length+2];	
		output[i][0] = arr[0];
		int j=1;
		for ( ; j < length+1 ; j++ ){
			output[i][j] = output[ i-size ][j-1];
		}
		output[i][j] = INT_MIN;
	}
	return 2*size;
}

int main() {
	int n;
	cin >> n;
	
	int* arr = new int[n];
	for ( int i=0; i<n; i++ ) {
		cin >> arr[i];
	}
	
	int **output = new int*[getSize(n)];
	int size = returnSubsets( arr, n, output );
	
	for ( int i=0; i<size; i++ ) {
		for ( int j=0; j< getLength(output[i]); j++ ) {
			cout << output[i][j] << "  ";
		}
		cout << endl;
	}
	
	for ( int i=0; i<size; i++ ) {
		delete [] output[i];
	}
	delete [] output;
	delete [] arr;
}
