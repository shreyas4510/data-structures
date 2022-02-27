#include <iostream>
using namespace std;

void insertIntoArray(int arr[][100], int row, int col) {
	for( int i=0; i<row; i++ ) {
		for( int j=0; j<col; j++ ) {
			cin >> arr[i][j];
		}
	}
}

void printArray(int arr[][100], int row, int col) {
	int count = row;
	for( int i=0; i<row; i++ ) {
		for( int k=0; k<count; k++ ) {
			for( int j=0; j<col; j++ ) {
				cout << arr[i][j] << " ";	
			}
			cout << endl;
		}
		count--;
	}
}

void printArray1(int arr[][100], int row, int col) {
	int sum=0;
	for( int i=0; i<row; i++ ) {
		sum += row - i;
	}
	int count = row-1, cur=0;
	for ( int i=0; i<sum; i++ ) {
		if( i > count ) {
			count = count + row - 1 - cur;
			cur++; 
		}
		for ( int j=0; j<col; j++ ) {
			cout << arr[cur][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int arr[100][100], row, col;
	cin >> row >> col;
	
	insertIntoArray(arr, row, col);
//	printArray(arr, row, col);
	printArray1(arr, row, col);
	
}

