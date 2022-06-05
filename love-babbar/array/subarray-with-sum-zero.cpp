#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n) {
	unordered_set<int> inset;
    int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0)
			return true;

		sum += arr[i];
		if ( sum == 0 || inset.count(sum) )
			return true;

		inset.insert(arr[i]);
	}
	return false;
}

int main() {
	int arr[] = { 4, 2, -3, 1, 6 };
	int n = 5;
	cout << (subArrayExists(arr, n) ? "Yes" : "No") << endl;
}