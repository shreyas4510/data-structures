#include <bits/stdc++.h>
using namespace	std;

int main() {
	vector<int> nums = {1, -4, -2, 5, 3};

	int i = 0, j = nums.size() - 1;
	while( i < j ) {
		if (nums.at(i) < 0) {
			i++;
		}
		else if (nums.at(j) > 0) {
			j--;
		}
		else {
			int temp = nums.at(i);
			nums.at(i) = nums.at(j);
			nums.at(j) = temp; 
		}
	}

	for (int i = 0; i < nums.size(); ++i) {
		cout << nums.at(i) << " ";
	}
	cout << endl;
}