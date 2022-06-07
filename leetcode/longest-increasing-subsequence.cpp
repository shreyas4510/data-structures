#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> nums = {1,3,5,4,7};
	int count = 1, currentMax = INT_MIN, prev = nums.at(0);
	for (int i=1; i<nums.size(); i++ ) {
		if ( nums.at(i) > prev )
			++count;
		else
			count = 1;

		if (currentMax < count)
			currentMax = count;
		prev = nums.at(i);
	}
	cout << (currentMax == INT_MIN ? nums.size() : currentMax) << endl;
}