#include <iostream>
using namespace std;

void printIndices( int *numbers, int size, int target, int index = 0 ) {
	if ( size == 0 ) {
		return;
	}
	
//	cout << *numbers << "\t" << (*numbers == target) << endl;
	if ( *numbers == target) {
		cout << index << " ";
	} 
	printIndices(numbers+1, size-1, target, index+1);
	return;
}

int main() {
	int size, target;
	cin >> size;
	int *numbers = new int[size];
	
	for ( int i=0; i<size; i++ ) {
		cin >> *(numbers + i);
	}
	cin >> target;
	printIndices(numbers, size, target);
	
}
