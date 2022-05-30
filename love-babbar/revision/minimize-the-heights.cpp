#include <bits/stdc++.h>
using namespace std;

// incorrect solution

int main() {
	int k = 5, n = 10;
	int arr[] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
	for (int i = 0; i < n; ++i)
		arr[i] = arr[i] < k ? arr[i] + k : arr[i] - k; 
	sort(arr, arr + n);
	cout << arr[0] << endl << arr[n-1] << endl;
	// int first = arr[0] + k, second = (arr[n-1] - k) > 0 && (arr[n-1] - k) > first ? (arr[n-1] - k) : (arr[n-1] + k);
	cout << arr[n-1] - arr[0] << endl;
}