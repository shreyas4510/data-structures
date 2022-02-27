#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v1 = { 2, 2, 2, 2, 2 };
	int target = 4, count=0;
	sort(v1.begin(), v1.end());
	
	int i=0, j=v1.size()-1;
	while( i < j ) {
		if ( v1[i] + v1[j] <= target ) {
			if ( v1[i] + v1[j] == target ) {
				count++;
				int temp = j-1;
				while ( v1[temp] == v1[j] && i < temp ) {
					count++;
					temp--;
				}
			}
			i++;
		}
		else {
			j--;
		}
	}
	
	cout << count;
}
