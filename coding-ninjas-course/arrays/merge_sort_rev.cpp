#include <iostream>
using namespace std;

void mergeSort( int* arr, int start, int end, int* output ) {

	if (start == end) { 
		output[start] = arr[start];
		return;	
	}

	int mid = ( start + end ) / 2;
	mergeSort( arr, start, mid, output );
	mergeSort( arr, mid+1, end, output );

	int i=start, j=mid+1, count=0;
	while( (i<mid+1) || (j<=end) ) {
		if (i >= mid+1)
		{
			output[start+count] = arr[j];
			j++;	
		}
		else if (j > end) {
			output[start+count] = arr[i];
			i++;
		}
		else if (arr[i] < arr[j] ) {
			output[start+count] = arr[i];
			i++;
		}
		else {
			output[start+count] = arr[j];
			j++;	
		}
		count++;
	}
	
	for( int i=start; i<=end; i++ ) {
		arr[i] = output[i];
	}

}

int main()
{
	int arr[8] = { 7, 3, 2, 16, 24, 4, 11, 9 }, len = 8, output[8];
	mergeSort( arr, 0, len-1, output );

	for( int i=0; i<len; i++ ) {
		cout << output[i] << " ";
	}

	return 0;
}