#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr = {10, 9, 8, 7, 6};
	int m = 2+1;

	for (int i = m; i < (m + arr.size()) / 2; i++) {
		int temp = arr.at(i);
		arr[i] = arr[arr.size() - 1 - i + m];
		arr[arr.size() - 1 - i + m] = temp;
	}

	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;
}