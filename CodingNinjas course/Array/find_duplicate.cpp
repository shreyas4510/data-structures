#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v = { 0, 3, 1, 5, 4, 3, 2 };
	
	// First Approach
	
	//	sort(v.begin(), v.end());
	//	for ( int i=0; i<v.size(); i++ ) {
	//		if( v[i] == v[i+1] ) {
	//			cout << v[i];
	//			break;
	//		}
	//	}
	
	// Second Approach
	
	int sum=0;
	for( int i=0; i<v.size(); i++ ) {
		sum += v[i];
	}
	
	int temp = ((v.size()-2) *(v.size() + -1))/2;
	cout << sum-temp;
}
