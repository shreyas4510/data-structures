#include <iostream>
using namespace std;

int findIndex( int arr[], int size, int target, int index ) {
	if ( size == 0 ) {
		return -1;
	}
	
	if ( arr[0] == target ) {
		return index;
	}
	
	index = findIndex(arr+1, --size, target, ++index);
	return index;
}

int main() {
	int size, target;
	cin >> size;
	int* arr = new int[size];
	
	for(int i=0; i<size; i++) {
		cin >> arr[i];
	}
	cin >> target;
	
	cout << findIndex(arr, size, target, 0);
	delete [] arr;
}
