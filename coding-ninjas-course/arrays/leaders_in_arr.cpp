#include<iostream>
using namespace std;

void findLeader(int arr[], int len) {
	for ( int i=0; i<len; i++ ) {
		bool flag = false;
		for ( int j=i+1; j<len; j++ ) {
			if( arr[i] < arr[j] ) {
				flag = true;
				break;
			}
		}
		if ( !flag )
			cout << arr[i] << " ";
	}	
}

void findLeader1(int arr[], int len) {
	int temp[100]={0}, right_max, index = 1;
	
	temp[0] = arr[len-1];
	right_max = arr[len-1];
	for( int i=len-2; i>=0; i-- ) {
		if( right_max < arr[i] ) {
			temp[index] = arr[i];
			right_max = arr[i];
			index++;
		}
	}
	
	for( int i=(index -1); i>=0; i-- ) {
		cout << temp[i] << " ";
	}
}

int main() {
	int len;
	cin >> len;
	int arr[len];
	
	for( int i=0; i<len; i++ ) {
		cin >> arr[i];
	}
	
//	findLeader(arr, len);
	findLeader1(arr, len);
}
