#include<iostream>
using namespace std;

int partition( int *a, int si, int ei ) {
	int count = 0;
	for( int i=si+1; i<=ei; i++ ) {
		if ( a[i] < a[si] ) {
			count++;
		}
	}
	
	int placeHolder = a[si];
	a[si] = a[si + count];
	a[si + count] = placeHolder;
	
	int i=si, j=ei;
	while ( i<(si+count) && j>(si+count) ) {
		
		if (a[i] < a[si+count]) {
			i++;
		}
		
		if (a[j] > a[si+count]) {
			j--;
		}
		
		if ( (a[i] > a[si+count]) && (a[j] < a[si+count]) ) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	return count+si;
}

void quickSort( int *a, int si, int ei ) {
	if( si >= ei ) {
		return;
	}
	
	int point = partition( a, si, ei );
	quickSort(a, si, point-1);
	quickSort(a, point+1, ei);
}

int main() {
	int a[10] = { 38, 27, 43, 3, 9, 82, 10, 93, 1, 54 };
	quickSort(a, 0, 9);
	
	cout << "Sorted Array : [ ";
	for ( int i=0; i<=9; i++ ) {
		cout << a[i] << " ";
	}
	cout << "] \n";
}
