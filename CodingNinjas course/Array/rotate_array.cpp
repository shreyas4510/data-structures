#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 }, temp;
	int shift = 2;

//	First Approach
	
//	for ( int i=0; i<shift; i++ ) {
//		temp.push_back(arr[i]);
//	}
//	
//	for( int i=shift; i<arr.size(); i++ ) {
//		arr[i-shift] = arr[i];
//	}
//	
//	for( int i=0; i<shift; i++ ) {
//		arr[arr.size()-shift+i] = temp[i];
//	}
	
	
//	Second Approach
	for ( int i=0; i < (arr.size()/2); i++ ) {
		int temp = arr[i];
		arr[i] = arr[ arr.size() - i - 1];
		arr[ arr.size() - i - 1] = temp;
	}
	
	for ( int i=0; i < ((arr.size()-shift)/2); i++ ) {
		int temp = arr[i];
		arr[i] = arr[ arr.size() - shift - i - 1];
		arr[ arr.size() - shift - i - 1] = temp;
	}


	int i=(arr.size()-shift), j=arr.size()-1;
	while( i<j ) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
	
	for ( int i=0; i<arr.size(); i++ ) {
		cout << arr[i] << " ";
	}
}
