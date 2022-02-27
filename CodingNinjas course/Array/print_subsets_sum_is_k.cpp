#include<iostream>
#include<vector>
using namespace std;

void printSubsets( vector<int>& arr, int target, vector<int> temp, int index ) {
	if ( arr.size() == index ) {
		if ( target == 0 ) {
			for ( int i=0; i < temp.size(); i++ ) {
				cout << temp[i] << " ";
			}
			cout << endl;	
		}
		return;
	}
	printSubsets( arr, target, temp, index+1 );
	temp.push_back( arr[index] );
	printSubsets( arr, target-arr[index], temp, index+1 );
	return;
}

int main() {
	int target = 6;
	vector<int> arr = { 5, 12, 3, 17, 1, 18, 15, 3, 17 }, temp={};	
	printSubsets(arr, target, temp, 0);
}

