#include <bits/stdc++.h>
using namespace std;

int main() {

	// O(n^2)
	// unordered_map<int, int[2]> sums;
	// vector<int> arr = { 1, 0, 3 };
	// int n = 3, max = 0;

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j <= i; ++j) {
	// 		sums[j][0] += arr.at(i);
	// 		sums[j][1]++;
	// 		if ( sums[j][0] == 0 && sums[j][1] > max  ) {
	// 			max = sums[j][1];
	// 		}
	// 	}
	// }

	// cout << max << endl;


	// Optimal approach
	unordered_map<int, int> sums;
	sums[0] = 0;
	int cumSum = 0, longest = -1;

	vector<int> arr = { 1, 0, 3 };
	int n = 3;

	for (int i = 0; i < n; ++i) {
		cumSum += arr[i];
		if (sums.find(cumSum) != sums.end())
			longest = max(longest, i + 1 - sums[cumSum]);
		else
			sums[arr[i]] = i+1;
	}
	cout << longest << endl;
}