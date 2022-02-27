#include<iostream>
using namespace std;

void fillArray( int* tempArr, int tempLen, int** output, int outLen ) {
	// fill output array
	output[outLen] = new int[tempLen+1];
	for ( int i=0; i<tempLen; i++ ) {
		output[outLen][i] = tempArr[i]; 
	}
	output[outLen][tempLen] = INT_MIN;
	
}

int getLength( int* arr ) {
	int i=0;
	while( arr[i] != INT_MIN ) {
		i++;
	}
	return i;
}

int returnSubsets( int* arr, int len, int** output, int outLen, int* tempArr, int tempLen, int target, bool flag ) {
	if( len == 0 ) {
		// fill array
		if ( target == 0 ) {
			fillArray( tempArr, tempLen, output, outLen );
			tempArr = {};
			tempLen = 0;	
			return outLen+1;
		}
		else {
			if ( flag ) {
				tempArr = {};
				tempLen = 0;
			}
		}
		return outLen;
	}
	
	outLen = returnSubsets( arr+1, len-1, output, outLen, tempArr, tempLen, target, false );
	tempArr[tempLen] = arr[0];
	outLen = returnSubsets( arr+1, len-1, output, outLen, tempArr, tempLen+1, target-arr[0], true);
	
	return outLen;
}

int main() {
	int n=8, target=10;
	int arr[] = { 3, 5, -4, 8, 11, 1, -1, 6 };
	
	int** output = new int*[100];
	int* tempArr = new int[100];
	
	int size = returnSubsets(arr, n, output, 0, tempArr, 0, target, false);
	cout << "Output Array size is : " << size << endl;
	
	for ( int i=0; i<size; i++ ) {
		for (int j=0; j< getLength(output[i]); j++) {
			cout << output[i][j] << "  ";
		}
		cout << endl;
	}
	
}
