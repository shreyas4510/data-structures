#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = { 1, 2, 4, 5, 6, 6, 6 };
	int n = 7;
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if( max < arr[i] )
			max = arr[i];

		if( min > arr[i] )
			min = arr[i];
	}
	cout << max + min << endl;
}	