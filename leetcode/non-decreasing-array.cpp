#include <bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int>& nums) {
	bool modified = false;
	for (int i = 1; i < nums.size(); ++i) {
		if ( nums.at(i) < nums.at(i-1) ) {
			if (modified)
				return false;

			if ( i == 1 || nums.at(i-2) < nums.at(i) ) {
				nums.at(i-1) = nums.at(i);
			} else {
				nums.at(i) = nums.at(i-1);
			}
			modified = true;
		}
	}
	return true;
}

int main() {
	vector<int> nums = {3,4,2,3};
	cout << checkPossibility(nums) << endl;
}