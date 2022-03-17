#include<iostream>
using namespace std;

void printArray( int* output, int outLen ) {
	for( int i=0; i<outLen; i++ ) {
		cout << output[i] << "   ";
	}
	cout << endl;
}

int* helperFunction( int* output, int outLen, int target ) {
	int* helperArr = new int[outLen+1];
	for ( int i=0; i< outLen; i++ ) {
		helperArr[i] = output[i];
	}
	helperArr[outLen] = target;
	return helperArr;
}

void printSubsets(int* arr, int len, int* output, int outLen) {
	if(len == 0){
		printArray(output, outLen);
		return;
	}
	
	printSubsets( arr+1, len-1, output, outLen );
	printSubsets( arr+1, len-1, helperFunction(output, outLen, arr[0]) , outLen+1 );
}

int main() {
//	int n;
//	cin >> n;
//	int* arr = new int[n];
//	int* output = new int[n];

	int n=3;
	int arr[] = {15, 20, 12};
	int* output = new int[n];
	printSubsets( arr, n, output, 0 );
}
