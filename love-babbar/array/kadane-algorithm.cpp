#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 5;
	int arr[] = {1,2,3,-2,5};

	long long maxSum = INT_MIN, currentSum = 0;
	for (int i = 0; i < n; ++i) {

		currentSum = currentSum + arr[i];

		if (maxSum < currentSum) 
			maxSum = currentSum;

		if (currentSum < 0)
			currentSum = 0;
	}
	cout << maxSum << endl;
	return 0;
}
