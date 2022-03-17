#include<iostream>
using namespace std;

int binarySearch( int* numbers, int start, int end, int target ){
	
	if (start > end)
		return -1;
	
	if ( numbers[start] == target )
		return start;
	
	if ( numbers[end] == target )
		return end;
		
	int mid = (start + end) / 2;
	if ( numbers[mid] == target ) 
		return mid;
	
	return binarySearch( numbers, ( numbers[mid] > target ? start : mid+1 ), ( numbers[mid] > target ? mid-1 : end ), target );
}

int main() {
	int arr[] = { 2, 3, 4, 5, 6, 8 };
	cout << binarySearch(arr, 0, 5, 8);
}
