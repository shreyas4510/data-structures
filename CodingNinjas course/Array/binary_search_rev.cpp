#include<iostream>
using namespace std;

int binarySearch( int *arr, int start, int end, int mid, int target ) {
	if (start > end)
	{
		return -1;
	}

	if ( arr[mid] == target )
	{
		return mid;
	}

	if ( arr[start] == target )
	{
		return start;
	}

	if (arr[end] == target)
	{
		return end;
	}

	if ( arr[mid] > target )
	{
		return binarySearch( arr, start, mid-1, (start+mid-1)/2, target );
	}
	else {
		return binarySearch( arr, mid+1, end, (mid+1+end)/2, target );
	}

}

int main(int argc, char const *argv[])
{
	int n, target;

	cout << "Enter the size of array : ";
	cin >> n;

	cout << "\nEnter the target element : ";
	cin >> target;

	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	// ## Iterative approach ## //

	// int i=0, j=n-1, mid = (i+j)/2;
	// while( arr[mid] != target ) {

	// 	if (i > j) {
	// 		mid = -1;
	// 		break;
	// 	}

	// 	if (arr[i] == target)
	// 	{
	// 		mid = i;
	// 		break;
	// 	}

	// 	if (arr[j] == target){
	// 		mid = j;
	// 		break;
	// 	}

	// 	if ( arr[mid] > target ) {
	// 		j = mid-1;
	// 	}
	// 	else {
	// 		i = mid+1;
	// 	}
	// 	mid = (i+j)/2;
	// }

	// cout << "Element found at index : " << mid;

	// ## Recursive Approach ## //

	cout << binarySearch(arr, 0, n-1, (n-1)/2, target);

	return 0;
}