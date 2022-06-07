#include<bits/stdc++.h>
using namespace std;

vector<int> mergerSort( vector<int> nums, int start, int end ) {
	if (start >= end) {
		vector<int> v;
		if (end >= 0)
			v.push_back(nums.at(start));
		return v;
	}

	int mid = (start+end) / 2;
	vector<int> left = mergerSort(nums, start, mid);
	vector<int> right = mergerSort(nums, mid+1, end);
	int i=0, j=0, lsize = left.size(), rsize = right.size();
	vector<int> result;
	while( i < lsize || j < rsize ) {
		if ( i < lsize && j < rsize ) {
			if ( left.at(i) < right.at(j) ) {
				result.push_back(left.at(i));
				++i;
			} else {
				result.push_back(right.at(j));
				++j;
			}
		} else if ( i < lsize && j >= rsize ) {
			result.push_back(left.at(i));
			++i;
		} else {
			result.push_back(right.at(j));
			++j;
		}
	}
	return result;
}

int main() {
	vector<int> nums = { 54, 49, 42, 12, 89, 32, 64, 6 };
	vector<int> result = mergerSort( nums, 0, nums.size()-1 );

	for (int i : result)
		cout << i << "  ";
	cout << endl;

}