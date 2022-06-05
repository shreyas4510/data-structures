#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 6, m = 4;
	int arr1[] = { 1, 5, 9, 10, 15, 20 };
	int arr2[] = { 2, 3, 8, 13 };

	// Time Limit excedded
	// int i=0, j=0;
	// while( true ) {
	// 	if ( i < n && j < m ) {
	// 		if ( arr1[i] > arr2[j] ) {
	// 			swap( arr1[i], arr2[j] );
	// 			if ( j < m-1 && arr2[j] > arr2[j+1]) {
	// 				int temp = j;
	// 				while( temp < m-1 && arr2[temp] > arr2[temp+1] ) {
	// 					swap(arr2[temp], arr2[temp+1]);						
	// 					++temp;
	// 				}
	// 			}
	// 			++i;
	// 		} else
	// 			++i;
	// 	} else {
	// 		break;
	// 	}
	// }

	// 23 27
	// 1 1 2 2 2 2 4 4 5 5 7 8 10 11 11 12 14 15 17 18 19 19 20
	// 1 2 2 3 3 4 5 5 7 7 8 8 8 9 9 10 13 13 14 15 16 17 18 18 18 19 19

	int i=0, j=0, k=n-1;
	while( i < n && j < m ) {
		if ( arr1[i] < arr2[j] )
			i++;
		else
			swap( arr1[k--], arr2[j++] );
	}

	sort(arr1, arr1+n);
	sort(arr2, arr2+m);


	for (int i = 0; i < n; i++)
		cout << arr1[i] << " ";

	for (int i = 0; i < m; i++)
		cout << arr2[i] << " ";

	cout << endl;
}