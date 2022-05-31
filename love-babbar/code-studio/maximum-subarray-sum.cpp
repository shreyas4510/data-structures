#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = { -7, -8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10 };
	int n = 15;

	int continuousSum = 0, sumTillNow = INT_MIN;
	for (int i = 0; i < n; i++) {
	 	continuousSum += arr[i];

	 	if (sumTillNow < continuousSum)
	 		sumTillNow = continuousSum;
	 	
	 	if (continuousSum < 0)
	 		continuousSum = 0;
	}
	cout << continuousSum << "  " << sumTillNow << endl;
	return 0;
}