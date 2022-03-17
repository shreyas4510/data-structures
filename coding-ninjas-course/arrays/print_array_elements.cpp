#include<iostream>
using namespace std;

int printArrayElements(int *arr, int index) {
	
	if ( index == 6 ) { 
		return 0;
	}
	
	index ++;
	printArrayElements(arr, index);
	cout << arr[index-1] << endl;
	return 0;
}

int main() {
	int * p = new int[6];
	
	for ( int i=0; i<6; i++ ) {
		cin >> *( p+i );
	}
	printArrayElements(p, 0);
}
