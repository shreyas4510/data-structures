#include<iostream>
using namespace std;

void merge( int *a, int si, int ei ) {
	int i=si, j=((si + ei)/2)+1;
	int tempArr[ ei - si + 1 ];
	
	for( int k=0; k<(ei - si + 1); k++ ) {
		if ( i > ((si + ei)/2) ) {
			tempArr[k] = a[j];
			j++; 
		}
		else if( j > ei ) {
			tempArr[k] = a[i];
			i++;
		}
		else {
			if( a[i] < a[j] ) {
				tempArr[k] = a[i];
				i++;
			}
			else {
				tempArr[k] = a[j];
				j++;
			}
		}
	}
	
	int m=0;
	for( int x=si; x<=ei; x++ ) {
		a[x] = tempArr[m];
		m++;
	}
}

void mergeSort( int *a, int si, int ei ) {
	if ( si >= ei ) {
		return;
	}
	
	if ( ei == si+1 ) {
		if( a[si] > a[ei] ) {
			int temp = a[si];
			a[si] = a[ei];
			a[ei] = temp;
		}
		return;
	}
	
	int mid = (si+ei)/2;
	mergeSort( a, si, mid );
	mergeSort( a, mid+1, ei );
	merge(a, si, ei);
	
}

int main() {
	int a[10] = { 38, 27, 43, 3, 9, 82, 10, 93, 1, 54 };

	mergeSort(a, 0, 9);
	for ( int i=0; i<10; i++ ) {
		cout << a[i] << " ";
	}
}
