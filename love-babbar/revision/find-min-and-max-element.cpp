#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a[] = {3, 2, 1, 56, 10000, 167};
	int n = 6;

	long long max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if ( a[i] > max )
			max = a[i];

		if ( a[i] < min )
			min = a[i];
	}

	cout << max << "  " << min << endl;
}