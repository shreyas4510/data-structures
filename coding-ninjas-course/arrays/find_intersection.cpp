#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> firstArr = { 2, 6, 8, 5, 4, 3 }, secondArr = { 2, 3, 4, 7 };
	
	sort(firstArr.begin(), firstArr.end());
	sort(secondArr.begin(), secondArr.end());
	
	int i=0, j=0;
	while( i<firstArr.size() && j < secondArr.size() ) {
		if ( firstArr[i] < secondArr[j] ) {
			i++;
		}
		else if ( firstArr[i] > secondArr[j] ) {
			j++;
		}
		else {
			cout << firstArr[i] << " ";
			i++;
			j++;
		}
	}
}
