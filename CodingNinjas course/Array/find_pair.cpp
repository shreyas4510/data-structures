#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

void printPair( int begin, int end, vector<int> v, int target ) {
	if ( begin >= end ) {
		return;
	}
	
	int sum = v[begin] + v[end];
	if( sum <= target ) {
		if ( sum == target ) {
			cout << "[ " << v[begin] << ", " << v[end] << " ]" << endl;
		}
		begin++;		
	}
	else {
		end--;
	}
	printPair(begin, end, v, target);
}
 
int main() {
	vector<int> v = { 3, 5, -4, 8, 11, 1, -1, 6 };
	sort ( v.begin(), v.end() );
	int target = 10;
	printPair(0, v.size()-1, v, target);
}

