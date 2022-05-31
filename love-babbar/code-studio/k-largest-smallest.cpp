#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr = { 5, 6, 7, 2 };
	int n = 4, k = 4;
	sort(arr.begin(), arr.end());

	vector<int> ans;
	ans.push_back( arr.at( k - 1 ) );
	ans.push_back( arr.at( arr.size() - k ) );

	for (int i : ans) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}