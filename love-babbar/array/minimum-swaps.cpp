#include <bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k) {

	int wsize=0;
	for (int i = 0; i < n; ++i) {
		if ( arr[i] <= k )
			wsize++;
	}

	cout << wsize << endl;

	int nFav=0, j=0, ans=INT_MAX;
	while( j < wsize ) {
		if ( arr[j] > k ) {
			nFav++;
		}
		j++;
	}
	ans = min(ans, nFav);
	cout << nFav << " " << ans << " " << j << endl;

	for (int i = j; i < n; ++i) {
		if ( arr[i] > k ) {
			nFav++;
		}

		if ( arr[i-wsize] > k ) {
			nFav--;
		}
		ans = min(ans, nFav);
	}
	return ans;
}

int main() {
	int arr[] = {19, 9};
	int k = 18, n = 2;
	cout << minSwap(arr, n, k) << endl;
}