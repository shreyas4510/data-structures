#include<iostream>
using namespace std;

int fillArray( int** output, int outputLen, int* tempArr, int tempOutputLen ) {
//	output[0] = new int*[100];
	for( int i=0; i<tempOutputLen; i++ ) {
		output[outputLen][i] = tempArr[i];
	}
	return outputLen+1;	
}

int* helperFunction( int* output, int outputLen, int target ) {
	int* helperArr = new int[outputLen+1];
	for( int i=0; i<outputLen; i++ ) {
		helperArr[i] = output[i];
	}
	helperArr[outputLen] = target;
	return helperArr;
} 

int returnSubsets( int* numbers, int inputLen, int *tempOutput, int tempOutputLen, int **output, int outLen, int target ) {
	if ( inputLen == 0 ) {
		if ( target == 0 ) {
			outLen = fillArray(output, outLen, tempOutput, tempOutputLen);
		}
		return outLen;
	}
	
	outLen = (numbers+1, inputLen-1, tempOutput, tempOutputLen, output, outLen, target);
	outLen = (numbers+1, inputLen-1, helperFunction(tempOutput, tempOutputLen, numbers[0]), tempOutputLen, output, outLen, target-numbers[0]);
	
	return outLen;
}

int main() {
	int n, target;
	cin >> n;
	int *number = new int[n];
	for( int i=0; i<n; i++ ) {
		cin >> number[i];
	}
	cin >> target;
	
	int **output = new int*[1000];
	int size = returnSubsets( number, n, {}, 0, output, 0, target);
}
