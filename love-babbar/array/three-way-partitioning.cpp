#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = {6,22,68,5,14,62,55,27,60,45,3,3,7,85};
	int a = 22, b = 64, n = 14;

	int i=0;
	for (int k = 0; k < n; ++k) {
		if ( arr[k] < a ) {
			swap(arr[k], arr[i]);
			i++;
		}
	}

	int j = n-1;
	while( arr[j] > b )
		j--;

	for (int k = i; k < j; ++k) {
		if ( arr[k] > b ) {
			swap(arr[k], arr[j]);
			j--;
			k--;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}