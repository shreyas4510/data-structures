#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v = { 2,7,11,15 };
	int target = 9;	
	bool flag = false;
	
	vector<int> pair;
	for ( int i=0; i<nums.size(); i++ ) {
		for ( int j=i+1; j<nums.size(); j++ ) {
			if ( nums[i] + nums[j] == target ) {
				pair.push_back(i);
				pair.push_back(j);
				flag=true;
				break;
			}
		}
		if ( flag ) {
			break;
		} 
	}

}

