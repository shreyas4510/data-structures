#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = 8;

	long long maxSoFar = 0, maxSum = INT_MIN;

	for (int i = 0; i < n; i++) {
		maxSoFar += arr[i];

		if (maxSum < maxSoFar)
			maxSum = maxSoFar;

		if (maxSoFar < 0)
			maxSoFar = 0;
	}
	cout << maxSoFar << "   " << maxSum << endl;
	return 0;
}