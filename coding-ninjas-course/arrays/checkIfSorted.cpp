#include <iostream>
using namespace std;

bool checkArraySorted(int arr[], int size) {
	if ( size == 0 || size == 1 ) {
		return true;
	}
	
	if ( arr[0] > arr[1] ) {
		return false;
	}
	
	return checkArraySorted(arr + 1, --size);
	
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = 8;
	
	cout << (checkArraySorted(arr, size) ? "Sorted" : "UnSorted");
}
