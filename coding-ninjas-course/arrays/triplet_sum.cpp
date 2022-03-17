#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr = { 2, -5, 8, -6, 0, 5, 10, 11, -3 };
	int target = 10, count=0;
	sort(arr.begin(), arr.end());
	
	for( int i=0; i<arr.size() - 2; i++ ) {
		int j=i+1, k=arr.size()-1, tempSum = target-arr[i];
		while ( j<k ) {
			if( arr[j] + arr[k] <= tempSum ) {
				if( arr[j] + arr[k] == tempSum ) {
					count++;
					int temp = k-1;
					while( arr[j] == arr[temp] && j < temp ) {
						count++;
						temp--;
					}
				}
				j++;
			}
			else {
				k--;
			}
		}
	}
	
	cout << count;
}
