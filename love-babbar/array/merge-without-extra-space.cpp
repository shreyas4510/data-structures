#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr1[] = { 13, 21, 25, 25, 25, 28, 30, 30, 34, 35, 36, 39, 49, 49 }, arr2[] = { 10, 29 };
	int n = 14, m = 2;

	int i=0, j=0, k=n-1;
	while( i <= k && j < m ) {
		if ( arr1[i] > arr2[j] ) {
			int temp = arr1[k];
			arr1[k] = arr2[j];
			arr2[j] = temp;

			k--;
			j++;
		} else {
			i++;
		}
	}

	sort(arr1, arr1+n);
	sort(arr2, arr2+m);

	for (int i = 0; i < n; ++i) {
		cout << arr1[i] << " ";
	}

	for (int i = 0; i < m; ++i) {
		cout << arr2[i] << " ";
	}
	cout << endl;
}