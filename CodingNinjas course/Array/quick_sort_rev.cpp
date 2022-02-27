#include<iostream>
#include <vector>
using namespace std;

void quickSort( vector<int> &arr, int start, int end ) {

	if ( start > end ) {
		return;
	}

	int count = 0;
	for (int i = start; i < end; ++i)
	{
		if (arr[i] < arr[end])
			count++;
	}

	int temp = arr[start + count];
	arr[start + count] = arr[end];
	arr[end] = temp;

	int i=start, j=start+count+1;
	while( i < start+count ) {
		if ((arr[i] > arr[start+count]) && (arr[j] < arr[start+count])) {
			int sub = arr[i];
			arr[i] = arr[j];
			arr[j] = sub;
		}

		if (arr[i] < arr[start+count]) {
			i++;
		}

		if ( arr[j] > arr[start+count] ) {
			j++;
		}
	}

	quickSort(arr, start, start+count-1);
	quickSort(arr, start+count+1, end);
}

int main()
{
	vector<int> arr = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
	quickSort(arr, 0, arr.size()-1);

	for (int i : arr) {
		cout << i << " ";
	}

	return 0;
}