#include <bits/stdc++.h>
using namespace std;

int main() {

	int arr[] = { 1, 2, 3, -2, 5 };
	int n = 5;

	int sum = 0, maxTillNow = INT_MIN;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		
		if (maxTillNow < sum)
			maxTillNow = sum;

		if (sum < 0)
			sum = 0;
	}
	cout << maxTillNow << endl;
}