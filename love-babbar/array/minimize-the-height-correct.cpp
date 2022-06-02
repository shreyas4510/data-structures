#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = {1, 5, 8, 10};
	int n = 4, k = 2;

	sort(arr, arr+n);

	int ans = arr[n-1] - arr[0];
	int smallest = arr[0] + k;
	int largest = arr[n-1] - k;
	int mi, ma;

	for ( int i = 0; i < n; i++ ) {
		mi = min(smallest, arr[i+1]-k);
		ma = max(largest, arr[i]+k);

		if (mi < 0)
			continue;
		ans = min( ans, ma - mi );
	}

	cout << ans << endl;
}


// K = 2, N = 4
// Arr[] = {1, 5, 8, 10}
// Output:
// 5

