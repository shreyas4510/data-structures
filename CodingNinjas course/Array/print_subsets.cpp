#include<iostream>
using namespace std;

void printSubSets(int *arr, int len, string output) {
	if ( len == 0 ) {
		cout << output << endl;
		return;
	}
	
	printSubSets(arr+1, len-1, output);
	printSubSets(arr+1, len-1, output += " " + to_string(arr[0]));
	
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for ( int i=0; i<n; i++ ) {
		cin >> arr[i];
	}
	printSubSets( arr, n, "" );
	delete [] arr;
}
