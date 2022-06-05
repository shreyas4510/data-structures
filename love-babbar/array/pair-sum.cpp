#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = 6, k = 7;

	// O( n^2 )
	unordered_map<int, int> pairs;
	int count = 0;

	for (int i = 0; i < n; i++) {
		int diff = k - arr[i]; 
		if ( pairs[k] ) {
			count += pairs[k];
		}
		pairs[arr[i]]++;
		
	}
	cout << count << endl; 

	// sort(arr, arr+n);
	// int i=0, j=n-1, counter=0;

	// while( i < j ) {
	// 	int temp = arr[i] + arr[j];
	// 	if ( temp == k ) {
	// 		counter++;
	// 		if ( arr[i] == arr[i+1] )
	// 			i++;
	// 		else if ( arr[j] == arr[j-1] )
	// 			j--;
	// 		else {
	// 			i++;
	// 			j--;
	// 		}

	// 	} else if ((arr[i] + arr[j]) > k)
	// 		j--;
	// 	else
	// 		i++;
	// }
	// cout << counter << endl;
	// return 0;
}