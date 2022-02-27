#include<iostream>
using namespace std;

int addAllElements( int arr[], int size ) {
	int sum = 0;
	if ( size == 1 ) {
		sum += *(arr);
		return sum;
	}
	sum = addAllElements((arr + 1), --size) + *(arr);
	return sum;
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	cout << addAllElements(arr, 5);
}
