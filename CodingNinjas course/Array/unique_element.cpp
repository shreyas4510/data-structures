#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr = { 1, 3, 1, 3, 6, 6, 7, 10, 7 };
	
	// First Approach
	//	sort(arr.begin(), arr.end());
	//	for ( int i=0; i<arr.size(); i++ ) {
	//		if ( arr[i] != arr[i+1] && arr[i] != arr[i-1]) {
	//			cout << arr[i];
	//			break; 
	//		}
	//	}

	int unique=0;
	for ( int i=0; i<arr.size(); i++ ) {
		unique = unique^arr[i];
	}
	cout << unique;
}
