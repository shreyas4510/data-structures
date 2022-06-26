#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> cardPoints = {1,2,3,4,5,6,1};
	int k = 3;

	int windowSum = 0, totalSum = 0, rem = cardPoints.size() - k, minSum = INT_MAX;
	for (int i = 0; i < rem; ++i) {
		windowSum += cardPoints.at(i);
		totalSum += cardPoints.at(i);
	}
	minSum = windowSum;

	for (int i=rem; i < cardPoints.size(); i++) {
		windowSum += cardPoints.at(i);
		windowSum -= cardPoints.at( i-rem );
		minSum = min( minSum, windowSum );
		totalSum += cardPoints.at(i);
	}

	cout << (totalSum - minSum) << endl;
}
