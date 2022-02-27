#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> array = {12, 3, 1, 2, -6, 5, -8, 6};
	int target = 0;
	sort(array.begin(), array.end());
	
	vector<vector<int>> tripletSums;
	for(int i=0; i<array.size()-3; i++) {
		int start = i+1, end = array.size() - 1;
		while ( start < end ) {
			int sum = array[i] + array[start] + array[end]; 
			if( (array[start] + array[end]) <= (target-array[i]) ) {
				if ( sum == target ) {			

					vector<int> temp;
					temp.push_back(array[i]);
					temp.push_back(array[start]);
					temp.push_back(array[end]);			

					tripletSums.push_back(temp);
				}
				start++;
			}
			else {
				end--;
			}
		}
	}

	cout << "[";
	for( int i=0; i<tripletSums.size(); i++ ) {
		cout << "[";
		for ( int j=0; j<tripletSums[i].size(); j++ ) {
			cout << tripletSums[i][j] << ( j!=tripletSums[i].size()-1 ? "," : "" );
		}
		cout << "]";
	}
	cout << "]";

}
