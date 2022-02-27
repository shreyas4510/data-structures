#include <iostream>
using namespace std;

// HEAD RECURSION
//int findLastIndex( int* numbers, int size, int target ) {
//	if ( size == 0 ) {
//		return -1;
//	}
//	
//	if ( numbers[size - 1] == target ) {
//		return size - 1;
//	}
//	
//	int ans = findLastIndex(numbers, --size, target);
//	return ans;
//}

// TAIL RECURSION
int findLastIndex( int* numbers, int size, int target ) {
	if ( size == 0 ) {
		return -1;
	}
	
	int ans = findLastIndex(numbers+1, --size, target);	
	if ( *numbers == target && ans == -1 ) {
		ans = size;
	}
	
	return ans;
}

int main() {
	int size, target;
	cin >> size;

	int *numbers = new int[size];
	for ( int i=0; i<size; i++ ) {
		cin >> numbers[i];
	}
	cin >> target;
	int result = findLastIndex(numbers, size, target);
	cout << ( result == -1 ? -1 : ( size - result - 1 ));
	
	delete [] numbers; 
}
