#include<iostream>
using namespace std;

bool checkElement( int arr[], int size, int target ) {
	
	if ( size == 0 ) {
		return false;
	}
	
	if ( arr[0] == target ) {
		return true;
	}
	
	bool result = checkElement( arr+1, --size, target );
	return result;
}

int main() {
	int size, target;
	cin >> size;
	int* arr = new int[size];
	
	for ( int i=0; i<size; i++ ) {
		cin >> arr[i];
	}
	
	cin >> target;
	cout << (checkElement(arr, size, target) ? "true" : "false" );
	delete [] arr;
}
