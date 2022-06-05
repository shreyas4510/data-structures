#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int arr[] = {1, 1, 1, 1};
	int n=4, k=2;

	unordered_map<int, int> pairs;
	int counter = 0;
	for (int i = 0; i < n; ++i) {
		if ( pairs[k - arr[i]] ) {
			counter += pairs[k - arr[i]];
		}
		pairs[arr[i]] = pairs[arr[i]] ? pairs[arr[i]]+1 : 1;
	}
	cout << counter << endl;
}