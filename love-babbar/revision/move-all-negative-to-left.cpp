#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = {1, -1, 3, 2, -7, -5, 11, 6 };
	int n = 8;

	vector<int> positives, negatives;
	for (int i = 0; i < n; ++i) {
		if ( arr[i] >= 0 )
			positives.push_back(arr[i]);
		else
			negatives.push_back(arr[i]);
	}

	for (int i = 0; i < n; ++i) {
		if ( i < positives.size() )
			arr[i] = positives.at(i);
		else
			arr[i] = negatives.at(i - positives.size());	
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << endl;
	}
}
